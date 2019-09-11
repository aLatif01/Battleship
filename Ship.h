#ifndef Ship_h
#define Ship_h
#include <utility>
#include<iostream>

class Ship
{
public:
  Ship(int length);
  int getLength();
  void addCoordinate(int row, char col);
  bool checkForHit(int row, char col);

private:
  int m_shipLength = 0;
  std::vector<pair<int,char>> m_pairs; //this is a list of ordered pairs
};
#endif /* Player_h */
