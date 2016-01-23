#include "ST.h"

/*
******************************************************
Scheduled Tasks Tab
Scheduled Tasks under C:\Windows\Tasks\
******************************************************
*/

/*
####
  NOTE!!!
  path here is explicitly set to wstring
####
*/
int ST_xp (  vector<tstring> *result,
                vector<tstring> *descript,
                vector<tstring> *publisher,
                vector<wpath> *path)
{
    WIN32_FIND_DATA file;
    HANDLE hfile;
    string tmp;
    wpath pathbuff;
    
    if ( (hfile = FindFirstFile("C:\\Windows\\Tasks\\*.job", &file)) == INVALID_HANDLE_VALUE )
         return 0;
    tmp = file.cFileName;
    result->push_back( tmp );
    tmp = "C:\\Windows\\Tasks\\" + tmp;
    FILE *job = fopen(tmp.c_str(), "r");
    if ( job == NULL )
        { memset((void*)pathbuff.p, '\0', 1000);
          path->push_back(pathbuff);
          goto KeepGoing;      }
    // Parse job file
    //       0x46    short unsigned int : length
    //       0x48    unicode_string     : path
    fseek( job, 0x46, SEEK_SET);
    unsigned short int len;
    //for ( int i = 0; i < 1000 && (str[i] = fgetc(job)) != '\0'; i++);
    len = fgetwc(job);
    fseek( job, 0x48, SEEK_SET);
    fgetws ( pathbuff.p, len*2, job);      // double the length char->wchar
    path->push_back(pathbuff);
    fclose(job);
    
    KeepGoing:
    // TODO: description & publisher
    descript->push_back("");
    publisher->push_back("");
    
    // iterator through & retrive all the *.job files
    while ( FindNextFile( hfile, &file) )
    {
          tmp = file.cFileName;
          result->push_back( tmp );
          // Open job file
          tmp = "C:\\Windows\\Tasks\\" + tmp;
          FILE *job = fopen(tmp.c_str(), "r");
          if ( job == NULL )
             { memset((void*)pathbuff.p, '\0', 1000);
               path->push_back(pathbuff);
               goto MOVEON;        }
          // Parse job file
          //       0x46    short unsigned int : length
          //       0x48    unicode_string     : path
          fseek( job, 0x46, SEEK_SET);
          //for ( int i = 0; i < 1000 && (str[i] = fgetc(job)) != '\0'; i++);
          len = fgetwc(job);
          fseek( job, 0x48, SEEK_SET);
          fgetws ( pathbuff.p, len*2, job);      // double the length char->wchar
          path->push_back(pathbuff);
          
          fclose(job);
          
          MOVEON:
                 // TODO: description & publisher
                 descript->push_back("");
                 publisher->push_back("");
          }
    
    // CleanUp
    FindClose(hfile);
    
    return 1;
                 }

