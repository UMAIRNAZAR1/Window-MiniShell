#ifndef CREATE_FILE_H
#define CREATE_FILE_H

#include <stdio.h>

// Function to create a file
#include "file_create.h"


#include <stdio.h>

void create_file(const char* filename) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error creating file\n");
        return;
    }

    // Close the file
    fclose(fp);
}



#endif
