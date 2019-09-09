#include "Ship.h"
#include <algorithm>
#include <utility>

Ship::Ship(int length)
{
  m_shipLength = length;
}

int Ship::getLength()
{
  return m_shipLength;
}

bool Ship::checkForHit(int row, char col)
{
  pair<int,char> checkPair;
  checkPair.first = row;
  checkPair.second = col;
  if(std::find(m_pairs.begin(), m_pairs.end(), checkPair) != m_pairs_end()) {
    //will enter this if statement if the pair is in the ships
    //we do NOT need to remove the specific element from the vector because this checkForHit function will
    //only be called if the space is 'S' and the space will be changed to '#' in Player.cpp right after this function finishes
    m_shipLength--;
    return true;
  }
  else {
    return false;
  }
}
