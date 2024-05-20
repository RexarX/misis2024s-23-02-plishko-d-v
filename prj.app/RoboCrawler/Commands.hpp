#pragma once

#include <utility>
#include <fstream>

class ICommand
{
public:
  virtual void Execute(double& x, double& y) = 0;

  virtual std::pair<double, double>& GetDistance() = 0;
};

//Move commands

class IMoveCommand : public ICommand
{
public:
  virtual void Execute(double& x, double& y) override {};

  virtual std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoWest: public IMoveCommand
{
public:
  GoWest(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoEast: public IMoveCommand
{
public:
  GoEast(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoNorth: public IMoveCommand
{
public:
  GoNorth(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};

class GoSouth : public IMoveCommand
{
public:
  GoSouth(const double distance);

  void Execute(double& x, double& y) override;

  std::pair<double, double>& GetDistance() override { return m_Distance; }

private:
  std::pair<double, double> m_Distance;
};