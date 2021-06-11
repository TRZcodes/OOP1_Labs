#include <iostream>
#include <cmath>
#include "Functions.h"

void Functions::setFunName(const std::string name)
{
  _funName=name;
}

std::string Functions::getFunName() const
{
  return _funName;
}




Asin::Asin()
{
  setFunName("arcsin");
}

double Asin::getValue(double x) const
{
  if(fabs(x)<1)
    return std::asin(x);
  else 
    throw std::domain_error("wrong argument of arcsin");
}

Log10::Log10()
{
  setFunName("log10");
}

double Log10::getValue(double x) const
{
  if(x>0)
    return std::log10(x);
  else 
    throw std::domain_error("wrong argument of log10");
}


DivideBy::DivideBy(double x)
{
  setFunName("DivideBy");
  _numerator=x;
}

double DivideBy::getValue(double x) const
{
  if(x!=0)
    return _numerator/x;
  else
    throw std::domain_error("divide by zero!");
}


