Battleship: main.o Player.o
	g++ -g -std=c++11 -Wall main.o Player.o -o Battleship
main.o: main.cpp Player.h
	g++ -g -std=c++11 -Wall -c main.cpp
Player.o: Player.h Player.cpp
	g++ -g -std=c++11 -Wall -c Player.cpp
clean:
	rm *.o Battleship
