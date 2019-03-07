//
//  shellListDir_code.c
//  shellPrograms
//
//  Created by Natalie Agus on 11/01/19.
//  Copyright © 2019 Natalie Agus. All rights reserved.
//

#include "shellPrograms.h"

/*
	List the items in the directory
*/
int shellListDir_code(char **args)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return 1;
}

int main(int argc, char **args)
{
    return shellListDir_code(args);
}
