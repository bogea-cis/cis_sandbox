VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5130
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   9930
   LinkTopic       =   "Form1"
   ScaleHeight     =   5130
   ScaleWidth      =   9930
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox CardBox 
      Height          =   615
      Left            =   1800
      TabIndex        =   3
      Top             =   1200
      Width           =   6495
   End
   Begin VB.CommandButton CancelaButton 
      Caption         =   "Cancela"
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   2040
      Width           =   1335
   End
   Begin VB.CommandButton LeButton 
      Caption         =   "Leitura"
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   1200
      Width           =   1335
   End
   Begin VB.CommandButton AbreButton 
      Caption         =   "Abre"
      Height          =   615
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function WinStartLeAssincronoCartaoPassagemXP Lib "P32TCATM.DLL" (ByVal TimeLe As Long) As Long
Private Declare Function WinLeAssincronoCartaoPassagemXP Lib "P32TCATM.DLL" (ByVal TamBuff As Long, ByVal lpAppBuff As String) As Long
Private Declare Function WinCancelaLeituraCartaoPassagemXP Lib "P32TCATM.DLL" () As Long

Private Sub AbreButton_Click()
Dim iRet As Long
Dim TimeLe As Long
TimeLe = 60
iRet = WinStartLeAssincronoCartaoPassagemXP(TimeLe)
End Sub

Private Sub CancelaButton_Click()
Dim iRet As Long
iRet = WinCancelaLeituraCartaoPassagemXP()
End Sub

Private Sub LeButton_Click()
Dim iRet As Long
Dim TamBuff As Long
Dim lpAppBuff As String
lpAppBuff = Space$(1024)
TamBuff = 1024
iRet = WinLeAssincronoCartaoPassagemXP(TamBuff, lpAppBuff)
End Sub
