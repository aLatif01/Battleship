#include "Player.h"

Player::Player()
{

}

void Player::createBoard()
{
  for(int x = 1; x <= m_rows; x++)
  {
    for(int y = 1; y <= m_cols; y++)
    {
      gameBoard[x][y] = '#'; //BLANK BOARD SPACE
    }
  }
}

void Player::printBoard()
{
  int rowLabel = 1;
  std::cout << "\tA\tB\tC\tD\tE\tF\tG\tH\n"; //COLUMN LABELS

  for(int x = 1; x <= m_rows; x++)
  {
    std::cout << rowLabel << "\t";
    rowLabel++;

    for(int y = 1; y <= m_cols; y++)
    {
      std::cout << gameBoard[x][y] << "\t";
    }

    std::cout << std::endl;
  }
}
