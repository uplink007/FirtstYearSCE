#include<iostream>
#include"Menu.h"

using namespace std;
/***********************************************************************************************************************/
//first part of the second part
template<typename T>

void quick_sort(T* arr, int size){
	quicsort(arr, 0, size - 1);
}

template<typename T>

void quicsort(T* arr, int left,int right){
	/********************************Function that sort arrays from small to big***********************************************/
	int i, last;
	if (left >= right)//end case
		return;
	swapp(arr[left], arr[(left + right) / 2]);
	last = left;
	for (i = left + 1; i <= right; i++){
		if (arr[i]<arr[left]){
			swapp(arr[++last], arr[i]);
		}
	}
	swapp(arr[left], arr[last]);
	quicsort(arr, left, last - 1);//1 left array
	quicsort(arr, last + 1, right);//2 right array
}

template<typename T>

void quick_sort(T** arr, int size){
	quicsort(arr, 0, size - 1);
}

template<typename T>

void quicsort(T** arr, int left, int right){
	/********************************Function that sort arrays from small to big***********************************************/
	int i, last;
	if (left >= right)//end case
		return;
	swapp(arr[left], arr[(left + right) / 2]);
	last = left;
	for (i = left + 1; i <= right; i++){
		if (*arr[i]<*arr[left]){
			swapp(arr[++last], arr[i]);
		}
	}
	swapp(arr[left], arr[last]);
	quicsort(arr, left, last - 1);//1 left array
	quicsort(arr, last + 1, right);//2 right array
}

template<typename T>

void swapp(T& first, T& second){
	T temp(first);
	first = second;
	second = temp;
}

template<typename T>

bool binary_search(T* arr,int size,const T& object ){
	return bSearch(arr, object, 0, size - 1);
}

template<typename T>

bool bSearch(T* arr,const T& str, const int& left, const int& right){
	if (!arr){//no definitions
		return false;
	}
	else if (right<left){//stop case
		if (arr[left] == str){
			return true;
		}
		else{
			return  false;
		}
	}
	int flag = (left + right) / 2;//midle
	if (str < arr[flag]){//cheack
		return bSearch( arr,str, left, flag - 1);//recurtion left
	}
	else{
		return bSearch(arr,str, flag + 1, right);//recurtion right
	}
}

template<typename T>

bool binary_search(T** arr, int size, const T& object){
	return bSearch(arr, object, 0, size - 1);
}

template<typename T>

bool bSearch(T** arr, const T& str, const int& left, const int& right){
	if (!arr){//no definitions
		return false;
	}
	else if (right<left){//stop case
		if (*arr[left] == str){
			return true;
		}
		else{
			return  false;
		}
	}
	int flag = (left + right) / 2;//midle
	if (!(*arr[flag] < str)){//cheack
		return bSearch(arr, str, left, flag - 1);//recurtion left
	}
	else{
		return bSearch(arr, str, flag + 1, right);//recurtion right
	}
}
/*****************************************************************************************************************/
//main for CSet
int main(){
	Menu m;
	m.start();
	return 0;
}