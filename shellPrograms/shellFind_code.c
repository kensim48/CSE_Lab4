//
//  shellFind_code.c
//  shellPrograms
//
//  Created by Natalie Agus on 11/01/19.
//  Copyright © 2019 Natalie Agus. All rights reserved.
//

#include "shellPrograms.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
/*
 List all files matching the name in args[1] under current directory and subdirectories
*/

int stringCheck(char *str1, char *str2)
{
    int x = 0;
    int counter = strlen(str1);
    int n = 0;
    for (int i = 0; i < strlen(str2); i++)
    {
        if (str1[n] != str2[n + x])
            x++;
        else
        {
            n++;
            counter--;
        }
    }
    if (counter == 0)
        return 1;
    else
        return 0;
}

void recursion(DIR *d, char *fileName, char *directory)
{
    struct dirent *dir;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (stringCheck(fileName, dir->d_name) == 1)
                printf("%s%s\n", directory, dir->d_name);
            struct stat path_stat;
            char c = dir->d_name[0];
            stat(dir->d_name, &path_stat);

            if (S_ISREG(path_stat.st_mode) == 0 && c != '.')
            {

                char *newDirectory = malloc(sizeof(char) * ((strlen(dir->d_name) + (strlen(directory)) + 1)));
                int end = 0;
                for (int i = 0; directory[i] != 0; i++)
                {
                    newDirectory[i] = directory[i];
                    end = i + 1;
                }
                int newEnd = 0;
                for (int i = 0; dir->d_name[i] != 0; i++)
                {
                    newDirectory[i + end] = dir->d_name[i];
                    newEnd = i + end + 1;
                }
                newDirectory[newEnd] = '/';
                DIR *e;
                // printf("%d, newdirectory: %s\n", S_ISREG(path_stat.st_mode) == 0 && c != '.', newDirectory);
                e = opendir(dir->d_name);
                recursion(e, fileName, newDirectory);
            }
        }
        closedir(d);
    }
}

int shellFind_code(char **args)
{
    DIR *d;
    d = opendir(".");
    recursion(d, args[1], "./");
    return 1;
}

int main(int argc, char **args)
{
    return shellFind_code(args);
}
