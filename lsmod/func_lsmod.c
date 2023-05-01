/******************************************************************************
 *Name: func_lsmod.c
 *@brief: Personal implementation of lsmod command using C APis from Linux.
 *This function is designed to be used with a main source file to make a
 *personal implementation of minibusybox.
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "lsmod.h"

#define MAXBUFFSIZE 100

int func_lsmod(int num_arg)
{
    //Tries to open file /proc/modules, if there is an error exit
    FILE *proc_f = fopen("/proc/modules", "rt");
    if (proc_f == NULL)
    {
        perror("Error opening file modules:" );
        return 7;
    }

    //Prepares buffer to save data inside file
    char buff_file[MAXBUFFSIZE] = "\0";
    //Reads file as long as EOF has not been found
    printf("%-20s%-10s%-5s", "Module", "Size", "Used by\n");
    char *ptrstk;
    while ((fgets(buff_file, MAXBUFFSIZE, proc_f)) != NULL)
    {
        //Gives correct format according the original command
        ptrstk = strtok(buff_file, " ");
        printf("%-20s", ptrstk);
        ptrstk = strtok(NULL, " ");
        printf("%-10s", ptrstk);
        ptrstk = strtok(NULL, " ");
        printf("%-5s\n", ptrstk);
        //Clears all data previously saved
        for (int i = 0; *(buff_file + i) != '\0'; i++)
        {
            *(buff_file + i) = '\0';
        }
    }

    //Closes file
    if (fclose(proc_f) == -1)
    {
        perror("Error closing file: ");
        return 1;
    }

    return 0;
}

/*********************************END OF FILE*********************************/
