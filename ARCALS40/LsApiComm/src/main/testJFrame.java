/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import br.com.cis.LsApiComm;
import br.com.cis.LsApiComm.Beep;
import br.com.cis.LsApiComm.ClearBlack;
import br.com.cis.LsApiComm.CodelineType;
import br.com.cis.LsApiComm.DoubleLeafing;
import br.com.cis.LsApiComm.Feed;
import br.com.cis.LsApiComm.FrontStamp;
import br.com.cis.LsApiComm.ResetType;
import br.com.cis.LsApiComm.ScanDocType;
import br.com.cis.LsApiComm.ScanMode;
import br.com.cis.LsApiComm.Side;
import br.com.cis.LsApiComm.Sorter;
import br.com.cis.LsApiComm.WaitTimeout;
import br.com.cis.LsReply;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.image.RenderedImage;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

/**
 *
 * @author LuisBogea
 */
public class testJFrame extends javax.swing.JFrame {

    LsApiComm scanner;

    
    
    
    
    /**
     * Creates new form testJFrame
     */
    public testJFrame() {
        initComponents();
        scanner = LsApiComm.getInstance();
        int ret = scanner.Connect();
        System.out.println("main.testJFrame.<init>()"+" Connect ret=["+ret+"]");
        if( ret == LsReply.LS_TRY_TO_RESET.getValue()) {
            scanner.Reset( ResetType.RESET_FREE_PATH.getValue());
            ret = scanner.Connect();
        }
        ret = scanner.PeripheralStatus();
        System.out.println("main.testJFrame.<init>()"+" PeripheralStatus ret=["+ret+"]");
        if( ret == LsReply.LS_PAPER_JAM.getValue()) {
            scanner.Reset( ResetType.RESET_FREE_PATH.getValue());
            ret = scanner.Connect();
        }
        byte[] pLsCfg = new byte[128];
        byte[] LsModel = new byte[128]; 
        byte[] FwVersion = new byte[128];
        byte[] FwDate = new byte[128];
        byte[] PeripheralID = new byte[128];
        byte[] BoardVersion = new byte[128];
        byte[] DecoderExpVersion = new byte[128];
        byte[] InkJetVersion = new byte[128];
        byte[] FeederVersion = new byte[128];
        byte[] SorterVersion = new byte[128];
        byte[] MotorVersion = new byte[128];
        byte[] Reserved1 = new byte[128];
        byte[] Reserved2 = new byte[128];
        ret = scanner.UnitIdentify( pLsCfg, LsModel, FwVersion, FwDate, PeripheralID, BoardVersion, DecoderExpVersion, InkJetVersion, FeederVersion, SorterVersion, MotorVersion, Reserved1, Reserved2);
        if( ret == LsReply.LS_OKAY.getValue()) {
            String info = new String( LsModel).trim();
            System.out.println("main.testJFrame.<init>()"+" pLsCfg=["+info+"]");
            jTextArea_info.setText( info + "\n" + scanner.GetLibVersion());
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton_LeDoc = new javax.swing.JButton();
        jTextField_DocCode = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea_info = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jButton_LeDoc.setText("Le Doc");
        jButton_LeDoc.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_LeDocActionPerformed(evt);
            }
        });

        jTextArea_info.setColumns(20);
        jTextArea_info.setRows(5);
        jScrollPane1.setViewportView(jTextArea_info);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jTextField_DocCode, javax.swing.GroupLayout.DEFAULT_SIZE, 380, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButton_LeDoc)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 121, Short.MAX_VALUE)
                .addComponent(jButton_LeDoc)
                .addGap(18, 18, 18)
                .addComponent(jTextField_DocCode, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton_LeDocActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_LeDocActionPerformed
        // TODO add your handling code here:
        int reply;
        Image image = (Image)null;
        
        // test is doc is present
        reply = scanner.PeripheralStatus();
        System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" status reply=["+reply+"]");
        if( reply == LsReply.LS_OKAY.getValue() || reply == LsReply.LS_FEEDER_EMPTY.getValue()) {
            if( ( scanner.getSensorStatus() & 0x01) == 0x01) { // doc is on
                
                reply = scanner.ConfigDoubleLeafAndDocLength( DoubleLeafing.DOUBLE_LEAFING_DISABLE.getValue(), ( short)50, 100, 320);
                System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" double leaf reply=["+reply+"]");
                
                reply = scanner.DisableWaitDocument( true);
                System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" dis wait reply=["+reply+"]");
                
                
                // doc handle
                short stamp = FrontStamp.NO_STAMP.getValue();
                short validate = 0;
                short codeline = CodelineType.READ_CODELINE_CMC7.getValue();
                char side = Side.SIDE_ALL_IMAGE.getValue();
                short scanmode = ScanMode.SCAN_MODE_256GR300.getValue();
                short feeder = Feed.AUTO_FEED.getValue();
                short sorter = Sorter.SORTER_BAY1.getValue();
                short waittimeout = WaitTimeout.WAIT_YES.getValue();
                short beep = Beep.NO_BEEP.getValue();
                short scandoctype = ScanDocType.SCAN_LONG_DOCUMENT.getValue();
                reply = scanner.DocHandle( stamp, validate, codeline, side, scanmode, feeder, sorter, waittimeout, beep, scandoctype);
                System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" DocHandle reply=["+reply+"]");

                // leitura de cheque
                byte[] Codeline = new byte[128];
                reply = scanner.ReadCodeline( Codeline, ( short)128, null, (short)0, null, (short)0);
                System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" codeline reply=["+reply+"]");
                if( reply == LsReply.LS_OKAY.getValue()) {
                    String cheque = "";
                    int i = 0;
                    while( Codeline[i] != 0) {
                        cheque += String.valueOf( ( char)Codeline[i]);
                        i++;
                    }
                    System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" cheque=["+cheque+"]");
                    if( cheque.matches( "<[0-9]{8}< [0-9]{10}> [0-9]{12}:")) {
                        jTextField_DocCode.setText( cheque);
                    }
                }
                
                // pega imagem do documeto
//                byte[] frontImage = null;
//                byte[] rearImage = null;
                short clearblack = ClearBlack.CLEAR_AND_ALIGN_IMAGE.getValue();
                
//                try {
//                    image = scanner.ReadImage( clearblack, side, ( short)0, scanner.getDocumentNumber(), frontImage, rearImage);
//                } catch (IOException ex) {
//                    Logger.getLogger(testJFrame.class.getName()).log(Level.SEVERE, null, ex);
//                }
                image = scanner.GetFrontImage( clearblack);
                
                if( image != (Image)null) {
                    byte[] Barcode = new byte[128];
                    char barcodeType = ( char)CodelineType.READ_BARCODE_2_OF_5.getValue();
                    reply = scanner.ReadBarcodeFromFrontImage( barcodeType, 0, 0, 0, 0, Barcode, 128);
                    System.out.println("main.testJFrame.jButton_LeDocActionPerformed()"+" barcode reply=["+reply+"]");
                    if( reply == LsReply.LS_OKAY.getValue()) {
                        String barcode = "";
                        int i = 0;
                        while( Barcode[i] != 0) {
                            barcode += String.valueOf( ( char)Barcode[i]);
                            i++;
                        }
                        jTextField_DocCode.setText( barcode);
                    }
//                    JLabel labelF = new JLabel( new ImageIcon( image));
//                    JOptionPane.showMessageDialog( null, labelF, "Front", JOptionPane.PLAIN_MESSAGE, null);
                    BufferedImage bImage = new BufferedImage( image.getWidth(null), image.getHeight(null), BufferedImage.TYPE_BYTE_GRAY);
                    Graphics2D bGr = bImage.createGraphics();
                    bGr.drawImage( image, 0, 0, null);
                    bGr.dispose();
                    File outputFile = new File( "front.png");
                    try {
                        ImageIO.write((RenderedImage) bImage, "png", outputFile);
                    } catch (IOException ex) {
                        Logger.getLogger(testJFrame.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    
                    BufferedImage showImage = new BufferedImage( image.getWidth(null)/2, image.getHeight(null)/2, BufferedImage.TYPE_BYTE_GRAY);
                    Graphics2D g2 = showImage.createGraphics();
                    g2.drawImage(image, 0, 0, image.getWidth(null)/2, image.getHeight(null)/2, null);
                    g2.dispose();
                    JLabel showF = new JLabel( new ImageIcon( showImage));
                    JOptionPane.showMessageDialog( null, showF, "Front", JOptionPane.PLAIN_MESSAGE, null);
                }
                
                reply = scanner.FreeImage();
            }
        }
        
    }//GEN-LAST:event_jButton_LeDocActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(testJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(testJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(testJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(testJFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new testJFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton_LeDoc;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea_info;
    private javax.swing.JTextField jTextField_DocCode;
    // End of variables declaration//GEN-END:variables
}
