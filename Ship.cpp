#include "Ship.h"
#include <algorithm>
#include <utility>
#include <vector>


Ship::Ship(int length)
{
  m_shipLength = length;
  std::vector<std::pair<int, int>> m_pairs;
}

int Ship::getLength()
{
  return m_shipLength;
}

void Ship::addCoordinate(int row, int col)
{
  std::pair<int,int> newPair;
  newPair.first = row;
  newPair.second = col;
  m_pairs.push_back(newPair);
}

bool Ship::checkForHit(int col, int row)
{
  for (int i = 0; i < m_pairs.size(); i++)
  {
    if(m_pairs[i].first == row && m_pairs[i].second == col)
    {
      m_shipLength--;
      return true;
    }
  }
  return false;
}

std::vector<int> Ship::returnCoordinates()
{
  std::vector<int> coords;
  for(int i = 0; i < m_pairs.size(); i++)
  {
    coords.push_back(m_pairs[i].first);
    coords.push_back(m_pairs[i].second);
  }
  return coords;
}
