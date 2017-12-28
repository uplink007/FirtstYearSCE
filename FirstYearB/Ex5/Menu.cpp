#include "Menu.h"

//ctor
Menu::Menu()
{
	/*cin >> INT1 >> INT2 >> CHAR >> CDATE1 >> CDATE2;*/
}
//start
void Menu::start(){
	int num;
	do{//choose
		cout << *this;
		cin >> num;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num < I || num>XI){
			cout << "Bad input ,try one more time!" << endl;
		}
		else if (cin){//switch case
			switch (num){
			case I:
			{
				add();
				break;
			}
			case II:
			{
				remove();
				break;
			}
			case III:
			{
				or_int();
				break;
			}
			case IV:
			{
				and_date();
				break;
			}
			case V:
			{
				sub_int();
				break;
			}
			case VI:
			{
				include_date();
				break;
			}
			case VII:
			{
				xor_int();
				break;
			}
			case VIII:
			{
				equal_date();
				break;
			}
			case IX:
			{
				defWrite_date();
				break;
			}

			case X:{
				print();
				break;
			}

			}
		}
	} while (num != 11);

}
void Menu::add(){//add element
	int num;
	do{//choose
		cout << "Choose grup to add element:" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl << "3-CHAR" << endl << "4-CDATE1" << endl << "5-CDATE2" << endl;
		cin >> num;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num < I || num>V){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num<I||num>V);
	switch (num){//switch case to add
	case I:
	{
		int temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		while (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
			cin >> temp;
		}
		INT1 += temp;
		break;
	}
	case II:
	{
		int temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		while (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
			cin >> temp;
		}
		INT2 += temp;
		break;
	}
	case III:
	{
		char temp;
		cout << "Enter char:" << endl;
		cin >> temp;
		CHAR += temp;
		break;
	}
	case IV:
	{
		CDate temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		CDATE1 += temp;
		break;
	}
	case V:
	{
		CDate temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		CDATE2 += temp;
		break;
	}

	}
}
void Menu::remove(){//remove element
	int num;
	do{//choose
		cout << "Choose grup to delete element" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl << "3-CHAR" << endl << "4-CDATE1" << endl << "5-CDATE2" << endl;
		cin >> num;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num < I || num>V){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num<I || num>V);
	switch (num){//switch case to remove element
	case I:
	{
		int temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		while (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
			cin >> temp;
		}
		INT1 -= temp;
		break;
	}
	case II:
	{
		int temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		while (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
			cin >> temp;
		}
		INT2 -= temp;
		break;
	}
	case III:
	{
		char temp;
		cin >> temp;
		CHAR -= temp;
		break;
	}
	case IV:
	{
		CDate temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		CDATE1 -= temp;
		break;
	}
	case V:
	{
		CDate temp;
		cout << "Enter integer number:" << endl;
		cin >> temp;
		CDATE2 -= temp;
		break;
	}

	}
}
void Menu::or_int()const{//int's or
	cout << (INT1 | INT2) << endl;;
}
void Menu::and_date()const{//CDate and
	cout << (CDATE1&CDATE2) << endl;;

}
void Menu::include_date()const{//include CDate's function
	int num1,num2;
	do{//choose base grup
		cout << "Choose base grup:" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl;
		cin >> num1;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num1 < I || num1>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num1<I || num1>II);
	do{//choose parameter grup
		cout << "Choose param grup:" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl;
		cin >> num2;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num2 < I || num2>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num2<I || num2>II);
	CSet<CDate> base = num1 == 1 ? CDATE1 : CDATE2;//base grup
	CSet<CDate> param = num1 == 1 ? CDATE1 : CDATE2;//parameter grup
	if (base > param){
		cout << "The base grup contains the parameter grup" << endl;
	}
	else{
		cout << "The parameter grup is not contained in the base grup" << endl;
	}
}
void Menu::sub_int()const{//sub int's
	int num1, num2;
	do{//choose base
		cout << "Choose base grup:" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl;
		cin >> num1;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num1 < I || num1>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num1<I || num1>II);
	do{//choose param
		cout << "Choose param grup:" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl;
		cin >> num2;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num2 < I || num2>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num2<I || num2>II);
	CSet<int> base = num1 == 1 ? INT1 : INT2;//base
	CSet<int> param = num1 == 1 ? INT1 : INT2;//param
	cout << (base - param)<<endl;//print

}
void Menu::xor_int()const{//xor int's
	cout << (INT1^INT2) << endl;

}
void Menu::equal_date()const{//cheack if CDate's are equal
	if (CDATE1 == CDATE2){
		cout << "The two groups are equal" << endl;
	}
	else{
		cout << "The two grups are not equal" << endl;
	}

}
void Menu::defWrite_date()const{//writing the sub to the file
	int num1, num2;
	do{//base
		cout << "Choose base grup:" << endl;
		cout << "1-CDATE1" << endl << "2-CDATE2" << endl;
		cin >> num1;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num1 < I || num1>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num1<I || num1>II);
	do{//param
		cout << "Choose param grup:" << endl;
		cout << "1-CDATE1" << endl << "2-CDATE2" << endl;
		cin >> num2;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num2 < I || num2>II){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num2<I || num2>II);
	CSet<CDate> base = num1 == 1 ? CDATE1 : CDATE2;//base
	CSet<CDate> param = num1 == 1 ? CDATE1 : CDATE2;//param
	base.DifWrite(param);
}
void Menu::print()const{//print
	int num;
	do{//choose grup to print
		cout << "Choose grup to print" << endl;
		cout << "1-INT1" << endl << "2-INT2" << endl << "3-CHAR" << endl << "4-CDATE1" << endl << "5-CDATE2" << endl;
		cin >> num;
		if (cin.fail()){
			cout << "Wrong type of input" << endl;
			char a[ERROR_VAL];
			cin.clear();
			do{
				cin >> a;
			} while (cin.fail());
		}
		else if (num < I || num>V){
			cout << "Bad input ,try one more time!" << endl;
		}
	} while (num<I || num>V);
	switch (num){//switch case to print
	case I:
	{
		cout << INT1 << endl;
		break;
	}
	case II:
	{
		cout << INT2 << endl;
		break;
	}
	case III:
	{
		cout << CHAR << endl;
		break;
	}
	case IV:
	{
		cout << CDATE1 << endl;
		break;
	}
	case V:
	{
		cout << CDATE2 << endl;
		break;
	}

	}

}

ostream& operator<<(ostream& out, const Menu&){//print menu
	fflush(stdin);
	cout << "Press any key . . ." << endl;
	getchar();
	fflush(stdin);
	system("cls");
	out << "Choose:" << endl;
	out << "1-Add new member to a grup." << endl;
	out << "2-Remove a member from a grup." << endl;
	out << "3-Consolidation int grups" << endl;
	out << "4-Cutting Date grups." << endl;
	out << "5-Sub int grups." << endl;
	out << "6-Contains for Date grups." << endl;
	out << "7-XOR for int grups." << endl;
	out << "8-Cheack if equal for date grups." << endl;
	out << "9-defWrite for date grups." << endl;
	out << "10-Print a grup." << endl;
	out << "11-Exit." << endl;
	out << "Your choise:";
	return out;
}