all: game
	
	
game: main.cpp cards.cpp utility.cpp cards.h utility.h
	g++ -std=c++11 -O0 -g main.cpp cards.cpp utility.cpp cards.h utility.h -o game

clean:
	rm game