package br.com.cis;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import com.sun.jna.Library;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.ByteByReference;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.PointerByReference;
import com.sun.jna.ptr.ShortByReference;

/**
 *
 * @author LuisBogea
 */
public interface LsApiInterface extends Library {
    
	public int LSConnect( int hWnd, int hInst, short Peripheral, ShortByReference hConnect);
	public int LSDisconnect( short hConnect, int hWnd);
	public int LSUnitIdentify( short hConnect, int hWnd, byte[] pLsCfg, byte[] LsModel, byte[] FwVersion, byte[] FwDate, byte[] PeripheralID, byte[] BoardVersion, byte[] DecoderExpVersion, byte[] InkJetVersion, byte[] FeederVersion, byte[] SorterVersion, byte[] MotorVersion, byte[] Reserved1, byte[] Reserved2);
	public int LSPeripheralStatus( short hConnect, int hWnd, ByteByReference senseKey, ByteByReference sensorStatus);
	public int LSReset( short hConnect, int hWnd, short ResetType);
	public int LSLoadStringWithCounterEx( short hConnect, int hWnd, short PrintType, Pointer strEndorse, short LenEndorse, int StartNumber, short Step);
	public int LSLoadString( short hConnect, int hWnd, short PrintType, short LenEndorse, Pointer strEndorse);
	public int LSConfigDoubleLeafingAndDocLength( short hConnect, int hWnd, int Type, short Value, int DocMin, int DocMax);
	public int LSChangeStampPosition( short hConnect, int hWnd, short Step, byte Reserved);
	public int LSDisableWaitDocument( short hConnect, int hWnd, boolean fWait);
	public int LSSetUnitSpeed( short hConnect, int hWnd, short UnitSpeed);
	public int LSSetLightIntensity( short hConnect, int hWnd, short LightIntensity);
	public int LSModifyPWMUltraViolet( short hConnect, int hWnd, short UnitSpeed, boolean HighContrast, short Reserved);
	public int LSGetDocData( short hConnect, int hWnd, IntByReference NrDoc, Pointer FilenameFront, Pointer FilenameRear, Pointer Reserved1, Pointer Reserved2, PointerByReference FrontImage, PointerByReference RearImage, PointerByReference Reserved3, PointerByReference Reserved4, Pointer CodelineSW, Pointer CodelineHW, Pointer Barcode, Pointer CodelinesOptical, ShortByReference DocToRead, IntByReference NrPrinted, Pointer Reserved5, Pointer Reserved6);
	public int LSDocHandle( short hConnect, int hWnd, short Stamp, short Validate, short CodeLine, char Side, short ScanMode, short Feeder, short Sorter, short WaitTimeout, short Beep, IntByReference NrDoc, short ScanDocType, int Reserved);
	public int LSDocHandleAndReadImage( short hConnect, int hWnd, short Stamp, short Validate, short CodeLine, char Side, short ScanMode, short Feeder, short Sorter, short WaitTimeout, short Beep, short ScanDocType, int Reserved, short ClearBlack, PointerByReference FrontImage, PointerByReference RearImage, PointerByReference FrontImage2, PointerByReference RearImage2);
	public int LSReadCodeline( short hConnect, int hWnd, byte[] CodelineHW, ShortByReference LenCodelineHW, byte[] Barcode, ShortByReference LenBarcode, byte[] CodelinesOptical, ShortByReference LenOptic);
	public int LSReadImage( short hConnect, int hWnd, short ClearBlack, char Side, short ReadMode, int NrDoc, PointerByReference FrontImage, PointerByReference RearImage, PointerByReference FrontImage2, PointerByReference RearImage2);
	public int LSReadBarcodeFromBitmap( int hWnd, Pointer hImage, int BarcodeType, int Pos_x, int Pos_y, int Width, int Height, byte[] Codeline, IntByReference Length_Codeline);
	public int LSReadPdf417FromBitmap( int hWnd, Pointer hImage, Pointer Codeline, IntByReference Length_Codeline, byte Reserved, float Pos_x, float Pos_y, float Width, float Height);
	public int LSMergeImageGrayAndUV( int hWnd, Pointer hFrontGrayImage, Pointer hFrontUVImage, float Reserved, float Reserved2, PointerByReference hGrayUVImage);
	public int LSFreeImage( int hWnd, Pointer hImage);
	public int LSSaveJPEG( int hWnd, Pointer hImage, int quality, String filename);
	public int LSSaveTIFFEx( int hWnd, Pointer hImage, String filename, int Type, int Quality, int SaveMode, int PageNumber);
	public int LSConvertImageToBW( int hWnd, short Method, Pointer GrayImage, PointerByReference BwImage, short Parameter1, float Threshold);
	public int LSSaveDIB( int hWnd, Pointer hImage, String filename);
        public int LSGetVersion( byte[] DllVersion, ShortByReference Length);
        public int LSBeep( short hConnect, int hWnd, short NrBeep, short TimeOn, short TimeOff);
        public int LSLED( short hConnect, int hWnd, short Color, short TimeOn, short TimeOff);
}
