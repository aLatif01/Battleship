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
    }
}


void Player::fire(int row, char col)
{
  char location = find(row, col);
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

        if(shipDirection == "HORIZONTAL")
        {
          //m_ships[i].erase causes an error and im unsure what to do
          //erase automatically decreases the size
          m_ships.erase(m_ships.begin()+col);
        }
        else if(shipDirection == "VERTICAL")
        {
          //m_ships[i].erase causes an error and im unsure what to do
          //erase automaticall decreases the size
          m_ships.erase(m_ships.begin()+row);
        }
      }
        if(m_ships[i].getLength() == 0)
        {
          //Line below should be m_ship[i].clear().
          //However I'm getting the same error for erase
          m_ships.clear();
          m_shipCount--;
          std::cout << "You sunk a ship! \n";
        }
    }
    if(m_shipCount == 0)
    {
      //print the win or loss message but we should do this
      // in a different function that only checks for this
    }
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

        if(validCoordinate(shipPosition) == true)
        {
          correctInput = true;
          //update board
        }
        else
        {
          std::cout << "Sorry, invalid coordinate.\n";
          break;
        }
        //check if this is a valid shipPosition
      }
      else if(shipDirection == "VERTICAL")
      {
        correctInput = true;
        std::cout << "What is the bottom-most position you would like your ship to be placed?\n >";
        std::cin >> shipPosition;
        changeCase(shipPosition);

        if(validCoordinate(shipPosition) == true)
        {
          correctInput = true;
          //update board
        }
        else
        {
          std::cout << "Sorry, invalid coordinate.\n";
          break;
        }
        //gameBoard[shipPosition.at(0)][shipPosition.at(1)] = 'S';
      }
      else
      {
        std::cout << "Please enter a valid shipDirection\n";
      }

    }

    //need to start updating board
    //this is where I need to user the variables shipDirection and shipPosition to place ships on a board
  }
}

bool Player::validCoordinate(std::string shipPosition)
{
  if((shipPosition.at(0) == 'A' || shipPosition.at(0) == 'B' || shipPosition.at(0) == 'C' || shipPosition.at(0) == 'D' || shipPosition.at(0) == 'E' || shipPosition.at(0) == 'F' || shipPosition.at(0) == 'G' || shipPosition.at(0) == 'H') && (shipPosition.at(1) == '1' || shipPosition.at(1) == '2' || shipPosition.at(1) == '3' || shipPosition.at(1) == '4' || shipPosition.at(1) == '5' || shipPosition.at(1) == '6' || shipPosition.at(1) == '7' || shipPosition.at(1) == '8'))
  {
    return true;
  }
  else
  {
    return false;
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
