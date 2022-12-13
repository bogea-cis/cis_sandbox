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

const char *m_pcszLibrary ="P32CM7CX.DLL";
HMODULE m_pLibraryHandle;

typedef int( __stdcall *PWinStartLeAssincronoCm7Cx)( int TimeLe, int TamBuff);
typedef int( __stdcall *PWinLeAssincronoCm7Cx)( int* TamBuff, char* lpAppBuff);

PWinStartLeAssincronoCm7Cx     m_WinStartLeAssincronoCm7Cx;
PWinLeAssincronoCm7Cx          m_WinLeAssincronoCm7Cx;

int LoadLib( void)
{
  m_pLibraryHandle = LoadLibrary( ( char*)m_pcszLibrary);
  if( m_pLibraryHandle == NULL) {
    return 1;
  }
  
  m_WinStartLeAssincronoCm7Cx = (PWinStartLeAssincronoCm7Cx)GetProcAddress( m_pLibraryHandle, "WinStartLeAssincronoCm7Cx");
  if( m_WinStartLeAssincronoCm7Cx == NULL)   return 2;
  m_WinLeAssincronoCm7Cx = (PWinLeAssincronoCm7Cx)GetProcAddress( m_pLibraryHandle, "WinLeAssincronoCm7Cx");
  if( m_WinLeAssincronoCm7Cx == NULL)  return 3;
  
  return 0;
}

int UnloadLib( void)
{
  return FreeLibrary( m_pLibraryHandle);
}


int main( int argc, char *argv[])
{
  int API_Ret;
  
  int ret = LoadLib();
  printf( "[%s][%04d]LoadLib [%d]\n", __FUNCTION__, __LINE__, ret);
  if( ret != 0) return ret;
  
  API_Ret = m_WinStartLeAssincronoCm7Cx( 60, 50);    
  printf("[%s][%04d]m_WinStartLeAssincronoCm7Cx:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  char Buffer[100] = {0};
  int Tamanho = 50;
  do {
  
    API_Ret = m_WinLeAssincronoCm7Cx( &Tamanho, Buffer);
    Sleep(100);
  } while( API_Ret == 01);
    
  printf("[%s][%04d]m_WinLeAssincronoCm7Cx:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  printf("[%s][%04d]Tamanho:[%d]\n", __FUNCTION__, __LINE__, Tamanho);
  printf("[%s][%04d]Buffer:[%s]\n", __FUNCTION__, __LINE__, Buffer);
  
  
  UnloadLib();
  printf( "Press any key to exit\n");
  getch();
  return 0;
}
