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
Private Declare Function WinLeAssincronoCm7Cx Lib "P32CM7CX.DLL" (TamBuff As Long, ByVal lpAppBuff As String) As Long

Private Sub LeButton_Click()

End Sub
