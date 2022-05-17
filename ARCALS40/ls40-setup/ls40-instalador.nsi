; ls40-instalador
;
; This script is perhaps one of the simplest NSIs you can make. All of the
; optional settings are left to their default settings. The installer simply 
; prompts the user asking them where to install, and drops a copy of example1.nsi
; there. 

;--------------------------------

; The name of the installer
Name "Instalador LS-40"

; The file to write
OutFile "ls40-setup.exe"

; The default installation directory
InstallDir $PROGRAMFILES\CIS\ScannerLS40

; Request application privileges for Windows Vista
RequestExecutionLevel user

;--------------------------------

; Pages

Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "" ;No components page, name is not important

  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  CreateDirectory "$INSTDIR\Config"
  CreateDirectory "$INSTDIR\Images"
  CreateDirectory "$INSTDIR\LS40Files"
  CreateDirectory "$INSTDIR\Support"
  CreateDirectory "$INSTDIR\Traces"
  
  File "program files\CIS\ScannerLS40\ServiceScannerLS40.exe"
  
  SetOutPath "$INSTDIR\Config"
  
  File "program files\CIS\ScannerLS40\Config\ScannerConfig.ini"
  
  SetOutPath "$INSTDIR\LS40Files"
  
  File "program files\CIS\ScannerLS40\LS40Files\Driver_installer.exe"
  
  SetOutPath "$INSTDIR\Support"
  
  File "program files\CIS\ScannerLS40\Support\instdrv.exe"
  
  SetOutPath "$INSTDIR\Traces"
  
  File "program files\CIS\ScannerLS40\Traces\blank.txt"
  
  SetOutPath "$INSTDIR\Images"
  
  File "program files\CIS\ScannerLS40\Images\blank.txt"
  
  SetOutPath "$WINDIR\System32"
  
  File "System32\BarDecode.dll"  
  File "System32\LsApi.dll"
  File "System32\MSVCRT.DLL" 
  File "System32\ltdlg13n.dll"  
  File "System32\msvcm90.dll"
  File "System32\CtsDecod.dll"
  File "System32\LsApi.ini"
  File "System32\img_util.dll"
  File "System32\ltefx13n.dll"
  File "System32\msvcp80.dll"
  File "System32\HSTAPI_DLL.dll"
  File "System32\LsApiClass.dll"
  File "System32\lfbmp13n.dll"
  File "System32\ltfil13n.DLL"
  File "System32\msvcp90.dll"
  File "System32\LFCMP13n.DLL" 
  File "System32\LsFamily.cfg"
  File "System32\lffax13n.dll"
  File "System32\ltimg13n.dll"
  File "System32\msvcr80.dll"
  File "System32\LTDIS13n.dll"
  File "System32\MICRDecodelib.dll"
  File "System32\lftif13n.dll"
  File "System32\ltkrn13n.dll"
  File "System32\msvcr90.dll"
  
  SetOutPath "$WINDIR"
  
  File "WinRoot\enablelog"
  
  SetOutPath "$INSTDIR"
    
  ExecWait "sc create Scanner binPath= $\"$INSTDIR\ServiceScannerLS40.exe$\"  start= auto"
  ExecWait "sc description Scanner $\"Scanner LS40$\""
  
 
SectionEnd ; end the section


;Section "Uninstall"

;  ExecWait "sc delete Scanner"
  
;  Delete "$INSTDIR\ServiceScannerLS40.exe"
;  Delete "$INSTDIR\Config\ScannerConfig.ini"
;  Delete "$INSTDIR\LS40Files\Driver_installer.exe"
;  Delete "$INSTDIR\Support\instdrv.exe"
  
  
;SectionEnd
