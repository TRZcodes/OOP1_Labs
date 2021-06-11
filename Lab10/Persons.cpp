#include "Persons.h"

Woman::~Woman()
{
  std::cout<<std::endl<<_name<<" "<<(_haircut==true?"nie":"")<<"obcieta i "<<(_makeup==true?"nie":"")<<"umalowana idzie na zakupy";
}

void Woman::print() const
{
  std::cout<<_name<<" "<<(_haircut==true?"nie":"")<<"obcieta i "<<(_makeup==true?"nie":"")<<"umalowana\n";
}

bool Woman::done() const
{
  if(_haircut==false&&_makeup==false)
    return true;
  return false;
}

void Woman::makeup()
{
  if(_makeup) _makeup=false;
}

Man::~Man()
{
  std::cout<<std::endl<<_name<<" "<<(_haircut==true?"nie":"")<<"obciety i "<<(_shave==true?"nie":"")<<"ogolony idzie na piwko";
}

void Man::print() const
{
  std::cout<<_name<<" "<<(_haircut==true?"nie":"")<<"obciety i "<<(_shave==true?"nie":"")<<"ogolony\n";
}

bool Man::done() const
{
  if(_haircut==false&&_shave==false)
    return true;
  return false;
}

void Man::shave()
{
  if(_shave) _shave=false;
}