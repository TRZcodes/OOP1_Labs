#include "Table.h"


void PrintDate(const Data& data)
{
  std::cout<<data.get_day()<<":"<<std::setw(6);
  for(auto const &elem: data.get_vals())
    {
      std::cout<<elem<<std::setw(6);
    }
    std::cout<<std::endl;
}

bool colSort(const Data& d1, const Data& d2, int i)
{
  return d1.get_vals()[i]<d2.get_vals()[i];
}


void Table::print() const
{
  std::for_each(_dates.begin(),_dates.end(),PrintDate);
  std::cout<<std::endl;
}
void Table::operator+=(const Data& o)
{
  _dates.push_back(o);
  if(o.get_vals().size()<_min)
    _min=o.get_vals().size();
}

Table& Table::sort(int column)
{
  if(column>=int(_min))
  {
    std::cout<<"Indeks "<<column<<" nieprawidlowy!\n";
  }
  else
  {
    auto comp=std::bind(colSort,std::placeholders::_1,std::placeholders::_2,column);
    std::sort(_dates.begin(),_dates.end(),comp);
  }
  return *this;
}
Table& Table::sortBy(bool(*comp)(const Data&, const Data&))
{
  std::sort(_dates.begin(),_dates.end(),comp);
  return *this;
}