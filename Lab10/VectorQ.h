#pragma once
#include "Person.h"
#include "Persons.h"
#include<algorithm>
#include<functional>
#include<memory>
#include<vector>
#include<string>
#include<utility>
#include<map>


class VectorQ
{
  public:
  VectorQ()=default;

  void add(std::unique_ptr<Person> prsn);

  void print(std::string s) const;

  std::vector<Woman*> getWomen();

  void countNames();

  void haircut();

  void haircut(std::string name);

  void shave();

  void shave(std::string name);


  protected:
  std::vector<std::unique_ptr<Person>> _queue;
};