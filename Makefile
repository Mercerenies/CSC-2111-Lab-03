AutomatedMakefile = am
CC = g++ -std=c++0x

FILES = Password.o PasswordDriver.o
EXECUTABLE = Password.exe

PROJECT_PATH = $(PROJECT_DIR)

INC_DIRS = 
LIB_DIRS = 
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

Password.o:		Password.h Password.cpp
			$(COMPILE) Password.cpp

all: Project

Project: 		$(FILES)
			$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)



