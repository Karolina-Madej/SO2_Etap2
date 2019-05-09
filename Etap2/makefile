
main: Screen.o Ball.o Wall.o main.cpp
	g++ -std=c++11 Screen.o Ball.o Wall.o main.cpp -lncurses -pthread -fpermissive

Screen.o: Screen.cpp Screen.h
	g++  -c Screen.cpp -std=c++11 -lncurses -fpermissive

Ball.o: Ball.cpp Ball.h
	g++  -c Ball.cpp -std=c++11 -lncurses -fpermissive
Wall.o: Wall.cpp Wall.h
	g++  -c Wall.cpp -std=c++11 -lncurses -fpermissive

clean:
	rm -f *.o test
