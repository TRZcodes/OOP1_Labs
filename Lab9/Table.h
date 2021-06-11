#pragma once
#include "Data.h"
#include <functional>

//klasa operująca na obiektach typu Data
class Table
{
  protected:
  //wektor "dat"
  std::vector<Data> _dates;
  //najmniejsza ilość wartości w wektorze _vals ze wszystkich przechowywanych "dat"
  unsigned int _min;
  public:
  //konstruktor domyślny
  Table()
  {
    _min=1000;
  }
  //metoda wyświetlająca zawartość 
  void print() const;
  /*przeładowanie operatora += 
  *@param o obiekt Data dodawany do wektora _dates*/
  void operator+=(const Data& o);

  /* metoda sortująca rosnąco po wartościach w danej kolumnie
  *@param column wybrana kolumna wartości*/
  Table& sort(int column);

  /*metoda sortująca w zależności od przekazanego komparatora
  *@param comp komparator wartości*/
  Table& sortBy(bool(*comp)(const Data&, const Data&));
};

//funkcje pomocnicze
void PrintDate(const Data& data);
bool colSort(const Data& d1, const Data& d2, int i);