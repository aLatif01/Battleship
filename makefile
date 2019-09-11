Battleship: main.o Player.o Ship.o
	g++ -g -std=c++11 -Wall main.o Player.o Ship.o -o Battleship
main.o: main.cpp Player.h Ship.h
	g++ -g -std=c++11 -Wall -c main.cpp
Player.o: Player.h Player.cpp
	g++ -g -std=c++11 -Wall -c Player.cpp
Ship.o: Ship.h Ship.cpp
		g++ -g -std=c++11 -Wall -c Ship.cpp
clean:
	rm *.o Battleship
