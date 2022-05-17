package br.com.cis;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.ByteByReference;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;
import com.sun.jna.ptr.ShortByReference;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.awt.image.MemoryImageSource;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.LogRecord;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
import java.util.Properties;
import javax.imageio.ImageIO;


/**
 *
 * @author LuisBogea
 */
public class LsApiComm {
    
    private static LsApiComm instance = null;
    private LsApiInterface DEVICE = null;
    
    private String nativeLibraryName = null;
    
    private static final String OS = System.getProperty( "os.name").toLowerCase();
    private static final String PATH = System.getProperty( "user.dir");
    
    protected ShortByReference hConnect = null;
 
    protected byte SenseKey;
    protected byte SensorStatus;
    protected int DocumentNumber;
    protected Pointer ImageHandleFront = null;
    protected Pointer ImageHandleRear = null;
    
    private static Logger log;
    private static boolean logDebug;
    
    /**
     * Verify if is Java 64 or 32 bits
     * @return true for java 64 bits
     */
    private boolean isJava64bits() {
        String sJavaBitsSize = System.getProperty( "sun.arch.data.model");
        return sJavaBitsSize.contains( "64");
    }
    
    /**
     * getInstance()
     * @return LsApiComm instance
     */
    public static LsApiComm getInstance() {
        if( instance == null) {
            instance = new LsApiComm();
        }
        return instance;
    }
    
    /**
     * 
     */
    public LsApiComm() {
        super();
        // initial config file
        Properties cnfprop = new Properties();
        String iniPath = PATH + "\\" + this.getClass().getSimpleName();
        System.out.println("br.com.cis.LsApiComm.<init>()"+" iniPath=["+iniPath+"]");
        String iniFileName = String.valueOf( iniPath.substring( 0, iniPath.length())) + ".ini";
        System.out.println("br.com.cis.LsApiComm.<init>()"+" iniFileName=["+iniFileName+"]");
        InputStream iniFile = null;
        try {
            iniFile = new FileInputStream( iniFileName);
        } catch( FileNotFoundException e) {
        }
        if( iniFile != null) {
            try {
                cnfprop.load( iniFile);
                System.out.println("br.com.cis.LsApiComm.<init>()"+" Log=["+cnfprop.getProperty( "Log")+"]");
                logDebug = cnfprop.getProperty( "Log").equalsIgnoreCase( "debug");
            } catch( IOException e) {
            }
        }
        // log file
        log = Logger.getLogger( this.getClass().getName());
        log.setLevel(Level.ALL);
        SimpleDateFormat actualDate = new SimpleDateFormat( "yyyyMMdd");
        String today = actualDate.format( new Date());
        FileHandler fh;
        try {
            fh = new FileHandler( "logLsApiComm" + today + "log%g.log", 100000000, 20);
            fh.setFormatter( new LogFormatter());
            log.addHandler( fh);
            log.setUseParentHandlers( false);
            log.info( "--start:");
        } catch( SecurityException e) {
        } catch( IOException e) {
        }
        // native interface
        if( DEVICE == null) {
            try {
                if( OS.contains( "win")) {
                    if( isJava64bits()) {
                        System.out.println("br.com.cis.LsApiComm.<init>()"+" [win64]");
                        nativeLibraryName = "WIN64\\LsApi.dll";
                    } else {
                        System.out.println("br.com.cis.LsApiComm.<init>()"+" [win32]");
                        nativeLibraryName = "LsApi.dll";
                    }
                } else {
                    System.out.println("br.com.cis.LsApiComm.<init>()"+" [linux]");
                    nativeLibraryName = "LsApi.so";
                }
                
                String nativeLibrary = PATH + "\\lib\\" + nativeLibraryName;
                System.out.println("br.com.cis.LsApiComm.<init>()"+" path: ["+nativeLibrary+"]");
                log.entering( this.getClass().getCanonicalName(), " lib path=["+nativeLibrary+"]");
                DEVICE = ( LsApiInterface) Native.load( nativeLibrary, LsApiInterface.class);
                System.out.println("br.com.cis.LsApiComm.<init>()"+" loaded: ["+nativeLibrary+"]");
                log.entering( this.getClass().getCanonicalName(), " lib loaded=["+nativeLibrary+"]");
            } catch( Exception e) {
                System.err.println( "Fail to load " + "[" + nativeLibraryName + "]" + e.getMessage());
                log.log(Level.WARNING, " Fail to load [{0}]{1}", new Object[]{nativeLibraryName, e.getMessage()});
            }
        }        
    }
    
    /**
     * Retorna o numero do documento processado pela funcao
     * DocHandle()
     * @return Documet number
     */
    public int getDocumentNumber() {
        log.log(Level.INFO, "DocumentNumber=[{0}]", DocumentNumber);
        return DocumentNumber;
    }
    
    /**
     * Retorna parametro da funcao PeripheralStatus
     * @return SenseKey
     */
    public byte getSenseKey() {
        log.log(Level.INFO, "SenseKey=[{0}]", SenseKey);
        return SenseKey;
    }
    
    /**
     * Retorna parametro da funcao PeripheralStatus
     * @return SensorStatus
     */
    public byte getSensorStatus() {
        log.log(Level.INFO, "SensorStatus=[{0}]", SensorStatus);
        return SensorStatus;
    }
    
    /**
     * Conecta o leitor com a inteface
     * @return LsReply
     */
    public int Connect() {
        int ret;
        if( hConnect == null) {
            hConnect = new ShortByReference();
        }
        ret = DEVICE.LSConnect(0, 0, ( short)40, hConnect);
        log.entering( this.getClass().getCanonicalName(), "LSConnect ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        return ret;
    }
    
    /**
     * Desconecta o leitor da inteface
     * @return LsReply
     */
    public int Disconnect() {
        int ret = LsReply.LS_OKAY.getValue();
        if( hConnect != null) {
            ret = DEVICE.LSDisconnect( hConnect.getValue(), 0);
            if( ret == LsReply.LS_OKAY.getValue()) {
                hConnect = null;
            }
        }
        return ret;
    }
        
    /**
     * Leitura de status do leitor
     * @return LsReply
     */
    public int PeripheralStatus() {
        int ret;
        ByteByReference senseKey = new ByteByReference();
        ByteByReference sensorStatus = new ByteByReference();
        
        ret = DEVICE.LSPeripheralStatus( hConnect.getValue(), 0, senseKey, sensorStatus);
        log.entering( this.getClass().getCanonicalName(), "LSDisconnect ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        if( ret == LsReply.LS_OKAY.getValue()) {
            SenseKey = senseKey.getValue();
            SensorStatus = sensorStatus.getValue();
            log.log(Level.INFO, "SenseKey=[{0}], SensorStatus=[{1}]", new Object[]{SenseKey, SensorStatus});
        }
        return ret;
    }
    
    /**
     * Reset
     * @param ResetType RESET_ERROR, RESET_FREE_PATH, RESET_BELT_CLEANING, RESET_COUNTER_CARTRIDGE, RESET_UNIT_RESERVE
     * @return LsReply
     */
    public int Reset( short ResetType) {
        int ret;
        ret = DEVICE.LSReset( hConnect.getValue(), 0, ResetType);
        log.entering( this.getClass().getCanonicalName(), "LSReset ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        return ret;
    }
    
    /**
     * ConfigDoubleLeafAndDocLength
     * @param Type DOUBLE_LEAFING_ERROR, DOUBLE_LEAFING_WARNING, DOUBLE_LEAFING_DISABLE
     * @param Value from 0 to 100, default 50
     * @param DocMin length in millimeters 
     * @param DocMax length in millimeters
     * @return LS_OKAY, LS_PERIPHERAL_NOT_FOUND, LS_HARDWARE_ERROR, LS_PAPER_JAM, LS_INVALID_TYPE, LS_INVALID_VALUE
     * obs.: for LS40 always return LS_OKAY
     */
    public int ConfigDoubleLeafAndDocLength( int Type, short Value, int DocMin, int DocMax) {
        int ret;
        ret = DEVICE.LSConfigDoubleLeafingAndDocLength( hConnect.getValue(), 0, Type, Value, DocMin, DocMax);
        log.entering( this.getClass().getCanonicalName(), "LSConfigDoubleLeafingAndDocLength ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "Type=[{0}], Value=[{1}], DocMin=[{2}], DocMax=[{3}]", new Object[]{ Type, Value, DocMin, DocMax});
        return ret;
    }
    
    /**
     * DisableWaitDocument
     * @param Value true, false
     * @return LS_OKAY, LS_PERIPHERAL_NOT_FOUND, LS_HARDWARE_ERROR, LS_OPEN_NOT_DONE
     */
    public int DisableWaitDocument( boolean Value) {
        int ret;
        ret = DEVICE.LSDisableWaitDocument( hConnect.getValue(), 0, Value);
        log.entering( this.getClass().getCanonicalName(), "LSDisableWaitDocument ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "Value=[{0}]", Value);
        return ret;
    }
    
    /**
     * SetUnitSpeed
     * @param Speed SPEED_NORMAL, SPEED_STAMP
     * @return LS_OKAY, LS_SYSTEM_ERROR, LS_USB_ERROR, LS_PERIPHERAL_NOT_FOUND, LS_HARDWARE_ERROR, LS_INVALID_UNIT_SPEED
     */
    public int SetUnitSpeed( short Speed) {
        int ret;
        ret = DEVICE.LSSetUnitSpeed( hConnect.getValue(), 0, Speed);
        log.entering( this.getClass().getCanonicalName(), "LSSetUnitSpeed ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "Speed=[{0}]", Speed);
        return ret;
    }
    
    /**
     * SetLightIntensity
     * @param LightIntensity from 0 to 30
     * @return LS_OKAY, LS_SYSTEM_ERROR, LS_USB_ERROR, LS_PERIPHERAL_NOT_FOUND, LS_HARDWARE_ERROR, LS_INVALID_VALUE
     */
    public int SetLightIntensity( short LightIntensity) {
        int ret;
        ret = DEVICE.LSSetLightIntensity( hConnect.getValue(), 0, LightIntensity);
        log.entering( this.getClass().getCanonicalName(), "LSSetLightIntensity ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "LightIntensity=[{0}]", LightIntensity);
        return ret;
    }

    /**
     * DocHandle
     * @param Stamp NO_STAMP
     * @param Validate NO_PRINT_VALIDATE
     * @param CodeLine NO_READ_CODELINE, READ_CODELINE_MICR, READ_CODELINE_CMC7, READ_CODELINE_E13B
     * @param Side
     * @param ScanMode
     * @param Feeder
     * @param Sorter
     * @param WaitTimeout
     * @param Beep
     * @param ScanDocType
     * @return LsReply
     */
    public int DocHandle(   short Stamp,
                            short Validate,
                            short CodeLine,
                            char Side,
                            short ScanMode,
                            short Feeder,
                            short Sorter,
                            short WaitTimeout,
                            short Beep,
                            short ScanDocType) {
        int ret;
        IntByReference NrDoc = new IntByReference();
        ret = DEVICE.LSDocHandle( hConnect.getValue(), 0, Stamp, Validate, CodeLine, Side, ScanMode, Feeder, Sorter, WaitTimeout, Beep, NrDoc, ScanDocType, 0);
        DocumentNumber = NrDoc.getValue();
        log.entering( this.getClass().getCanonicalName(), "LSDocHandle ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "Stamp=[{0}]", Stamp);
        log.log( Level.INFO, "Validate=[{0}]", Validate);
        log.log( Level.INFO, "CodeLine=[{0}]", CodeLine);
        log.log( Level.INFO, "Side=[{0}]", Side);
        log.log( Level.INFO, "ScanMode=[{0}]", ScanMode);
        log.log( Level.INFO, "Feeder=[{0}]", Feeder);
        log.log( Level.INFO, "Sorter=[{0}]", Sorter);
        log.log( Level.INFO, "WaitTimeout=[{0}]", WaitTimeout);
        log.log( Level.INFO, "Beep=[{0}]", Beep);
        log.log( Level.INFO, "ScanDocType=[{0}]", ScanDocType);
        log.log( Level.INFO, "NrDoc=[{0}]", NrDoc.getValue());
        return ret;
    }
    
    /**
     * 
     * @param Codeline
     * @param LenCodeline
     * @param Barcode
     * @param LenBarcode
     * @param Optic
     * @param LenOptic
     * @return LsReply
     */
    public int ReadCodeline(    byte[] Codeline,
                                short LenCodeline,
                                byte[] Barcode,
                                short LenBarcode,
                                byte[] Optic,
                                short LenOptic) {
        int ret;
        ShortByReference lenCodeline = new ShortByReference();
        ShortByReference lenBarcode = new ShortByReference();
        ShortByReference lenOptic = new ShortByReference();
        lenCodeline.setValue( LenCodeline);
        lenBarcode.setValue( LenBarcode);
        lenOptic.setValue( LenOptic);
        
        ret = DEVICE.LSReadCodeline( hConnect.getValue(), 0, Codeline, lenCodeline, Barcode, lenBarcode, Optic, lenOptic);
        log.entering( this.getClass().getCanonicalName(), "LSReadCodeline ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        
        return ret;
    }
    
    /**
     * 
     * @param ClearBlack
     * @param side
     * @param ReadMode
     * @param NrDoc
     * @param frontImage
     * @param rearImage
     * @return LsReply
     * @throws IOException 
     */
    public Image ReadImage( short ClearBlack,
                            char side,
                            short ReadMode,
                            int NrDoc,
                            byte[] frontImage,
                            byte[] rearImage) throws IOException {
        int ret;
        PointerByReference FrontImage = new PointerByReference();
        PointerByReference RearImage = new PointerByReference();
        PointerByReference FrontImage2 = new PointerByReference();
        PointerByReference RearImage2 = new PointerByReference();
        Image image;
        
        ret = DEVICE.LSReadImage( hConnect.getValue(), 0, ClearBlack, side, ReadMode, NrDoc, FrontImage, RearImage, FrontImage2, RearImage2);
        log.entering( this.getClass().getCanonicalName(), "LSReadImage ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        System.out.println("br.com.cis.LsApiComm.ReadImage()"+" ret=["+ret+"]");
        
        ImageHandleFront = FrontImage.getValue();
        ImageHandleRear = RearImage.getValue();
        
        image = GetImage( RearImage.getValue());        
        BufferedImage bImageR = new BufferedImage( image.getWidth( null), image.getHeight( null), BufferedImage.TYPE_BYTE_GRAY);
        
        image = GetImage( FrontImage.getValue());        
        BufferedImage bImageF = new BufferedImage( image.getWidth( null), image.getHeight( null), BufferedImage.TYPE_BYTE_GRAY);
      
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ImageIO.write( bImageR, "bmp", baos);
        baos.flush();
        rearImage = baos.toByteArray();
        
        ImageIO.write( bImageF, "bmp", baos);
        frontImage = baos.toByteArray();
        
        return image;
    }

    /**
     * GetFrontImage
     * @param ClearBlack
     * @return Image image
     */
    public Image GetFrontImage( short ClearBlack) {
        int ret;
        Image image = (Image)null;
        PointerByReference FrontImage = new PointerByReference();
        PointerByReference RearImage = new PointerByReference();
        PointerByReference FrontImage2 = new PointerByReference();
        PointerByReference RearImage2 = new PointerByReference();

        ret = DEVICE.LSReadImage( hConnect.getValue(), 0, ClearBlack, Side.SIDE_ALL_IMAGE.getValue(), (short)0, DocumentNumber, FrontImage, RearImage, FrontImage2, RearImage2);
        log.entering( this.getClass().getCanonicalName(), "LSReadImage ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        
        if( ret == LsReply.LS_OKAY.getValue()) {
            ImageHandleFront = FrontImage.getValue();
            image = GetImage( FrontImage.getValue());        
        } else {
            log.log( Level.INFO, "ClearBlack=[{0}]", ClearBlack);
        }
        
        return image;
    }
    
   
    /**
     * GetRearImage
     * @param ClearBlack
     * @return Image image
     */
    public Image GetRearImage( short ClearBlack) {
        int ret;
        Image image = (Image)null;
        PointerByReference FrontImage = new PointerByReference();
        PointerByReference RearImage = new PointerByReference();
        PointerByReference FrontImage2 = new PointerByReference();
        PointerByReference RearImage2 = new PointerByReference();

        ret = DEVICE.LSReadImage( hConnect.getValue(), 0, ClearBlack, Side.SIDE_ALL_IMAGE.getValue(), (short)0, DocumentNumber, FrontImage, RearImage, FrontImage2, RearImage2);
        log.entering( this.getClass().getCanonicalName(), "LSReadImage ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        
        if( ret == LsReply.LS_OKAY.getValue()) {
            ImageHandleRear = RearImage.getValue();
            image = GetImage( RearImage.getValue());        
        } else {
            log.log( Level.INFO, "ClearBlack=[{0}]", ClearBlack);
        }
        
        return image;
    }
    
   
    /**
     * ReadBarcodeFromFrontImage
     * @param TypeBarcode
     * @param pos_x
     * @param pos_y
     * @param sizeW
     * @param sizeH
     * @param Codeline
     * @param LenCodeline
     * @return LsReply
     */
    public int ReadBarcodeFromFrontImage(   char TypeBarcode, 
                                            int pos_x, 
                                            int pos_y, 
                                            int sizeW, 
                                            int sizeH, 
                                            byte[] Codeline, 
                                            int LenCodeline) {
        int ret;
        IntByReference length = new IntByReference( LenCodeline);
        if( ImageHandleFront == null) {
            return LsReply.LS_BARCODE_ERROR.getValue();
        }
        ret = DEVICE.LSReadBarcodeFromBitmap( 0, ImageHandleFront, ( byte)TypeBarcode, pos_x, pos_y, sizeW, sizeH, Codeline, length);
        log.entering( this.getClass().getCanonicalName(), "LSReadBarcodeFromBitmap ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "TypeBarcode=[{0}]", TypeBarcode);
        log.log( Level.INFO, "pos_x=[{0}], pos_y=[{1}], sizeW=[{2}], sizeH=[{3}]", new Object[]{pos_x, pos_y, sizeW, sizeH});
        log.log( Level.INFO, "Codeline=[{0}]", Codeline);
        log.log( Level.INFO, "LenCodeline=[{0}], legth=[{1}]", new Object[]{ LenCodeline, length.getValue()});
        return ret;
    }
    
    /**
     * ReadBarcodeFromRearImage
     * @param TypeBarcode
     * @param pos_x
     * @param pos_y
     * @param sizeW
     * @param sizeH
     * @param Codeline
     * @param LenCodeline
     * @return LsReply
     */
    public int ReadBarcodeFromRearImage(    char TypeBarcode, 
                                            int pos_x, 
                                            int pos_y, 
                                            int sizeW, 
                                            int sizeH, 
                                            byte[] Codeline, 
                                            int LenCodeline) {
        int ret;
        IntByReference length = new IntByReference( LenCodeline);
        if( ImageHandleRear == null) {
            return LsReply.LS_BARCODE_ERROR.getValue();
        }
        ret = DEVICE.LSReadBarcodeFromBitmap( 0, ImageHandleRear, ( byte)TypeBarcode, pos_x, pos_y, sizeW, sizeH, Codeline, length);
        log.entering( this.getClass().getCanonicalName(), "LSReadBarcodeFromBitmap ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        log.log( Level.INFO, "TypeBarcode=[{0}]", TypeBarcode);
        log.log( Level.INFO, "pos_x=[{0}], pos_y=[{1}], sizeW=[{2}], sizeH=[{3}]", new Object[]{pos_x, pos_y, sizeW, sizeH});
        log.log( Level.INFO, "Codeline=[{0}]", Codeline);
        log.log( Level.INFO, "LenCodeline=[{0}], legth=[{1}]", new Object[]{ LenCodeline, length.getValue()});
        return ret;
    }
    
    /**
     * FreeImage
     * @return LS_OKAY
     */
    public int FreeImage() {
        if( ImageHandleFront != null) {
            DEVICE.LSFreeImage( 0, ImageHandleFront);
        }
        if( ImageHandleRear != null) {
            DEVICE.LSFreeImage( 0, ImageHandleRear);
        }
        ImageHandleFront = null;
        ImageHandleRear = null;
        return LsReply.LS_OKAY.getValue();
    }
    
    /**
     * UnitIdentify
     * @param pLsCfg
     * @param LsModel
     * @param FwVersion
     * @param FwDate
     * @param PeripheralID
     * @param BoardVersion
     * @param DecoderExpVersion
     * @param InkJetVersion
     * @param FeederVersion
     * @param SorterVersion
     * @param MotorVersion
     * @param Reserved1
     * @param Reserved2
     * @return LsReply
     */
    public int UnitIdentify(    byte[] pLsCfg, 
                                byte[] LsModel,
                                byte[] FwVersion,
                                byte[] FwDate,
                                byte[] PeripheralID,
                                byte[] BoardVersion,
                                byte[] DecoderExpVersion,
                                byte[] InkJetVersion,
                                byte[] FeederVersion,
                                byte[] SorterVersion,
                                byte[] MotorVersion,
                                byte[] Reserved1,
                                byte[] Reserved2) {
        int ret;
        ret = DEVICE.LSUnitIdentify( hConnect.getValue(), 0, pLsCfg, LsModel, FwVersion, FwDate, PeripheralID, BoardVersion, DecoderExpVersion, InkJetVersion, FeederVersion, SorterVersion, MotorVersion, Reserved1, Reserved2);
        log.entering( this.getClass().getCanonicalName(), "LSUnitIdentify ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        return ret;
    } 
    
    /**
     * GetLibVersion
     * @return String info
     */
    public String GetLibVersion() {
        ShortByReference len = new ShortByReference();
        String info = "";
        byte[] version = new byte[65];
        int ret = DEVICE.LSGetVersion( version, len);
        log.entering( this.getClass().getCanonicalName(), "LSGetVersion ret=["+ret+"]["+getLsReplyVerbose(ret)+"]");
        if( ret == 0) {
            info = new String( version);
        }
        return info;
    }
    
    
    /**
     * getLsReplyVerbose
     * @param rep
     * @return 
     */
    private String getLsReplyVerbose( int rep) {
       String srep = "";
       for( LsReply e : LsReply.values()) {
           if( e.getValue() == rep) {
               srep = e.getErrorMessage();
           }
       }
       return srep;
    }
    
    
    /**
     * GetImage
     * @param imageHandle
     * @return 
     */
    private Image GetImage( Pointer imageHandle) {
        Image image = (Image)null;

        int bilen = 40; // 40-byte BITMAPINFOHEADER
        byte bi[] = new byte[bilen];
        
        bi = imageHandle.getByteArray( 0, bilen);
        
        int nbisize = ( ( ( int)bi[3]&0xff)<<24)
        | ( ( ( int)bi[2]&0xff)<<16)
        | ( ( ( int)bi[1]&0xff)<<8)
        | ( int)bi[0]&0xff;
        System.out.println("Size of bitmapinfoheader is :"+nbisize);
        int nwidth = (((int)bi[7]&0xff)<<24)
        | (((int)bi[6]&0xff)<<16)
        | (((int)bi[5]&0xff)<<8)
        | (int)bi[4]&0xff;
        System.out.println("Width is :"+nwidth);
        int nheight = (((int)bi[11]&0xff)<<24)
        | (((int)bi[10]&0xff)<<16)
        | (((int)bi[9]&0xff)<<8)
        | (int)bi[8]&0xff;
        System.out.println("Height is :"+nheight);
        int nplanes = (((int)bi[13]&0xff)<<8) | (int)bi[12]&0xff;
        System.out.println("Planes is :"+nplanes);
        int nbitcount = (((int)bi[15]&0xff)<<8) | (int)bi[14]&0xff;
        System.out.println("BitCount is :"+nbitcount);
        int nsizeimage = (((int)bi[23]&0xff)<<24)
        | (((int)bi[22]&0xff)<<16)
        | (((int)bi[21]&0xff)<<8)
        | (int)bi[20]&0xff;
        System.out.println("SizeImage is :"+nsizeimage);
        int nxpm = (((int)bi[27]&0xff)<<24)
        | (((int)bi[26]&0xff)<<16)
        | (((int)bi[25]&0xff)<<8)
        | (int)bi[24]&0xff;
        System.out.println("X-Pixels per meter is :"+nxpm);
        int nypm = (((int)bi[31]&0xff)<<24)
        | (((int)bi[30]&0xff)<<16)
        | (((int)bi[29]&0xff)<<8)
        | (int)bi[28]&0xff;
        System.out.println("Y-Pixels per meter is :"+nypm);
        int nclrused = (((int)bi[35]&0xff)<<24)
        | (((int)bi[34]&0xff)<<16)
        | (((int)bi[33]&0xff)<<8)
        | (int)bi[32]&0xff;
        System.out.println("Colors used are :"+nclrused);
        int nclrimp = (((int)bi[39]&0xff)<<24)
        | (((int)bi[38]&0xff)<<16)
        | (((int)bi[37]&0xff)<<8)
        | (int)bi[36]&0xff;
        System.out.println("Colors important are :"+nclrimp);
        if( nbitcount == 24)
        {
            // No Palatte data for 24-bit format but scan lines are
            // padded out to even 4-byte boundaries.
            int npad = (nsizeimage / nheight) - nwidth * 3;
            int ndata[] = new int [nheight * nwidth];
            byte brgb[] = new byte [( nwidth + npad) * 3 * nheight];

            brgb = imageHandle.getByteArray( bilen, (nwidth + npad) * 3 * nheight);

            int nindex = 0;
            for( int j = 0; j < nheight; j++)
            {
                for( int i = 0; i < nwidth; i++)
                {
                    ndata [nwidth * (nheight - j - 1) + i] =
                        (255&0xff)<<24
                        | (((int)brgb[nindex+2]&0xff)<<16)
                        | (((int)brgb[nindex+1]&0xff)<<8)
                        | (int)brgb[nindex]&0xff;
        //            System.out.println("Encoded Color at ("
        //                +i+","+j+")is:"+brgb+" (R,G,B)= ("
        //                +((int)(brgb[2]) & 0xff)+","
        //                +((int)brgb[1]&0xff)+","
        //                +((int)brgb[0]&0xff)+")");
                    nindex += 3;
                }
                nindex += npad;
            }
       
            image = Toolkit.getDefaultToolkit().createImage( new MemoryImageSource( nwidth, nheight, ndata, 0, nwidth));
        
        }
        else if( nbitcount == 8)
        {
            // Have to determine the number of colors, the clrsused
            // parameter is dominant if it is greater than zero.  If
            // zero, calculate colors based on bitsperpixel.
            int nNumColors = 0;
            if( nclrused > 0)
            {
                nNumColors = nclrused;
            }
            else
            {
                nNumColors = ( 1&0xff)<<nbitcount;
            }
//            System.out.println("The number of Colors is :"+nNumColors);
            // Some bitmaps do not have the sizeimage field calculated
            // Ferret out these cases and fix 'em.
            if( nsizeimage == 0)
            {
                nsizeimage = ((((nwidth*nbitcount)+31) & ~31 ) >> 3);
                nsizeimage *= nheight;
//                System.out.println("nsizeimage (backup) is :"+nsizeimage);
            }
            // Read the palatte colors.
            int  npalette[] = new int [nNumColors];
            byte bpalette[] = new byte [nNumColors*4];

    //        fs.read (bpalette, 0, nNumColors*4);
            bpalette = imageHandle.getByteArray( bilen, nNumColors*4);

            int nindex8 = 0;
            for( int n = 0; n < nNumColors; n++)
            {
                npalette[n] = (255&0xff)<<24
                | (((int)bpalette[nindex8+2]&0xff)<<16)
                | (((int)bpalette[nindex8+1]&0xff)<<8)
                | (int)bpalette[nindex8]&0xff;
    //             System.out.println ("Palette Color "+n
    //            +" is:"+npalette[n]+" (res,R,G,B)= ("
    //            +((int)(bpalette[nindex8+3]) & 0xff)+","
    //            +((int)(bpalette[nindex8+2]) & 0xff)+","
    //            +((int)bpalette[nindex8+1]&0xff)+","
    //            +((int)bpalette[nindex8]&0xff)+")");
                nindex8 += 4;
            }
            // Read the image data (actually indices into the palette)
            // Scan lines are still padded out to even 4-byte
            // boundaries.
            int npad8 = ( nsizeimage / nheight) - nwidth;
//            System.out.println( "nPad is:"+npad8);
            int  ndata8[] = new int [nwidth*nheight];
            byte bdata[] = new byte [(nwidth+npad8)*nheight];

    //        fs.read (bdata, 0, (nwidth+npad8)*nheight);
            bdata = imageHandle.getByteArray( bilen + ( nNumColors*4), ( nwidth+npad8)*nheight);

            nindex8 = 0;
            for( int j8 = 0; j8 < nheight; j8++)
            {
                for( int i8 = 0; i8 < nwidth; i8++)
                {
                    ndata8 [nwidth*(nheight-j8-1)+i8] = npalette [((int)bdata[nindex8]&0xff)];
                    nindex8++;
                }
                nindex8 += npad8;
            }
            image = Toolkit.getDefaultToolkit().createImage( new MemoryImageSource( nwidth, nheight, ndata8, 0, nwidth));
    //        JLabel labelF = new JLabel( new ImageIcon( image));
    //        JOptionPane.showMessageDialog( null, labelF, "Front", JOptionPane.PLAIN_MESSAGE, null);
        }
        else
        {
//            System.out.println ("Not a 24-bit or 8-bit Windows Bitmap, aborting...");
            image = (Image)null;
        }
        
        return image;
    }
    
    
    class LogFormatter extends SimpleFormatter {

        private final String lineSeparator = System.getProperty( "line.separator");

        /**
         * Format the given LogRecord.
         * 
         * @param record
         *            the log record to be formatted.
         * @return a formatted log record
         */
        @Override
        public synchronized String format( LogRecord record) {
            StringBuilder sb = new StringBuilder();

            String message = formatMessage( record);
            sb.append( getActualTime());
            sb.append( " ");
            sb.append( String.format("%1$-7s", record.getLevel().getName()));
            sb.append( " ");
            sb.append( message);
            sb.append( " ");
            if( record.getLevel() == Level.FINER && "ENTRY".equals( message)) {
                StringBuilder append = sb.append("- ").append(record.getSourceClassName()).append(" : ").append(record.getSourceMethodName());
            }
            sb.append( lineSeparator);
            if( record.getThrown() != null) {
                try {
                    StringWriter sw = new StringWriter();
                    PrintWriter pw = new PrintWriter(sw);
                    record.getThrown().printStackTrace(pw);
                    pw.close();
                    sb.append(sw.toString());
                } catch( Throwable ex) {
                }
            }
            return sb.toString();
        }

        private String getActualTime() {
            SimpleDateFormat formato = new SimpleDateFormat( "yyyy/MM/dd HH:mm:ss:SSS");
            return formato.format( new Date());
        }
    }
    
    //...enum...
    public enum CodelineType {
        NO_READ_CODELINE( ( short) 0),
        READ_CODELINE_MICR( ( short) 1),
        READ_BARCODE_PDF417( ( short) 2),
        READ_CODELINE_CMC7( ( short) 5),
        READ_BARCODE_HW( (short) 6),
        READ_MICR_AND_BARCODE_HW( ( short) 7),
        READ_CODELINE_OPTIC( ( short) 21),
        READ_MICR_AND_OPTIC( ( short) 22),
        READ_OPTIC_AND_PDF417( ( short) 23),
        READ_BARCODE_2_OF_5( ( short) 50),
        READ_BARCODE_CODE39( ( short) 51),
        READ_BARCODE_CODE128( ( short) 52),
        READ_BARCODE_EAN13( ( short) 53),
        READ_CODELINE_HW_OCRA( ( short) 0x41),
        READ_CODELINE_HW_OCRB_NUM( ( short) 0x42),
        READ_CODELINE_HW_OCRB_ALFANUM( ( short) 0x43),
        READ_CODELINE_HW_E13B( ( short) 0x45),
        READ_CODELINE_HW_E13B_X_OCRB( ( short) 0x58),
        READ_CODELINE_HW_MULTI_READ( ( short) 0x4D),
        READ_ONE_CODELINE_TYPE( ( short) 0x4e);
        private final short value;
        CodelineType( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }

    public enum FrontStamp {
        NO_STAMP( ( short) 0),
        FRONT_STAMP( ( short) 1),
        BACK_STAMP( ( short) 2),
        FRONT_AND_BACK_STAMP( ( short) 3);        
        private final short value;
        FrontStamp( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    } 
    
    
    public enum Side {
        SIDE_NONE_IMAGE( 'N'),
        SIDE_FRONT_IMAGE( 'F'),
        SIDE_BACK_IMAGE( 'B'),
        SIDE_ALL_IMAGE( 'X'),
        SIDE_FRONT_BLUE_IMAGE( 'G');
        private final char value;
        Side( char value) {
            this.value = value;
        }
        public char getValue() {
            return this.value;
        }
    }
    
    public enum ScanMode {
        SCAN_MODE_BW( ( short) 1),
        SCAN_MODE_16GR100( ( short) 2),
        SCAN_MODE_16GR200( ( short) 3),
        SCAN_MODE_256GR100( ( short) 4),
        SCAN_MODE_256GR200( ( short) 5),
        SCAN_MODE_256GR100BN( ( short) 8),
        SCAN_MODE_256GR200BN( ( short) 9),
        SCAN_MODE_COLOR100( ( short) 10),
        SCAN_MODE_COLOR_200( ( short) 11),
        SCAN_MODE_16GR300( ( short) 20),
        SCAN_MODE_256GR300( ( short) 21),
        SCAN_MODE_COLOR_300( ( short) 22);
        private final short value;
        ScanMode( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum Feed {
        AUTO_FEED( ( short) 0),
        PATH_FEED( ( short) 1);
        private final short value;
        Feed( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum Sorter {
        HOLD_DOCUMENT( ( short) 0),
        SORTER_BAY1( ( short) 1),
        SORTER_BAY2( ( short) 2),
        SORTER_AUTOMATIC( ( short) 3),
        SORTER_SWITCH_1_TO_2 ( ( short) 4),
        EJECT_DOCUMENT( ( short) 6),
        SORTER_ON_CODELINE_CALLBACK( ( short) 6);
        private final short value;
        Sorter( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
 
    public enum Beep {
        NO_BEEP( ( short) 0),
        YES_BEEP( ( short) 1);
        private final short value;
        Beep( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum WaitTimeout {
        WAIT_NO( ( short) 'G'),
        WAIT_YES( ( short) 'W');
        private final short value;
        WaitTimeout( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum DoubleLeafing {
        DOUBLE_LEAFING_WARNING( ( short) 0),
        DOUBLE_LEAFING_ERROR( ( short) 1),
        DOUBLE_LEAFING_DISABLE( ( short) 7);
        private final short value;
        DoubleLeafing( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum ScanDocType {
        SCAN_PAPER_DOCUMENT( ( short) 0),
        SCAN_CARD( ( short) 1),
        SCAN_SHORT_DOCUMENT( ( short) 2),
        SCAN_LONG_DOCUMENT( ( short) 3),
        SCAN_A4_DOCUMENT( ( short) 4);
        private final short value;
        ScanDocType( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum ClearBlack {
        NO_CLEAR_BLACK( ( short) 0),
        CLEAR_ALL_BLACK( ( short) 1),
        CLEAR_AND_ALIGN_IMAGE( ( short) 2);
        private final short value;
        ClearBlack( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }
    
    public enum UnitSpeed {
        SPEED_DEFAULT( ( short) 0),
        SPEED_NORMAL( ( short) 1);
        private final short value;
        UnitSpeed( short value) {
            this.value = value;
        }
        public short getValue() {
            return this.value;
        }
    }

    public enum ResetType {
       RESET_ERROR( ( short)0x30),
       RESET_FREE_PATH( ( short)0x31),
       RESET_BELT_CLEANING( ( short)0x32),
       RESET_COUNTERCARTRIDGE( ( short)0x33),
       RESET_RESERVED( ( short)0x34),
       RESET_USB_HW_ERROR( ( short)0x39),
       RESET_FREE_PATH_IN_FEEDER( ( short)0x51),
       RESET_UNIT_RESERVE( ( short)0x60);
       private final short value;
       ResetType( short value) {
           this.value = value;
       }
       public short getValue() {
           return this.value;
       }
    }
    
    public enum TiffType {
        FILE_TIF( ( int)3),
        SAVE_TIF_JPEG( ( int)8),
        FILE_CCITT( ( int)25),
        FILE_CCITT_GROUP3_1DIM( ( int)27),
        FILE_CCITT_GROUP3_2DIM( ( int)28),
        FILE_CCITT_GROUP4( ( int)29);
        private final int value;
        TiffType( int value) {
            this.value = value;
        }
        public int getValue() {
            return this.value;
        }
    }
    
    
}

