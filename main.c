/******************************************************************************
 *Name: minibusybox_modular_FranciscoSaldivar.c
 *@brief: Personal implementation of tool similar to BusyBox built with shared
 *libraries. Each shared library implement one of the next commands:
 *sleep
 *uname
 *ls
 *cat
 *uptime
 *lsmod
 ******************************************************************************
 *Author: José Francisco Saldivar Ceniceros
 *Date: 27/04/2023
 *Place: Guadalajara, México
 *****************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "./lsmod/lsmod.h"
#include "./cat/jcat.h"

int main(int argc, char **arg_v)
{
    unsigned char o = 0;
    puts("Welcome to minibusybox_modular!!!");
    puts("Select one valid option from menu to execute a command:");
    printf("Option 1: cat\n");
    printf("Option 2: lsmod\n");
    scanf("%hhu", &o);
    switch (o)
    {

       case 1:
        //If the command requested was cat

            char file_name[100] = "\0";
            printf("Enter file name or full path: ");
            scanf("%s", file_name);
#ifdef DEBUG
            printf("File entered: %s\n", file_name);
#endif
            if(jcat(file_name))
            {
                return 1;
            }
        break;

       case 2:
        //If the command requested was lsmod
            if(func_lsmod(argc))
            {
                return 1;
            }
        break;

        //If the entry is not valid shows an error and exits
        default:
            puts("Another command without implementation was entered");
            return 2;

    }

    puts("Successfull");
    return 0;
}
