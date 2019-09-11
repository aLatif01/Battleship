#ifndef Player_h
#define Player_h
#include <utility>
#include<iostream>
#include "Ship.h"

class Player
{
public:
  Player();
  void createBoard();
  void printBoard();
  void fire(int row, char col);
  char find(int row, char col); //will return the value of the board at the specified location (ex: find(3,C))
  void setShipCount(int numShips);

private:
  const static int m_rows = 8;
  const static int m_cols = 8;
  char gameBoard[m_rows][m_cols]; //int,chars
  int m_shipCount = 0;
  std::vector<Ship> m_ships; //vector of the ship
};
#endif /* Player_h */

//we will still need to deal with the placing of ships which will include constructing the ships by size and adding them to m_ships vector
