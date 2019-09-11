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
  void addCoordinate(int row, int col);
  bool checkForHit(int row, int col);
  void setShips(int numOfShips);

private:
  int m_shipLength = 0;
  std::vector<std::pair<int,int>> m_pairs; //this is a list of ordered pairs
};
#endif /* Ship_h */
