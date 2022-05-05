// CDCCOMM_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>

#include "CDCCOMM.h"

int _tmain(int argc, _TCHAR* argv[])
{
  if (CISCDC_Open() == CISCDC_OK)
  {
    printf("Open Ok!\n");
  }
  else
  {
    printf("Open Error!\n");
  }
	return 0;
}

