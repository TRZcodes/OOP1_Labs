#include "MyArray.h"

MyArray::MyArray(int s)
{
  _asize = s;
  _arr =new int[s];
  for(int i=0;i<s;i++)
    {
      _arr[i]=0;
    }
}


MyArray::MyArray(const MyArray& a)
{

}

MyArray::MyArray(MyArray&& a);


MyArray::~MyArray();


MyArray& MyArray::operator=(const MyArray& a);


int MyArray::size() const;


int MyArray::operator[](int i);


void MyArray::operator++();


void MyArray::print(std::string text);