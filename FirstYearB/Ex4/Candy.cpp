/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include "Candy.h"
//inisialzie string array of types
const String Candy::types[NUM_OF_TYPES] = { String("ChoopaChoops"), String("Caramel"), String("Chocolate"), String("GumWorms"), String("Kokus") };
//candy ctor
Candy::Candy(const int& _type, const int& _amount)
	:weight(setAmount(_amount))
{
	setType(_type);
	setCost();
}
//candy copy ctor
Candy::Candy(const Candy& other){
	*this = other;
}
//operator = for candy
SweetItem& Candy::operator=(const SweetItem& other){
	type = other.getType();
	cost = other.getCost();
	weight = other.getAmount();
	return *this;
}

//print candy function , get ostream object
void Candy::Print(ostream& out)const{
	color(Red, Bright_White);
	out << type << " " << weight << "g";
	color();
}
//set cost
void Candy::setCost(){
	cost = getPrice(this->type);
}
//set amoutn and return the value
int Candy::setAmount(const int& _amount)
{
	weight = _amount > ONE? _amount : ONE;
	return weight;
}

//set type,recive int for the string type array
void Candy::setType(const int& _type){
	type = _type >= ZERO&&_type < FIVE ? types[_type] : types[ZERO];
}
//return price for recived type in string
float Candy::getPrice(const String& name)const{
	if (name == "Caramel"){
		return CaramelPrice;
	}
	if (name == "Chocolate"){
		return ChocolatePrice;
	}
	if (name == "GumWorms"){
		return GumWormsPrice;
	}
	if (name == "Kokus"){
		return KokusPrice;
	}
	return ChoopaChoopsPrice;
}
//recive total cost of the object
float Candy::getTotalPrice()const{
	return (static_cast<float>(weight) / 1000)*cost;
}
//function that control the input ogf the object for the shop
void Candy::input(istream& in){
	color(Red, Bright_White);//set color
	cout << "What would you like?(Default option is 1)" << endl;
	//print types
	for (int i = 0; i < FIVE; i++){
		cout << i + 1 << "-" << types[i] << " cost " << getPrice(types[i]) << endl;
	}
	int _type, _weight;
	//cheack validation of user inupt
	do{
		color();
		in >> _type;
		if (in.fail()){
			in.clear();
			String trash;
			in >> trash;
		}
	} while (in.fail());
	color(Red, Bright_White);//set color
	cout << "How many gram?(Default amount 1g)" << endl;
	do{
		color();
		in >> _weight;
		if (in.fail()){
			in.clear();
			String trash;
			in >> trash;
		}
	} while (in.fail());
	//make the candy
	Candy temp(--_type, _weight);
	*this = temp;
}