#ifndef CDCCOMM_H
#define CDCCOMM_H

#ifdef CDCCOMM_EXPORTS
#define CISCDC_API __declspec(dllexport)
#else
#define CISCDC_API __declspec(dllimport)
#endif

typedef enum cisReply {
  CISCDC_OK = 0,
  CISCDC_ALREADY_OPEN = 1,

  CISCDC_UNKNOWN_ERROR = -1,
  CISCDC_OPEN_ERROR = -2,
} CISCDC_RET;

#ifdef __cplusplus
extern "C" {
#endif

  CISCDC_API CISCDC_RET CISCDC_Open( void);
  CISCDC_API CISCDC_RET CISCDC_Close( void);
  CISCDC_API CISCDC_RET CISCDC_Read( unsigned char* buffer, DWORD numberOfBytes);
  CISCDC_API CISCDC_RET CISCDC_Write( unsigned char* buffer, int length);

#ifdef __cplusplus
}
#endif

#endif