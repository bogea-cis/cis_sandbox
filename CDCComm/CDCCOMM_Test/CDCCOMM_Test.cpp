// CDCCOMM_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <conio.h>

#include "CDCCOMM.h"

typedef union{
  unsigned short crc;
  unsigned char ccrc[2];
}CRC;

unsigned char buffer[512] = { 0 };

//___________________prototypes___________________
void dump(unsigned char *buffer, int length);
unsigned short CRC_Calc(const unsigned char *pbData, int iLength);
int send(unsigned char* data, int length);
int receive(unsigned char* data, int timeout);
void communic(char* data);

//___________________main___________________
int _tmain(int argc, _TCHAR* argv[])
{
  if (CISCDC_Open() == CISCDC_OK)
  {
    printf("Open Ok!\n");
    communic("GDI000");
  }
  else
  {
    printf("Open Error!\n");
  }
  printf(" Press any key to exit!\n");
  _getch();
	return 0;
}


void communic( char* data)
{
  send((unsigned char*)data, strlen(data));
  Sleep(100);
  receive(buffer, 1000);
  dump(buffer, 256);
}

int send(unsigned char* data, int length)
{
  int iRet = -1;
  CRC ucrc;
  std::string cmd;

  cmd.append("0");
  cmd.append((char*)data);
  cmd.append(1, 0x03);
  ucrc.crc = CRC_Calc((unsigned char*)cmd.c_str(), cmd.length());
  cmd.append(1, (char)ucrc.ccrc[1]);
  cmd.append(1, (char)ucrc.ccrc[0]);
  cmd.insert(0, 1, 0x02);

  CISCDC_Write((unsigned char*)cmd.c_str(), cmd.length());
  return iRet;
}

int receive(unsigned char* data, int timeout)
{
  int iRet = -1;
  std::string cmd;


  CISCDC_Read(buffer, 256);
  return iRet;
}

unsigned short CRC_Calc(const unsigned char *pbData, int iLength)
{
  unsigned short wData, wCRC = 0;
  int i;
  for (; iLength > 0; iLength--, pbData++)
  {
    wData = (unsigned short)(((unsigned short)*pbData) << 8);
    for (i = 0; i < 8; i++, wData <<= 1)
    {
      if ((wCRC ^ wData) & 0x8000)
        wCRC = (unsigned short)((wCRC << 1) ^ 0x1021);
      else
        wCRC <<= 1;
    }
  }
  return wCRC;
}


void dump(unsigned char *buffer, int length)
{
  int offset = 0, i, j = 0;

  printf("\r\n");
  while (length) {
    printf("%05d - %04x - ", offset, offset);
    offset += 16;
    if (length >= 16) {
      length -= 16;
      for (i = 0; i < 16; i++) {
        printf("%02X ", buffer[i + j]);
      }
      printf("\t");
      for (i = 0; i < 16; i++) {
        if (buffer[i + j] >= 0x20) {
          printf("%c ", buffer[i + j]);
        }
        else {
          printf(". ");
        }
      }
      j += 16;
      printf("\r\n");
    }
    else {
      for (i = 0; i < length; i++) {
        printf("%02X ", buffer[i + j]);
      }
      printf("\t");
      for (i = 0; i < length; i++, length--) {
        if (buffer[i + j] >= 0x20) {
          printf("%c ", buffer[i + j]);
        }
        else {
          printf(". ");
        }
      }
    }
  }
  printf("\r\n");
}
