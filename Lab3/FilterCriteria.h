#pragma once
#include<iostream>
#include<vector>
#include<functional>

class FilterCriteria
{
  public:

  //konstruktor domyślny klasy
  FilterCriteria()=default;
  
  //destruktor
  ~FilterCriteria()
  {
    _funV.clear();
  }

  /*funckja dostępu do elementu vectora funkcji
  *@param n znacznik miejsca w vectorze
  */
  std::function<bool(int)> get(int n)
  {
    return _funV[n];
  }

  /* procedura dodająca funkcję do vectora 
  *@param fun dodawana funkcja
  */
  void add(std::function<bool(int)> fun) 
  {
    _funV.push_back(fun);
  }

  //funkcja zwracająca długość vectora funkcji
  int size() const
  {
    return _funV.size();
  }

  private:
  //vector przechowujący funkcje
  std::vector<std::function<bool(int)>> _funV;

};