#ifndef Ship_h
#define Ship_h
#include <utility>
#include<iostream>
#include<vector>

class Ship
{
public:
  Ship(int length);
  int getLength();
  void addCoordinate(int row, char col);
  bool checkForHit(int row, char col);

private:
  int m_shipLength = 0;
  std::vector<std::pair<int,char>> m_pairs; //this is a list of ordered pairs
};
#endif /* Player_h */
