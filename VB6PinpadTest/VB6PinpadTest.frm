VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   8040
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   15510
   LinkTopic       =   "Form1"
   ScaleHeight     =   8040
   ScaleWidth      =   15510
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox Text_GetPIN 
      Height          =   525
      Left            =   8880
      TabIndex        =   18
      Top             =   6000
      Width           =   3375
   End
   Begin VB.CommandButton Command_GetPIN 
      Caption         =   "Senha GetPIN"
      Height          =   615
      Left            =   6600
      TabIndex        =   17
      Top             =   6000
      Width           =   2055
   End
   Begin VB.TextBox TextEmvTagList 
      Height          =   375
      Left            =   6120
      TabIndex        =   16
      Text            =   "5A5F349F269F279F109F379F36959A9C9F025F2A829F1A8C84"
      Top             =   6840
      Width           =   8895
   End
   Begin VB.TextBox TextEmvAid 
      Height          =   375
      Left            =   2400
      TabIndex        =   15
      Text            =   "A0000000043060"
      Top             =   6840
      Width           =   3615
   End
   Begin VB.TextBox Text_EmvMac 
      Height          =   375
      Left            =   6120
      TabIndex        =   14
      Text            =   "19F2701009F10120010800003220000000000000000000000FF9F3704Ae49B7179F360200D495058"
      Top             =   7440
      Width           =   8895
   End
   Begin VB.TextBox TextEmvPinBlock 
      Height          =   375
      Left            =   2400
      TabIndex        =   13
      Text            =   "D9E54FA202262B4D"
      Top             =   7440
      Width           =   3615
   End
   Begin VB.CommandButton Command_EMVpinExchange 
      Caption         =   "EMV PIN exchange"
      Height          =   615
      Left            =   240
      TabIndex        =   12
      Top             =   6840
      Width           =   2055
   End
   Begin VB.CommandButton Command_EMVgetCard 
      Caption         =   "EMV getCard"
      Height          =   615
      Left            =   240
      TabIndex        =   11
      Top             =   3480
      Width           =   2055
   End
   Begin VB.TextBox TxtPinBlock 
      Height          =   375
      Left            =   2400
      TabIndex        =   10
      Top             =   5880
      Width           =   3615
   End
   Begin VB.CommandButton Command_Senha 
      Caption         =   "Senha PINBLOCK"
      Height          =   615
      Left            =   240
      TabIndex        =   9
      Top             =   5880
      Width           =   2055
   End
   Begin VB.TextBox APDUResp 
      Height          =   3015
      Left            =   2520
      MaxLength       =   1024
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   2
      Top             =   2640
      Width           =   12255
   End
   Begin VB.CommandButton Command_ReadSMC 
      Caption         =   "Lê cartão com chip"
      Height          =   615
      Left            =   240
      TabIndex        =   8
      Top             =   2640
      Width           =   2055
   End
   Begin VB.TextBox Track3 
      Height          =   375
      Left            =   2520
      TabIndex        =   7
      Top             =   2040
      Width           =   9735
   End
   Begin VB.TextBox Track2 
      Height          =   375
      Left            =   2520
      TabIndex        =   6
      Top             =   1560
      Width           =   9735
   End
   Begin VB.TextBox Track1 
      Height          =   375
      Left            =   2520
      TabIndex        =   5
      Top             =   1080
      Width           =   9735
   End
   Begin VB.TextBox InfoDev 
      Height          =   615
      Left            =   6360
      TabIndex        =   4
      Top             =   240
      Width           =   5895
   End
   Begin VB.TextBox Info 
      Height          =   615
      Left            =   2520
      TabIndex        =   3
      Top             =   240
      Width           =   3615
   End
   Begin VB.CommandButton Command_INFO 
      Caption         =   "INFO"
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   240
      Width           =   2055
   End
   Begin VB.CommandButton Command_ReadMSR 
      Caption         =   "Lê cartão magnético"
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   1080
      Width           =   2055
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Type stMsrEvent_t
Track1 As String
Track2 As String
Track3 As String
End Type

Private Declare Function pInitialize Lib "cis_pinpadlib32.dll" Alias "Initialize" (ByVal mode As Long) As Long
Private Declare Function pTerminate Lib "cis_pinpadlib32.dll" Alias "Terminate" () As Long
Private Declare Function pGetApiInfo Lib "cis_pinpadlib32.dll" Alias "GetApiInfo" (ByVal apiInfo As String, ByVal maxSize As Long) As Long
Private Declare Function pGetDeviceInfo Lib "cis_pinpadlib32.dll" Alias "GetDeviceInfo" (ByVal devInfo As String) As Long
Private Declare Function pClearScreen Lib "cis_pinpadlib32.dll" Alias "ClearScreen" (ByVal poX As Long, ByVal poY As Long, ByVal width As Long, ByVal height As Long) As Long
Private Declare Function pWriteDisplay Lib "cis_pinpadlib32.dll" Alias "WriteDisplay" (ByVal linha As Long, ByVal coluna As Long, ByVal data As String) As Long
Private Declare Function pStartReadMSR Lib "cis_pinpadlib32.dll" Alias "StartReadMSR" (ByRef eventId As Long) As Long
Private Declare Function pGetDataMSR Lib "cis_pinpadlib32.dll" Alias "GetDataMSR" (ByVal stMsrEvent As String) As Long
Private Declare Function pGetDataMSR2 Lib "cis_pinpadlib32.dll" Alias "GetDataMSR" (ByRef msrEvent As stMsrEvent_t) As Long
Private Declare Function pCancelEvent Lib "cis_pinpadlib32.dll" Alias "CancelEvent" (ByVal eventId As Long) As Long
Private Declare Function pStartReadSMC Lib "cis_pinpadlib32.dll" Alias "StartReadSMC" (ByRef eventId As Long) As Long
Private Declare Function pGetDataSMC Lib "cis_pinpadlib32.dll" Alias "GetDataSMC" (ByVal smcData As String, ByRef smcDataLength As Long) As Long
Private Declare Function pChipIO Lib "cis_pinpadlib32.dll" Alias "ChipIO" (ByVal cardType As Long, ByVal prot As Long, ByVal packed As Long, ByVal APDU As String, ByVal APDUSize As Long, ByVal APDUResp As String, ByRef maxSize As Long) As Long
Private Declare Function pGetMediaStatus Lib "cis_pinpadlib32.dll" Alias "GetMediaStatus" (ByVal mediaStatus As String, ByVal maxSize As Long) As Long
Private Declare Function pStartReadSKey Lib "cis_pinpadlib32.dll" Alias "StartReadSKey" (ByVal pinParams As String, ByRef enventId As Long) As Long
Private Declare Function pGetDataSKey Lib "cis_pinpadlib32.dll" Alias "GetDataSKey" (ByRef endKey As Long, ByRef eventId As Long) As Long
Private Declare Function pCreatePinBlock Lib "cis_pinpadlib32.dll" Alias "CreatePinblock" (ByVal mode As Byte, ByVal pbFmt As Byte, ByVal mKeyIdx As Long, ByVal wKey As String, ByVal PAN As String, ByVal pinBlock As String, ByRef maxSize As Long) As Long
Private Declare Function pLedControl Lib "cis_pinpadlib32.dll" Alias "LedControl" (ByVal cLED1 As Byte, ByVal cLED2 As Byte, ByVal cLED3 As Byte, ByVal cLED4 As Byte, ByVal cLEDBL As Byte) As Long
Private Declare Function pEMV_getCard Lib "cis_pinpadlib32.dll" Alias "EMV_getCard" (ByRef cardType As Byte, ByRef chipLastStatus As Byte, ByRef appTypeSel As Byte, ByRef networkSel As Byte, ByRef aidIndex As Byte, ByRef Track1 As Byte, ByRef Track2 As Byte, ByRef Track3 As Byte, ByRef PAN As Byte, ByRef panSeq As Byte, ByRef aquirerData As Byte) As Long
Private Declare Function pEMV_PINChangeStart Lib "cis_pinpadlib32.dll" Alias "EMV_PINChangeStart" (ByVal aid As String, ByVal tagList As String, ByRef data As Byte) As Long
Private Declare Function pEMV_PINChangeFinish Lib "cis_pinpadlib32.dll" Alias "EMV_PINChangeFinish" (ByVal pinBlock As String, ByVal mac As String) As Long
Private Declare Function pGetPIN Lib "cis_pinpadlib32.dll" Alias "GetPIN" (ByRef endKey As Long, ByRef keyLen As Long, ByVal pin As String) As Long


Private Sub Command_GetPIN_Click()
Dim iRet As Long
Dim eventId As Long
Dim pinParams As String
Dim endKey As Long
Dim keyLen As Long
Dim pinBlock As String
pinBlock = Space$(100)
Dim maxSize As Long

minKeys = 4
MaxKeys = 12
startPosX = 3
startPosY = 2
autoEnd = True
interKeyEv = True
echoStar = True
clearKeyBS = False

pinParams = conv32bits(minKeys) + conv32bits(MaxKeys) + convBol(autoEnd) + convBol(interKeyEv) + _
            convBol(clearKeyBS) + convBol(echoStar) + conv32bits(startPosX) + conv32bits(startPosY) + Space$(1024)

iRet = pInitialize(0)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pWriteDisplay(1, 5, "DIGITE A SENHA")
iRet = pLedControl(48, 48, 48, 48, 49)

iRet = pStartReadSKey(pinParams, eventId)

endKey = -1
Do
    iRet = pGetPIN(endKey, keyLen, pinBlock)
Loop While (endKey = -1)

Text_GetPIN.Text = Left$(pinBlock, 16)
'MsgBox (PinBlock)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pLedControl(48, 48, 48, 48, 48)

iRet = pCancelEvent(eventId)

End Sub

Private Sub Command_INFO_Click()
Dim iRet As Long
Dim apiInfo As String
Dim devInfo As String
apiInfo = Space$(1024)
devInfo = Space$(1024)

iRet = pInitialize(0)
iRet = pGetApiInfo(apiInfo, 255)
'apiInfo = Left$(apiInfo, InStr(1, apiInfo, vbNullChar) - 1)
iRet = pGetDeviceInfo(devInfo)
'dumpStr (devInfo)
'MsgBox (devInfo)
Info.Text = Left$(apiInfo, 255)
InfoDev.Text = Mid$(devInfo, 1, InStr(1, devInfo, Chr(0)) - 1) + " " + Mid$(devInfo, 22, InStr(22, devInfo, Chr(0)) - 23) + " " _
                + Mid$(devInfo, 43, InStr(43, devInfo, Chr(0)) - 44) + " " + Mid$(devInfo, 64, InStr(64, devInfo, Chr(0)) - 65)
End Sub

Private Sub Command_ReadMSR_Click()
Dim iRet As Long
Dim eventId As Long
Dim stMsrEvent As String
stMsrEvent = Space$(1024)
Dim msrEvent As stMsrEvent_t
msrEvent.Track1 = Space$(160)
msrEvent.Track2 = Space$(82)
msrEvent.Track3 = Space$(216)

iRet = pInitialize(0)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pWriteDisplay(1, 5, "PASSE O CARTAO")
iRet = pStartReadMSR(eventId)
'MsgBox (eventId

iRet = -6
While (iRet = -6)
    iRet = pGetDataMSR(stMsrEvent)
Wend

'tmpStr$ = ""
'For ii = 1 To 1024
'    tmpStr$ = tmpStr$ + Hex$(Asc(Mid$(stMsrEvent, ii, 1))) + " "
'Next ii

'MsgBox (Str(iRet) + " - " + tmpStr$)

Track1.Text = Left$(stMsrEvent, InStr(1, stMsrEvent, " "))
Track2.Text = Mid$(stMsrEvent, 80 + 1, (InStr(80 + 1, stMsrEvent, " ") - 80 + 1))
Track3.Text = Mid$(stMsrEvent, 80 + 41 + 1, (InStr(80 + 41 + 1, stMsrEvent, " ") - 80 + 41 + 1))
'iRet = -6
'While iRet = -6
'    iRet = pGetDataMSR2(msrEvent)
'Wend

'Track1.Text = Left$(msrEvent.Track1, 80)
'Track2.Text = Left$(msrEvent.Track2, 41)
'Track3.Text = Left$(msrEvent.Track3, 108)

iRet = pClearScreen(0, 0, 0, 0)
iRet = pCancelEvent(eventId)
End Sub

Private Sub Command_ReadSMC_Click()
Dim iRet As Long
Dim eventId As Long
Dim mediaStatus As String
mediaStatus = Space$(10)
Dim smcData As String
smcData = Space$(256)
Dim Resp As String
Resp = Space$(1024)

Dim APDU(14) As String
APDU(1) = Space$(50)
APDU(2) = Space$(50)
APDU(3) = Space$(50)
APDU(4) = Space$(50)
APDU(5) = Space$(50)
APDU(6) = Space$(50)
APDU(7) = Space$(50)
APDU(8) = Space$(50)
APDU(9) = Space$(50)
APDU(10) = Space$(50)
APDU(11) = Space$(50)
APDU(12) = Space$(50)
APDU(13) = Space$(50)
APDU(14) = Space$(50)

APDU(1) = "00A404000E315041592E5359532E4444463031"
APDU(2) = "00A4040007A0000000031010"
APDU(3) = "00A4040007A0000000032010"
APDU(4) = "00A4040007A0000000041010"
APDU(5) = "00A4040007A0000000043060"
APDU(6) = "00A4040007A0000000046000"
APDU(7) = "00A4040007A0000000038010"
APDU(8) = "00A4040007A0000000030001"
APDU(9) = "00A4040007A0000001544442"
APDU(10) = "00A4040007F0000000030001"
APDU(11) = "00B2010C00"
APDU(12) = "00B2020C00"
APDU(13) = "00B2030C00"

Dim GetResp As String
GetResp = "00C00000"

iRet = pInitialize(0)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pWriteDisplay(1, 5, "INSIRA O CARTAO")
iRet = pLedControl(49, 49, 49, 49, 48)
iRet = pStartReadSMC(eventId)

Do
    iRet = pGetMediaStatus(mediaStatus, 3)
    temp$ = Asc(Mid$(mediaStatus, 2, 1))
Loop While (temp <> 49)

iRet = pGetDataSMC(smcData, 255)
APDUResp.Text = Left$(smcData, InStr(1, smcData, Chr(32))) + vbCrLf

For i = 1 To 13
    iRet = pChipIO(48, 48, 48, APDU(i), Len(APDU(i)), Resp, 512)
    
    tmpResp = Left(Resp, InStr(1, Resp, Chr$(0)))
    
    'MsgBox (Resp)
    If Left$(Resp, 4) = "9000" Then
        APDUResp.Text = APDUResp.Text + vbCrLf + tmpResp
    End If
    If Left$(Resp, 2) = "61" Then
        APDUgetResp = GetResp + Mid$(Resp, 3, 2)
        'GetResp(9) = Resp(3)
        'GetResp(10) = Resp(4)
        iRet = pChipIO(48, 48, 48, APDUgetResp, 10, Resp, 512)
        tmpResp = Left(Resp, InStr(1, Resp, Chr$(0)))
        APDUResp.Text = APDUResp.Text + vbCrLf + tmpResp
    End If
Next i


iRet = pClearScreen(0, 0, 0, 0)
iRet = pLedControl(48, 48, 48, 48, 48)

iRet = pCancelEvent(eventId)
End Sub
Function conv32bits(ByVal val2conv As Long) As String
    conv32bits = ""
    For ii = 1 To 4
        conv32bits = conv32bits + Chr(val2conv Mod 256)
'        Print (val2conv Mod 256), "-"
        val2conv = val2conv / 256
    Next ii
End Function
Function convBol(ByVal val2conv As Integer) As String
    If (val2conv = 0) Then
        convBol = Chr(0)
    Else
        convBol = Chr(1)
    End If
End Function




Private Sub Command_Senha_Click()
Dim iRet As Long
Dim eventId As Long
Dim pinParams As String
Dim endKey As Long
Dim keyLen As Long
'pinParams = Space$(64)
Const MasterKey As String = "11111111111111111111111111111111"  'Masterkey no slot 01 3DES
'Const WorkingKey As String = "19A8759115F525EF19A8759115F525EF" 'WorkingKey AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA criptogrfada com a MasterKey
Const WorkingKey As String = "19A8759115F525EFB6D5852D4E1FE591" 'WorkingKey AAAAAAAAAAAAAAAABBBBBBBBBBBBBBBB criptogrfada com a MasterKey

Const PAN As String = "1234123412341234"
Dim pinBlock As String
pinBlock = Space$(100)
Dim maxSize As Long

minKeys = 4
MaxKeys = 6
startPosX = 3
startPosY = 2
autoEnd = True
interKeyEv = True
echoStar = True
clearKeyBS = False

pinParams = conv32bits(minKeys) + conv32bits(MaxKeys) + convBol(autoEnd) + convBol(interKeyEv) + _
            convBol(clearKeyBS) + convBol(echoStar) + conv32bits(startPosX) + conv32bits(startPosY) + Space$(1024)
'tmpStr$ = ""
'For i = 1 To 1024
'    tmpStr$ = tmpStr$ + Hex$(Asc(Mid$(pinParams, i, 1))) + " "
'Next i
'MsgBox (Str(iRet) + " - " + tmpStr$)

iRet = pInitialize(0)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pWriteDisplay(1, 5, "DIGITE A SENHA")
iRet = pLedControl(48, 48, 48, 48, 49)

iRet = pStartReadSKey(pinParams, eventId)

endKey = -1
Do
    iRet = pGetDataSKey(endKey, keyLen)
Loop While (endKey = -1)

'MsgBox (Str(endKey) + " " + Str(keyLen))

maxSize = 64
iRet = pCreatePinBlock(49, 50, 1, WorkingKey, PAN, pinBlock, maxSize)

TxtPinBlock.Text = Left$(pinBlock, 16)
'MsgBox (PinBlock)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pLedControl(48, 48, 48, 48, 48)

iRet = pCancelEvent(eventId)
End Sub

Private Sub Command_EMVgetCard_Click()
Dim iRet As Long
ReDim aquirerData(512) As Byte
Dim cardType As Byte
Dim chipLastStatus As Byte
Dim appTypeSel As Byte
Dim networkSel As Byte
Dim aidIndex As Byte
ReDim Track1(128) As Byte
ReDim Track2(128) As Byte
ReDim Track3(128) As Byte
ReDim PAN(20) As Byte
Dim panSeq As Byte

Dim eventId As Long
Dim mediaStatus As String
mediaStatus = Space$(10)
Dim smcData As String
smcData = Space$(256)
Dim Resp As String
Resp = Space$(1024)

iRet = pInitialize(0)
iRet = pClearScreen(0, 0, 0, 0)
iRet = pWriteDisplay(1, 5, "INSIRA O CARTAO")
iRet = pLedControl(49, 49, 49, 49, 48)
iRet = pStartReadSMC(eventId)

Do
    iRet = pGetMediaStatus(mediaStatus, 3)
    temp$ = Asc(Mid$(mediaStatus, 2, 1))
Loop While (temp <> 49)

iRet = pGetDataSMC(smcData, 255)
APDUResp.Text = Left$(smcData, InStr(1, smcData, Chr(32))) + vbCrLf

iRet = pEMV_getCard(cardType, chipLastStatus, appTypeSel, networkSel, aidIndex, Track1(0), Track2(0), Track3(0), PAN(0), panSeq, aquirerData(0))

If iRet = 0 Then
    APDUResp.Text = APDUResp.Text + StrConv(Track1, vbUnicode) + vbNewLine
    APDUResp.Text = APDUResp.Text + StrConv(Track2, vbUnicode) + vbNewLine
    APDUResp.Text = APDUResp.Text + StrConv(Track3, vbUnicode) + vbNewLine
    APDUResp.Text = APDUResp.Text + StrConv(PAN, vbUnicode) + vbNewLine
    APDUResp.Text = APDUResp.Text + StrConv(aquirerData, vbUnicode) + vbNewLine
End If

iRet = pClearScreen(0, 0, 0, 0)
iRet = pLedControl(48, 48, 48, 48, 48)

iRet = pCancelEvent(eventId)

End Sub

Private Sub Command_EMVpinExchange_Click()
Dim iRet As Long
Dim data As String
ReDim sData(128) As Byte

iRet = pInitialize(0)

If TextEmvAid.Text <> "" And TextEmvTagList.Text <> "" And TextEmvPinBlock.Text <> "" And Text_EmvMac.Text <> "" Then
    iRet = pEMV_PINChangeStart(TextEmvAid.Text, TextEmvTagList.Text, sData(0))
    
    If iRet = 0 Then
        data = StrConv(sData, vbUnicode)
    End If
        
    iRet = pEMV_PINChangeFinish(TextEmvPinBlock.Text, Text_EmvMac.Text)
Else
    MsgBox ("Campos vazios")
End If



End Sub

Sub dumpStr(strVal As String)
tmpStr$ = ""
For ii = 1 To Len(strVal)
    tmpStr$ = tmpStr$ + Hex$(Asc(Mid$(strVal, ii, 1))) + " "
Next ii


MsgBox (Str(iRet) + " - " + tmpStr$)

End Sub

