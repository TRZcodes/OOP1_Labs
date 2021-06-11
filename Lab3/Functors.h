#pragma once 
#include <iostream>

//klasa przechowująca funktory DivisibleBy oraz LowerThan
class Functors{
public:
//konstruktor domyślny klasy Functors
Functors()=default;

//destruktor
~Functors()=default;

class DivisibleBy
{
  public:

  //konstruktor domyślny klasy DivisibleBy
  DivisibleBy()=default;

  /*konstruktor klasy DivisibleBy przyjmujący argument 
  *@param x argument funkcji a%x (reszty z dzielenia)
  */
  DivisibleBy(int x):_arg(x)
  {};

  //destruktor
  ~DivisibleBy()=default;

  /*nadpisanie operatora () zwracające "poprawność" stwierdzenia x podzielne przez _arg
  *@param x przyjmowany argument x*/
  bool operator()(int x)
  {
    return(x%_arg?false:true);
  }

  private: 
  //argument x funkcji a%x (reszty z dzielenia)
  int _arg;
};

class LowerThan
{
  public:
  //konstruktor domyślny klasy LowerThan
  LowerThan()=default;

  /*konstruktor klasy LowerThan przyjmujący argument 
  *@param x argument funkcji a<x 
  */
  LowerThan(int x): _arg(x)
  {};

  //destruktor
  ~LowerThan()=default;

  /*nadpisanie operatora () zwracające "poprawność" stwierdzenia x<_arg
  *@param x przyjmowany argument x*/
  bool operator()(int x)
  {
    return x<_arg?true:false;
  }

  private:
  //argument x funkcji a<x 
  int _arg;
};
};