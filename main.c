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
#include "../sleep/sleep.h"
#include "../ls/ls.h"
#include "../lsmod/lsmod.h"
#include "../uname/uname.h"
#include "../uptime/uptime.h"
#include "../cat/cat.h"

int main(int argc, char **arg_v)
{
    unsigned char o = 0;
    puts("Welcome to minibusybox_modular!!!");
    puts("Select one valid option from menu to execute a command:");
    printf("Option 0: sleep\n");
    printf("Option 1: uname\n");
    printf("Option 2: ls\n");
    printf("Option 3: cat\n");
    printf("Option 4: uptime\n");
    printf("Option 5: lsmod\n");
    scanf("%hhu", &o);
    switch (o)
    {
        case 0:
            //If the command requested was sleep
            ;
            char seconds[10] = "\0";
            printf("Enter number of seconds for sleep: ");
            scanf("%s", seconds);
#ifdef DEBUG
            printf("Seconds entered: %s\n", seconds);
#endif
            if(func_sleep(argc, seconds))
            {
                return 1;
            }
        break;

        case 1:
        //If the command requested was uname
            if(func_uname(argc))
            {
                return 1;
            }
        break;

       case 2:
        //If the command requested was ls
            ;
            char dir_name[100] = "\0";
            printf("Enter full path: ");
            scanf("%s", dir_name);
#ifdef DEBUG
            printf("Directory entered: %s\n", dir_name);
#endif
            if(func_ls(argc, dir_name))
            {
                return 1;
            }
        break;


       case 3:
        //If the command requested was cat
            ;
            char file_name[100] = "\0";
            printf("Enter file name or full path: ");
            scanf("%s", file_name);
#ifdef DEBUG
            printf("File entered: %s\n", file_name);
#endif
            if(func_cat(argc, file_name))
            {
                return 1;
            }
        break;

       case 4:
        //If the command requested was uptime
            if(func_uptime(argc))
            {
                return 1;
            }
        break;

       case 5:
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
