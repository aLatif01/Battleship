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

char find(int row, char col); //will return the value of the board at the specified location (ex: find(3,C))
{
  //to do
}

void Player::fire(int row, char col)
{
  char location = find(row, col);
  if (location == '#' || location == 'M') {
    std::cout << "No ship at location " << row << col <<'\n';
    return;
  }
  //if location is 'S', iterate through ships to find the hit point and allow that ship to account for the hit, then set location to '#'
  for(int i = 0; i < m_shipCount; i++)
  {
    if (m_ships[i].checkForHit(row, col) == true) {
      //to do in here: 
      //1. set location to '#',
      //2. check if m_ships[i].getLength() == 0 and if so then remove it from m_ships vector
      //3. check if m_ships is empty and, if so, game is over because all ships are
      //4. return;
    }
  }
}
