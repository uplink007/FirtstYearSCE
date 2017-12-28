/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef SWEETITEM_H
#define SWEETITEM_H
#include<iostream>
#include"String.h"
#include"windows.h"
enum Color{Black,Blue,Green,Aqua,Red,Purple,Yellow,White,Gray,Light_Blue,Light_Green,Light_Aqua,Light_Red,Light_Purple,Light_Yellow,Bright_White};
using namespace std;
class SweetItem{
private:
	static int ID;
public:
	SweetItem();
	virtual ~SweetItem();
	static int NoSweets();
	//pure function of abstract class
	virtual void Print(ostream& =std::cout)const = 0;
	virtual const float& getCost()const = 0;
	virtual const unsigned int& getAmount()const = 0;
	virtual const String& getType()const = 0;
	virtual float getTotalPrice()const = 0;
	virtual void input(istream & = std::cin) = 0;
};
ostream& operator<<(ostream&, const SweetItem&);
istream& operator>>(istream&, SweetItem& );
void color(Color text = Black ,Color Back = Bright_White);
#endif