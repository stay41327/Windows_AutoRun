#include "IE.h"

/*
******************************************************
IE Tab
IE BHO, Extension, Tool bar
******************************************************
*/

int IE_BHO (  vector<tstring> *result,
                 vector<tstring> *descript,
                 vector<tstring> *publisher,
                 vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\explorer\\browser helper objects",
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
     DWORD maxKey = 1024;
     LPTSTR keyName = (LPTSTR)malloc(1024);
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     vector<tstring> tmp;
     tstring str;
     DWORD maxClsid = 1024;
     LPTSTR Clsid = (LPTSTR)malloc(1024);
     while ( true )
     {
           Clsid[0] = '\0';
           maxClsid = 1024;
           if ( RegEnumKeyEx( hKey, i, Clsid, &maxClsid, NULL, NULL, NULL, NULL))
              break;

           str = Clsid;
           tmp.push_back( str );
           i++;
           }

     for (vector<tstring>::iterator it = tmp.begin(); it != tmp.end(); ++it )
     {
           // Open subKey first. Check it's a Service or Driver?
           HKEY subKey = NULL;
           tstring subkeypath = "clsid\\" + (*it);
           if ( RegOpenKeyEx( HKEY_CLASSES_ROOT, subkeypath.c_str(),
                              0, KEY_READ|KEY_WOW64_64KEY, &subKey ) )
                continue;
           // get KeyName
           if ( RegQueryValueEx( subKey, NULL, NULL, &type, (LPBYTE)keyName, &maxKey) )
                { RegCloseKey(subKey); 
                  maxKey = 1024;
                  keyName[0] = '\0';
                  continue; }
           // get Path
           HKEY ssKey = NULL;
           if ( RegOpenKeyEx( subKey, "InprocServer32",
                              0, KEY_READ|KEY_WOW64_64KEY, &ssKey ) )
                continue;
           if ( RegQueryValueEx( ssKey, NULL, NULL, &type, (LPBYTE)value, &valueSiz) )
                { RegCloseKey(ssKey); 
                  valueSiz = 1024;
                  value[0] = '\0'; }
           
           
           // Push back key and values
           str = value;
           path->push_back(str);
           str = (*it);
           result->push_back( str );
          
           
           // TODO: find publisher & description
           publisher->push_back("");
           descript->push_back( ""); 
           // CleanUp
           maxKey = 1024;
           keyName[0] = '\0';
           valueSiz = 1024;
           value[0] = '\0';
           RegCloseKey(subKey);
           RegCloseKey(ssKey);
           }
     
     free(value);
     free(keyName);
     free(Clsid);
     RegCloseKey(hKey);
     return 1;
     }


int IE_wow_BHO (  vector<tstring> *result,
                     vector<tstring> *descript,
                     vector<tstring> *publisher,
                     vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\wow6432node\\"
                                  "microsoft\\windows\\currentversion"
                                  "\\explorer\\browser helper objects",
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
     DWORD maxKey = 1024;
     LPTSTR keyName = (LPTSTR)malloc(1024);
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     vector<tstring> tmp;
     tstring str;
     DWORD maxClsid = 1024;
     LPTSTR Clsid = (LPTSTR)malloc(1024);
     while ( true )
     {
           Clsid[0] = '\0';
           maxClsid = 1024;
           if ( RegEnumKeyEx( hKey, i, Clsid, &maxClsid, NULL, NULL, NULL, NULL))
              break;

           str = Clsid;
           tmp.push_back( str );
           i++;
           }

     for (vector<tstring>::iterator it = tmp.begin(); it != tmp.end(); ++it )
     {
           // Open subKey first. Check it's a Service or Driver?
           HKEY subKey = NULL;
           tstring subkeypath = "wow6432node\\clsid\\" + (*it);
           if ( RegOpenKeyEx( HKEY_CLASSES_ROOT, subkeypath.c_str(),
                              0, KEY_READ|KEY_WOW64_64KEY, &subKey ) )
                continue;
           // get KeyName
           if ( RegQueryValueEx( subKey, NULL, NULL, &type, (LPBYTE)keyName, &maxKey) )
                { RegCloseKey(subKey); 
                  maxKey = 1024;
                  keyName[0] = '\0';
                  continue; }
           // get Path
           HKEY ssKey = NULL;
           if ( RegOpenKeyEx( subKey, "InprocServer32",
                              0, KEY_READ|KEY_WOW64_64KEY, &ssKey ) )
                continue;
           if ( RegQueryValueEx( ssKey, NULL, NULL, &type, (LPBYTE)value, &valueSiz) )
                { RegCloseKey(ssKey); 
                  valueSiz = 1024;
                  value[0] = '\0'; }
           
           
           // Push back key and values
           str = value;
           path->push_back(str);
           str = (*it);
           result->push_back( str );
          
           
           // TODO: find publisher & description
           publisher->push_back("");
           descript->push_back( ""); 
           // CleanUp
           maxKey = 1024;
           keyName[0] = '\0';
           valueSiz = 1024;
           value[0] = '\0';
           RegCloseKey(subKey);
           RegCloseKey(ssKey);
           }
     
     free(value);
     free(keyName);
     free(Clsid);
     RegCloseKey(hKey);
     return 1;
     }

int IE_SearchHook (  vector<tstring> *result,
                        vector<tstring> *descript,
                        vector<tstring> *publisher,
                        vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_CURRENT_USER,
                                  "software\\microsoft"
                                  "\\internet explorer"
                                  "\\urlsearchhooks",
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
     DWORD maxKey = 1024;
     LPTSTR keyName = (LPTSTR)malloc(1024);
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     vector<tstring> tmp;
     tstring str;
     DWORD maxClsid = 1024;
     LPTSTR Clsid = (LPTSTR)malloc(1024);
     while ( true )
     {
           Clsid[0] = '\0';
           maxClsid = 1024;
           if ( RegEnumValue( hKey, i, Clsid, &maxClsid, NULL, NULL, NULL, NULL))
              break;

           str = Clsid;
           tmp.push_back( str );
           i++;
           }

     for (vector<tstring>::iterator it = tmp.begin(); it != tmp.end(); ++it )
     {
           // Open subKey first. Check it's a Service or Driver?
           HKEY subKey = NULL;
           tstring subkeypath = "software\\classes\\clsid\\" + (*it);
           if ( RegOpenKeyEx( HKEY_LOCAL_MACHINE, subkeypath.c_str(),
                              0, KEY_READ|KEY_WOW64_64KEY, &subKey ) )
                continue;
           // get KeyName
           if ( RegQueryValueEx( subKey, NULL, NULL, &type, (LPBYTE)keyName, &maxKey) )
                { RegCloseKey(subKey); 
                  maxKey = 1024;
                  keyName[0] = '\0';
                  continue; }
           // get Path
           HKEY ssKey = NULL;
           if ( RegOpenKeyEx( subKey, "InprocServer32",
                              0, KEY_READ|KEY_WOW64_64KEY, &ssKey ) )
                continue;
           if ( RegQueryValueEx( ssKey, NULL, NULL, &type, (LPBYTE)value, &valueSiz) )
                { RegCloseKey(ssKey); 
                  valueSiz = 1024;
                  value[0] = '\0'; }
           
           
           // Push back key and values
           str = value;
           path->push_back(str);
           str = (*it);
           result->push_back( str );
          
           
           // TODO: find publisher & description
           publisher->push_back("");
           descript->push_back( ""); 
           // CleanUp
           maxKey = 1024;
           keyName[0] = '\0';
           valueSiz = 1024;
           value[0] = '\0';
           RegCloseKey(subKey);
           RegCloseKey(ssKey);
           }
     
     free(value);
     free(keyName);
     free(Clsid);
     RegCloseKey(hKey);
     return 1;
     }
