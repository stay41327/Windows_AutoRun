#include "Logon.h"

/*
******************************************************
Logon Tab
Common registry key
******************************************************
*/

int Logon_startupprograms (vector<tstring> *result,
                              vector<tstring> *descript,
                              vector<tstring> *publisher,
                              vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "system\\currentcontrolset"
                                  "\\control\\terminal server"
                                  "\\wds\\rdpwd",
                                  0,
                                  KEY_READ | KEY_WOW64_64KEY, &hKey);
     
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
     
     // Get startupprogram value
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     lResult = RegQueryValueEx( hKey, "StartupPrograms",
                                NULL, &type,
                                (LPBYTE)value, &valueSiz);
     tstring str = value;
     int ic = 0;
     while ( str.find(",", ic, valueSiz) != string::npos )
        {
         result->push_back(str.substr(ic,str.find(",", ic, valueSiz)));
         
         // TODO: search for more info in 
         // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
         descript->push_back("");
         publisher->push_back("");
         path->push_back("");                                    
         ic = str.find(",", ic, valueSiz) + 1;
         }
     result->push_back(str.substr(ic,valueSiz));
     
     // TODO: search for more info in 
     // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
     descript->push_back("");
     publisher->push_back("");
     path->push_back(""); 
     
     RegCloseKey(hKey);
     free(value);
     return 1;
     }

int Logon_userinit ( vector<tstring> *result,
                        vector<tstring> *descript,
                        vector<tstring> *publisher,
                        vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\microsoft"
                                  "\\windows nt\\currentversion"
                                  "\\winlogon",
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
     
     // Get userinit value
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     lResult = RegQueryValueEx( hKey, "Userinit",
                                NULL, &type,
                                (LPBYTE)value, &valueSiz);
     tstring str = value;
     int ic = 0;
     while ( str.find(",", ic, valueSiz) != string::npos )
        {
         result->push_back(str.substr(ic,str.find(",", ic, valueSiz)));
          
         // TODO: search for more info in 
         // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
         descript->push_back("");
         publisher->push_back("");
         path->push_back(str.substr(ic,str.find(",", ic, valueSiz)));
         ic = str.find(",", ic, valueSiz) + 1;
         }
     result->push_back(str.substr(ic,valueSiz));
      
     // TODO: search for more info in 
     // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
     descript->push_back("");
     publisher->push_back("");
     path->push_back(str.substr(ic,str.find(",", ic, valueSiz)));
     
     RegCloseKey(hKey);
     free(value);
     return 1;
     }

int Logon_shell ( vector<tstring> *result,
                     vector<tstring> *descript,
                     vector<tstring> *publisher,
                     vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\microsoft"
                                  "\\windows nt\\currentversion"
                                  "\\winlogon",
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
     
     // Get shell value
     DWORD valueSiz = 1024;
     DWORD type = REG_SZ;
     LPTSTR value = (LPTSTR)malloc(1024);
     lResult = RegQueryValueEx( hKey, "shell",
                                NULL, &type,
                                (LPBYTE)value, &valueSiz);
     tstring str = value;
     int ic = 0;
     while ( str.find(",", ic, valueSiz) != string::npos )
        {
         result->push_back(str.substr(ic,str.find(",", ic, valueSiz)));
          
         // TODO: search for more info in 
         // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
         descript->push_back("");
         publisher->push_back("");
         path->push_back("");
         ic = str.find(",", ic, valueSiz) + 1;
         }
     result->push_back(str.substr(ic,valueSiz));
     
     // TODO: search for more info in 
     // HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\Terminal Server\SysProcs.
     descript->push_back("");
     publisher->push_back("");
     path->push_back("");
     
     free(value);
     RegCloseKey(hKey);
     return 1;
     }

int Logon_run ( vector<tstring> *result,
                   vector<tstring> *descript,
                   vector<tstring> *publisher,
                   vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\run",
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
     
int Logon_runonce ( vector<tstring> *result,
                       vector<tstring> *descript,
                       vector<tstring> *publisher,
                       vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\runonce",
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

int Logon_wow_run ( vector<tstring> *result,
                       vector<tstring> *descript,
                       vector<tstring> *publisher,
                       vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\wow6432node"
                                  "\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\run",
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
  
int Logon_wow_runonce ( vector<tstring> *result,
                           vector<tstring> *descript,
                           vector<tstring> *publisher,
                           vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "software\\wow6432node"
                                  "\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\runonce",
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

int Logon_CU_run ( vector<tstring> *result,
                      vector<tstring> *descript,
                      vector<tstring> *publisher,
                      vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_CURRENT_USER,
                                  "software\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\run",
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

int Logon_CU_runonce ( vector<tstring> *result,
                          vector<tstring> *descript,
                          vector<tstring> *publisher,
                          vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_CURRENT_USER,
                                  "software\\microsoft"
                                  "\\windows\\currentversion"
                                  "\\runonce",
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
