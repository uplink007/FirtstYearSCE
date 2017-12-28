/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef SWEETSHOP_H
#define SWEETSHOP_H
#include"Customer.h"
#include"CDate.h"
class SweetShop
{
public:
	SweetShop();
	~SweetShop();
	void StartDay(const CDate&);
private:
	int cust_length;
	Customer** custs;
	float sum;
};

#endif