#include<iostream>
#include "SecureCalc.h"

void SecureCalc::run(const Functions& fun, double x)
{
  std::cout<<"Obliczamy "<<fun.getFunName()<<"("<<x<<")\n";

  try
  {
    double value=fun.getValue(x);
    std::cout<<"-> Wynik: "<<value<<std::endl;
  }
  catch(std::domain_error error)
  {
    std::cout<<"->Error: "<<error.what()<<std::endl;
  }
}