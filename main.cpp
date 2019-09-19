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
  player1.setShipCount(numberShips);
  player1.addShip(numberShips);
  //do all this again for player 2

  //ships are now set, so begin letting players fire onto the other player's board
  //after each fire, you call playerx.checkForWin() and if it returns true then print game over (and which player won) and return


  //TESTS:
  player1.fire(1, 'E');
  player1.fire(2, 'E');
  player1.printBoard();

  //each "shot" will call the fire function (example: player1.fire(guessRow, guessColumn);)

  return 0;
}
