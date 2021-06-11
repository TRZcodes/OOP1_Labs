#include "Dir.h"
#include<typeinfo>
 
std::ostream& Dir::print(std::ostream& s,int spaces) const 
{
  for(int i=0;i<spaces;i++)
  {
    s<<" ";
  }
  s<<_name<<" (dir) "<<std::endl;

  for(int i=0;i<_tab.size();i++)
  {
    _tab[i]->print(s,spaces+2);
  }
  return s;
}

Object* Dir::get(const char* name) 
{
  if(_name==name)
    return this;

  for(int i=0;i<_tab.size();i++)
  {
    if(_tab[i]->get(name))
      return _tab[i]->get(name);
  }

  return nullptr;
}

Dir& Dir::operator+=(Object* o)
{
  _tab.push_back(o);
  return *this;
}

Dir& Dir::operator-=(const char* name)
{
  Object* temp=nullptr;

  for(int i=0;i<_tab.size();i++)
  {
    if(_tab[i]->name()==name)
    {
      temp=_tab[i];
      _tab.erase(_tab.begin()+i);
    }
  }

  if(temp!=nullptr)
    delete temp;

  return *this;
}

void Dir::copy(Object* o)
{
  *this+=o;
}

Dir* Dir::getDir(const char* name)
{
  if(get(name))
    return (Dir*)get(name);
  else
    return nullptr;  
}

