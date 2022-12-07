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

const char *m_pcszLibrary ="P32PinCx.dll";
HMODULE m_pLibraryHandle;

typedef int( __stdcall *PAbrePIN)( void);
typedef int( __stdcall *PFechaPIN)( void);
typedef int( __stdcall *PLeBufferPIN)( char* Buffer, int* Tamanho, int* Controle);

PAbrePIN          m_AbrePIN;
PFechaPIN         m_FechaPIN;
PLeBufferPIN      m_LeBufferPIN;

int LoadLib( void)
{
  m_pLibraryHandle = LoadLibrary( ( char*)m_pcszLibrary);
  if( m_pLibraryHandle == NULL) {
    return 1;
  }
  
  m_AbrePIN = (PAbrePIN)GetProcAddress( m_pLibraryHandle, "AbrePIN");
  if( m_AbrePIN == NULL)   return 2;
  m_FechaPIN = (PFechaPIN)GetProcAddress( m_pLibraryHandle, "FechaPIN");
  if( m_FechaPIN == NULL)  return 3;
  m_LeBufferPIN = (PLeBufferPIN)GetProcAddress( m_pLibraryHandle, "LeBufferPIN");
  if( m_LeBufferPIN == NULL)   return 4;
  
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
  
  API_Ret = m_AbrePIN();    
  printf("[%s][%04d]AbrePIN:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  
  char Buffer[100] = {0};
  int Tamanho = 4;
  int Controle = -1;
  API_Ret = m_LeBufferPIN( Buffer, &Tamanho, &Controle);
  printf("[%s][%04d]LeBufferPIN:[%d]\n", __FUNCTION__, __LINE__, API_Ret);
  printf("[%s][%04d]Tamanho:[%d]\n", __FUNCTION__, __LINE__, Tamanho);
  printf("[%s][%04d]Controle:[%d]\n", __FUNCTION__, __LINE__, Controle);
  printf("[%s][%04d]Buffer:[%s]\n", __FUNCTION__, __LINE__, Buffer);
  
  
  API_Ret = m_FechaPIN();
  UnloadLib();
  return 0;
}
