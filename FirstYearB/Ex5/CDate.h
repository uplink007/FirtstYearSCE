/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef CDATE_H
#define CDATE_H
#include<iostream>
#define EIGHT 8
#define TEN 10
using namespace std;
class CDate{
private:
	int day;
	int month;
	int year;
	void SetDay(const int _day);
	void SetMonth(const int _month);
	void SetYear(const int _year);
public:
	CDate();
	CDate(const CDate&);
	CDate(const int day, const int month, const int year);
	~CDate();
	CDate& operator=(const CDate&);
	int GetDay()const{ return day; }//inline return curent day
	int GetMonth()const{ return month; }//inline return curent month
	int GetYear()const{ return year; }//inline return curent year
	void PrintMonthName()const;
	bool leap_year()const;
	bool leap_year(int)const;
	int DayInMonth()const;
	void Next_Day()const;	
	void SetDate(int=1, int=1, int=2000);
	bool operator<(const CDate&)const;
	bool operator==(const CDate&)const;
	friend ostream& operator<<(ostream&, const CDate&);
	friend istream& operator>>(istream& in, CDate&);
};

ostream& operator<<(ostream& out, const CDate&);

istream& operator>>(istream& in, CDate&);










#endif