#include "Player.h"

int main(int argc, const char* argv[])
{
  std::cout << "\n\nWelcome to Battleship!\n\n";

  int numberShips = 0;

  std::cout << "How many ships do you want to play with (1 - 5)? ";
  std::cin >> numberShips;

  bool correctInput = false;
  while(correctInput == false)
  {
    if(numberShips < 0 || numberShips > 5)
    {
      //insert code which will run the game here

      correctInput = true;
    }
    else
    {
      std::cout << "Sorry please enter the correct number of ships!\n"
    }
  }

  Player player1;
  player1.createBoard();
  player1.printBoard();

  //each "shot" will call the fire function (example: player1.fire(guessRow, guessColumn);)


  return 0;
}
