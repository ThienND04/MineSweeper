src = *.cpp *.h

all: 
	g++ ${src} -o minesweeper.exe

run: 
	.\minesweeper.exe

clean: 
	del minesweeper.exe