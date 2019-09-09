#ifndef Player_h
#define Player_h
#include<iostream>

class Player
{
public:
  Player();
  void createBoard();
  void printBoard();

private:
  const static int m_rows = 8;
  const static int m_cols = 8;
  char gameBoard[m_rows][m_cols];
};
#endif /* Player_h */
