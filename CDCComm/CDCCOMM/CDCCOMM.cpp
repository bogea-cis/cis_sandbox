// CDCCOMM.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <setupapi.h>	
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <rpc.h>
#include <initguid.h>
#include <winusb.h>
#include <winioctl.h>
#include <shlwapi.h>
#include <wchar.h>
#include <initguid.h>

#include "CDCCOMM.h"

HANDLE hDevice = NULL;
HDEVINFO hDevInfo = INVALID_HANDLE_VALUE;
SP_DEVICE_INTERFACE_DATA InterfaceDataStructure = { 0 };
PSP_DEVICE_INTERFACE_DETAIL_DATA InterfaceDetailStructure = { 0 };
SP_DEVINFO_DATA DevInfoData = { 0 };
WCHAR devicePath[512] = { 0 };
BOOL connected = false;


GUID guid = { 0xa5dcbf10, 0x6530, 0x11D2, { 0x90, 0x1f, 0x00, 0xc0, 0x4f, 0xb9, 0x51, 0xed } }; //GUID - Globally Unique Identifier - regedit para todas portas CDC

int m_vendorId = 0xfff0;
int m_productId = 0x0100;


/*========================================================================================
     Fnc: CISCDC_API CISCDC_RET CISCDC_Open( void)
  ===========================================*/ /**
  @brief
  @details
  @param none
  @return none
  @author L.Bogea
  @warning
  */
CISCDC_API CISCDC_RET CISCDC_Open( void)
{
  CISCDC_RET response = CISCDC_OK;

  int iVid;
  int iPid;

  hDevInfo = SetupDiGetClassDevsA(&guid, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
  if (hDevInfo == 0) {
    response = CISCDC_OPEN_ERROR;
    return response;
  }

  InterfaceDataStructure.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
  DWORD memberIndex = 0;
  BOOL success = false;

  do {
    success = SetupDiEnumDeviceInterfaces(hDevInfo, NULL, &guid, memberIndex, &InterfaceDataStructure);
    if (success) {
      DWORD cbRequired = 0;
      SetupDiGetDeviceInterfaceDetail(hDevInfo, &InterfaceDataStructure, 0, 0, &cbRequired, 0);
      if (ERROR_INSUFFICIENT_BUFFER == GetLastError()) {
        PSP_DEVICE_INTERFACE_DETAIL_DATA pdidd = (PSP_DEVICE_INTERFACE_DETAIL_DATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cbRequired);
        if (pdidd) {
          pdidd->cbSize = sizeof(*pdidd);
          if (SetupDiGetDeviceInterfaceDetail(hDevInfo, &InterfaceDataStructure, pdidd, cbRequired, &cbRequired, 0)) {
            //          printf( "memberIndex[%d] DevicePath=%s\n", memberIndex, pdidd->DevicePath);
            wprintf(L" DevicePath=%s\n", pdidd->DevicePath);
            wcsncpy_s(devicePath, pdidd->DevicePath, 511);

            HeapFree(GetProcessHeap(), 0, pdidd);
          }
          else {
            HeapFree(GetProcessHeap(), 0, pdidd);
            success = false;
          }
        }
      }
      memberIndex++;
      WCHAR *ptrs;
      WCHAR vid[10] = { 0 };
      WCHAR pid[10] = { 0 };
      ptrs = wcsstr(devicePath, L"vid");
      wcsncpy_s(vid, ptrs, 8);

      ptrs = wcsstr(devicePath, L"pid");
      wcsncpy_s(pid, ptrs, 8);

      wprintf(L"%s %s\n", vid, pid);
      swscanf_s(&vid[4], L"%x", &iVid);
      swscanf_s(&pid[4], L"%x", &iPid);
    }
    else {
      success = false;
      break;
    }
  } while ( m_vendorId != iVid || m_productId != iPid);

  SetupDiDestroyDeviceInfoList(hDevInfo);

  if (success == false) {
    response = CISCDC_OPEN_ERROR;
    return response;
  }

  hDevice = CreateFile(devicePath, GENERIC_READ | GENERIC_WRITE,
                        FILE_READ_DATA | FILE_WRITE_DATA,
                        NULL,
                        OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL);
  if (hDevice == INVALID_HANDLE_VALUE) {
    response = CISCDC_OPEN_ERROR;
    return response;
  }
  connected = true;
  return response;
}

/*========================================================================================
     Fnc: CISCDC_API CISCDC_RET CISCDC_Close( void)
  ===========================================*/ /**
  @brief
  @details
  @param none
  @return none
  @author L.Bogea
  @warning
  */
CISCDC_API CISCDC_RET CISCDC_Close( void)
{
  CISCDC_RET response = CISCDC_OK;
  if (hDevice != NULL && hDevice != INVALID_HANDLE_VALUE) {
    CloseHandle(hDevice);
  }
  connected = false;
  return response;
}

/*========================================================================================
     Fnc: CISCDC_API CISCDC_RET CISCDC_Read( unsigned char* buffer, DWORD numberOfBytes)
  ===========================================*/ /**
  @brief    
  @details  
  @param    buffer
  @param    numberOfBytes
  @return   CISCDC_RET
  @author   L.Bogea
  @warning  
  */
CISCDC_API CISCDC_RET CISCDC_Read( unsigned char* buffer, DWORD numberOfBytes)
{
  CISCDC_RET response = CISCDC_OK;
  DWORD numberOfBytesRead;

  if (connected) {
    ReadFile( hDevice, buffer, numberOfBytes, &numberOfBytesRead, NULL);
  }
  return response;
}

/*========================================================================================
     Fnc: CISCDC_API CISCDC_RET CISCDC_Write( unsigned char* buffer, int length)
  ===========================================*/ /**
  @brief
  @details
  @param none
  @return none
  @author L.Bogea
  @warning
  */
CISCDC_API CISCDC_RET CISCDC_Write( unsigned char* buffer, int length)
{
  CISCDC_RET response = CISCDC_OK;
  DWORD size = 0;
  if (connected) {
    WriteFile(hDevice, buffer, length, &size, NULL);
  }
  return response;
}

