#include "Operation.h"

Operation::Operation(double el1, double el2):_len(2)
{
  _tab=new double[2];
  _tab[0]=el1;
  _tab[1]=el2;
}

Operation::Operation(double* tab, int len):_len(len)
{
  _tab=new double[len];
  for(int i=0;i<len;i++)
  {
    _tab[i]=tab[i];
  }
}

Operation::~Operation()
{
  if(_tab!=nullptr)
    delete[] _tab;
}

void operator>>=(const std::string& s, const Operation& o)
{
  std::cout<<s<<" ";
  o.print();
  std::cout<<" "<<s<<std::endl;
}