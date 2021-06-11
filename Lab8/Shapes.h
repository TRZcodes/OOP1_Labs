#pragma once 
#include "Virtuals.h"
#include<iostream>
#include<cmath>

class Point
{
  public:
  /* zaprzyjaźniony operator wypisywania na ekran
  *@param s początkowy ciąg wypisywania
  *@param p obiekt klasy Point*/
  friend std::ostream& operator<<(std::ostream& s, const Point& p);

  /*konstruktor przyjmujący współrzędne punktu
  *@param x wsp_x
  *@param y wsp_y*/
  Point(const double x, const double y):_x(x),_y(y){}

  /*konstruktor kopiujący
  *@param o obiekt klasy Point*/
  Point(const Point& o);

  //współrzędne punktu
  double _x;
  double _y;
};

class Circle: public Drawable, public Transformable, public ClosedShape
{
  public:
  /*konstruktor przyjmujący punkt środka i dlugość promienia
  *@param p srodek-obiekt klasy Point
  *@param r dlugość promienia*/
  Circle(const Point& p, double r):_center(p),_r(r){}

  void draw() const override;

  double length() const override;

  void shift(double dx, double dy) override;

  double area() const override; 

  //środek i promien koła
  protected:
  Point _center;
  double _r;
};

class Section: public Drawable, public Transformable
{
  public:
  /*konstruktor przyjmujący punkty końcowe odcinka
  *@param p1 początek-obiekt klasy Point
  *@param p2 koniec-obiekt klasy Point*/
  Section(const Point& p1, const Point& p2):_p1(p1),_p2(p2){}

  void draw() const override;

  double length() const override;

  void shift(double dx, double dy) override;

  //początek i koniec odcinka
  Point _p1;
  Point _p2;
};

class Deltoid: public Drawable, public Transformable, public ClosedShape
{
  public:
  /*konstruktor przyjmujący punkty jako wierzcholki deltoidu
  *@param p1 obiekt klasy Point
  *@param p2 obiekt klasy Point
  *@param p3 obiekt klasy Point
  *@param p4 obiekt klasy Point*/
  Deltoid(const Point& p1, const Point& p2,const Point& p3,const Point& p4):_p1(p1),_p2(p2),_p3(p3),_p4(p4){}


  /*konstruktor przyjmujący przekątne deltoidu
  *@param diag1 obiekt klasy Section
  *@param diag2 obiekt klasy Section*/
  Deltoid(const Section& diag1, const Section& diag2):_p1(diag1._p1),_p2(diag2._p1),_p3(diag1._p2),_p4(diag2._p2){}

  void draw() const override;

  double length() const override;

  void shift(double dx, double dy) override;

  double area() const override; 

  //wierzcholki deltoidu
  protected:
  Point _p1;
  Point _p2;
  Point _p3;
  Point _p4;
};