#include "Commands.hpp"

#include <iostream>

//Move commands

GoWest::GoWest(const double distance)
{
  m_Distance.first -= distance;
}

void GoWest::Execute(double& x, double& y)
{
  x += m_Distance.first;
}

GoEast::GoEast(const double distance)
{
  m_Distance.first += distance;
}

void GoEast::Execute(double& x, double& y)
{
  x += m_Distance.first;
}

GoNorth::GoNorth(const double distance)
{
  m_Distance.second += distance;
}

void GoNorth::Execute(double& x, double& y)
{
  y += m_Distance.second;
}

GoSouth::GoSouth(const double distance)
{
  m_Distance.second -= distance;
}

void GoSouth::Execute(double& x, double& y)
{
  y += m_Distance.second;
}
