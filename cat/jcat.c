#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jcat.h"

int jcat(int argc, char** argv){
	const int bufferSize = 4096;
	char buffer[bufferSize];
    FILE *fp;

    if(argc > 1){
        fp = fopen(argv[argc -1], "rb");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: No such file or directory", argv[0], argv[argc-1]);
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
