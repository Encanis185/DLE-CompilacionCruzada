CC = gcc
CROSS = 
CFLAGS = -Wall
LIB_NAME = jcat

.PHONY: all install clean

all: jcat

jCat: jcat.o
	@#Compiling with position independent code
	$(CROSS)$(CC) -c $(CFLAGS) -fPIC jcat.c
	$(CROSS)$(CC) -shared -o lib$(LIB_NAME).so


jcat.o: jcat.c jcat.h
	$(CROSS)$(CC) $(CFLAGS) -c jcat.c -o jcat.o  

install:
	@sudo cp ./$(LIB_NAME).so /usr/lib
	@sudo cp ./$(LIB_NAME).h /usr/include
clean:
	rm -rf *.o *.so
