#include "Player.h"
#include<iostream>

Player::Player()
{

}

void Player::createBoard()
{
  for(int x = 0; x <= m_rows; x++)
  {
    for(int y = 0; y <= m_cols; y++)
    {
      gameBoard[x][y] = 0; //BLANK BOARD SPACE
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

char Player::find(int row, char col) //will return the value of the board at the specified location (ex: find(3,C))
{
  //to do fhadsjklsfdsjkl

  if (row >= 1 && row < 9)
  {
    if(col == 'A' || col == 'B' || col == 'C' || col == 'D' || col == 'E' || col == 'F' || col == 'G' || col == 'H')
    {
        if(col == 'A')
        {
            return (gameBoard[row][0]);
        }

        if(col == 'B')
        {
            return (gameBoard[row][1]);
        }

        if(col == 'C')
        {
            return (gameBoard[row][2]);
        }

        if(col == 'D')
        {
            return (gameBoard[row][3]);
        }

        if(col == 'E')
        {
            return (gameBoard[row][4]);
        }

        if(col == 'F')
        {
           return (gameBoard[row][5]);
        }

        if(col == 'G')
        {
            return (gameBoard[row][6]);
        }

        if(col == 'H')
        {
            return (gameBoard[row][7]);
        }
      }
    }
}



void Player::fire(int row, char col)
{
  char location = find(row, col);
  if (location == '#')
  {
    std::cout << "You have missed at location " << row << col << "\n";
    return;
  }
  else if(location == 'M')
  {
    std::cout << "You already missed at location " << row << col <<'\n';
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
