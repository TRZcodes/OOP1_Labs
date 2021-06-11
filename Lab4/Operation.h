#pragma once 
#include<iostream>
#include<cmath>
#include<string>

//klasa nadrzędna obejmująca operacje matematyczne na wartościach typu double: wypisywanie ich oraz zwracanie wartości
class Operation{
  public:
  /*
  *przeładowanie operatora >>= wypisujące operacje w formacie s o std
  *@param s - tekst wypisywany przed i po operacji
  *@param o - operacja 
  */
  friend void operator>>=(const std::string& s, const Operation& o);

  /*
  *konstruktor dwuargumentowy przyjmujący dwie wartości
  *@param el1 - pierwsza wartość 
  *@param el2 - druga wartość
  */
  Operation(double el1, double el2);

  /*
  *konstruktor dwuargumentowy przyjmujący wskaźnik na tablicę wartości oraz jej długość
  *@param tab - tablica wartości
  *@param len - długość tablicy
  */
  Operation(double* tab, int len);

  //destruktor
  virtual ~Operation();

  //metoda wypisująca obecną operacje
  virtual void print() const = 0;

  //funkcja zwracająca wartość danej operacji
  virtual double eval() const = 0;

  protected: 
  //tablica wartości 
  double* _tab;
  //długość tablicy
  int _len;
};