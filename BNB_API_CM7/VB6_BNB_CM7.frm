VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4950
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8670
   LinkTopic       =   "Form1"
   ScaleHeight     =   4950
   ScaleWidth      =   8670
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CacelaButton 
      Caption         =   "Cancela"
      Height          =   615
      Left            =   240
      TabIndex        =   2
      Top             =   3600
      Width           =   1335
   End
   Begin VB.TextBox LeBox 
      Height          =   615
      Left            =   240
      TabIndex        =   1
      Top             =   1080
      Width           =   8175
   End
   Begin VB.CommandButton LeButton 
      Caption         =   "Le documento"
      Height          =   615
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
Private Declare Function WinStartLeAssincronoCm7Cx Lib "P32CM7CX.DLL" (ByVal TimeLe As Long, ByVal TamBuff As Long) As Long
Private Declare Function WinLeAssincronoCm7Cx Lib "P32CM7CX.DLL" (ByRef TamBuff As Long, ByVal lpAppBuff As String) As Long
Private Declare Function WinCancelaLeituraCm7Cx Lib "P32CM7CX.DLL" () As Long

Dim cancelaFlag As Integer

Private Sub CacelaButton_Click()
cancelaFlag = 1
End Sub

Private Sub LeButton_Click()
Dim iRet As Long
Dim TimeLe As Long
Dim TamBuff As Long
Dim lpAppBuff As String
lpAppBuff = Space$(1024)
TamBuff = 50
TimeLe = 60
iRet = WinStartLeAssincronoCm7Cx(TimeLe, TamBuff)
If iRet = 0 Then
    LeBox.Text = "Passe o documento"
    cancelaFlag = 0
    Do
    dummy = DoEvents()
    iRet = WinLeAssincronoCm7Cx(TamBuff, lpAppBuff)
    If iRet = 0 Then
        LeBox.Text = lpAppBuff
    End If
    Loop While (iRet = 1 And cancelaFlag = 0)
End If
If cancelaFlag = 1 Then
    iRet = WinCancelaLeituraCm7Cx()
    LeBox.Text = "Opera��o cancelada"
End If
    
End Sub
