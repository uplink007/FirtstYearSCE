/* 
Assignment: 4
Campus: Beer-Sheva 
Author1: Sergey Sevchuk, ID: 321274524
Date: 24/5/2015 
*/
#include "Customer.h"
//counter
int Customer::last_serial = 0;
//ctor,recive String
Customer::Customer(const String& _name)
	:name(_name), buing_item(NULL), serial(++last_serial)
{
}

//dctor
Customer::~Customer()
{
	if (buing_item){
		for (int i = 0; buing_item[i] != NULL; i++){
			delete buing_item[i];
		}
		delete[]buing_item;
	}
	last_serial--;
}
//count the buing_items array
int Customer::items()const{
	int i = ONE;
	if (buing_item){
		i--;
		while (buing_item[i++] != NULL);
	}
	return i;
}
//operator += that add a sweet item to the customer,recive sweet item
Customer& Customer::operator+=( SweetItem* sweet){
	if (buing_item&&sweet){//add
		int i = this->items();
		SweetItem** temp = new SweetItem*[i + ONE];
		if (!temp){
			cout << "allocation faild!!!" << endl;
			exit(1);
		}
		for (int j = 0; buing_item[j]!=NULL; j++){//copy
			temp[j] = buing_item[j];
		}
		temp[i-ONE] = sweet;//add
		temp[i] = NULL;
		delete[] buing_item;
		buing_item = temp;
	}
	else if(sweet){//first sweet
		buing_item = new SweetItem*[TWO];
		if (!buing_item){
			cout << "allocation faild!!!" << endl;
			exit(1);
		}
		*buing_item = sweet;
		buing_item[ONE] = NULL;
	}
	return *this;
}
//operator != tell if the sweet lread exist,resive sweetitem,return bool
bool Customer::operator!=(const SweetItem& sweet){
	bool flag = true;
	if (buing_item && &sweet){//cheack
		for (int i = 0; buing_item[i] != NULL; i++){
			if (buing_item[i]->getType() == sweet.getType()){
				if (buing_item[i]->getAmount() == sweet.getAmount()){
					flag = false;//exist
				}
			}
		}
	}
	else if (!(&sweet)){
		flag = false;
	}
	return flag;
}
//operator -= that cancel an item from user
Customer& Customer::operator-=(const int& sweet){
	int i = this->items();
	if (sweet>=ZERO&&sweet<i-ONE){
		SweetItem** temp = new SweetItem*[i - ONE];
		for (int j = 0, k = 0; j < i; j++){
			if (j != sweet){
				temp[k++] = buing_item[j];
			}
			else{
				delete buing_item[j];
			}
		}
		buing_item = temp;
	} 
	return *this;
}

//count sum off all sweets
float Customer::sum()const{
	float sum = 0;
	for (int i = 0; buing_item[i] != NULL;i++){
		sum += buing_item[i]->getTotalPrice();
	}
	return sum;
}

//the last input options of the customer
float Customer::end(){
	int choise;
	float sum = ZERO;
	do{
		do{
			cout << "What would you like  to do? 1- pay 2- cancel item" << endl;
			cin >> choise;
			if (cin.fail()){
				cin.clear();
				String trash;
				cin >> trash;
			}
		} while (cin.fail() && choise != ONE && choise != TWO);
		if (choise == TWO){//cancel item
			int temp;
			cout << *this;
			if (items()-ONE){
			do{
				cout << "Which item to cancel ?" << endl;
				do{
					cin >> temp;
					if (cin.fail()){
						cin.clear();
						String trash;
						cin >> trash;
					}
				} while (cin.fail());
			} while (temp < ZERO || temp >= items());
			Cookielida* sweet = dynamic_cast<Cookielida*>(buing_item[--temp]);
			if (sweet){
				sum += sweet->bitul();
				cout << "Cancelation fee is:  " << sweet->bitul() << endl;//amlat bitul
			}
			*this -= temp;
			}
			else{
				choise = ONE;
			}
		}
	} while (choise != ONE);
	sum += this->sum();//calc
	fstream inout;
	inout.open("Subscription.txt",ios::app);//creat if doesnt exist
	inout.close();
	inout.open("Subscription.txt", ios::in);
	if (!inout.is_open()){
		cerr << "File opening faild" << endl;
		exit(1);
	}
	String temp;
	bool flag = false;
	inout.seekg(ZERO, ios::beg);
	while (inout >> temp){
		if (temp == this->name){
			flag = true;//already in the file
		}
	}
	inout.close();
	inout.open("Subscription.txt", ios::app);
	if (!flag){//if not in the file
		char a;
		do{
			cout << "You are not a member it cost 15 to join. Would you like to join? Y-yes N-no" << endl;
			fflush(stdin);
			a = getchar();
			if (a >= 'a'&&a <= 'z'){
				a -= 'a' - 'A';
			}
			switch (a){
			case 'Y':{//if he want to be added
				inout<< (this->name);
				inout <<endl;
				flag = true;
				break;
			}
			default:{
				if (a != 'N'){
					cout << "You cann't choose this option!!!" << endl << "Try again" << endl;
				}
			}
			}
		} while (a != 'N'&&!flag);
	}
	inout.close();
	if (flag){
		sum = sum*(0.9f);//make the mivza for the user
	}
	cout << fixed<<std::setprecision(1);//fixed output
	cout << "Your bill is:" << endl<<sum << endl << "Thank you" << endl;
	return sum;
}

//operator << to output the users sweets
ostream& operator<<(ostream & out, const Customer& cust){
	out << "You have " <<cust.items()-ONE << " items:" << endl;
	if (cust.buing_item){
		for (int i = 0; cust.buing_item[i] != NULL; i++){
			out << i + ONE << ".  " << *(cust.buing_item[i]) << endl;
		}
	}
	return out;
}
//operator >> to control input one user
istream& operator>>(istream& in, Customer& cust){
	bool flag;
	do{
		flag = true;
		int x;
		do{
			cout << "What would you like?" << endl;
			color(Red, Bright_White);
			cout<<"1-Candy ";
			color(Aqua, Bright_White);
			cout << "2 - Cookie ";
			color(Green, Bright_White);
			cout << "3 - IceCream ";
			color(Light_Purple, Bright_White);
			cout<<"4 - Cookielida " << endl;
			color();
			in >> x;
			if (in.fail()){
				String trash;
				in.clear();
				in >> trash;
			}
		} while (in.fail());
		switch (x){
		case ONE:{//candy
			Candy* candy=new Candy();
			if (!candy){
				cout << "allocation faild!!!" << endl;
				exit(1);
			}
			cin >> *candy;
			if (cust != *candy){
				cust += candy;
			}
			else{
				delete candy;
			}
			break;
		}
		case TWO:{//cookie
			Cookie* cookie = new Cookie();
			if (!cookie){
				cout << "allocation faild!!!" << endl;
				exit(1);
			}
			cin >> *cookie;
			if (cust != *cookie){
				cust += cookie;
			}
			else{
				delete cookie;
			}
			break;
		}
		case THREE:{//ice cream
			IceCream* iceCream = new IceCream();
			if (!iceCream){
				cout << "allocation faild!!!" << endl;
				exit(1);
			}
			cin >> *iceCream;
			if (cust != *iceCream){
				cust += iceCream;
			}
			else{
				delete iceCream;
			}
			break;
		}
		case FOUR:{//cookielida
			Cookielida* cookielida = new Cookielida();
			if (!cookielida){
				cout << "allocation faild!!!" << endl;
				exit(1);
			}
			cin >> *cookielida;
			if (cust != *cookielida){
				cust += cookielida;
			}
			else{
				delete cookielida;
			}
			break;
		}
		default:{flag = false;
			cout << "You cann't choose this option!!!" << endl << "Try again" << endl;;

		}
		}
		if (flag){
			char a;
			do{
				cout << "would you like something else? Y-yes N- no" << endl;
				fflush(stdin);
				a = getchar();
				if (a >= 'a'&&a <= 'z'){
					a -= 'a' - 'A';
				}
				switch (a){
				case 'Y':flag = false;
					break;
				default:{
					if (a != 'N'){
						cout << "You cann't choose this option!!!" << endl << "Try again"<<endl;
					}
				}
				}
			} while (a != 'N'&&flag);
		}
	} while (!flag);

	return in;
}
//return name
String Customer::getName()const{
	return name;
}
//calc procents of the users buings,recive array and fill him
void Customer::procent(float* arr, int size, float total)const{
	if (this){
		for (int i = 0; buing_item[i] != NULL; i++){
			Cookielida* cookielida = dynamic_cast<Cookielida*>(buing_item[i]);
			Cookie* cookie = dynamic_cast<Cookie*>(buing_item[i]);
			if (cookie&&!cookielida){
				arr[ONE] += cookie->getTotalPrice();
			}
			Candy* candy = dynamic_cast<Candy*>(buing_item[i]);
			if (candy){
				arr[ZERO] += candy->getTotalPrice();
			}
			IceCream* iceCream = dynamic_cast<IceCream*>(buing_item[i]);
			if (iceCream&&!cookielida){
				arr[TWO] += iceCream->getTotalPrice();
			}

			if (cookielida){
				arr[THREE] += cookielida->getTotalPrice();
			}
		}
	}

	if (total){
		arr[ZERO] = (arr[ZERO] / total) * 100;
		arr[ONE] = (arr[ONE] / total) * 100;
		arr[TWO] = (arr[TWO] / total) * 100;
		arr[THREE] = (arr[THREE] / total) * 100;
	}
	else{
		arr[ZERO] = ZERO;
		arr[ONE] = ZERO;
		arr[TWO] = ZERO;
		arr[THREE] = ZERO;
	}

}