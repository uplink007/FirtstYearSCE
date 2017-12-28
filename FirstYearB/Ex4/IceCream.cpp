/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include "IceCream.h"
//type array
const String IceCream::types[NUM_OF_TYPES] = { String("Vanilla Dream Ball"), String("Raspberry Ball"), String("Swis Chocolate Ball"), String("Pistachio Ball"), String("Coconut Ball") };
//ctro
IceCream::IceCream(const int& _type, const int& _amount)
	:amount(setAmount(_amount))
{
	setType(_type);
	setCost();
}
//copy ctor
IceCream::IceCream(const IceCream& other){
	*this = other;
}
//operator = for ice cream
SweetItem& IceCream::operator=(const SweetItem& other){
	type = other.getType();
	cost = other.getCost();
	amount = other.getAmount();
	return *this;
}
//print ice cream ,recive ostrea object
void IceCream::Print(ostream& out)const{
	color(Green, Bright_White);
	out << amount << " " << type ;
	color();
}
//set cost of one ice cream ball
void IceCream::setCost(){
	cost = getPrice(this->type);
}

//set amount of ice cream balls
int IceCream::setAmount(const int& _amount)
{
	amount = _amount > ZERO ? _amount : ONE;
	return amount;
}
//set type of ice cream , get int for the type array
void IceCream::setType(const int& _type){
	type = _type >= ZERO&&_type < FIVE ? types[_type] : types[ZERO];
}
//get price of the specificated type
float IceCream::getPrice(const String& name)const{
	if (name == "Raspberry Ball"){
		return RaspberryBallPrice;
	}
	if (name == "Swis Chocolate Ball"){
		return SwisChocolateBallPrice;
	}
	if (name == "Pistachio Ball"){
		return PistachioBallPrice;
	}
	if (name == "Coconut Ball"){
		return CoconutBallPrice;
	}
	return VanillaDreamPrice;
}

//return total price of the ice cream
float IceCream::getTotalPrice()const{
	return static_cast<float>(amount*cost);
}
//control input of the ice cream object from user
void IceCream::input(istream& in){
	color(Green, Bright_White);//set colors
	//ask
	cout << "What ice cream would you like?(Default option is 1)" << endl;
	for (int i = 0; i < FIVE; i++){
		cout << i + 1 << "-" << types[i] << " cost " << getPrice(types[i]) << endl;
	}
	int _type, _amount;
	//choose type
	do{
		color();//set colors
	in >> _type;
	if (in.fail()){
		in.clear();
		String trash;
		in >> trash;
	}
} while (in.fail());//valiuation cheack 
	color(Green, Bright_White);//set colors
	cout << "How many balls?(Default amount 1)" << endl;
	//choose amount
	do{
		color();//set colors
	in >> _amount;
	if (in.fail()){
		in.clear();
		String trash;
		in >> trash;
	}
} while (in.fail());//valiuation cheack 
	IceCream temp(--_type, _amount);
	*this = temp;
}

const String& IceCream::getType(const int& num){
	return types[num];
}