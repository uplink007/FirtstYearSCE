/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include "Cookielida.h"
#define BITUL 0.1f
//ctor
Cookielida::Cookielida(const int& cookie, const int& ice_cream)
	:Cookie(cookie), IceCream(ice_cream), cost((this->Cookie::getTotalPrice() + this->IceCream::getTotalPrice())*1.5f), amount(static_cast<int>(ONE))
{
	type += Cookie::getType();
	type +=String(" ")+=Cookie::getType();
}
//return the cost of the cookielida
const float& Cookielida::getCost()const{	
	return cost;
}
//print the chookielida ,recive ostream object
void Cookielida::Print(ostream& out)const{
	color(Light_Purple, Bright_White);
	out << "Cookielida: ";
	Cookie::Print(out);
	out << " and ";
	IceCream::Print(out);
	color();
}
//copy ctor
Cookielida::Cookielida(const Cookielida& other){
	*this = other;
}
//operator = for chookielida object
Cookielida& Cookielida::operator = (const Cookielida& other){
	Cookie::operator=(other);
	IceCream::operator=(other);
	type = other.type;
	cost = other.cost;
	return *this;
}
//control the input for cookielida object from user
void Cookielida::input(istream & in){
	int cookie;
	//choose cookie
	color(Light_Purple, Bright_White);//color
		cout << "What cookie would you like?(Default option is 1)" << endl;
		for (int i = 0; i < FIVE; i++){
			cout << i + 1 << "-" << Cookie::getType(i) << " cost " << Cookie::getPrice(Cookie::getType(i))*3.0 << endl;
		}
		do{
			color();
		in >> cookie;
		if (in.fail()){
			in.clear();
			String trash;
			in >> trash;
		}
	} while (in.fail());
		color(Light_Purple, Bright_White);//color
		//choose ice cream
	cout << "What Ice Cream ball would you like?(Default option is 1)" << endl;
	for (int i = 0; i < FIVE; i++){
		cout << i + 1 << "-" << IceCream::getType(i) << " cost " << IceCream::getPrice(IceCream::getType(i))*1.5 << endl;
	}
	int ice_cream;
	do{
		color();
	in >> ice_cream;
	if (in.fail()){
		in.clear();
		String trash;
		in >> trash;
	}
	} while (in.fail());
	Cookielida temp(--cookie, --ice_cream);//make 
	*this = temp;
}
//function that count how the amlat bitul
float Cookielida::bitul(){
		float sum = this->getCost()*BITUL;
		return sum;
}
