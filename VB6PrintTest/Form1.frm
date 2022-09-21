VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5400
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   7470
   LinkTopic       =   "Form1"
   ScaleHeight     =   5400
   ScaleWidth      =   7470
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command4 
      Caption         =   "Cortar"
      Height          =   975
      Left            =   240
      TabIndex        =   4
      Top             =   3120
      Width           =   2535
   End
   Begin VB.TextBox Text1 
      Height          =   735
      Left            =   3120
      TabIndex        =   3
      Top             =   2160
      Width           =   2775
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Status"
      Height          =   855
      Left            =   240
      TabIndex        =   2
      Top             =   2160
      Width           =   2535
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Autenticar"
      Height          =   855
      Left            =   240
      TabIndex        =   1
      Top             =   1200
      Width           =   2535
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Imprimir"
      Height          =   855
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   2535
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
    Private Declare Function pInitialize Lib "D:\my-git\cis_sandbox\VB6PrintTest\cis_printerlibPR1500win32.dll" Alias "Initialize" () As Long
    Private Declare Function pTerminate Lib "D:\my-git\cis_sandbox\VB6PrintTest\cis_printerlibPR1500win32.dll" Alias "Terminate" () As Long
    Private Declare Function pPrintRaw Lib "D:\my-git\cis_sandbox\VB6PrintTest\cis_printerlibPR1500win32.dll" Alias "PrintRaw" (ByVal data As String, ByVal dataLength As Long) As Long
    Private Declare Function pPrtCutter Lib "D:\my-git\cis_sandbox\VB6PrintTest\cis_printerlibPR1500win32.dll" Alias "PrtCutter" (ByVal cut As Long) As Long
    Private Declare Function pGetStatus Lib "D:\my-git\cis_sandbox\VB6PrintTest\cis_printerlibPR1500win32.dll" Alias "GetStatus" (ByRef status As Long) As Long

Private Sub Command1_Click()
Dim iRet As Long
iRet = pInitialize()
iRet = pPrintRaw("123456789012345678901234567890123456789012345678" & Chr(10), 49)
iRet = pTerminate()
End Sub

Private Sub Command2_Click()
iRet = pInitialize()
Autentica ("1234567890123456789012345678901234567890123")
iRet = pTerminate()
End Sub

Private Sub Command3_Click()
Dim status As Long
iRet = pInitialize()
iRet = pGetStatus(status)
Text1.text = status
iRet = pTerminate()
End Sub

Private Sub Command4_Click()
iRet = pInitialize()
iRet = pPrtCutter(1)
iRet = pTerminate()
End Sub

Private Sub Autentica(ByVal text As String)
Const Logo As String = "FF FF 83 83 AB AB AB AB 83 D7 FF FF 87 83 EB EB EB EB 83 87 FF FF 83 83 F3 E7 CF 9F 83 83 FF FF 83 83 EB EB EB EB E3 F7 FF FF "
Dim LogoBin As String
For ii = 1 To Len(Logo) Step 3
    LogoBin = LogoBin + Chr$(Val("&h" + Mid$(Logo, ii, 2)))
Next ii
LogoBin = Chr$(27) + "K" + Chr$(Len(LogoBin) Mod 256) + Chr$(Len(LogoBin) / 256) + LogoBin


iRet = pPrintRaw(Chr(27) & "V" & LogoBin & text & Chr(10), (Len(LogoBin) + Len(text) + 3))

End Sub
