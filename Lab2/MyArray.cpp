#include "MyArray.h"

MyArray::MyArray(const int size)
{
  _size=size;
  _tab=new int[_size];
  _next=nullptr;
}

MyArray::MyArray(MyArray& o)
{
  _size=o._size;
  _next=o._next;
  _tab=new int[_size];
  for(int i=0;i<_size;i++)
  {
    _tab[i]=o._tab[i];
  }
}

MyArray::MyArray(MyArray&& o)
{
  _size=std::__exchange(o._size,0);
  _tab=std::__exchange(o._tab,nullptr);
  _next=std::__exchange(o._next,nullptr);
}

MyArray::~MyArray()
{
  delete[] _tab;
  _size=0;
  delete _next;
}

int& MyArray::operator[](int n)
{
  MyArray* temp=this;
  while(n>=_size&&temp->_next!=nullptr)
  {
    n-=_size;
    temp=temp->_next;
  }
  return temp->_tab[n];
}

int MyArray::operator[](const int n) const
{
  return _tab[n];
}

MyArray MyArray::operator++()
{
  for(int i=0;i<_size;i++)
  {
    _tab[i]++;
  }
  return *this;
}

MyArray MyArray::operator--(int x)
{
  MyArray temp =*this;
  for(int i=0;i<_size;i++)
  {
    _tab[i]--;
  }
  return temp;
}

MyArray& MyArray::operator=(const MyArray& o)
{
  if(this==&o)
    return *this;
  else
  {
    _size=o._size;
    _next=o._next;
    delete[] _tab;
    _tab=new int[_size];
    for(int i=0;i<_size;i++)
    {
      _tab[i]=o._tab[i];
    }
  }
  return *this;
}

MyArray& MyArray::operator+=(MyArray& o)
{
  MyArray* temp= this;
  while(temp->_next!=nullptr)
  {
    temp=temp->_next;
  }
  temp->_next=&o;
  return *this;
}

MyArray& MyArray::operator+=(MyArray&& o)
{
  _size+=o._size;
  int temp[_size];
  for(int i=0;i<_size;i++)
  temp[i]=_tab[i];
  int tempsize=_size;
  _size+=o._size;
  delete[] _tab;
  _tab= new int[_size];
  for(int i=tempsize;i<_size;i++)
  {
    _tab[i]=o._tab[i-tempsize];
  }
  
  return *this;
}

void MyArray::print(std::string s) const
{
  const MyArray* temp=this;
  std::cout<<s;
  while(temp->_next!=nullptr)
  {
    std::cout<<*temp<<" ";
    temp=temp->_next;
  }
  std::cout<<*temp;
}

MyArray& MyArray::getNext()
{
  return *_next;
}

int MyArray::size() const
{
  return _size;
}

int MyArray::sizeall() const
{
  int sum=0;
  const MyArray* temp= this;
  while(temp->_next!=nullptr)
  {
    sum+=temp->_size;
    temp=temp->_next;
  }
  sum+=temp->_size;
  return sum;
}

std::ostream& operator<<(std::ostream& out, const MyArray& o)
{
  if(o._size)
  {
    std::cout<<"[";
    for(int i=0;i<o._size;i++)
    {
      std::cout<<o._tab[i]<<", ";
    }
    std::cout<<"]";
  }
  return out;
}
