#OBJS specifies which files to compile as part of the project

SOURCES = source/*.cpp \
		  source/GUI/*.cpp \
		  source/Items/*.cpp \
		  source/Window/*.cpp \
		  source/Game/*.cpp \
		  source/Test/*.cpp \
		  source/Controller/*.cpp

#CC specifies which compiler we're using
CC = g++

INCLUDE_PATHS = -Iinclude/SDL2
INCLUDE_PATHS += -Iheader/GUI
INCLUDE_PATHS += -Iheader/Game
INCLUDE_PATHS += -Iheader/Items
INCLUDE_PATHS += -Iheader/Window
INCLUDE_PATHS += -Iheader/Test
INCLUDE_PATHS += -Iheader/Controller
INCLUDE_PATHS += -Iheader

LIBRARY_PATH = -Llib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings

# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main.exe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(SOURCES) $(INCLUDE_PATHS) ${LIBRARY_PATH} $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run: 
	.\main.exe 
test: 
	.\main.exe test