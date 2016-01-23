
/*
******************************************************
Scheduled Tasks Tab
Scheduled Tasks under C:\Windows\Tasks\
******************************************************
*/

#include <windows.h>
#include <malloc.h>
#include <vector>
#include <string>
#include <stdio.h>

#ifndef KEY_WOW64_64KEY
#define KEY_WOW64_64KEY 0x0100
#endif

using namespace std;

#ifdef UNICODE
    typedef wstring tstring;           
#else
    typedef string tstring;
#endif

typedef struct wpath{
       wchar_t p[1000];
       } wpath;
/*
####
  NOTE!!!
  path here is explicitly set to wpath
####
*/
int ST_xp (  vector<tstring> *result,
                vector<tstring> *descript,
                vector<tstring> *publisher,
                vector<wpath> *path);
