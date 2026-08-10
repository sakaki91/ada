#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>

// ls - v2.1
// Copyright (C) by Sakaki, 2026.
// LICENSE: BSD 3-Clause License <https://opensource.org/license/bsd-3-clause>

void directoryCreation(DIR *dir, bool o_dir){
    struct dirent *entry;
    if (dir == NULL){
        perror("ls");
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL){
        if (o_dir != true){
            if (entry->d_name[0] == '.'){
                continue;
            }
        }
        printf("%s\n", entry->d_name);
    }
}

void directoryDetection(int argc, char *argv[], bool u_dir, bool m_dir, bool o_dir, int i){
    DIR *dir;
    if (u_dir == true){
        if (o_dir == true){
            dir = (argc == 2) ? opendir(".") : opendir(argv[2]);
        } else {
            dir = (argc == 1) ? opendir(".") : opendir(argv[1]);
        }
        directoryCreation(dir, o_dir);
        closedir(dir);
    } else if (m_dir == true){
        for (i; i < argc; i++){
            dir = opendir(argv[i]);
            directoryCreation(dir, o_dir);
            closedir(dir);
        }
    }
}

int main(int argc, char *argv[]){
    int i = 0;
    bool u_dir = false;
    bool m_dir = false;
    bool o_dir = false;
    if (argc < 2){
        u_dir = true;
    } else if (argc > 1){
        if (argc > 1){
            if (strcmp(argv[1], "-h") == 0){
                fprintf(stdout, "usage: ls <operation> dir1 dir2...\n"
                                " -a    : show hidden directories/files.\n\n");
            } else if (strcmp(argv[1], "-a") == 0){
                i = 2;
                o_dir = true;
                if (argc == 2){
                    u_dir = true;
                } else {
                    m_dir = true;
                }
            } else {
                i = 1;
                m_dir = true;
            }
        } 
    } 
    directoryDetection(argc, argv, u_dir, m_dir, o_dir, i);
    return 0;
}
