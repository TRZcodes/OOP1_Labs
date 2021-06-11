#pragma once

//klasa interfejsu rysowania
class Drawable 
{
  public:
    
    //destruktor wirtualny
    virtual ~Drawable()=default;

    //polimorficzna metoda wypisująca dane kształtu
    virtual void draw() const=0;

    //polimorficzna metoda wypisująca długość/obwód kształtu
    virtual double length() const 
    {
      return 0.0;
    }

    
};

class Transformable
{
  public:
    //destruktor wirtualny
    virtual ~Transformable()=default;

    //polimorficzna metoda przesuwająca w przestrzeni kształt o wektor <dx,dy>
    virtual void shift(double dx, double dy) = 0;
};

class ClosedShape
{
  public:
    //destruktor wirtualny
    virtual ~ClosedShape()=default;

    //polimorficzna metoda wypisująca pole powierzchni kształtu
    virtual double area() const=0;
};