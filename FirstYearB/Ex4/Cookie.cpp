/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include "Cookie.h"

const String Cookie::types[NUM_OF_TYPES] = { String("Soft Chocolate Chip Cookies"), String("Vanilla Wafers Cookies"), String("Fruit Filled Cookies"), String("Nut Cookies"), String("Chocolate Cookies") };
//ctor
Cookie::Cookie(const int& _type, const int& _amount)
	:amount(setAmount(_amount))
{
	setType(_type);
	setCost();
}

//print function .recive ostream by refarance
void Cookie::Print(ostream& out)const{
	color(Aqua, Bright_White);//set color
	out << amount << " " << type ;
	color();
}
//set cost
void Cookie::setCost(){
	cost = getPrice(this->type);
}
//set amount ,and return the value
int Cookie::setAmount(const int& _amount)
{
	amount = _amount > ZERO ? _amount : TWO;
	return amount;
}
//set type, get int number and set the type with the string array 
void Cookie::setType(const int& _type){
	type = _type >= ZERO&&_type < FIVE ? types[_type] : types[ZERO];
}
//recive the price for each type
float Cookie::getPrice(const String& name)const{
	if (name == "Vanilla Wafers Cookies"){
		return VanillaWafersCookiesPrice;
	}
	if (name == "Fruit Filled Cookies"){
		return FruitFilledCookiesPrice;
	}
	if (name == "Nut Cookies"){
		return NutCookiesPrice;
	}
	if (name == "Chocolate Cookies"){
		return ChocolateCookiesPrice;
	}
	return SoftChocolateChipCookiesPrice;
}

//recive the total price for the object
float Cookie::getTotalPrice()const{
	return static_cast<float>(amount*cost);
}
//copy ctor ,recive other cookie object
Cookie::Cookie(const Cookie& other){
	*this = other;

}

//operator = ,recive other sweet item
 SweetItem& Cookie::operator=(const SweetItem& other){
	 type = other.getType();
	 cost = other.getCost();
	 amount = other.getAmount();
	 return *this;
}
 //function that control the input of cookie from user
 void Cookie::input(istream& in){
	 color(Aqua, Bright_White);
	 cout << "What cokie would you like?(Default option is 1)" << endl;
	 for (int i = 0; i < FIVE; i++){
		 cout << i + 1 << "-" << types[i] << " cost " << getPrice(types[i]) << endl;
	 }
	 int _type, _amount;
	 do{
		 color();//set color to defalt
		 in >> _type;
		 if (in.fail()){
			 in.clear();
			 String trash;
			 in >> trash;
		 }
	 } while (in.fail());//cheack if cin failed
	 color(Aqua, Bright_White);
	 cout << "How many?(Default amount 2)" << endl;
	 do{//valiade input from user
		 color();
		 in >> _amount;
		 if (in.fail()){
			 in.clear();
			 String trash;
			 in >> trash;
		 }
	 } while (in.fail());
	 Cookie temp(--_type, _amount);
	 *this = temp;
 }

 //return the string from the array of types ,get the place of the type in the array
const String& Cookie::getType(const int& num){
	return types[num];
}