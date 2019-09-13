#include "Player.h"
#include <limits>   //  i cant compile without these in WINDOW
using namespace std;
>>>>>>> QUIbranch

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


  player1.fire(1, 'E');
  player1.fire(2, 'E');
  player1.fire(3, 'E');
  player1.fire(4, 'E');
  player1.fire(5, 'E');
  player1.fire(6, 'E');
  player1.fire(7, 'E');
  player1.fire(8, 'E');




  player1.printBoard();


  for(int i = 0; i < numberShips; i++)
  {
    //call setShips() [AUSTIN] - direction & coordinates
  }

  //1. Player 1 determines number of ships to play with (FORCED VALID INPUT)
  //2. Player 1's board is created and they begin placing ships
  //      ENTER FOR-LOOP
  //3. Player 1 is prompted for direction of placement (vertical/horiztonal)
  //4. Player 1 is prompted for a coordinate of some end-point (left OR bottom) of ship
  //5. Player 1's input is passed into a function to verify if the placement is VALID or not,
  //    IF NOT VALID, then Player 1 is re-prompted for direction and coordinate
  //6. Once placement IS VALID, some other function places the ship on the correct player's BOARD and
  //    coordinates of that entire ship are stored with addCoordinate(row,col)
  //    ship is then added to PLAYER
  //7. Process repeats for number of ships Player 1 picked to play with
  //8. ship placement control swtiches to Player 2 and steps 2-7 are repeated.
  //9. THIS IS WHERE THE GAME BEGINS...




  //each "shot" will call the fire function (example: player1.fire(guessRow, guessColumn);)

  return 0;
}
