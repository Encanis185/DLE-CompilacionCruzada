CC = gcc
CROSS = 
CFLAGS = -Wall -g
LIB_NAME = jcat
OBJS = jcat.o

.PHONY: all install clean

all: jcat

jcat: jcat.o
	@#Compiling with position independent code
	$(CROSS)$(CC) $(CFLAGS) -shared -fPIC jcat.c -o lib$(LIB_NAME).so  

jcat.o: jcat.c jcat.h
	$(CROSS)$(CC) $(CFLAGS) -c jcat.c -o jcat.o

install:
	@sudo cp ./lib$(LIB_NAME).so /usr/lib
	@sudo cp ./$(LIB_NAME).h /usr/include
clean:
	rm -rf *.o *.so
