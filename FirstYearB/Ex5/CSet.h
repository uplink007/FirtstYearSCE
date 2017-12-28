#ifndef CSET_H
#define CSET_H
#include<iostream>
#include<fstream>
#include"MyError.h"
#include<typeinfo>
#define ERROR_VAL 10

using namespace std;
/**************************Class********************************************/
template <typename T> 
class CSet{
public:
	typedef enum INT{ M_ONE = -1, ZERO = 0, ONE = 1 ,TWO=2};
	CSet();
	CSet(const CSet&);
	~CSet();
	/**
	inline function that tell the size of the CSet obj
	@return the size of int type of this CSet obj
	*/
	int getSize()const{ return size; }
	/**
	inline function that return const pointer to the Group array(gp)
	@return the gp[] adress
	*/
	const T** getGP()const{ return gp; }
	CSet& operator=(const CSet&);
	CSet& operator+=(const T&);
	bool operator!=(const T&)const;
	CSet& operator-=(const T&);
	CSet operator|(const CSet&)const;
	CSet operator&(const CSet&)const;
	CSet operator-(const CSet&)const;
	bool operator==(const CSet&)const;
	bool operator>(const CSet&)const;
	bool operator<(const CSet&)const;
	CSet operator^(const CSet&)const;
	void DifWrite(const CSet&)const;
	void print(ostream& out = cout)const;
private:
	int index(const T&)const;
	T** gp;
	int size;
};
/************************************Functions*******************************************************/
template<typename T>
/**
template function to print the CSet obj(used by the operator<< overload)
@param out - ostream obj by refarance
*/
void CSet<T>::print(ostream& out)const{
	out << "(";
	for (int i = 0; i < size; i++){
		out << *(gp[i]);//print element
		if (i < size - CSet<T>::ONE){//no need of a "," after the last element
			out << ",";
		}
	}
	out << ")";
}

template<typename T>
/**
operator<< thet use print function and print the CSet object
@param out - ostream object by refarance
@param other - CSet object
@return ostream object by refarance
*/
ostream& operator<<(ostream& out, const CSet<T>& other){
	other.print(out);
	return out;
}

template<typename T>
/**
default ctor for CSet obj
*/
CSet<T>::CSet()
	:size(CSet<T>::ZERO), gp(NULL)
{}

template<typename T>
/**
copy ctor for CSet obj
@param other- other CSet object to copy from the data
*/
CSet<T>::CSet(const CSet& other)
	: gp(NULL), size(CSet<T>::ZERO)
{
	*this = other;
}

template<typename T>
/**
dtor for CSet obj
*/
CSet<T>::~CSet()
{
	if (gp){
		for (int i = CSet<T>::ZERO; i < size; i++){
			delete gp[i];
		}
		delete[]gp;
		gp = NULL;
	}
}

template<typename T>
/**
operator= for CSet obj
@param other-CSet obj to copy from data
@return the curent CSet obj after the data copy
*/
CSet<T>& CSet<T>::operator=(const CSet& other){
	if (other.gp == this->gp){//not the same obj
		return *this;
	}
	try{
		if (other.gp){//copy
			T** temp;
			try{
				temp = new T*[other.size];
			}
			catch (const bad_alloc&){
				throw;
			}
			for (int i = CSet<T>::ZERO; i < other.size; i++){
				try{
					temp[i] = new T(*other.gp[i]);
				}
				catch (const bad_alloc&){
					for (int j = 0; j < i; j++){
						delete temp[j];
					}
					delete[]temp;
					throw;
				}
			}
			size = other.size;
			if (gp){
				this->~CSet();//delete curent
			}
			gp = temp;
		}
	}
	catch (const bad_alloc&){
		cerr <<"Exception bad_alloc:operator= <T**> failed to alocate : Not enugh memory!!! The CSet object didn't changed" << endl;
	}
	catch (const exception&){
		throw;
	}
	return *this;
}

template<typename T>
/**
operator+= add an element to the CSet obj
@param obj-an element of <T> type to be added to the CSet object
@return curent CSet obj after the increasment with the new element
*/
CSet<T>& CSet<T>::operator+=(const T& obj){
	try{
		if (gp){//cheack if there is already elements
			if (!(*this != obj)){//cheack if the element isn't already in
				return *this;
			}
			T** temp;
			try{
				temp = new T*[size + CSet<T>::ONE];//inc
			}
			catch (const bad_alloc&){
					throw;
			}
			for (int i = CSet<T>::ZERO; i < size; i++){//copy
					temp[i] = gp[i];
			}
			try{
				temp[size] = new T(obj);//add
			}
			catch (const bad_alloc&){
				delete[] temp;
					throw;
			}
			delete gp;
			gp = temp;
		}
		else{
			try{
				gp = new T*[size + ONE];//inc
				*gp = new T(obj);//add
			}
			catch (bad_alloc&){
				if (gp) delete[] gp;
					throw;
			}
		}
		size++;
	}
	catch (const bad_alloc&){
		cerr << "Exception bad_alloc:Operator+= failed:Not enugh memory!!! The CSet object didn't changed" << endl;
	}
	catch (const exception&){
		throw;
	}
	return *this;
}

template<typename T>
/**
operator-= remove an element from the CSet obj if he exist
@param obj - element to be removed
@return curent CSet after element removed
*/
CSet<T>& CSet<T>::operator-=(const T& obj){
	try{
		if (gp){//cheack if there is elements
			if (*this != obj){//cheack if the element don't exist
				return *this;
			}
			T** temp;
			try{
				 temp = new T*[size - CSet<T>::ONE];//dec
			}
			catch (const bad_alloc&){
				throw ;
			}
			int ind = index(obj);
			for (int i = CSet<T>::ZERO; i < ind; i++){//copy up to element
				temp[i] = gp[i];
			}
			for (int i = ind, j = ind + CSet<T>::ONE; j < size; i++, j++){//copy after element
				temp[i] = gp[j];
			}
			//delete
			delete gp[ind];
			delete[] gp;
			gp = temp;
			size--;
			if (size == CSet<T>::ZERO){
				gp = NULL;
			}
		}
	}
	catch (const bad_alloc&){
		cout <<"Exception bad_alloc:Operator-= failed:Not enugh memory!!! The CSet object didn't changed" << endl;
	}
	catch (const exception&){
		throw;
	}
	return *this;
}


template<typename T>
/**
operator!= cheack if the element exist or not
@param obj- object to cheack
@return true if doesn't exist and false if exist
*/
bool CSet<T>::operator!=(const T& obj)const{
	try{
		if (index(obj) == CSet<T>::M_ONE){//M-ONE=-1
			return true;
		}
	}
	catch (const exception&){
		throw;
	}
	return false;	
}

template<typename T>
/**
function thet return index of an element if he exist
@param obj-element to cheack 
@return index of the element in the array or M_ONE=-1 if he doeasn't exist
*/
int CSet<T>::index(const T& obj)const{
	if (gp){
		for (int i = 0; i < size; i++){
			try{
				if (*gp[i] == obj){
					return i;//exist
				}
			}
			catch (const runtime_error&){
				throw;
			}
		}
	}
	return CSet<T>::M_ONE;//doesn't exit
}

template<typename T>
/**
operator|(OR) for CSet
@param other- second CSet obj
@return new CSet that include all the elements of curent and the second CSet object
*/
CSet<T> CSet<T>::operator|(const CSet& other)const{
	if (!other.gp){//other is empty
		return *this;
	}
	if (!gp){//this is empty
		return other;
	}
	CSet<T> temp;//new CSet
	try{
		for (int i = CSet<T>::ZERO; i < size; i++){
			if (other.size > i){
				temp += *other.gp[i];//add from other
			}
			temp += *gp[i];//add from this
		}
		if (other.size > size){//if other biger then curent
			for (int i = size; i < other.size; i++){
				temp += *other.gp[i];//add from other
			}
		}
	}
	catch (const runtime_error&){
		throw;
	}
	return temp;//return new CSet obj
}

template<typename T>
/**
operator&(AND) for CSet
@param other - second CSet obj
@return new grup that include only the elements that exist in both of CSet objects(curent and other)
*/
CSet<T> CSet<T>::operator&(const CSet& other)const{
	if (!other.gp){//other empty
		return other;
	}
	if (!gp){//this empty
		return *this;
	}
	CSet<T> temp;
	try{
		for (int i = CSet<T>::ZERO; i < size; i++){
			if (!(other != *gp[i])){//cheack if exist in both
				temp += *gp[i];//add 
			}
		}
	}
	catch (const runtime_error&){
		throw MyError("The operator& fail:runtime_error!!!");
	}
	catch (const exception&){
		throw;
	}
	return temp;
}

template<typename T>
/**
operator-(Subtraction)
@param other- second CSet obj
@return the new CSet that is substruction of the curent CSet obj with the other
*/
CSet<T> CSet<T>::operator-(const CSet& other)const{
	if (!other.gp){//cheack if other empty
		return *this;
	}
	if (!gp){//cheack if this empty
		return *this;
	}
	CSet<T> temp;
	try{
		for (int i = CSet<T>::ZERO; i < size; i++){
			if (other != *gp[i]){//cheack if doesn't exist in other
				temp += *gp[i];//add
			}
		}
	}
	catch (const runtime_error&){
		throw MyError("The operator& fail:runtime_error!!!");
	}
	catch (const exception&){
		throw;
	}
	return temp;
}

template<typename T>
/**
operator== equal
@param other- secons CSet obj
@return true if the CSet objects are equal and false if the aren't
*/
bool CSet<T>::operator==(const CSet& other)const{
	try{
		CSet<T> temp1 = *this - other;	//if temp1==NULL=>*this>other
		CSet<T> temp2 = other - *this;//if temp2==NULL=>*this<other
		if (temp1.gp == NULL&&temp2.gp == NULL){//=>*this=other
			return true;
		}
	}
	catch (const exception&){
		throw;
	}
	return false;
}

template<typename T>
/**
operator> cheack if all elements of other exist in the curent CSet obj
@param other-second CSet obj
@return true if all elements of other exist in the curent and false if they aren't
*/
bool CSet<T>::operator>(const CSet& other)const{
	try{
		if (!(*this - other).gp){//if (*this - other).gp==NULL=>*this>other
			return true;
		}
	}
	catch (const exception&){
		throw;
	}
	return false;
}

template<typename T>
/**
operator> cheack if all elements of curent exist in the other CSet obj
@param other-second CSet obj
@return true if all elements of curent exist in the other and false if they aren't
*/
bool CSet<T>::operator<(const CSet& other)const{
	try{
		if (!(other - *this).gp){//if (other - *this).gp==NULL=>*this<other
			return true;
		}
	}
	catch (const exception&){
		throw;
	}
	return false;
}

template<typename T>
/**
operator^(XOR) for CSet obj
@param other-second CSet obj
@return new CSet object that include all the elements that exist only in a or only in B but not in both
*/
CSet<T> CSet<T>::operator^(const CSet& other)const{
	try{
		return ((*this | other) - (*this&other));//the math formula
	}
	catch (const exception&){
		throw;
	}
}

template<typename T>
/**
function that write to the Subtruction file the answare of *this-other
@param other-second CSet object 
*/
void CSet<T>::DifWrite(const CSet& other)const{
	try{
		ofstream File("Subtraction.txt", ios::app);//open
		if (File.fail()){//exeption
			throw MyError("File Subtraction.txt didn't opened");
		}
		File << (*this - other) << endl;//write
		File.close();//close
	}
	catch(const MyError& err){//exeption
		cerr << err.what() << endl;
	}
	catch (const exception&){
		throw;
	}
}
template<typename T>
istream& operator>>(istream& in,CSet<T>& grup){
	int trueNum;
	cout << "Enter ";
	try{
		 cout<< typeid(T).name();
	}
	catch (const bad_typeid&){
		cout << "Unnown";
	}
	cout << " grup:" << endl;
	do{
		bool flag;
		if (in)	
		do{
			cout << "1-add , 2-finish" << endl;
			try{
				flag = true;
				int num;
				in >> num;
				if (in.fail()){
					throw MyError("Bad input ,try one more time!");
				}
				else{
					throw num;
				}
			}
			catch (const MyError& err){
				cerr << err.what() << endl;
				char a[ERROR_VAL];
					in.clear();
					do{
						in >> a;
					} while (in.fail());
				flag = true;
			}
			catch (int num){
				trueNum = num;
				flag = false;
			}
		} while (flag);
		if (trueNum==1){
			T temp;
			cout << "Enter:";
			in >> temp;
			grup += temp;
		}
		else if (trueNum != 2){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (trueNum!=2);
	
	return in;
}
/*************************The End****************************************/
#endif

