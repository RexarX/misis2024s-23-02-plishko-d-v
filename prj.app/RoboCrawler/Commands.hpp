#pragma once

#include <utility>
#include <fstream>

class Command
{
public:
  virtual void Execute(double& x, double& y) = 0;

  virtual std::pair<double, double>& GetDistance() = 0;
};

//Move commands

class MoveCommand : public Command
{
public:
  virtual void Execute(double& x, double& y) override {};

  virtual std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoWest: public MoveCommand
{
public:
  GoWest(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoEast: public MoveCommand
{
public:
  GoEast(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoNorth: public MoveCommand
{
public:
  GoNorth(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoSouth : public MoveCommand
{
public:
  GoSouth(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};