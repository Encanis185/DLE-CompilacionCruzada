
OBJECTS = liblsmod.so libcat.so main.o
COMPILER = gcc
CROSS_COMPILER =
SHARED_PATH = ./
APP_NAME = minibusy_modular
FLAGS = -Wall -Werror -o
SHARED_FLAGS = -c -Wall -Werror -fPIC
SHARED_LIBS_FLAGS = -llsmod -lcat
LSMOD_SOURCE_PATH = ./lsmod/func_lsmod.c
LSMOD_INC_PATH = ./lsmod/lsmod.h
CAT_SOURCE_PATH = ./cat/jcat.c
CAT_INC_PATH = ./cat/jcat.h

.PHONY : all install clean

all : $(APP_NAME)

$(APP_NAME) : $(OBJECTS)
	$(CROSS_COMPILER)$(COMPILER) -L$(SHARED_PATH) $(FLAGS) $@ main.o $(SHARED_LIBS_FLAGS)

liblsmod.so : $(LSMOD_SOURCE_PATH) $(LSMOD_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(LSMOD_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_lsmod.o

libcat.so : $(CAT_SOURCE_PATH) $(CAT_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(CAT_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ jcat.o

main.o : main.c
	$(CROSS_COMPILER)$(COMPILER) -c $<

install :
	sudo cp liblsmod.so libcat.so /usr/lib


clean :
	rm -f *.o *.so $(APP_NAME)
