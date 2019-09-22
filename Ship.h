#ifndef Ship_h
#define Ship_h
#include <utility>
#include<iostream>
#include<vector>

class Ship
{
public:
  /**
  * @pre: valid ship object is created
  * @post: initializes shipLength and Vector Pairs for a ship
  * @param: int length - length of the ship
  * @return: nothing
  **/
  Ship(int length);

  /**
  * @pre: valid ship object exists
  * @post: returns length of a ship
  * @param: none
  * @return: integer length of ship
  **/
  int getLength();

  /**
  * @pre: valid row and column passed in
  * @post: returns length of a ship
  * @param: int col - column of coordinate
  * @param: int row - row of coordinate
  * @return: none
  **/
  void addCoordinate(int col, int row);

  /**
  * @pre: valid row and column passed in
  * @post: returns boolean value based on if hit or not
  * @param: int col - column of coordinate
  * @param: int row - row of coordinate
  * @return: boolean true/false of hit
  **/
  bool checkForHit(int col, int row);

  /**
  * @pre: boards exist and ship coordinates have been updated
  * @post: returns vector integer of coordinates
  * @param: none
  * @return: vector integer of coordinates
  **/
  std::vector<int> returnCoordinates();

private:
  int m_shipLength = 0;
  std::vector< std::pair<int,int> > m_pairs; //this is a list of ordered pairs
};
#endif /* Ship_h */
