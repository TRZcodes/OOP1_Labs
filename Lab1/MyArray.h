#pragma once
class MyArray
{
public:
friend std::ostream& operator<<(std::ostream& o, const MyArray& a);
//konstruktor klasy MyArray, wypełniający tablice zerami
//@param s - długość tablicy
MyArray(int s);

//konstruktor kopiujący
//@param a - kopiowany obiekt klasy
MyArray(const MyArray& a);

//konstruktor przenoszący
//@param a - przenoszony obiekt klasy
MyArray(MyArray&& a);

//destruktor
~MyArray();

//operator przypisania =
//@param a -przypisywany obiekt klasy
MyArray& operator=(const MyArray& a);

//metoda size
int size() const;

//operator dostępu do elementów tablicy []
//@param i - iterator miejsca w tablicy
int operator[](int i);

//operator ++ inkrementujący wszystkie pola w tablicy
void operator++();

//metoda print
//@param text - nazwa wyświetlana przed wartościami tablicy
void print(std::string text);


private: 
int* _arr;
int _asize;
}

//operator wypisania na ekran <<
//@param o - dane wcześniej wypisywane przez cout
//@param a - obiekt klasy MyArray z którego wypisywane będą dane
std::ostream& operator<<(std::ostream& o, const MyArray& a);