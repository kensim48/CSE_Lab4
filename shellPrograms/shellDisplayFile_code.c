//
//  shellDisplayFile_code.c
//  shellPrograms
//
//  Created by Natalie Agus on 11/01/19.
//  Copyright © 2019 Natalie Agus. All rights reserved.
//

#include "shellPrograms.h"
#define MAXCHAR 1000
/**
   Allows one to display the content of the file 
 */
int shellDisplayFile_code(char **args)
{
  int start = 8;
  int end = 0;
  int i = start;

  //get length of file name
  while (end == 0 && i < 200)
  {
    char c = args[0][i];
    if (c == '\0')
    {
      end = i;
    }
    i++;
  }
  if (end == 0)
    return 1;

  //copy file name to variable fileName
  char *fileName = malloc(sizeof(char) * (end - start));
  for (i = start; i < end; i++)
    fileName[i - start] = args[0][i];

  //start reading out .txt file
  FILE *fp;
  char str[MAXCHAR];
  fp = fopen(fileName, "r");
  if (fp == NULL)
  {
    printf("Could not open file %s\n", fileName);
    return 1;
  }
  while (fgets(str, MAXCHAR, fp) != NULL)
  {
    printf("%s", str);
  }
  fclose(fp);
  printf("\n");
  return 1;
}

int main(int argc, char **args)
{
  return shellDisplayFile_code(args);
}
