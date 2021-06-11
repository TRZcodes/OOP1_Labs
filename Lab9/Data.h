#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<numeric>
#include<cmath>

//klasa przechowująca dzien i wartosci typu double
class Data
{
  protected:
  //nazwa dnia
  std::string _day;
  //vector wartosci typu double
  std::vector<double> _vals;
  public:
  /*konstruktor przyjmujący nazwe dnia i vector wartości
  *@param day nazwa dnia
  *@param vals vector wartości*/
  Data(std::string day,std::vector<double> vals):_day(day),_vals(vals){}

  //metoda wyświetlająca zawartość
  void print() const;
  /*przeładowanie operatora dostępu
  *@param i miejsce w wektorze wartości*/
  double operator[](int i) const;
  //gettery
  std::string get_day() const;
  std::vector<double> get_vals() const;
};