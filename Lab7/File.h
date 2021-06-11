#pragma once
#include "Object.h"

class File:public Object
{
  public: 
  File(const char* name):Object(name)
  {}

  File(const char* name, int size):Object(name),_size(size)
  {}


  std::ostream& print(std::ostream& s,int spaces) const override
  {
    for(int i=0;i<spaces;i++)
    {
      s<<" ";
    }
    return s<<_name<<" ("<<_size<<") "<<std::endl;
  }

  Object* get(const char* name) override
  {
    if(_name==name) 
      return this;
    else
      return nullptr;
  }

  protected: 
  int _size=0;
};