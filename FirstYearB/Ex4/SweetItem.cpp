/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include"SweetItem.h"
int SweetItem::ID = 0;
//ctor
SweetItem::SweetItem()
{ID++;}
//dctor
SweetItem::~SweetItem(){
	ID--;
}
//return number of maded sweets
int SweetItem::NoSweets(){
	return ID;
}
//operator output for all the sweet objects
ostream& operator<<(ostream& out, const SweetItem& sweet){
	sweet.Print(out);//virtual function for output
	return out;
}
//operator >> for all the sweet objects
istream& operator>>(istream& in, SweetItem& item){
	item.input(in);//virtual function for input
	return in;
}
//global function that control the color of text and background
void color(Color text,Color back){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text + back * 16);
}
