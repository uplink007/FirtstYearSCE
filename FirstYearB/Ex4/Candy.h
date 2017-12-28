/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/

#ifndef CANDY_H
#define CANDY_H
#include "SweetItem.h"
#define NUM_OF_TYPES 5
//prices
#define ChoopaChoopsPrice 10.0f
#define CaramelPrice 20.0f
#define ChocolatePrice 30.0f
#define GumWormsPrice 40.0f
#define KokusPrice 50.0f


class Candy :
	public SweetItem
{
public:
	Candy(const int& = ZERO,const int& = ZERO );
	Candy(const Candy&);
	virtual SweetItem& operator=(const SweetItem&);
	virtual ~Candy(){}//dector
	virtual void Print(ostream&)const;
	void setCost();
	int setAmount(const int&);
	void setType(const int& =ZERO);
	virtual float getTotalPrice()const;
	//return cost of 1kg for the curent type
	virtual const float& getCost()const { return cost; }
	//return weight
	virtual const unsigned int& getAmount()const{ return weight; }
	//return type
	virtual const String& getType()const{return type;}
	virtual void input(istream&);
private:
	unsigned int weight;
	float cost;
	String type;
	static const String types[NUM_OF_TYPES];//types in string
	float getPrice(const String&)const;
};

#endif