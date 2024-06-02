//#ifndef MKDIR_COMMAND_H
//#define MKDIR_COMMAND_H
//
//#include <stdio.h>
//#include <stdlib.h>
//
//void execute_mkdir(const char* FolderName)
//{
//    char command[100];
//    sprintf(command, "powershell -Command New-Item -Path \"%s\" -ItemType Directory", FolderName);
//
//    int status = system(command);
//
//    if (status == 0)
//    {
//        printf("Folder created successfully.\n");
//    }
//    else
//    {
//        printf("Folder creation Failed.\n");
//    }
//}
//
//
//#endif 
//#ifndef MKDIR_COMMAND_H
//#define MKDIR_COMMAND_H
//
//#include <stdio.h>
//#include <windows.h>
//
//void execute_mkdir(const char* FolderName) {
//    wchar_t wFolderName[MAX_PATH];
//    MultiByteToWideChar(CP_UTF8, 0, FolderName, -1, wFolderName, MAX_PATH);
//
//    // Create the directory
//    if (CreateDirectoryW(wFolderName, NULL) != 0) {
//        printf("Folder created successfully.\n");
//    }
//    else {
//        printf("Folder creation failed.\n");
//    }
//}
#ifndef MKDIR_COMMAND_H
#define MKDIR_COMMAND_H

#include <stdio.h>
#include <windows.h>

void execute_mkdir(const char* FolderName)
{
    if (!CreateDirectory(FolderName, NULL))
    {
        DWORD dwError = GetLastError();
        if (dwError == ERROR_ALREADY_EXISTS)
        {
            printf("Folder '%s' already exists.\n", FolderName);
        }
        else
        {
            printf("Failed to create folder '%s'. Error code: %lu\n", FolderName, dwError);
        }
    }
    else
    {
        printf("Folder '%s' created successfully.\n", FolderName);
    }
}

#endif



