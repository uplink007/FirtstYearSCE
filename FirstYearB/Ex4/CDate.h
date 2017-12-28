/*
Assignment: 4
Campus: Beer-Sheva
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015
*/
#ifndef CDATE_H
#define CDATE_H
#include"String.h"
#define EIGHT 8
#define TEN 10
class CDate{
private:
	int day;
	int month;
	int year;
	bool SetDay(const int _day);
	bool SetMonth(const int _month);
	bool SetYear(const int _year);
public:
	CDate();
	CDate(const int day, const int month=1, const int year=2000);
	~CDate();
	int GetDay()const{ return day; }//inline return curent day
	int GetMonth()const{ return month; }//inline return curent month
	int GetYear()const{ return year; }//inline return curent year
	void PrintMonthName()const;
	bool leap_year()const;
	bool leap_year(int)const;
	int DayInMonth()const;
	void Next_Day()const;
	void SetDate(int=1, int=1, int=2000);
	CDate(const String&);
	friend ostream& operator<<(ostream& out, const CDate&);

};

ostream& operator<<(ostream& out, const CDate&);












#endif