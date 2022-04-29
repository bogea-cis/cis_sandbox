/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include <stdio.h>

#include "DinamicLib.h"

#include <openssl/des.h>
#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/err.h>


void dump( unsigned char *buffer, int length);
void ConvAsciiToHex( char *pszStr, int lengthStr, unsigned char *pbHex);
void ConvHexToAscii( unsigned char *pbHex, int lengthHex, char *pszStr);


int CIS_PINPADAPI ShowInfo( void)
{
  printf( "****************************************\n");
  printf( "* %s %s \n", __FILE__, __DATE__ );
  printf( "****************************************\n");
  return 0;
}

int CIS_PINPADAPI TestSSL( void)
{
  char TDESKey[] = "11111111111111111111111111111111";
  char WorkingKey[] = "2222222222222222";
  char AESKey[] = "1111111111111111111111111111111111111111111111111111111111111111";

  unsigned char aesKeyHex[32];
  unsigned char aesDecrypted[32];
  unsigned char aesEncrypted[32];

  /* Triple DES key for Encryption and Decryption */
  DES_cblock Key1;
  DES_cblock Key2;
  DES_cblock Key3;
  DES_key_schedule SchKey1,SchKey2,SchKey3;

  ConvAsciiToHex( TDESKey, 16, Key1);
  ConvAsciiToHex( &TDESKey[16], 16, Key2);
  ConvAsciiToHex( TDESKey, 16, Key3);

  /* Input data to encrypt */
  DES_cblock input_data;

  ConvAsciiToHex( WorkingKey, 16, input_data);

  DES_set_key_unchecked( &Key1, &SchKey1);
  DES_set_key_unchecked( &Key2, &SchKey2);
  DES_set_key_unchecked( &Key3, &SchKey3);

  /* Buffers for Encryption and Decryption */
  DES_cblock cipher;
  DES_cblock text;

  /* Triple-DES ECB Encryption */
  DES_ecb3_encrypt( &input_data, &cipher, &SchKey1, &SchKey2, &SchKey3, DES_ENCRYPT);

  dump( (unsigned char*)cipher, 32);

  /* Triple-DES ECB Decryption */
  DES_ecb3_encrypt( &cipher, &text, &SchKey1, &SchKey2, &SchKey3, DES_DECRYPT);

  dump( (unsigned char*)text, 32);

  AES_KEY aesKey;

  ConvAsciiToHex( AESKey, 64, aesKeyHex);

  AES_set_encrypt_key( aesKeyHex, 256, &aesKey);

  ConvAsciiToHex( WorkingKey, 16, aesDecrypted);
  AES_ecb_encrypt( aesDecrypted, aesEncrypted, &aesKey, AES_ENCRYPT);

  BIGNUM *bnMod, *bnExp;
  RSA *rsaInfo = RSA_new();

  BN_hex2bn( &bnMod, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"); //  Carrega o modulo da chave na rsa struct
  BN_hex2bn( &bnExp, "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"); //  Carrega o expoente da chave na rsa struct

  RSA_set0_key(rsaInfo, bnMod, bnExp, NULL);                                    //  Salva chave publica RSA para cifrar 
  int rsaLength = RSA_size( rsaInfo);                                           //  Pega o tamanho da chave
  unsigned char rsaResult[rsaLength];                                           //  Aloca tamanho
  return 0;
}


/**__________________
 * @brief	Convert ASCII stringz into HEX byte array
 * @param	pszStr
 * @param	lengthStr
 * @param	pbHex
 */
void ConvAsciiToHex( char *pszStr, int lengthStr, unsigned char *pbHex)
{
	int i;
	char c;

	for ( i = 0; i < lengthStr; i++) {
		c = pszStr[i];

		if( c >= 97 && c <= 122) { 				// [a(97) - z(122)]
			c = ( c - ( 'a' - 'A'));
		}
		if( ( c >= '0' && c <= '9') || ( c >= 'A' && c <= 'F')) {
			if( c <= '9') {
				c -= '0';
			} else {
				c -= ( 'A' - 10);
			}
			if( ( i & 1) == 0) {
				pbHex[i / 2] = ( c << 4);
			} else {
				pbHex[i / 2] += c;
			}
		} else {
			break;
		}
	}
}


/**_________________
 * @brief	Convert HEX byte array into ASCII stringz
 * @param	pbHex
 * @param	lengthHex
 * @param	pszStr
 */
void ConvHexToAscii( unsigned char *pbHex, int lengthHex, char *pszStr)
{
    int  i;
    char c;

    for( i = 0; i < lengthHex*2; i++) {
        if( ( i & 1) == 0) {
            c = ( ( pbHex[i / 2]) >> 4);
        } else {
            c = ( ( pbHex[i / 2]) & 15);
        }
        if( c < 10) {
        	pszStr[i] = '0' + c;
        } else {
        	pszStr[i] = 'A' - 10 + c;
        }
    }
    pszStr[lengthHex*2] = '\0';
}


/**__________________________________________
 * @brief	Dump buffer
 */
void dump( unsigned char *buffer, int length)
{
  int offset = 0, i, j = 0;

  printf( "\r\n");
  while( length) {
    printf("%05d - %04x - ",offset, offset);
    offset += 16;
    if( length >= 16) {
      length -= 16;
      for( i = 0; i < 16; i++) {
        printf( "%02X ", buffer[i+j]);
      }
      printf( "\t");
      for( i = 0; i < 16; i++) {
        if( buffer[i+j] >= 0x20) {
          printf( "%c ", buffer[i+j]);
        } else {
          printf( ". ");
        }
      }
      j += 16;
      printf( "\r\n");
    } else {
      for( i = 0; i < length; i++) {
        printf( "%02X ", buffer[i+j]);
      }
      printf( "\t");
      for( i = 0; i < length; i++, length--) {
        if( buffer[i+j] >= 0x20) {
          printf( "%c ", buffer[i+j]);
        } else {
          printf( ". ");
        }
      }
    }
  }
  printf( "\r\n");
}
