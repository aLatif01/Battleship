#include "Player.h"
#include <limits>   //  i cant compile without these in WINDOW
using namespace std;


void isInt(int& checkInt)
{
  std::cin >> checkInt;

  while(std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "ERROR: Please enter an integer (1 - 5): ";
    std::cin >> checkInt;
  }
}
void isRow(int& checkRow)
{
  std::cin >> checkRow;

  while (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "ERROR: Please enter an integer (1 - 8): ";
    std::cin >> checkRow;
  }
}
void isColumn(char& checkColumn)
{
  std::cin >> checkColumn;

  while (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "ERROR: Please enter a letter (A - G): ";
    std::cin >> checkColumn;
  }
  toupper(checkColumn);//lower case input support should be covered by this
}
int main(int argc, const char* argv[])
{
  std::cout << "\n\nWelcome to Battleship!\n\n";
  int numberShips = 0;

  while(numberShips <= 0 || numberShips > 5)
  {
    std::cout << "How many ships do you want to play with (1 - 5)? ";
    isInt(numberShips);
  }

  Player player1;
  player1.createBoard();
  //have player one set their ships using addShip(numberShips)
  //do all this again for player 2

  //ships are now set, so begin letting players fire onto the other player's board
  //after each fire, you call playerx.checkForWin() and if it returns true then print game over (and which player won) and return
  bool gameOver = false;
  int row;
  char column;
  while (!gameOver)
  {
    player1.printBoard();
    row = 0;
    while (row <= 0 || row > 8)
    {
      std::cout << "Player 1, which row will you fire at (1 - 8)?";
      isRow(row);
    }
    column = 'Z';
    while (column!='A'&&column!='B'&&column!='C'&&column!='D'&&column!='E'&&column!='F'&&column!='G')
    {
      std::cout << "Player 1, which column will you fire at (A - G)?";
      isColumn(column);
    }
    player1.fire(row, column);
    if(player1.checkForWin())
    {
      gameOver = true;
      std::cout << "\n\n Player 1 sunk all of Player 2's battleships! Player 1 wins!";
      break;
    }
    row = 0;
    column = 'Z';
    player2.printBoard();
    while (row <= 0 || row > 8)
    {
      std::cout << "Player 2, which row will you fire at (1 - 8)?";
      isRow(row);
    }
    column = 'Z';
    while (column!='A'&&column!='B'&&column!='C'&&column!='D'&&column!='E'&&column!='F'&&column!='G')
    {
      std::cout << "Player 2, which column will you fire at (A - G)?";
      isColumn(column);
    }
    player2.fire(row, column);
    if(player2.checkForWin())
    {
      gameOver = true;
      std::cout << "\n\n Player 2 sunk all of Player 1's battleships! Player 2 wins!";
    }
  }

  //TESTS:
<<<<<<< HEAD
  /*
  player1.fire(1, 'E');
=======
  /*player1.fire(1, 'E');
>>>>>>> e97d8878cb3a333ec14bd1a3b63acca7fc6ffb8f
  player1.fire(2, 'E');
  player1.fire(3, 'E');
  player1.fire(4, 'E');
  player1.fire(5, 'E');
  player1.fire(6, 'E');
  player1.fire(7, 'E');
  player1.fire(8, 'E');
<<<<<<< HEAD
  player1.printBoard();
  */
=======
  player1.printBoard();*/

>>>>>>> e97d8878cb3a333ec14bd1a3b63acca7fc6ffb8f



  //each "shot" will call the fire function (example: player1.fire(guessRow, guessColumn);)

  return 0;
}
