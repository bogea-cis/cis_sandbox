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
