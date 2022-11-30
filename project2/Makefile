all: runMovies
	
	
runMovies: main.cpp movies.h movies.cpp
	g++ -std=c++11 -O0 -g main.cpp movies.h movies.cpp -o runMovies

clean:
	rm runMovies