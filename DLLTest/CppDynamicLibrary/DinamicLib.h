/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DinamicLib.h
 * Author: luisb
 *
 * Created on 27 de Abril de 2022, 17:41
 */

#ifndef DINAMICLIB_H
#define DINAMICLIB_H


#ifdef WINDOWS
  #include <windows.h>
  #define CIS_PINPADAPI __declspec(dllexport)
#else
  #define CIS_PINPADAPI
#endif




#ifdef __cplusplus
extern "C"
{
#endif

    
int CIS_PINPADAPI ShowInfo( void);
int CIS_PINPADAPI TestSSL( void);
    
    
#ifdef __cplusplus
}
#endif
    

#endif /* DINAMICLIB_H */

