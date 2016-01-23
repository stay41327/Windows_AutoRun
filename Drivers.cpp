#include "Drivers.h"

/*
******************************************************
Driver Tab
autorun drivers
******************************************************
*/

int Driver ( vector<tstring> *result,
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
           if ( RegQueryValueEx( subKey, "DisplayName", NULL, &type, (LPBYTE)disp, &dispSiz) )
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
           
           if (str.find("\\drivers\\") != string::npos )
           {    // Is Driver
                // Push back keyName
                str = value;
                path->push_back(str);
                str = (*it);
                result->push_back( str );
                str = disp;
                descript->push_back( str );
                                       }
           else {
                // Not Driver (service)
                // Just Pass~
                }
           
           // TODO: find publisher
           publisher->push_back("");
           
           // CleanUp
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
