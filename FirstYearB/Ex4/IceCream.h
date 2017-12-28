/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef ICECREAM_H
#define ICECREAM_H
#include "SweetItem.h"
#define NUM_OF_TYPES 5
//prices
#define VanillaDreamPrice 2.0f
#define RaspberryBallPrice 4.0f
#define SwisChocolateBallPrice 6.0f
#define PistachioBallPrice 8.0f
#define CoconutBallPrice 10.0f

class IceCream :
	virtual public SweetItem
{
public:
	IceCream(const int& = ZERO, const int& = ONE);
	IceCream(const IceCream&);
	virtual SweetItem& operator=(const SweetItem&);
	virtual ~IceCream(){}
	virtual void Print(ostream&)const;
	void setCost();
	int setAmount(const int&);
	void setType(const int& = ZERO);
	virtual float getTotalPrice()const;
	//return cost of one iceCream
	virtual const float& getCost()const { return cost; }
	//return amount of iceCream
	virtual const unsigned int& getAmount()const{ return amount; }
	//return typr of iceCream
	virtual const String& getType()const{ return type; }
	virtual void input(istream&);
	static const String& getType(const int&);
	float getPrice(const String&)const;
private:
	unsigned int amount;
	float cost;
	String type;
	static const String types[NUM_OF_TYPES];
};
#endif