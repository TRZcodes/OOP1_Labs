#pragma once
#include "Object.h"
#include<vector>


class Dir final: public Object
{
  public:
  Dir(const char* name):Object(name)
  {}


  std::ostream& print(std::ostream& s,int spaces) const override;

  Object* get(const char* name) override;

  void copy(Object* o);

  Dir* getDir(const char* name);

  Dir& operator+=(Object* o);

  Dir& operator-=(const char* name);

  protected:
  std::vector<Object*> _tab;
};