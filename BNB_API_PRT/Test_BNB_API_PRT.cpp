#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <winerror.h>
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

const char *m_pcszLibrary ="P32PRTCX.DLL";
HMODULE m_pLibraryHandle;

typedef int( __stdcall *PWinIniciaPrtCx)( void);
typedef int( __stdcall *PWinStatusPrtCx)( char* buff);
typedef int( __stdcall *PWinImprimePrtCx)( int media, int logo, char* buff, int tam);
typedef int( __stdcall *PWinCancelPrtCx)( void);

PWinIniciaPrtCx           m_WinIniciaPrtCx;
PWinStatusPrtCx           m_WinStatusPrtCx;
PWinImprimePrtCx          m_WinImprimePrtCx;
PWinCancelPrtCx           m_WinCancelPrtCx;

int LoadLib( void)
{
  m_pLibraryHandle = LoadLibrary( ( char*)m_pcszLibrary);
  if( m_pLibraryHandle == NULL) {
    return 1;
  }
  
  m_WinIniciaPrtCx = (PWinIniciaPrtCx)GetProcAddress( m_pLibraryHandle, "WinIniciaPrtCx");
  if( m_WinIniciaPrtCx == NULL)   return 2;
  m_WinStatusPrtCx = (PWinStatusPrtCx)GetProcAddress( m_pLibraryHandle, "WinStatusPrtCx");
  if( m_WinStatusPrtCx == NULL)  return 3;
  m_WinImprimePrtCx = (PWinImprimePrtCx)GetProcAddress( m_pLibraryHandle, "WinImprimePrtCx");
  if( m_WinImprimePrtCx == NULL)   return 4;
  m_WinCancelPrtCx = (PWinCancelPrtCx)GetProcAddress( m_pLibraryHandle, "WinCancelPrtCx");
  if( m_WinCancelPrtCx == NULL)   return 5;
  
  return 0;
}

int UnloadLib( void)
{
  return FreeLibrary( m_pLibraryHandle);
}


int main( int argc, char *argv[])
{
  int API_Ret;
  
  int r = LoadLib();
  printf( "[%s][%04d]LoadLib [%d]\n", __FUNCTION__, __LINE__, r);
  if( r != 0) return r;
  
  API_Ret = m_WinIniciaPrtCx();    
  printf("[%s][%04d]m_WinIniciaPrtCx:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  char buff[] = {
  "0         1         2         3         4 \n"
  "012345678901234567890123456789012345678901234567\n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "|         | \n"
  "\n\n\n\n"
  "\x1d" "V" "1"
  };
  int media = 0;
  int logo = 0;
  int tam = strlen( buff);
  API_Ret = m_WinImprimePrtCx( media, logo, buff, tam);
  printf("[%s][%04d]m_WinImprimePrtCx:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  char valida[] = {
  "0123456789012345678901234567890123456789012345678\n"
  };
  media = 1;
  logo = 0;
  tam = strlen( valida);
  API_Ret = m_WinImprimePrtCx( media, logo, valida, tam);
  printf("[%s][%04d]m_WinImprimePrtCx:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  
  API_Ret = m_WinCancelPrtCx();
  UnloadLib();
  return 0;
}
