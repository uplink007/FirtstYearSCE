/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include"CDate.h"
enum{JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
using namespace std;
CDate::CDate() //default ctor set curent date
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}
CDate::CDate(const int _day, const int _month, const int _year){//set date with parametrs sended
	bool flag;
	if (SetYear(_year)){
		if (SetMonth(_month)){
			if (SetDay(_day))
				flag = true;
			else
				flag = false;
		}
		else{
			flag = false;
		}
	}
	else{
		flag = false;
	}
	if (!flag){//if invalid date set to curent date
		cout << "Wrong input the Date was instalized to curent date!!! (" <<_day<<"/"<<_month<<"/"<<_year<<")"<< endl;
		CDate a;
		*this = a;
	}

}
void CDate::SetDate(int d, int m, int y){//set new date to a CDate object , if invalid set to curent date;
	CDate a(d, m, y);
	*this = a;
}
CDate::~CDate(){//destro object
}

bool CDate::SetDay(const int d){//set day , cheack if correct 
	if (d < 1 || d > (this->DayInMonth()))
		return false;
	else
		day = d;
	return true;

}
bool CDate::SetMonth(const int m ){//set month and check if correct

	if (m < JAN || m>DEC)
		return false;
	else
		month = m;
	return true;

}
bool CDate::SetYear(const int y){//set year and cheack if correct
	if (y < 1900)
		return false;
	else
		year = y;
	return true;
}
void CDate::PrintMonthName()const {//print month name of curetn object
	switch (month){
	case JAN:{
		cout << "January";
		break;
	}
	case FEB:{
		cout << "February";
		break;
	}
	case MAR:{
		cout << "March";
		break;
	}

	case APR:{
		cout << "April";
		break;
	}
	case MAY:{
		cout << " May";
		break;
	}
	case JUN:{
		cout << "June";
		break;
	}
	case JUL:{
		cout << "July";
		break;
	}
	case AUG:{
		cout << "August";
		break;
	}
	case SEP:{
		cout << "September";
		break;
	}
	case OCT:{
		cout << "October";
		break;
	}
	case NOV:{
		cout << "November";
		break;
	}
	case DEC:{
		cout << "December";
		break;
	}
	default:cout << "*WRONG*->Month" << endl;
	}
}

bool CDate::leap_year()const{//cheack if the year of curent object is leap_year
		if (GetYear() % 400 == 0){
			return true;
		}
		else{
			if (GetYear() % 4 == 0 && GetYear() % 100 != 0)
				return true;
		}
		return false;

}
bool CDate::leap_year(int y)const{//cheack if the year sended as a param is a leap_year
	CDate a;
	a.SetYear(y);
	return a.leap_year();
}
int  CDate::DayInMonth()const{//return the last day of the month of the curent object
	const int _1_3_5_7_8_10_12 = 31;
	const int _4_6_9_11 = 30;
	const int _leap_year = 29;
	const int _non_leap_year = 28;
		switch (month){
		case JAN:return _1_3_5_7_8_10_12;
		case FEB:{
			if (leap_year())
				return _leap_year;
			else
				return _non_leap_year;
		}
		case MAR:return _1_3_5_7_8_10_12;
		case APR:return _4_6_9_11;
		case MAY:return _1_3_5_7_8_10_12;
		case JUN:return _4_6_9_11;
		case JUL:return _1_3_5_7_8_10_12;
		case AUG:return _1_3_5_7_8_10_12;
		case SEP:return _4_6_9_11;
		case OCT:return _1_3_5_7_8_10_12;
		case NOV:return _4_6_9_11;
		case DEC:return _1_3_5_7_8_10_12;
		default:return -1;;
	}
}

void CDate::Next_Day()const{//Print the next day
	CDate next = *this;
	const int first_day = 1;
	if (day < this->DayInMonth()){
		next.SetDay(day + 1);
	}
	else{
		next.SetDay(1);
		if (month != DEC){
			next.SetMonth(month + 1);
		}
		else{
			next.SetDay(first_day);
			next.SetMonth(JAN);
			next.SetYear(year + 1);
		}
	}
	cout << next;
}

CDate::CDate(const String& str){
	bool flag2 = true;
	if (str.getLen() >= EIGHT){
		int temp[] = { 0,0,0 };
		for (int i = 0,j=0; i < str.getLen(); i++){
			if (str[i + 2] == '/'&&str[i]!='/'){
				temp[j] += (str[i] - '0')*TEN;
			}
			else if(str[i+1]=='/'){
				temp[j] += str[i] - '0';
			}
			else if(str[i]=='/'){
				j++;
			}
			if (j == TWO){
				bool flag = true;
				for (int k = i + ONE; k < str.getLen(); k++){
					if (str[k] - '0' < ZERO || str[k] - '0' >= TEN){
						flag = false;
					}
				}
				if (flag){
					*this=CDate(temp[ZERO], temp[ONE], (str[i + ONE] - '0') * 1000 + (str[i + TWO] - '0') * 100 + (str[i + THREE] - '0') * 10 + str[i + FOUR] - '0');
					i += 4;
					flag2 = false;
				}
			}
		}

	}
	if (flag2){
		*this = CDate();
	}
}

ostream& operator<<(ostream& out, const CDate& date){
	if (date.day&&date.month >= 10){
		out << date.day << '/' << date.month << '/' << date.year;
	}
	else {
		if (date.day >= 10 && date.month < 10){
			out << date.day << "/0" << date.month << "/" << date.year;
		}
		else{
			if (date.month >= 10 && date.day < 10){
				out << "0" << date.day << "/" << date.month << "/" << date.year;
			}
			else{
				out << "0" << date.day << "/0" << date.month << "/" << date.year;
			}
		}
	}
	return out;
}