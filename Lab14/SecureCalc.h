#pragma once
#include "Functions.h"

class SecureCalc
{
  public:
  //konstuktor i destruktor domyślny
  SecureCalc(){}
  ~SecureCalc(){}

  /*statyczna metoda obsługująca proces wyliczania wartości funkcji (zwraca wyjątek w przypadku argumentu niewłaściwego)
  *@param fun funkcja wyliczająca wartość
  *@param x argument funkcji*/
  static void run(const Functions& fun, double x);
};