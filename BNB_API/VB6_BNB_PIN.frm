VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4515
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7890
   LinkTopic       =   "Form1"
   ScaleHeight     =   4515
   ScaleWidth      =   7890
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox BufferBox 
      Height          =   495
      Left            =   1800
      TabIndex        =   3
      Top             =   1200
      Width           =   5895
   End
   Begin VB.CommandButton Fecha 
      Caption         =   "Fecha"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Top             =   2160
      Width           =   1335
   End
   Begin VB.CommandButton LeBuffer 
      Caption         =   "LeBuffer"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   1200
      Width           =   1335
   End
   Begin VB.CommandButton Abre 
      Caption         =   "Abre"
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Declare Function AbrePIN Lib "P32PinCx.dll" () As Long
Declare Function LeBufferPIN Lib "P32PinCx.dll" (ByVal Buffer As String, ByRef Tamanho As Long, ByRef Controle As Integer) As Long
Declare Function FechaPIN Lib "P32PinCx.dll" () As Long

Private Sub Abre_Click()
Dim iRet As Long
iRet = AbrePIN
End Sub

Private Sub Fecha_Click()
Dim iRet As Long
iRet = FechaPIN
End Sub

Private Sub LeBuffer_Click()
Dim iRet As Long
Dim Tamanho As Long
Dim Controle As Integer
Dim Buffer As String
Buffer = Space$(1024)
Tamanho = 4
iRet = LeBufferPIN(Buffer, Tamanho, Controle)
End Sub
