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
  /**
  * @pre: verify input from user, and make sure the input for column is upper case.
  * @post: find the location that user input
  * @param: int row and char column
  * @return: char array
  **/
  char find(int row, char col); //will return the value of the board at the specified location (ex: find(3,C))
  void setShipCount(int numShips);

  void addShip(int numbShips);
  bool validCoordinate(std::string shipPosition, std::string shipDirection, int shipSize);

  int convertColumn(char col); // convert character to integer
  bool checkForWin();

private:
  const static int m_rows = 9;
  const static int m_cols = 9;
  char gameBoard[m_cols][m_rows];
  int m_shipCount = 0;
  std::vector<Ship> m_ships; //vector of the ship
  std::string shipDirection;
  std::string shipPosition;

  /**
  * @pre: valid player object exists
  * @post: changes all string to upper case
  * @param: std::string& word
  * @return: nothing
  **/
  void changeCase(std::string &word);
};
#endif /* Player_h */

//we will still need to deal with the placing of ships which will include constructing the ships by size and adding them to m_ships vector
