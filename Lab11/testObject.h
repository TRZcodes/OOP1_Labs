#pragma once

//klasa obsługująca obiekt testowy przechowywany w naszym Vectorze
class TestObject
{
  public:  
  //konstruktor domyślny
  TestObject()=default;

  /*konstruktor jednoargumentowy
  *@param ID - numer ID utworzonego obiektu*/
  TestObject(int ID):_ID(ID){}

  //metoda wyświetlająca informacje o obiekcie
  void print() const
  {
    std::cout<<"Obiekt o indetyfikatorze ID="<<_ID<<std::endl;
  }

  /*setter wartości ID
  *@param ID - nowa wartość ID*/
  void set(int ID)
  {
    _ID=ID;
  }

  private:
  //numer ID obiektu
  int _ID;
};