#pragma once
#include<iostream>
#include<vector>
#include<functional>

class List
{
  public:
  //konstruktor domyślny klasy List
  List()=default;

  /* konstruktor kopiujący
  *@param o kopiowany obiekt
  */
  List(const List& o);

  //destruktor
  ~List();

  /* nadpisanie operatora dostępu do elementu listy
  *@param n znacznik miejsca w liście
  */
  int& operator[](int n);

  /* nadpisanie operatora wyświetlania elementu listy
  *@param n znacznik miejsca w liście
  */
  int operator[](int n) const;

  /*procedura dodająca element do listy
  *@param x dodawana wartość
  */
  void insert(int x);

  /*procedura wyświetlania zawartości listy
  *@param str strumień poprzedzający liste
  */
  void print(std::string str) const;

  //procedura wyświetlania zawartości listy
  void print() const;

  /*funkcja filtrująca listę zależnie od parametru
  *@param fun funktor określający poprawność filtrowanych danych
  */
  List filter(std::function<bool(int)> fun);

  private:
  //vector "lista" wartości całkowitych
  std::vector<int> _list;
};