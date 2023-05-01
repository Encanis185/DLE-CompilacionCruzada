
OBJECTS = libsleep.so libls.so liblsmod.so libuname.so \
          libuptime.so libcat.so minibusy_modular.o
COMPILER = gcc
CROSS_COMPILER =
SHARED_PATH = ./
APP_NAME = minibusy_modular
FLAGS = -Wall -Werror -o
SHARED_FLAGS = -c -Wall -Werror -fPIC
SRC_PATH = ./src/minibusy_modular.c
SHARED_LIBS_FLAGS = -lsleep -lls -llsmod -luname -luptime -lcat
SLEEP_SOURCE_PATH = ./sleep/func_sleep.c
SLEEP_INC_PATH = ./sleep/sleep.h
LS_SOURCE_PATH = ./ls/func_ls.c
LS_INC_PATH = ./ls/ls.h
LSMOD_SOURCE_PATH = ./lsmod/func_lsmod.c
LSMOD_INC_PATH = ./lsmod/lsmod.h
UNAME_SOURCE_PATH = ./uname/func_uname.c
UNAME_INC_PATH = ./uname/uname.h
UPTIME_SOURCE_PATH = ./uptime/func_uptime.c
UPTIME_INC_PATH = ./uptime/uptime.h
CAT_SOURCE_PATH = ./cat/func_cat.c
CAT_INC_PATH = ./cat/cat.h
SRC_PATH = ./src/minibusy_modular.c

.PHONY : all install clean

all : $(APP_NAME)

$(APP_NAME) : $(OBJECTS)
	$(CROSS_COMPILER)$(COMPILER) -L$(SHARED_PATH) $(FLAGS) $@ minibusy_modular.o $(SHARED_LIBS_FLAGS)

libsleep.so : $(SLEEP_SOURCE_PATH) $(SLEEP_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(SLEEP_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_sleep.o

libls.so : $(LS_SOURCE_PATH) $(LS_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(LS_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_ls.o

liblsmod.so : $(LSMOD_SOURCE_PATH) $(LSMOD_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(LSMOD_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_lsmod.o

libuname.so : $(UNAME_SOURCE_PATH) $(UNAME_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(UNAME_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_uname.o

libuptime.so : $(UPTIME_SOURCE_PATH) $(UPTIME_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(UPTIME_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_uptime.o

libcat.so : $(CAT_SOURCE_PATH) $(CAT_INC_PATH)
	$(CROSS_COMPILER)$(COMPILER) $(SHARED_FLAGS) $(CAT_SOURCE_PATH)
	$(CROSS_COMPILER)$(COMPILER) -shared -o $@ func_cat.o

minibusy_modular.o : $(SRC_PATH)
	$(CROSS_COMPILER)$(COMPILER) -c $(SRC_PATH)

install :
	sudo cp libsleep.so libls.so liblsmod.so libuname.so libuptime.so libcat.so /usr/lib


clean :
	rm -f *.o *.so $(APP_NAME)



