/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#include "SweetShop.h"
//ctor
SweetShop::SweetShop()
	:cust_length(ZERO), custs(NULL), sum(0)
{}

//dctro
SweetShop::~SweetShop()
{
	if (cust_length){
		for (int i = 0; i < cust_length; i++){
			delete custs[i];
		}
		delete[]custs;
	}
}

//function that control a day in the shop
void SweetShop::StartDay(const CDate& date){
	float max = 0;//max user buing value
	int user=0;//save the max user number in the array
	char a;//char for yes no inputs
	bool flag = true;//flag for correct input
	do{//loop for clients
			cout << "New client? Y-yes N-no" << endl;
			fflush(stdin);
			a = getchar();
			if (a >= 'a'&&a <= 'z'){
				a -= 'a' - 'A';
			}
			switch (a){//new customer
			case 'Y':{Customer** temp = new Customer*[cust_length+ONE];
				for (int i = 0; i < cust_length ; i++){//copy
					temp[i] = custs[i];
				}
				cout << "Enter name:" << endl;//get name
				String name;
				std::fflush(stdin);
				cin >> name;
				temp[cust_length ] = new Customer(name);//make a customer
				cin >> *temp[cust_length];//input customer
				float tempF = temp[cust_length]->end();//finish input and save max
				if (max < tempF){//compare
					user = cust_length;
					max = tempF;
				}
				sum += tempF;//add to total
				flag = true;
				cust_length++;//inc
				if (custs){
					delete[]custs;
				}
				custs = temp;
				break;
			}
			default:{
				if (a != 'N'){
					cout << "You cann't choose this option!!!" << endl << "Try again" << endl;
				}
			}
			}
		} while (a != 'N'&&flag);//end customer
	cout << fixed << std::setprecision(1);//fixed
	//last prints 
	float arr[FOUR] = { 0 };
	cout << "Sum of day:" << endl << "No customers : " << cust_length << endl << "Total Revenue: " << sum <<endl<< "Total sweets: " << SweetItem::NoSweets() << endl;
	if (custs){
		cout << "Best client:" << custs[user]->getName() << " client no " << user + ONE << " :  Total = " << max << endl;
		custs[user]->procent(arr, FOUR, max);//cal procents
		cout << "Candy:" << arr[ZERO] << "% Cookie:" << arr[ONE] << "% IceCream:" << arr[TWO] << "% Cookielida:" << arr[THREE] << "%" << endl;
	}
	else{
		cout << "There was no clients today!!! Total = " << max << endl;
	}
	cout << "See you tomorrow." << endl;
	//write to file
	ofstream endDay("SumShop.txt", ios::app);
	if (!endDay.is_open()){
		cerr << "File opening faild" << endl;
		exit(1);
	}
	endDay << date << " Total:" << max << endl;
	endDay.close();
}


