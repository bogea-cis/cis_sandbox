VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   7110
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   10065
   LinkTopic       =   "Form1"
   ScaleHeight     =   7110
   ScaleWidth      =   10065
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox ImprimirBox 
      Height          =   4695
      Left            =   1680
      MultiLine       =   -1  'True
      TabIndex        =   5
      Top             =   1680
      Width           =   5415
   End
   Begin VB.TextBox AutenticarBox 
      Height          =   375
      Left            =   1680
      TabIndex        =   4
      Top             =   960
      Width           =   5415
   End
   Begin VB.TextBox StatusBox 
      Height          =   375
      Left            =   1680
      TabIndex        =   3
      Top             =   240
      Width           =   2415
   End
   Begin VB.CommandButton ImprimirButton 
      Caption         =   "Imprimir"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Top             =   1680
      Width           =   1215
   End
   Begin VB.CommandButton AutenticarButton 
      Caption         =   "Autenticar"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   1215
   End
   Begin VB.CommandButton StatusButton 
      Caption         =   "STATUS"
      Height          =   495
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function WinIniciaPrtCx Lib "P32PRTCX.DLL" () As Integer
Private Declare Function WinStatusPrtCx Lib "P32PRTCX.DLL" (ByVal buff As String) As Integer
Private Declare Function WinImprimePrtCx Lib "P32PRTCX.DLL" (ByVal media As Integer, ByVal logo As Integer, ByVal buff As String, ByVal tam As Integer) As Integer
Private Declare Function WinCancelPrtCx Lib "P32PRTCX.DLL" () As Integer


Private Sub AutenticarButton_Click()
Dim iRet As Integer
Dim tam As Integer
Dim buff As String
buff = Space$(100)
iRet = WinIniciaPrtCx
If iRet = 0 Then
    buff = AutenticarBox.Text + Chr(10)
    tam = Len(AutenticarBox.Text) + 1
    iRet = WinImprimePrtCx(1, 0, buff, tam)
End If

End Sub

Private Sub ImprimirButton_Click()
Dim iRet As Integer
Dim tam As Integer
Dim buff As String
buff = Space$(5000)
iRet = WinIniciaPrtCx
If iRet = 0 Then
    buff = ImprimirBox.Text + Chr(10)
    tam = Len(ImprimirBox.Text) + 1
    iRet = WinImprimePrtCx(0, 0, buff, tam)
End If
End Sub

Private Sub StatusButton_Click()
Dim iRet As Integer
Dim buff As String
buff = Space$(10)
buff = "000"
iRet = WinIniciaPrtCx
If iRet = 0 Then
    iRet = WinStatusPrtCx(buff)
    StatusBox.Text = buff
End If
End Sub
