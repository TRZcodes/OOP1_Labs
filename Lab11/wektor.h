#pragma once
#include <iostream>
#include "testObject.h"

//klasa Vector przechowująca różne typy danych w formie tablicy
class Vector
{
  public:
  
  /*szablon funkcji inicjalizującej nowy wektor
  *@tparam T - typ obiektu przechowywanego przez wektor
  *@param size - rozmiar wektora*/
  template<typename T>
  static void initialise(T size)
  {
    _size=size;
    _vec= new T[_size];
  }

  /*szablon funkcji inicjalizującej nowy wektor
  *@tparam T - typ obiektu przechowywanego przez wektor
  *@param size - rozmiar wektora
  *@param obj - obiekt typu T, przypisywany do każdego elementu wektora*/
  template<typename T>
  static void initialise(const int size, T obj)
  {
    _size=size;
    _vec=new T[_size];
    for(int i=0;i<_size;i++)
    {
      static_cast<T*>(_vec)[i]=obj;
    }
  }

  /*szablon funkcji zwracającej referencję elementu wektora
  *@tparam T - typ obiektu przechowywanego przez wektor
  *@param n - pozycja w wektorze szukanego elementu
  *@return referencja na element wektora*/
  template<typename T>
  static T& at(int n)
  {
    return static_cast<T*>(_vec)[n];
  }
  
  /*szablon funkcji usuwającej z pamięci wektor
  *@tparam T - typ obiektu przechowywanego przez wektor*/
  template<typename T>
  static void reset()
  {
    if(_vec!=nullptr)
    {
      delete[] static_cast<T*>(_vec);
      _vec=nullptr;
    }
  }

  //getter rozmiaru wektora
  static int size()
  {
    return _size;
  }

  protected:
  //rozmiar wektora
  static int _size;
  //wskaźnik na początek wektora
  static void* _vec;
};

//przyjęcie wartości początkowych zmiennych statycznych
int Vector::_size=0;
void* Vector::_vec=nullptr;