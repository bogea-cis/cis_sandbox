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

const char *m_pcszLibrary ="P32TCATM.DLL";
HMODULE m_pLibraryHandle;

typedef int( __stdcall *PWinStartLeAssincronoCartaoPassagemXP)( int TimeLe);
typedef int( __stdcall *PWinLeAssincronoCartaoPassagemXP)( int* TamBuff, char* lpAppBuff);

PWinStartLeAssincronoCartaoPassagemXP     m_WinStartLeAssincronoCartaoPassagemXP;
PWinLeAssincronoCartaoPassagemXP          m_WinLeAssincronoCartaoPassagemXP;

int LoadLib( void)
{
  m_pLibraryHandle = LoadLibrary( ( char*)m_pcszLibrary);
  if( m_pLibraryHandle == NULL) {
    return 1;
  }
  
  m_WinStartLeAssincronoCartaoPassagemXP = (PWinStartLeAssincronoCartaoPassagemXP)GetProcAddress( m_pLibraryHandle, "WinStartLeAssincronoCartaoPassagemXP");
  if( m_WinStartLeAssincronoCartaoPassagemXP == NULL)   return 2;
  m_WinLeAssincronoCartaoPassagemXP = (PWinLeAssincronoCartaoPassagemXP)GetProcAddress( m_pLibraryHandle, "WinLeAssincronoCartaoPassagemXP");
  if( m_WinLeAssincronoCartaoPassagemXP == NULL)  return 3;
  
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
  
  API_Ret = m_WinStartLeAssincronoCartaoPassagemXP( 60);    
  printf("[%s][%04d]m_WinStartLeAssincronoCartaoPassagemXP:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  char Buffer[1024] = {0};
  int Tamanho = 1024;
  do {
  
    API_Ret = m_WinLeAssincronoCartaoPassagemXP( &Tamanho, Buffer);
    Sleep(100);
  } while( API_Ret == 01);
    
  printf("[%s][%04d]m_WinLeAssincronoCartaoPassagemXP:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  printf("[%s][%04d]Tamanho:[%d]\n", __FUNCTION__, __LINE__, Tamanho);
  printf("[%s][%04d]Buffer:[%s]\n", __FUNCTION__, __LINE__, Buffer);
  
  
  UnloadLib();
  printf( "Press any key to exit\n");
  getch();
  return 0;
}
