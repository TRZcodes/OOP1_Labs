#include "Operation.h"

//klasa obejmująca operacje dzielenia
class Division: public Operation
{
  public:
  /*
  *konstruktor dwuargumentowy przyjmujący dwie wartości
  *@param el1 - pierwsza wartość 
  *@param el2 - druga wartość
  */
  Division(double el1, double el2):Operation(el1,el2)
  {}

  //metoda wypisująca obecną operacje
  void print() const override
  {
    std::cout<<_tab[0]<<" / "<<_tab[1];
  }

  //funkcja zwracająca wartość danej operacji
  double eval() const override
  {
    return _tab[0]/_tab[1];
  }
};