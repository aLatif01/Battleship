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

void Player::fire(int row, char col)
{
  char location = find(row, col);
  if (location == 'F')
  {
    std::cout<<"Location is invalid "<<std::endl;
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
      if (m_ships[i].checkForHit(col, row) == true)
      {
        gameBoard[row][convertColumn(col)] = 'H'; //updates board
        if(m_ships[i].getLength() == 0)
        {
          m_shipCount--; //Decreases the ship count once the ship is erased from the vector
          std::cout << "You sunk a ship! \n";
          std::vector<int> shipCoords = m_ships[i].returnCoordinates()
          for(int i = 0; i < shipCoords.size(); i = i+2)
          {
            gameBoard[shipCoords[i]][shipCoords[i+1]] = 'X';
          }
        }

      }

    }
  }
}



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
    bool correctInput = false;
    while(correctInput == false)
    {

      std::cout << "Which direction would you like to place ship " << i <<"?\n REMINDER: SHIP LENGTH IS BASED ON SHIP NUMBER \n (Horizontal or vertical)\n >";
      std::cin >> shipDirection;
      changeCase(shipDirection);

      //asks user where bottom-most or left-most coordinate of his ship placement
      if(shipDirection == "HORIZONTAL")
      {
        std::cout << "What is the left-most position you would like your ship to be placed?\n >";
        std::cin >> shipPosition;
        changeCase(shipPosition);

        if(validCoordinate(shipPosition, shipDirection, i) == true) //this needs to check if ALL shipPosition are valid
        {
          correctInput = true;
          for(int i = 1; i <= numShips; i++)
          {
            gameBoard[convertColumn(shipPosition.at(0))][atoi(shipPosition.c_str())+i-1] = 'S';
          }
        }
        else
        {
          std::cout << "Sorry, invalid coordinate.\n";
          break;
        }
      }


      else if(shipDirection == "VERTICAL")
      {
        correctInput = true;
        std::cout << "What is the bottom-most position you would like your ship to be placed?\n >";
        std::cin >> shipPosition;
        changeCase(shipPosition);

        if(validCoordinate(shipPosition, shipDirection, i) == true)
        {
          correctInput = true;
          for(int i = 1; i <= numShips; i++)
          {
            gameBoard[convertColumn(shipPosition.at(0))+i-1][atoi(shipPosition.c_str())] = 'S';
          }
        }
        else
        {
          std::cout << "Sorry, invalid coordinate.\n";
          break;
        }
      }
      else
      {
        std::cout << "Please enter a valid ship direction\n";
      }

    } //end while loop
  } //end for loop
} //end addShip()

bool Player::validCoordinate(std::string shipPosition, std::string shipDirection, int shipSize)
{
  int goodCord = 0;
  if((shipPosition.at(0) == 'A' || shipPosition.at(0) == 'B' || shipPosition.at(0) == 'C' || shipPosition.at(0) == 'D' || shipPosition.at(0) == 'E' || shipPosition.at(0) == 'F' || shipPosition.at(0) == 'G' || shipPosition.at(0) == 'H') && (shipPosition.at(1) == '1' || shipPosition.at(1) == '2' || shipPosition.at(1) == '3' || shipPosition.at(1) == '4' || shipPosition.at(1) == '5' || shipPosition.at(1) == '6' || shipPosition.at(1) == '7' || shipPosition.at(1) == '8'))
  {
    if(shipDirection == "HORIZONTAL")
    {
      for(int i = 1; i <= shipSize; i++)
      {
        if(gameBoard[convertColumn(shipPosition.at(0))][atoi(shipPosition.c_str())+i-1] == '#')
        {
          goodCord++;
        }
      }
    }
    else if(shipDirection == "VERTICAL")
    {
      for(int i = 1; i <= shipSize; i++)
      {
        if(gameBoard[convertColumn(shipPosition.at(0))+i-1][atoi(shipPosition.c_str())] == '#')
        {
          goodCord++;
        }
      }
    }
  }
  else
  {
    return false;
  }
  if(goodCord == shipSize)
  {
    return true;
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
