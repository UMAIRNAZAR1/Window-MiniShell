#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <windows.h>

void printTree(const char* path, int indent) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(path, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Invalid path - %s\n", path);
        return;
    }

    do {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
            for (int i = 0; i < indent; i++) {
                printf("  ");
            }
            printf("|- %s\n", findFileData.cFileName);

            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                char newPath[MAX_PATH];
                snprintf(newPath, sizeof(newPath), "%s\\*", findFileData.cFileName);
                printTree(newPath, indent + 1);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void execute_tree_command(const char* path) {
    printf("Folder PATH listing\nVolume serial number is 000000C9 E611:1B3D\n");
    printTree(path, 0);
}

#endif /* TREE_COMMAND_H */
