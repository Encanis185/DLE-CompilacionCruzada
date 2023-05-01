#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jcat.h"

int jcat(const char* argv){
	const int bufferSize = 4096;
	char buffer[bufferSize];
    FILE *fp;

    if(argc > 1){
        fp = fopen(argv, "rb");
        if (fp == NULL) {
        	perror("An error happend while trying to open file\n");
            exit(EXIT_FAILURE);
	    }
    }


	while (fgets(buffer, bufferSize, (fp == NULL ? stdin : fp))) {
        int length = strlen(buffer);
        buffer[length - 1] = '\0';
        fprintf(stdout, "%s\n", buffer);
    }

    fclose(fp);
    return 0;
}
