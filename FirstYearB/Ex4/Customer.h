/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include"Candy.h"
#include"Cookielida.h"
#include<fstream>
#include <iomanip>
#define HANAHA 0.95f
class Customer
{
public:
	Customer(const String&);
	~Customer();
	Customer& operator+=(SweetItem*);
	bool operator!=(const SweetItem&);
	Customer& operator-=(const int&);
	float end();
	static void addToFile();
	float sum()const;
	friend ostream& operator<<(ostream & out, const Customer&);
	friend istream& operator>>(istream& in, Customer&);
	String getName()const;
	void procent(float*, int, float)const;
private:
	String name;
	SweetItem** buing_item;
	int serial;
	static int last_serial;
	int items()const;
};
ostream& operator<<(ostream & out, const Customer&);
istream& operator>>(istream& in, Customer&);
#endif
