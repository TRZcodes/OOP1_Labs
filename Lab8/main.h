#pragma once
#include "Shapes.h"

/* Hierarchia klas:

Klasy Drawable, Transformable oraz ClosedShape-> klasy wirtualne (interfejsy) obsługujące odpowiednio "Rysowanie", przeniesienie w przestrzeni oraz obliczenie pola powierzchni.

Klasa Point->osobno istniejąca klasa punktu w przestrzeni, zawierana jest w klasach typu Shapes jako wierzcholki (lub srodek koła)

Klasy Shapes(Section, Circle, Deltoid)-> klasy dziedziczące po klasach interfejsowych dostosowujące ich działanie pod wybrany kształt*/


//uniwersalna funkcja rysująca
void draw(Drawable* o)
{
  o->draw();
}