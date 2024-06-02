#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "cd_command.h"
#include "copy.h"
#include "mkdir.h"
#include "at.h"
#include "call.h"
#include "cls.h"
#include "cmd.h"
#include "color.h"
#include "comp.h"
#include "date_time.h"
#include "delete.h"
#include "dir.h"
#include "findstr.h"
#include "echo.h"
#include "file_create.h"
#include "edit.h"
#include "exit.h"
#include "linecount.h"
#include "more.h"
#include "print.h"
#include "task_list.h"
#include "type.h"
#include "wmic.h"
#include "move.h"
#include "shutdown.h"
#include "talent_display.h"
#include "title.h"
#include "tree.h"



int main() {
    char filename[100];
    char* extension;
    char input[256];
    char command[256];
    const char* delimiter = " ";
    printf("Custom Shell\n");

    while (1) {
        printf("Talha > ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

        
        if (input == NULL) {
            printf("Error reading input.\n");
            continue;
        }

       char* token = strtok(input, " ");
        char* arg1 = strtok(NULL, " ");
        char* arg2 = strtok(NULL, " ");

        if (token == NULL) {
            printf("Please enter a command.\n");
            continue;
        }
        char* arg = strtok(NULL, " ");


        if (strcmp(token, "exit") == 0) {
            break;
        }
        else if (strncmp(token, "cd", 2) == 0) {
            if (arg1 == NULL) {
                printf("Usage: cd <Path>\n");
                continue;
            }
            execute_cd(arg1); 
        }
        else if (strcmp(token, "copy") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: copy <source> <destination>\n");
                continue;
            }
            execute_cp(arg1, arg2); 
        }
        else if (strcmp(token, "mkdir") == 0) {
            if (arg1 == NULL) {
                printf("Usage: mkdir <directory_name>\n");
                continue;
            }
            execute_mkdir(arg1); 
        }
        else if (strcmp(token, "at") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: at <time> <command>\n");
                continue;
            }
            at_command(arg1, arg2); 
        }
        else if (strcmp(token, "call") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: call <batch_file> <label>\n");
                continue;
            }
            call_command(arg1, arg2); 
        }
        else if (strcmp(token, "cls") == 0) {
            cls_command(); 
        }
        else if (strcmp(input, "cmd") == 0) {
            execute_cmd_command();
        }
        else if (strcmp(token, "color") == 0) {
            if (arg1 == NULL) {
                printf("Usage: color <attribute>\n");
                continue;
            }
            color_command(arg1); 
        }
        else if (strcmp(token, "comp") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: comp <file1> <file2>\n");
                continue;
            }
            execute_comp_command(arg1, arg2); 
        }
        else if (strcmp(token, "date") == 0) {
            show_date(); 
        }
        else if (strcmp(token, "time") == 0) {
            show_time(); 
        }
        else if (strcmp(token, "del") == 0) {
            if (arg1 == NULL) {
                printf("Usage: del <filename or directory>\n");
                continue;
            }
            execute_del(arg1);
        }
       
        else if (strcmp(token, "createfiles") == 0) {
            strcpy(filename, arg1);
            extension = strchr(filename, '.');
            if (extension == NULL) {
                printf("Invalid filename. Please provide an extension.\n");
                continue;
            }
            *extension++ = '\0'; 

            
            create_file(filename, extension);
        }
        else if (strcmp(token, "dir") == 0) {
            if (arg1 == NULL) {
                printf("Usage: dir <Path> \n");
                continue;
            }
            execute_dir(arg1); 
        }

        else if (strcmp(token, "findstr") == 0) {
            if (arg1 == NULL || arg2 == NULL) {
                printf("Usage: findstr <filename> <search_string>\n");
                continue;
            }
            execute_findstr_command(arg1, arg2); 
        }


        else if (strcmp(token, "echo") == 0) {
            if (arg1 == NULL ||arg2==NULL) {
                printf("Usage: echo <message>\n");
                continue;
           }

            execute_echo_command(arg1);
        }

        else if (strcmp(token, "edit") == 0) {
            
            if (arg1 == NULL) {
                printf("Usage: edit <filename>\n");
                continue;
            }
            edit_command(arg1);
            }

        else if (strcmp(token, "count_line") == 0) {
            if (arg1== NULL) {
                printf("Usage: wc <filename>\n");
                continue;
            }
            execute_wc(arg1);
            }
            else if (strcmp(token, "more") == 0) {
                if (arg1 == NULL) {
                    printf("Usage: wc <filename>\n");
                    continue;
                }
                execute_more(arg1);
            }
            else if (strcmp(token, "move") == 0) {
                if (arg1 == NULL|| arg2==NULL) {
                    printf("Error: Missing source file argument.\n");
                    continue;
                }
                execute_move_command(arg1, arg2);
            }
            else if (strcmp(token, "msg") == 0) {
                if (arg1 == NULL || arg2 == NULL) {
                    printf("Usage: msg <username> <message>\n");
                    continue;
                }
                send_message(arg1, arg2);
                }

            else if (strcmp(token, "print") == 0) {
                    if (arg1 == NULL) {
                        printf("Usage: print <filename>\n");
                        continue;
                    }

                    execute_print(arg1);
                    }
            else  if (strcmp(token, "shutdown") == 0) {
                    char* option = strtok(NULL, delimiter);
                    execute_shutdown_command(option);
            }
            else if (strcmp(token, "talent_display") == 0) {
                execute_talent_display();
            }
            else if (strcmp(token, "tasklist") == 0) {
            execute_tasklist();
            }
            else if (strcmp(token, "title") == 0) {
                if (arg1 == NULL) {
                    printf("Usage: title <title_name>\n");
                    continue;
                }
                execute_title_command(arg1);
}
            else if (strcmp(token, "tree") == 0) {
                if (arg1 == NULL) {
                    printf("Usage: tree <directory>\n");
                    continue;
                }
                execute_tree_command(arg1);
                }
            else  if (strcmp(token, "type") == 0) {
                    if (arg1 == NULL) {
                        printf("Usage: type <filename>\n");
                        continue;
                    }
                    execute_type_command(arg1);
                }
                else if (strcmp(token, "wmic_disk_status") == 0) {
                    execute_wmic_disk_status();
                }
                else if (strcmp(token, "wmic_cpu_name") == 0) {
                    execute_wmic_cpu_name();
                }
                else if (strcmp(token, "ver") == 0) {
                    execute_ver(); // Call the execute_ver function
        }

        else {
            printf("'%s' is not recognized as a valid command.\n", token);
        }
    }

    return 0;
}
