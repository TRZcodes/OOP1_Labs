#pragma once
#include<iostream>

class Object
{
  public: 
  friend std::ostream& operator<<(std::ostream& s, const Object& o);

  Object(const char* name):_name(name)
  {}

  virtual ~Object()
  {}

  std::string name() const
  {
    return _name;
  }

  virtual std::ostream& print(std::ostream& s,int spaces) const = 0;

  virtual Object* get(const char* name)=0;
  
  protected: std::string _name;
};

