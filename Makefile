#OBJS specifies which files to compile as part of the project

OS = LINUX 

SOURCES = source/*.cpp \
		  source/GUI/*.cpp \
		  source/Items/*.cpp \
		  source/Window/*.cpp \
		  source/Game/*.cpp \
		  source/Test/*.cpp \
		  source/Controller/*.cpp

#CC specifies which compiler we're using
CC = g++

INCLUDE_PATHS = 
# INCLUDE_PATHS += -Iinclude/SDL2
INCLUDE_PATHS += -Iheader/GUI
INCLUDE_PATHS += -Iheader/Game
INCLUDE_PATHS += -Iheader/Items
INCLUDE_PATHS += -Iheader/Window
INCLUDE_PATHS += -Iheader/Test
INCLUDE_PATHS += -Iheader/Controller
INCLUDE_PATHS += -Iheader

INCLUDE_PATHS_H = 
# INCLUDE_PATHS_H += include/SDL2/*.h
INCLUDE_PATHS_H += header/GUI/*.h
INCLUDE_PATHS_H += header/Game/*.h
INCLUDE_PATHS_H += header/Items/*.h
INCLUDE_PATHS_H += header/Window/*.h
INCLUDE_PATHS_H += header/Test/*.h
INCLUDE_PATHS_H += header/Controller/*.h
INCLUDE_PATHS_H += header/*.h

# LIBRARY_PATH = -Llib
LIBRARY_PATH = 

# UNAME := $(shell uname)
LINKER_FLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = main

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w # -Wl,-subsystem,windows

#OBJ_NAME specifies the name of our exectuable
OBJ_FILE = obj.o

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(SOURCES) $(INCLUDE_PATHS) ${LIBRARY_PATH} $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: 
	./$(OBJ_NAME)
test: 
	.\$(OBJ_NAME) test
compile: 
	$(CC) -c ${INCLUDE_PATHS_H}
	${CC} -o cpl.oo *.o
clean: 
	del .\include\SDL2\*.gch
	del .\header\GUI\*.gch
	del .\header\Game\*.gch
	del .\header\Items\*.gch
	del .\header\Window\*.gch
	del .\header\Test\*.gch
	del .\header\Controller\*.gch
	del .\header\*.gch