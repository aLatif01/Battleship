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

char Player::find(char col, int row) //will return the value of the board at the specified location (ex: find(3,C))
{
  //to do
  if (row >= 1 && row < 9)
  {
    if(col == 'A' || col == 'B' || col == 'C' || col == 'D' || col == 'E' || col == 'F' || col == 'G' || col == 'H')
    {
        if(col == 'A')
        {
            return (gameBoard[1][row]);
        }

        if(col == 'B')
        {
            return (gameBoard[2][row]);
        }

        if(col == 'C')
        {
            return (gameBoard[3][row]);
        }

        if(col == 'D')
        {
            return (gameBoard[4][row]);
        }

        if(col == 'E')
        {
            return (gameBoard[5][row]);
        }

        if(col == 'F')
        {
           return (gameBoard[6][row]);
        }

        if(col == 'G')
        {
            return (gameBoard[7][row]);
        }

        if(col == 'H')
        {
            return (gameBoard[8][row]);
        }
      }
    }
}



void Player::fire(char col, int row)
{
  char location = find(col, row);
  if (location == '#' || location == 'M') {
    std::cout << "No ship at location " << col << row <<'\n';
    return;
  }
  //if location is 'S', iterate through ships to find the hit point and allow that ship to account for the hit, then set location to '#'
  for(int i = 0; i < m_shipCount; i++)
  {
    if (m_ships[i].checkForHit(col, row) == true) {
      //to do in here:
      //1. set location to '#',
      //2. check if m_ships[i].getLength() == 0 and if so then remove it from m_ships vector
      //3. check if m_ships is empty and, if so, game is over because all ships are
      //4. return;
    }
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
