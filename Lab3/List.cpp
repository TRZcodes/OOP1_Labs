#include "List.h"

List::List(const List& o)
{
  for(unsigned int i=0;i<o._list.size();i++)
  {
    _list.push_back(o._list[i]);
  }
}

List::~List()
{
  _list.clear();
}

int& List::operator[](int n)
{
  return _list[n];
}

int List::operator[](int n) const
{
  return _list[n];
}

void List::insert(int x)
{
  _list.push_back(x);
}

void List::print(std::string str) const
{
  std::cout<<str<<" [ ";
  for(unsigned int i=0;i<_list.size();i++)
  {
    std::cout<<_list[i]<<" ";
  }
  std::cout<<"]\n";
}

void List::print() const
{
  std::cout<<" [ ";
  for(unsigned int i=0;i<_list.size();i++)
  {
    std::cout<<_list[i]<<" ";
  }
  std::cout<<"]\n";
}

List List::filter(std::function<bool(int)> fun)
{
  List listf;
  
  for(unsigned int i=0;i<_list.size();i++)
  {
    if(fun(_list[i]))
    {
      listf.insert(_list[i]);
    }
  }
  return listf;
}