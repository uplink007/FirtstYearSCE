/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include"SweetShop.h"

#include<iostream>
using namespace std;
int main(){
	String day;
	cout << "Good morning" << endl << "********************" << endl << "Enter day :"<<endl;
	cin >> day;
	SweetShop sweetShop;
	sweetShop.StartDay(day);
	return 0;
}