#include "KD.h"

/*
******************************************************
KnownDll Tab
list of Known Dlls
******************************************************
*/

int KD (  vector<tstring> *result,
             vector<tstring> *descript,
             vector<tstring> *publisher,
             vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "system\\currentcontrolset"
                                  "\\control\\session manager"
                                  "\\knowndlls",
                                  0,
                                  KEY_READ|KEY_WOW64_64KEY, &hKey);
     
     if ( lResult )
         {
          // Check premission Level
          // report the error 
          
          // Not Found Error FILE_NOT_FOUND(2),PATH_NOT_FOUND(3)
          if ( lResult != 5 )                                      
                    return 0;
          // Premission denied Error (5) ---- add read premission
          return 0;
          // Else ? Move on, man!
                                       }

     // Enumerate through the whole subkey
     DWORD i = 0;
     DWORD maxKey = 255;
     LPTSTR keyName = (LPTSTR)malloc(255);
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     while ( true )
     {
           keyName[0] = '\0';
           maxKey = 255;
           if ( RegEnumValue( hKey, i, keyName, &maxKey, NULL, NULL, NULL, NULL))
              break;
           // Push back key
           tstring str = keyName;
           result->push_back(str);
           
           RegQueryValueEx( hKey, str.c_str(), NULL, &type, (LPBYTE)value, &valueSiz);
           str = value;
           path->push_back( str );
           
           // TODO: find discription and publisher
           descript->push_back("");
           publisher->push_back("");
           
           i++;
           }
     
     free(value);
     free(keyName);
     RegCloseKey(hKey);
     return 1;
     }
