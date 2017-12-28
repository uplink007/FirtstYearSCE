#ifndef MYERROR_H
#define MYERROR_H
#include<iostream>
#include<exception>
using namespace std;
struct MyError :
	public exception
{
	const char* my_err;
	MyError(const char* err);
	const char* what()const throw(){
		return my_err;
	}
};

#endif