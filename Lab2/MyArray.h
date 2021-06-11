#pragma once
#include<iostream>
#include<utility>

class MyArray
{
  public:
  friend std::ostream& operator<<(std::ostream& out, const MyArray& o);

  //konstruktor domyślny
  MyArray()=default;

  //konstruktor inicjowany z długością
  //@param size - długość tablicy
  MyArray(const int size);

  /*konstruktor kopiujący
  *@param o kopiowany obiekt*/
  MyArray(MyArray& o);
  
  /*konstruktor przenoszący
  *@param o przenoszony obiekt*/
  MyArray(MyArray&& o);

  //destruktor
  ~MyArray();

  /*operator [] zmiany wartości 
  *@param n miejsce w tablicy*/
  int& operator[](const int n);

  /*operator [] otrzymania wartości 
  *@param n miejsce w tablicy*/
  int operator[](const int n) const;

  //prein
  MyArray operator++();

  MyArray operator--(int x);

  MyArray& operator=(const MyArray& o);

  MyArray& operator+=(MyArray& o);

  MyArray& operator+=(MyArray&& o);

  void print(std::string s) const;

  MyArray& getNext();

  int size() const;

  int sizeall() const;

  private:
  int* _tab=nullptr;
  int _size=0;
  MyArray* _next=nullptr;
};

std::ostream& operator<<(std::ostream& out, const MyArray& o);