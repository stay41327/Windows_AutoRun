#include <cstdlib>
#include <iostream>
#include <wchar.h>
#include "Logon.h"
#include "Drivers.h"
#include "Service.h"
#include "IE.h"
#include "ST.h"
#include "KD.h"

using namespace std;

#define logon 1
#define driver 2
#define service 3
#define ie 4
#define st 5
#define kd 6
#define h 7

string ws2s(const wstring& ws)
{
    std::string curLocale = setlocale(LC_ALL, NULL);
    setlocale(LC_ALL, "chs");
    const wchar_t* _Source = ws.c_str();
    size_t _Dsize = 2 * ws.size() + 1;
    char *_Dest = new char[_Dsize];
    memset(_Dest,0,_Dsize);
    wcstombs(_Dest,_Source,_Dsize);
    string result = _Dest;
    delete []_Dest;
    setlocale(LC_ALL, curLocale.c_str());
    return result;
}

int main(int argc, char *argv[])
{
    // Var Defination
    vector<tstring> key,disc,publi,path;
    vector<wpath> ST_path;
    int switcher;
    
    if (argc == 1)
    {
       cout << "Parameter required! Try again with -h (Maybe?)\n";
       return 0;
    }
    
    if (strcmp(argv[1], "-logon") == 0)
       switcher = 1;
    else
    if (strcmp(argv[1], "-driver") == 0)
       switcher = 2;
    else
    if (strcmp(argv[1], "-service") == 0)
       switcher = 3;
    else
    if (strcmp(argv[1], "-ie") == 0)
       switcher = 4;
    else
    if (strcmp(argv[1], "-st") == 0)
       switcher = 5;
    else
    if (strcmp(argv[1], "-kd") == 0)
       switcher = 6;
    else
    if (strcmp(argv[1],"-h") == 0)
       switcher = 7;
    else
       switcher = 0;
    
    if (argc == 2)
    {
       switch (switcher)
       {
         case logon:
              cout << "+++++++++++++++++++++++++++++\n";
              cout << "+++    Logon  item list   +++\n";
              cout << "+++++++++++++++++++++++++++++\n";
              if (Logon_startupprograms(&key,&disc,&publi,&path) == 1)
                 {  cout << "###\n";
                    cout << "  Startup Programs\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                        cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
               if (Logon_userinit(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  User init\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
               if (Logon_shell(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  Shell\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                if (Logon_run(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  X64 Run\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                if (Logon_runonce(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  X64 RunOnce\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                if (Logon_wow_run(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  X32 Run\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                 if (Logon_wow_runonce(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  X32 RunOnce\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                  if (Logon_CU_run(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  CurrentUser Run\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                   if (Logon_CU_runonce(&key,&disc,&publi,&path) == 1)     
                  {  cout << "###\n";
                    cout << "  CurrentUser RunOnce\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case driver:
              cout << "+++++++++++++++++++++++++++++\n";
              cout << "+++   Driver  item list   +++\n";
              cout << "+++++++++++++++++++++++++++++\n";
              if (Driver(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  Drivers\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case service:
              cout << "++++++++++++++++++++++++++++++\n";
              cout << "+++   Service  item list   +++\n";
              cout << "++++++++++++++++++++++++++++++\n";
              if (Service(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  Services\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case ie:
              cout << "+++++++++++++++++++++++++++++\n";
              cout << "+++   IE BHO  item list   +++\n";
              cout << "+++++++++++++++++++++++++++++\n";
              if (IE_BHO(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  X64 BHO\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
              if (IE_wow_BHO(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  X32 BHO\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
              if (IE_SearchHook(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  IE Search Hook\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case st:
              cout << "+++++++++++++++++++++++++++++++++++++\n";
              cout << "+++   Scheduled Task  item list   +++\n";
              cout << "+++++++++++++++++++++++++++++++++++++\n";
              if (ST_xp(&key,&disc,&publi,&ST_path) == 1)     
                  { cout << "###\n";
                    cout << "  Scheduled Tasks\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case kd:
              cout << "++++++++++++++++++++++++++++++++\n";
              cout << "+++   Known DLL  item list   +++\n";
              cout << "++++++++++++++++++++++++++++++++\n";
              if (KD(&key,&disc,&publi,&path) == 1)     
                  { cout << "###\n";
                    cout << "  Known Dlls\n";
                    cout << "###\n";
                    for (vector<tstring>::iterator it = key.begin(); it != key.end(); ++it)
                    cout << "     " << (*it) << endl;
                    key.clear();
                    disc.clear();
                    publi.clear();
                    path.clear();
                    ST_path.clear();
                    }
                    break;
         case h:
              cout << "####################################\n";
              cout << "###       HELP INFORMATION       ###\n";
              cout << "####################################\n";
              cout << endl;
              cout << "Usage:    WinSec.exe [Operation [Key]]\n";
              cout << endl;
              cout << "Operation:\n";
              cout << "    -logon:   lists the Key names in Logon.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              cout << "    -driver:   lists the Key names in Drivers.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              cout << "    -service:   lists the Key names in Services.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              cout << "    -ie:   lists the Key names in IE BHO.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              cout << "    -st:   lists the Key names in Scheduled Tasks.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              cout << "    -kd:   lists the Key names in Known DLLs.\n";
              cout << "         set Key with the key names listed"
                               "to view the Key's detailed information."
                   << endl;
              break;
         default:
              cout << "Unknown Parameters. Try \"-h\" view help info.\n";
       }
       return 0;
    }
    
    if (argc == 3)
    {
        int index;
        switch (switcher)
        {
               case logon:
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under Logon           +++\n";
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    if ( Logon_startupprograms(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  Startup Programs\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_userinit(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  User init\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_shell(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  Shell\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_run(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  Run\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_runonce(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  RunOnce\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_wow_run(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  x32 Run\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_wow_runonce(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  x32 RunOnce\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_CU_run(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  Current User Run\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( Logon_CU_runonce(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  Current User RunOnce\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               case driver:
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under Drivers         +++\n";
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    if ( Driver(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               case service:
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under Services        +++\n";
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    if ( Service(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               case st:
                    cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under Scheduled Tasks        +++\n";
                    cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
                    if ( ST_xp(&key,&disc,&publi,&ST_path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : ";
                              for (int i = 0; i<1000 && (ST_path[index].p[i] != '\0' || ST_path[index].p[i+1] != '\0'); i++)
                                  wprintf(L"%lc",ST_path[index].p[i]);
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               case ie:
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under IE BHO          +++\n";
                    cout << "+++++++++++++++++++++++++++++++++++++\n";
                    if ( IE_BHO(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  IE BHO\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( IE_wow_BHO(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  x32 IE BHO\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    if ( IE_SearchHook(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   cout << "###\n";
                              cout << "  IE Search Hooks\n";
                              cout << "###\n";
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               case kd:
                    cout << "+++++++++++++++++++++++++++++++++++++++\n";
                    cout << "+++         Under Known DLLs        +++\n";
                    cout << "+++++++++++++++++++++++++++++++++++++++\n";
                    if ( KD(&key,&disc,&publi,&path) == 1);
                    {     
                          for ( index = 0; (index < key.size()) && (strcmp(key[index].c_str(), argv[2]) != 0); index++);
                          if ( index != key.size() )
                          {   
                              cout << "     Name  : " << key[index] << endl;
                              cout << "     Descpt: " << disc[index] << endl;
                              cout << "     File  : " << path[index] << endl;
                              break;
                          }
                          else
                          {
                              cout << "###\n";
                              cout << "  KEY not FOUND!\n";
                              cout << "###\n";    
                          }
                          index = 0;
                          key.clear();
                          disc.clear();
                          publi.clear();
                          path.clear();
                          ST_path.clear();
                    }
                    break;
               default:
                       cout << "Unknown Parameters. Try \"-h\" view help info.\n";
        } 
        return 0;
    }
    else
    {
        cout << "Too Many Arguments. Try \"-h\" view help info.\n";
        }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
