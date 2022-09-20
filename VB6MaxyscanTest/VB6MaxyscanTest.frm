VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5445
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   12345
   LinkTopic       =   "Form1"
   ScaleHeight     =   5445
   ScaleWidth      =   12345
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command_Cancel 
      Caption         =   "Cancela a leitura"
      Height          =   855
      Left            =   360
      TabIndex        =   2
      Top             =   1560
      Width           =   2175
   End
   Begin VB.TextBox dataResp 
      Height          =   855
      Left            =   2640
      TabIndex        =   1
      Top             =   480
      Width           =   8775
   End
   Begin VB.CommandButton Command_Read 
      Caption         =   "Lê um documento"
      Height          =   855
      Left            =   360
      TabIndex        =   0
      Top             =   480
      Width           =   2175
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function pInitialize Lib "cis_serlibw32_maxyscanii.dll" Alias "Initialize" () As Long
Private Declare Function pTerminate Lib "cis_serlibw32_maxyscanii.dll" Alias "Terminate" () As Long
Private Declare Function pGetApiInfo Lib "cis_serlibw32_maxyscanii.dll" Alias "GetApiInfo" (ByVal version As String, ByRef maxSize As Long) As Long
Private Declare Function pStartRead Lib "cis_serlibw32_maxyscanii.dll" Alias "StartRead" () As Long
Private Declare Function pGetRead Lib "cis_serlibw32_maxyscanii.dll" Alias "GetRead" (ByVal data As String, ByVal maxSize As Long) As Long
Private Declare Function pStopRead Lib "cis_serlibw32_maxyscanii.dll" Alias "StopRead" () As Long

Dim flag As Integer

Private Sub Command_Cancel_Click()
flag = 1
End Sub

Private Sub Command_Read_Click()
Dim iRet As Long
Dim data As String
data = Space$(256)

iRet = pInitialize()
iRet = pStartRead()

dataResp.Text = "Passe o documento"
dataResp.Refresh
flag = 0
Do
    dummy = DoEvents()
    iRet = pGetRead(data, 255)
Loop While (iRet = -6 And flag = 0)
If flag = 1 Then
    iRet = pStopRead()
    dataResp.Text = "Operação cancelada"
Else
    dataResp.Text = data
End If

'MsgBox (data)

iRet = pTerminate()
End Sub


Private Sub Form_Load()
flag = 0
End Sub
