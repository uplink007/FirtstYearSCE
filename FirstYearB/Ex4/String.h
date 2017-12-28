/* Assignment: 4
Campus:  Beer Sheva
Author: Sergey Shevchuk, ID: 321274524
*/
#ifndef SSTRING_H
#define SSTRING_H
#include<iostream>
typedef enum{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX}Ints;
#define ALLOCFAIL -1
#define MAX_STRING_SIZE 201
#define ASCII178 178
#define NOT_VALID -2
#define STARS 97
using namespace std;
class String{
	char* str;
	int len;
	void spaces();
public:
	String(const char* _str = NULL);
	String(const String&);
	~String();
	/**
	function that return length of the Srting object
	@return length of curent String
	*/
	int getLen()const{ return len; }
	/**
	function that return const pointer to the string array
	@return const char* of curent String
	*/
	const char* getStr()const{ return str; }
	String& operator=(const String&);
	String& operator=(const char*);
	String& operator+=(const String&);
	String& operator+=(const char*);
	String& operator+=(const char&);
	const char& operator[](const int&)const;
	char& operator[](const int&);
	bool operator<=(const String&)const;
	bool operator>(const String&)const;
	bool operator>=(const String&)const;
	bool operator==(const String&)const;
	bool operator<(const String&)const;
	bool operator!=(const String&)const;
	String& operator-=(const char&);
	void arrange();
};
int strLenCpy(const char* str1, char* = NULL);
bool alloc(char* & , const int&);
ostream& operator<<(ostream& out, const String&);
istream& operator>> (istream& in, String&);


#endif