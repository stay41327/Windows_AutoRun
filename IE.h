
/*
******************************************************
IE Tab
IE BHO, Extension, Tool bar
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

int IE_BHO (  vector<tstring> *result,
                 vector<tstring> *descript,
                 vector<tstring> *publisher,
                 vector<tstring> *path);

int IE_wow_BHO (  vector<tstring> *result,
                     vector<tstring> *descript,
                     vector<tstring> *publisher,
                     vector<tstring> *path);

int IE_SearchHook (  vector<tstring> *result,
                        vector<tstring> *descript,
                        vector<tstring> *publisher,
                        vector<tstring> *path);
