/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/

#ifndef COOKIE_H
#define COOKIE_H
#include "SweetItem.h"
#define NUM_OF_TYPES 5
//prices
#define SoftChocolateChipCookiesPrice 1.0f
#define VanillaWafersCookiesPrice 2.0f
#define FruitFilledCookiesPrice 3.0f
#define NutCookiesPrice 4.0f
#define ChocolateCookiesPrice 5.0f
class Cookie :
	virtual public SweetItem
{
public:
	Cookie(const int& = ZERO, const int& = TWO);
	Cookie(const Cookie&);
	virtual SweetItem& operator=(const SweetItem&);
	virtual ~Cookie(){}
	virtual void Print(ostream&)const;
	void setCost();
	int setAmount(const int&);
	void setType(const int& = ZERO);
	virtual float getTotalPrice()const;
	//return cost of one cookie
	virtual const float& getCost()const { return cost; }
	//return amount of cookies
	virtual const unsigned int& getAmount()const{ return amount; }
	//return typr of cookie
	virtual const String& getType()const{ return type; }
	static const String& getType(const int&);
	virtual void input(istream&);
	float getPrice(const String&)const;
private:
	unsigned int amount;
	float cost;
	String type;
	static const String types[NUM_OF_TYPES];
};
#endif
