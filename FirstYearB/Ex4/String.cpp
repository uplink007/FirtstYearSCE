/* Assignment: 4
Campus:  Beer Sheva
Author: Sergey Shevchuk, ID: 321274524
*/
#include"String.h"

/**
default and parametr constractor that make a String object
@param _str - char array to make curent String
*/
String::String(const char* _str)
	:len(ZERO), str(NULL)
{
	*this = _str;//operator =(const char*)
	if (!str){
		str = new char[ONE];
		*str = '\0';
	}
}
/**
copy constractor that make a String object from other string with a help of operator=
@param other - other string that used to make the 
*/
String::String(const String&other)
	:len(ZERO), str(NULL)
{
	*this += other;//operator+=(const String&)
}
/**
destructor destroy curent String
*/
String::~String(){
	if (str){
		delete[]str;
		str = NULL;
	}
}
/**
operator = ( assign)
@param other- String to copy to curent one
@return curent String bu rreferance
*/
String& String::operator=(const String& other){
	if (this != &other){//check that this isn't the same String
		if (str){//check if there is str array 
			delete[]str;
			str = NULL;
			len = ZERO;
		}
		*this += other;//operator +=(const String&)
	}
	return *this;
}
/**
operator = ( assign)
@param other - char* array to be coppied to curent string
@return curent String by referance
*/
String& String::operator=(const char* other){
	if (str != other){//check that this isn't the same char* arrays allready
		if (str){//check if there is str array 
			delete[]str;
			str = NULL;
			len = ZERO;
		}
		*this += other;//operator +=(const char*)
	}
	return *this;
}
/**
operator +=
@param other - String to add to curent one
@return curent string by referance with the other string added
*/
String& String::operator+=(const String& other){
	*this += other.str;
	return *this;
}
/**
operator +=
@param _str - char array to add to curent one
@return curent string by referance with the other char array added
*/
String& String::operator+=(const char* _str){

	if (len != ALLOCFAIL){//cheack if the string is valid
		char* temp = NULL;
		if (len){//check if there is char array already
			len += strLenCpy(_str);
			temp = new char[len + ONE];
			if (!temp){
				len = ALLOCFAIL;//Set string invalid
			}
			for (int i = 0, j = 0; i + j < len&&len != ALLOCFAIL;){//copy chars i indicate first char array j indicate the second char array
				if (str[i] != '\0'){
					temp[i + j] = str[i];
					i++;
				}
				else{
					temp[i + j] = _str[j];
					j++;
				}
			}
			if (temp){
				temp[len] = '\0';//end of string
			}
		}
		else{
			if (alloc(temp, strLenCpy(_str) + ONE)){
				len = strLenCpy(_str, temp);
				if (!_str){
					*temp = '\0';//if the char* is NULL
				}
			}
			else{
				len = ALLOCFAIL;
			}

		}
		delete[]str;
		str = temp;
	}
	return *this;

}
/**
function that copy one char array to another and return length
@param Sorce- char array to copy from ,if Dest =null return only Sorce length
@param Dest- char array thet coppy chars from Sorce
@return length of the Sorce char array without \0
*/
int strLenCpy(const char* Sorce,char* Dest ){
	int i;
	if (Sorce == NULL){//if null return zero
		return ZERO;
	}
	for (i = 0; Sorce[i] !='\0'; i++){//indicate 
		if (Dest!=NULL)//copy
			Dest[i] = Sorce[i];
	}
	if (Dest!=NULL)//if dest isn't null put \0 in the end
		Dest[i] = '\0';
	return i;
}
/**
bool function that alloc memory rom heap and return true if succeded or false if not
@param pt-pointer that need an alloc memory
@param size-size to alloc
@return true if alloc succeded ,false if allo faild
*/
bool alloc(char*& pt, const int& size){
	if (pt){
		delete[]pt;
	}
	pt = new char[size];
	if (!pt){
		return false;
	}
	return true;
}
/**
operator << for out put to the screen the String
@param out-ostream object by referance
@param str- String object to out put
@return ostream object by referance
*/
ostream& operator<<(ostream& out, const String& str){
	out << str.getStr();
	return out;
}
/**
operator>> for instolize String from input
@param in - istream object by referance
@param str - String object to inisilize
@return istream object by referance
*/
istream& operator>> (istream& in, String& str){
	char temp[MAX_STRING_SIZE];
	in.getline(temp, MAX_STRING_SIZE);
	str = temp;
	return in;
}
/**
function that return char in the index place
@param index- index for a char
@return char in the index place
*/
const char& String::operator[](const int& index)const{
	if (index > len){
		cout << "error index" << endl;
		return *(str + len);
	}
	return *(str + index);
}
/**
function that return char by referance in the index place
@param index- index for a char
@return char by referance in the index place of the curent string
*/
char& String::operator[](const int& index){
	if (index > len){
		cout << "error index" << endl;
		return *(str + len);
	}
	return *(str + index);
}
/**
operator +=
@param ch - char to add to curent string
@return curent string by referance with the ch added
*/
String& String::operator+=(const char& ch){
	char* pt=new char[TWO];
	*pt = ch;
	*(pt + ONE) = '\0';//making a char array with \0 in the end(string)
	*this += pt;//add this string to the String object
	delete pt;
	return *this;
}
/**
operator <= cheack if the curent String is smaller or equal in leksikografi than cmpStr String
@param cmpStr - String object to compare
@return true if curent smaller or equal ,false if biger
*/
bool String::operator<=(const String& cmpStr)const{
	int i = 0;
	for (i; cmpStr[i] != '\0'; ){//runing on the char array
		if (cmpStr[i] == str[i] && str[i] != '\0'){//first different char
			i++;
		}
		else if (str[i] == '\0'){//less chars
				return true;
			}
			else if (str[i] < cmpStr[i]){//diferent char of curent smaller then different char of cmpStr
				return true;
			}else
				return false;//diferent char of curent biger then different char of cmpStr
	}
	if (str[i] == '\0')//equal
		return true;
	else
		return false;//more chars 
}
/**
operator > check leksikografi
@param cmpStr - str to compare with
@return true if curent biger then cmpStr,false if doesn't
*/
bool String::operator>(const String& cmpStr)const{
	return !(*this <= cmpStr);
}
/**
operator == check leksikografi
@param cmpStr - str to compare with
@return true if curent equal to cmpStr,false if doesn't
*/
bool String::operator==(const String& cmpStr)const{
	return *this <= cmpStr&&cmpStr <= *this;
}
/**
operator != check leksikografi
@param cmpStr - str to compare with
@return true if curent diffarant from  cmpStr,false if equal
*/
bool String::operator!=(const String&cmpStr)const{
	return !(*this == cmpStr);

}
/**
operator < check leksikografi
@param cmpStr - str to compare with
@return true if curent smaller then cmpStr,false if doesn't
*/
bool String::operator<(const String& cmpStr)const{
	return *this <= cmpStr&&*this != cmpStr;
}
/**
operator >= check leksikografi
@param cmpStr - str to compare with
@return true if curent biger or equal then cmpStr,false if doesn't
*/
bool String::operator>=(const String& cmpStr)const{
	return !(*this < cmpStr);
}
/**
operator -= delete ch char from all the char array
@param ch - char to delete
@return curent String by referance without the ch char
*/
String& String::operator-=(const char& ch){
	String temp;
	for (int i = 0; i <= len; i++){
		if (str[i] != ch)
			temp += str[i];
	}
	delete[]str;
	 str = temp.str;
	 temp.str = NULL;
	 len = temp.len;
	 temp.len = ZERO;
	return *this;
}
/**
void function that make the String valiad for the dictionary using
*/
void String::arrange(){
	this->spaces();
	int i = 0;
	while (str[i] != '\0'){
		if (i - ONE == -1||i>0&&str[i - ONE] == '.'){//cappitalize in the start and after dot
			if (str[i] >= 'a' && str[i] <= 'z'){
				str[i] -= 'a';
				str[i] += 'A';
			}
		}
		else{
			if (str[i] >= 'A'&&str[i] <= 'Z'){//make small letters if they don't need to be capital letters
				str[i] -= 'A';
				str[i] += 'a';
			}
		}
		i++;
	}
}
/**
private function tht delete all not needed spaces
*/
void String::spaces(){
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			while (str[++i] == ' '){//change all not needed space to ascii 178
				str[i] = (char)ASCII178;
			}
		}
		if (str[i] == '.'||str[i]==','||str[i]==':'){//manage the spaces before and after (.,:)
			int j = i-ONE;
			if ((str[j] == ' ' || str[j] == (char)ASCII178)&&j>=0){
				while (j >= 0 && (str[j] == ' ' || str[j] == (char)ASCII178)){//before
				if (str[j] == ' '){
						str[j] = (char)ASCII178;
					}
				j--;
				}
			}
			while (str[++i] == ' '){//after
				str[i] = (char)ASCII178;
			}
		}
		if (str[i] == '\0'){//check if already the end
			i--;
		}
	}
	if (str[ZERO] == ' ')//first char in the char array
		str[ZERO] = (char)ASCII178;
	if (str[len] == ' ')//last char in the char array
		str[len] = (char)ASCII178;
	*this -= (char)ASCII178;//delete all the 178 ascii chars from the String
}