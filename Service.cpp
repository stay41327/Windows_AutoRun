#include "Service.h"

/*
******************************************************
Service Tab
autorun services
******************************************************
*/

int Service ( vector<tstring> *result,
                 vector<tstring> *descript,
                 vector<tstring> *publisher,
                 vector<tstring> *path)
{
     HKEY hKey;
     LONG lResult = RegOpenKeyEx( HKEY_LOCAL_MACHINE,
                                  "system\\currentcontrolset"
                                  "\\services",
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
     DWORD dispSiz = 1024;
     LPTSTR disp = (LPTSTR)malloc(1024);
     vector<tstring> tmp;
     tstring str;
     while ( true )
     {
           keyName[0] = '\0';
           maxKey = 1024;
           if ( RegEnumKeyEx( hKey, i, keyName, &maxKey, NULL, NULL, NULL, NULL))
              break;

           str = keyName;
           tmp.push_back( str );
           i++;
           }

     for (vector<tstring>::iterator it = tmp.begin(); it != tmp.end(); ++it )
     {
           // Open subKey first. Check it's a Service or Driver?
           HKEY subKey = NULL;
           if ( RegOpenKeyEx( hKey, (*it).c_str(), 0, KEY_READ|KEY_WOW64_64KEY, &subKey ) )
                continue;
           if ( RegQueryValueEx( subKey, "ImagePath", NULL, &type, (LPBYTE)value, &valueSiz) )
                { RegCloseKey(subKey); 
                  valueSiz = 1024;
                  value[0] = '\0';
                  continue; }
           if ( RegQueryValueEx( subKey, "Description", NULL, &type, (LPBYTE)disp, &dispSiz) )
                { RegCloseKey(subKey); 
                  dispSiz = 1024;
                  disp[0] = '\0'; }
           str = value;
           
           // Convert to lowCase
           #ifdef UNICODE
                  {
                    int idx = 0;
                    char c;
                    while(str[idx])
                    {  c = str[idx];
                       str[idx] = towlower(c);
                       idx++; }
                   }           
           #else
                  {
                    int idx = 0;
                    char c;
                    while(str[idx])
                    {  c = str[idx];
                       str[idx] = tolower(c);
                       idx++; }
                   }
            #endif
           
           // Check if AutoStart
           DWORD flagSiz = sizeof(DWORD);
           DWORD flagVal;
           DWORD flagtype = REG_DWORD;
           if ( RegQueryValueEx( subKey, "Start", NULL, &flagtype, (LPBYTE)&flagVal, &flagSiz) )
                goto CleanUp;
           if ( (LONG)flagVal != 2 )
                 goto CleanUp;           
           if (str.find("\\drivers\\") == string::npos )
           {    // Can be Service
                
                // Contain svchost.exe?
                if ( str.find("\\svchost") != string::npos )
                {  // Go To subKey Parameters
                   HKEY ssKey = NULL;
                   if ( RegOpenKeyEx( subKey, "Parameters", 0, KEY_READ|KEY_WOW64_64KEY, &ssKey ) )
                      { // No Parameter
                        str = "No Parameter specified;";
                        RegCloseKey(ssKey); }
                   else {
                        // Retrive Path from ssKey->ServiceDll
                        DWORD sdSiz = 1024;
                        DWORD sdType = REG_EXPAND_SZ;
                        LPTSTR sdVal = (LPTSTR)malloc(1024);
                        if ( !RegQueryValueEx( ssKey, "ServiceDll", NULL, &sdType, (LPBYTE)sdVal, &sdSiz) )
                        { str = sdVal;
                          RegCloseKey(ssKey); }
                        else {
                              // Whatever 
                              str = "";
                              RegCloseKey(ssKey); }
                        free(sdVal);
                        }
                     }
                else {  // Not svchost.exe
                             str = value;      }
                
                // Push back keyName
                path->push_back(str);
                str = (*it);
                result->push_back( str );
                str = disp;
                descript->push_back( str );
                                       }
           else {
                // Not Service (driver)
                // Just Pass~
                }
           
           // TODO: find publisher
           publisher->push_back("");
           
           // CleanUp
           CleanUp:
           dispSiz = 1024;
           disp[0] = '\0';
           valueSiz = 1024;
           value[0] = '\0';
           }
     
     free(value);
     free(keyName);
     RegCloseKey(hKey);
     return 1;
     }
