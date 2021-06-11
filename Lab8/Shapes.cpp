#include "Shapes.h"

Point::Point(const Point& o)
{
  _x=o._x;
  _y=o._y;
}

std::ostream& operator<<(std::ostream& s, const Point& p)
{
  s<<"("<<p._x<<", "<<p._y<<")";
  return s;
}

void Circle::draw() const 
{
  std::cout<<"Rysujemy kolo o srodku "<<_center<<" i promieniu "<<_r<<std::endl;
}

double Circle::length() const 
{
  return 2*M_PI*_r;
}

void Circle::shift(double dx, double dy)
{
  _center._x+=dx;
  _center._y+=dy;
}

double Circle::area() const 
{
  return M_PI*_r*_r;
}

void Section::draw() const 
{
  std::cout<<"Rysujemy odcinek od "<<_p1<<" do "<<_p2<<std::endl;
}

double Section::length() const 
{
  return sqrt(pow(_p1._x-_p2._x,2)+pow(_p1._y-_p2._y,2));
}

void Section::shift(double dx, double dy)
{
  _p1._x+=dx;
  _p2._x+=dx;
  _p1._y+=dy;
  _p2._y+=dy;
}

void Deltoid::draw() const 
{
  std::cout<<"Rysujemy deltoid o wierzcholkach  "<<_p1<<", "<<_p2<<", "<<_p3<<", "<<_p4<<std::endl;
}

double Deltoid::length() const 
{
  Section s1(_p1,_p2);
  Section s2(_p2,_p3);
  Section s3(_p3,_p4);
  Section s4(_p4,_p1);
  return s1.length()+s2.length()+s3.length()+s4.length();
}

void Deltoid::shift(double dx, double dy)
{
  _p1._x+=dx;
  _p2._x+=dx;
  _p3._x+=dx;
  _p4._x+=dx;
  _p1._y+=dy;
  _p2._y+=dy;
  _p3._y+=dy;
  _p4._y+=dy;
}

double Deltoid::area() const
{
  Section d1(_p1,_p3);
  Section d2(_p2,_p4);

  return d1.length()*d2.length();
}

