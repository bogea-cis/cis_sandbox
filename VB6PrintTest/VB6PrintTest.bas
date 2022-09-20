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
iRet = pPrintRaw(Chr(27) & "V" & "123456789012345678901234567890123456789012345678" & Chr(10), 51)
iRet = pTerminate()
End Sub

Private Sub Command3_Click()
Dim status As Long
iRet = pInitialize()
iRet = pGetStatus(status)
Text1.Text = status
iRet = pTerminate()
End Sub

Private Sub Command4_Click()
iRet = pInitialize()
iRet = pPrtCutter(1)
iRet = pTerminate()
End Sub
