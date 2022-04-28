/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luisb
 *
 * Created on 28 de Abril de 2022, 08:53
 */

#include <iostream>

#include <Windows.h>
#include <conio.h>
#include <winerror.h>
#include <cstdlib>
#include <errno.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/time.h>

HMODULE m_pLibraryHandle;

typedef int( __stdcall *pShowInfo)( void);
pShowInfo m_ShowInfo;
char m_szLibrary[256];

/*
 * 
 */
int main(int argc, char** argv)
{
  void* p_method;

   if (argc == 2) {
    strcpy( m_szLibrary, argv[1]);
  }
  else {
    printf( "app filename.dll\n");
  }
  
  setlocale( LC_ALL, "");
 
  m_pLibraryHandle = LoadLibrary( ( char*)m_szLibrary);
  if( m_pLibraryHandle == NULL) {
    LPVOID lpMsgBuf;
    DWORD dw = GetLastError(); 

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT),
        ( LPTSTR) &lpMsgBuf,
        0, NULL );
    wprintf( L"Error[%d] " L"%s\n", dw, lpMsgBuf);
    return 0;
  }
  
  char methodName[] = {"ShowInfo"};

  p_method = (void*)GetProcAddress( m_pLibraryHandle, methodName);
  if (p_method == NULL) {
    printf("Erro ao importar metodo %s\n", methodName);
    return 0;
  }
  m_ShowInfo = (pShowInfo) p_method;
  printf( "DLL=[%s] metodo=[%s]\n", m_szLibrary, methodName);
  m_ShowInfo();
  return 0;
}

