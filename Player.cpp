#include "Player.h"
#include<iostream>
Player::Player()
{
  shipDirection = "";
  shipPosition = "";
}

void Player::createBoard()
{
  for(int x = 1; x < m_rows; x++)
  {
    for(int y = 1; y < m_cols; y++)
    {
      gameBoard[x][y] = '#'; //BLANK BOARD SPACE
    }
  }
  gameBoard[1][4] = 'S';
  gameBoard[2][4] = 'S';
  gameBoard[3][4] = 'S';
}

void Player::printBoard()
{
  int rowLabel = 1;
  std::cout << "\tA\tB\tC\tD\tE\tF\tG\tH\n"; //COLUMN LABELS

  for(int x = 1; x < m_rows; x++)
  {
    std::cout << rowLabel << "\t";
    rowLabel++;

    for(int y = 1; y < m_cols; y++)
    {
      std::cout << gameBoard[x][y] << "\t";
    }

    std::cout << std::endl;
  }
}

char Player::find(int row, char col) //will return the value of the board at the specified location (ex: find(3,C))
{
  //to do
  if (row >= 1 && row < 9)
  {
    if(col == 'A' || col == 'B' || col == 'C' || col == 'D' || col == 'E' || col == 'F' || col == 'G' || col == 'H')
    {
        if(col == 'A')
        {
            return (gameBoard[row][1]);
        }

        if(col == 'B')
        {
            return (gameBoard[row][2]);
        }

        if(col == 'C')
        {
            return (gameBoard[row][3]);
        }

        if(col == 'D')
        {
            return (gameBoard[row][4]);
        }

        if(col == 'E')
        {
            return (gameBoard[row][5]);
        }

        if(col == 'F')
        {
           return (gameBoard[row][6]);
        }

        if(col == 'G')
        {
            return (gameBoard[row][7]);
        }

        if(col == 'H')
        {
            return (gameBoard[row][8]);
        }
      }
      else
      {
        return 'F';
      }
    }
}


void Player::setShipCount(int numShips)
{
  m_shipCount = numShips;
}

void Player::fire(char col, int row)
{
  char location = find(row, col);
  if (location == 'F')
  {
    std::cout<<"Location is invalid "<<endl;
  }
  if (location == '#')
  {
    std::cout << "You have missed at location " << col << row << "\n";
    gameBoard[row][convertColumn(col)] = 'M'; // UPDATES BOARD
    return;
  }
  else if(location == 'M')
  {
    std::cout << "You already missed at location " << col << row <<'\n';
    return;
  }
  else if(location == 'S')
  {
    for(int i = 0; i < m_shipCount; i++)
    {
      if (m_ships[i].checkForHit(col, row) == true) {
        //We need to decrease the size of the vector by 1 each time they
        //hit so the length of the ship will eventually be 0.
        location = 'H';


        if(m_ships[i].getLength() == 0)
        {
          delete m_ships[i];
          m_shipCount--;
          std::cout << "You sunk a ship! \n";
        }
    }

  }
}
}

  // if(m_shipCount == 0)
  // {check for iwn true for//
  //   //print the win or loss message but we should do this
  //   // in a different function that only checks for this
  // }




bool Player::checkForWin()
{
  if(m_shipCount == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Player::addShip(int numShips)
{
  for(int i = 1; i <= numShips; i++)
  {
    //following code asks user in which direction he would like the ship to be placed
    //need to cross check with while loop that the user either entered HORIZONTAL or VERTICAL
    std::cout << "Which direction would you like to place ship " << i <<"?\n REMINDER: SHIP LENGTH IS BASED ON SHIP NUMBER \n (Horizontal or vertical)\n >";
    std::cin >> shipDirection;
    changeCase(shipDirection);

    //asks user where bottom-most or left-most coordinate of his ship placement
    if(shipDirection == "HORIZONTAL")
    {
      std::cout << "What is the left-most position you would like your ship to be placed?\n >";
      std::cin >> shipPosition;
      changeCase(shipDirection);
    }
    else if(shipDirection == "VERTICAL")
    {
      std::cout << "What is the bottom-most position you would like your ship to be placed?\n >";
      std::cin >> shipPosition;
      changeCase(shipDirection);
    }


    //gameBoard[row][colum] = 'S';
    //need to start updating board
    //this is where I need to user the variables shipDirection and shipPosition to place ships on a board
  }
}

void Player::changeCase(std::string &word)
{
    int length = 0;
    std::locale loc;
    length = word.length();
    std::string swap = word;
    for (int i = 0; i < length; i++)
    {
        char upper = toupper(word[i],loc);
        swap[i] = upper;
    }
    word = swap;
}

int Player::convertColumn(char col)
{
  int num = 0;
  if(col == 'A' || col == 'B' || col == 'C' || col == 'D' || col == 'E' || col == 'F' || col == 'G' || col == 'H')
  {
      if(col == 'A')
      {
        num = 1;
          return (num);
      }

      if(col == 'B')
      {
        num =2;
          return (num);
      }

      if(col == 'C')
      {
        num =3;
          return (num);
      }

      if(col == 'D')
      {
        num = 4;
          return (num);
      }

      if(col == 'E')
      {
        num = 5;
          return (num);
      }

      if(col == 'F')
      {
        num = 6;
         return (num);
      }

      if(col == 'G')
      {
        num = 7;
          return (num);
      }

      if(col == 'H')
      {
        num = 8;
          return (num);
      }
    }
}

