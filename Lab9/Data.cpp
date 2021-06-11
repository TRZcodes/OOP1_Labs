  #include "Data.h"
  
  void Data::print() const
  {
    std::cout<<_day<<":"<<std::setw(6);
    for(auto const &elem: _vals)
    {
      std::cout<<elem<<std::setw(6);
    }
    std::cout<<std::endl;
  }

  double Data::operator[](int i) const
  {
    return _vals[i];
  }

  std::string Data::get_day() const
  {
    return _day;
  }
  std::vector<double> Data::get_vals() const
  {
    return _vals;
  }