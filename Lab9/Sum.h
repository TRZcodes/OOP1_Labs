#pragma once
#include "Data.h"

//klasa obslugujaca sumowanie wartosci double w klasie date
class Sum
{
  protected:
  //suma wartosci
  double _sum;
  public:
  //konstruktor domyślny
  Sum():_sum(0){}
  /*konstruktor przyjmujący wartość sumy
  *@param sum wartość sumy*/
  Sum(double sum):_sum(sum){}
  
  /*przeładowanie operatora ()
  *@param x wartość dodawana do sumy*/
  void operator()(double x)
  {
    _sum+=x;
  }

  //getter
  double value() const
  {
    return _sum;
  }
};

//funkcja zewnętrzna przyjmująca obiekt typu Data
//zwraca obiekt sumy typu Sum
Sum sumData(const Data& date)
{
  Sum suma;
  for (unsigned int i=0;i<date.get_vals().size();i++)
    suma(date[i]);
  return suma;
}