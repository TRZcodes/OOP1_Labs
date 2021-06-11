#include "Operation.h"

//klasa obejmująca operacje sumowania listy elementów
class SumOfElements: public Operation
{
  public:
  /*
  *konstruktor dwuargumentowy przyjmujący wskaźnik na tablicę wartości oraz jej długość
  *@param tab - tablica wartości
  *@param len - długość tablicy
  */
  SumOfElements(double* tab, int len):Operation(tab,len)
  {}

  //metoda wypisująca obecną operacje
  void print() const override
  {
    if(_len>0)
    {
      std::cout<<_tab[0];
      for(int i=1;i<_len;i++)
        std::cout<<" + "<<_tab[i];
    }
  }

  //funkcja zwracająca wartość danej operacji
  double eval() const override
  {
    double val=0;
    for(int i=0;i<_len;i++)
      val+=_tab[i];
    return val;
  }
};