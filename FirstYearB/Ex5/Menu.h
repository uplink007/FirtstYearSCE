#ifndef MENU_H
#define MENU_H
#include"CDate.h"
#include"CSet.h"
typedef enum{I=1,II,III,IV,V,VI,VII,VIII,IX,X,XI}INT;
class Menu
{
private:
	CSet<int> INT1, INT2;
	CSet<char> CHAR;
	CSet<CDate> CDATE1, CDATE2;
public:
	Menu();
	~Menu(){}
	void start();
	void add();
	void remove();
	void or_int()const;
	void and_date()const;
	void sub_int()const;
	void include_date()const;
	void xor_int()const;
	void equal_date()const;
	void defWrite_date()const;
	void print()const;
};
ostream& operator<<(ostream&, const Menu&);
#endif