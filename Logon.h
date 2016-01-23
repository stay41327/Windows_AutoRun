
/*
******************************************************
Logon Tab
Common registry key
******************************************************
*/

#include <windows.h>
#include <malloc.h>
#include <vector>
#include <string>

#ifndef KEY_WOW64_64KEY
#define KEY_WOW64_64KEY 0x0100
#endif

using namespace std;

#ifdef UNICODE
    typedef wstring tstring;           
#else
    typedef string tstring;
#endif

int Logon_startupprograms (vector<tstring> *result,
                              vector<tstring> *descript,
                              vector<tstring> *publisher,
                              vector<tstring> *path);

int Logon_userinit ( vector<tstring> *result,
                        vector<tstring> *descript,
                        vector<tstring> *publisher,
                        vector<tstring> *path);

int Logon_shell ( vector<tstring> *result,
                     vector<tstring> *descript,
                     vector<tstring> *publisher,
                     vector<tstring> *path);

int Logon_run ( vector<tstring> *result,
                   vector<tstring> *descript,
                   vector<tstring> *publisher,
                   vector<tstring> *path);

int Logon_runonce ( vector<tstring> *result,
                       vector<tstring> *descript,
                       vector<tstring> *publisher,
                       vector<tstring> *path);

int Logon_wow_run ( vector<tstring> *result,
                       vector<tstring> *descript,
                       vector<tstring> *publisher,
                       vector<tstring> *path);

int Logon_wow_runonce ( vector<tstring> *result,
                           vector<tstring> *descript,
                           vector<tstring> *publisher,
                           vector<tstring> *path);
                           
int Logon_CU_run ( vector<tstring> *result,
                      vector<tstring> *descript,
                      vector<tstring> *publisher,
                      vector<tstring> *path);
                      
int Logon_CU_runonce ( vector<tstring> *result,
                          vector<tstring> *descript,
                          vector<tstring> *publisher,
                          vector<tstring> *path);


