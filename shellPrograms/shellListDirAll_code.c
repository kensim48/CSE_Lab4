//
//  shellListDirAll_code.c
//  shellPrograms
//
//  Created by Natalie Agus on 11/01/19.
//  Copyright © 2019 Natalie Agus. All rights reserved.
//

#include "shellPrograms.h"
#include <sys/types.h>
#include <sys/stat.h>

void recursion(DIR *d)
{
    struct dirent *dir;

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
            struct stat path_stat;
            char c = dir->d_name[0];
            stat(dir->d_name, &path_stat);
            if (S_ISREG(path_stat.st_mode) == 0 && c!='.')
            {
                DIR *e;
                e = opendir(dir->d_name);
                recursion(e);
            }
        }
        closedir(d);
    }
}

int shellListDirAll_code(char **args)
{
    DIR *d;
    d = opendir(".");
    recursion(d);
    return 1;
}

int main(int argc, char **args)
{
    return shellListDirAll_code(args);
}
