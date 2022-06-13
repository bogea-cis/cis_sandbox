// XMLTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XMLFile.h"

#define _XMLFILE_ L"xmlfile.xml"
typedef struct _KEY_t {
  char name[256];
  int index;
  int type;
  unsigned char value[64 + 1];
  int usage;
  unsigned char ksn[32 + 1];
  unsigned char kcv[10];
} KEY_t;

int _tmain(int argc, _TCHAR* argv[])
{
  CXMLFile xmlFile;
  CXMLElement* elem;
  CXMLElement* xml;
  CXMLElement* root;
  CXMLElement* key;
  CXMLElement* data;
  
  KEY_t stkey;

  if (!xmlFile.LoadFromFile(_XMLFILE_)) {
    wprintf( L"file %s not found\n", _XMLFILE_);
    return -1;
  }
  wprintf( L"file %s loaded\n", _XMLFILE_);

  elem = xmlFile.GetRoot();

  wprintf( L"elem name: %s\n",elem->GetElementName());

  xml = elem->GetFirstChild();

  wprintf(L"xml name: %s\n", xml->GetElementName());
  wprintf(L"xml value: %s\n", xml->GetValue());

  root = elem->GetNextChild();

  wprintf(L"root name: %s\n", root->GetElementName());

  key = root->GetFirstChild();

  wprintf(L"key name: %s\n", key->GetElementName());
  wprintf(L"key value: %d\n", key->GetValue());
  wprintf(L"key number: %d\n", key->GetChildNumber());
  wprintf(L"key type: %d\n", key->GetElementType());

  int len = key->GetChildNumber();
  data = key->GetFirstChild();
  for (int i = 0; i < len; i++) {
    if (data->GetElementType() == XET_TAG) {
      wprintf(L"TAG name %s type: %d\n", data->GetElementName(), data->GetElementType());
      data = data->GetFirstChild();
    }
    if (data->GetElementType() == XET_ATTRIBUTE) {
      wprintf(L"attribute %s type: %d\n", data->GetElementName(), data->GetElementType());
      wprintf(L"value: %s\n", data->GetValue());
      stkey.index = atoi( ( char*)data->GetValue());
      printf("stkey.index: %d\n", stkey.index);
    }
    if (data->GetElementType() == XET_TEXT) {
      wprintf(L"text: %s type: %d\n", data->GetElementName(), data->GetElementType());
    }
    data = key->GetNextChild();
  }

  return 0;
}

