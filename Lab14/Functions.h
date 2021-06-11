#pragma once
#include <iostream>

class Functions
{
  public:
  //konstruktor domyślny
  Functions() {}
  //wirtualny destruktor
  virtual ~Functions()=default;

  //setter i getter nazwy funkcji 
  void setFunName(const std::string name);
  std::string getFunName() const;

  //getter wartości wyliczanej funkcji
  //@param x - argument funkcji
  virtual double getValue(double x) const = 0;

  private:
  std::string _funName;

};

class Asin : public Functions
{
  public:
  //konstruktor nadający nazwę funkcji
  Asin();
  ~Asin(){}

  //getter wartości wyliczanej funkcji
  //@param x - argument funkcji
  double getValue(double x) const override;
};

class Log10 : public Functions
{
  public:
  //konstruktor nadający nazwę funkcji
  Log10();
  ~Log10(){}

  //getter wartości wyliczanej funkcji
  //@param x - argument funkcji
  double getValue(double x) const override;
};

class DivideBy : public Functions
{
  public:
  //konstruktor nadający nazwę funkcji oraz ustawiający licznik w operacji dzielenia
  DivideBy(double x);
  ~DivideBy(){}


  //getter wartości wyliczanej funkcji
  //@param x - argument funkcji
  double getValue(double x) const override;
  
  private:
  double _numerator;
};