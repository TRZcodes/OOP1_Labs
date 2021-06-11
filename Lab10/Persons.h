#pragma once
#include "Person.h"

class Woman: public Person
{
  public: 
  Woman(std::string name, bool hair = true, bool makeup = true):Person(name,hair,false),_makeup(makeup){}

  ~Woman();

  void print() const override;
  bool done() const override;
  void makeup() override;
  void shave() override
  {}

  protected:
  bool _makeup; 

};

class Man: public Person
{
  public: 
  Man(std::string name, bool hair = true, bool shave = true):Person(name,hair,true),_shave(shave){}

  ~Man();

  void print() const override;
  bool done() const override;
  void shave() override;
  void makeup() override
  {}

  protected:
  bool _shave; 

};