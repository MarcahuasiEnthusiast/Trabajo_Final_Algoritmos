#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

using namespace std;

#ifndef DWORD
#define WINAPI
typedef unsigned long DWORD;
typedef short WCHAR;
typedef void * HANDLE;
#define MAX_PATH    PATH_MAX
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int BOOL;
#endif

typedef struct _FILETIME {
  DWORD dwLowDateTime;
  DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
  DWORD    dwFileAttributes;
  FILETIME ftCreationTime;
  FILETIME ftLastAccessTime;
  FILETIME ftLastWriteTime;
  DWORD    nFileSizeHigh;
  DWORD    nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;


int main(){
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir(".");
    while ((dp=readdir(dir)) != NULL) {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            // do nothing (straight logic)
        } else {
            file_name = dp->d_name; // use it
            if (access(file_name, X_OK) != -1) {
             cout << "executable:";
            }
            else if (dp->d_type == DT_DIR)
            {
               cout << "directory:";
            }
            else if(dp->d_type == DT_REG)
            {
               cout << "file:";
            }
            cout << "     \"%s\"\n",file_name;
        }
    }
    closedir(dir);

    return 0;
}