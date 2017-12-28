/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef COOKIELIDA_H
#define COOKIELIDA_H
#include "Cookie.h"
#include"IceCream.h"
class Customer;
class Cookielida :
	public Cookie,public IceCream
{
public:
	Cookielida(const int&  = ONE, const int& = ONE);
	Cookielida(const Cookielida&);
	Cookielida& operator=(const Cookielida&);
	virtual ~Cookielida(){}
	virtual void Print(ostream&)const;
	virtual const float& getCost()const;
	//return amount of cookielidas (allways one )
	virtual const unsigned int& getAmount()const{ return amount; }
	//return type of cookielida
	virtual const String& getType()const{ return type; }
	//return the cost of curent cookielida
	virtual float getTotalPrice()const{ return getCost(); }
	virtual void input(istream & );
	float Cookielida::bitul();

private:
	float cost;
	unsigned int amount;
	String type;
};
#endif

