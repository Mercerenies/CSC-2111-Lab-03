AutomatedMakefile = am
CC = g++ -std=c++0x -Wall

FILES = Password.o PasswordDriver.o
EXECUTABLE = Password.exe

PROJECT_PATH = $(PROJECT_DIR)

INC_DIRS = 
LIB_DIRS = 
LIBS = libCSC2110.a

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

all: Project

Password.o:		Password.h Password.cpp
			$(COMPILE) Password.cpp

PasswordDriver.o: 	Password.h PasswordDriver.cpp
			$(COMPILE) PasswordDriver.cpp

Project: 		$(FILES)
			$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)



