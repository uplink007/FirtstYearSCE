#ifndef PRINT_H
#define PRINT_H
#define printCode -1
#include"Struct.h"

/*
printCategory
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print category name(only value)
*/
void printCategory(Category category, int index);
/*
printOrderInfo
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print order info key(only value)
2- print quantity(only value)
3- print price per item(only value)
*/
void printOrderInfo(OrderInfo orderInfo, int index);
/*
printOrderInventory
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print product key(only value)
2- print quantity(only value)
3- print price per item(only value)
4- print date(dd/mm/yy)
*/
void printOrderInventory(OrderInventory orderInventory, int index);
/*
printWorker
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print first name(only value)
2- print last name(only value)
3- print password(only value)
4- print premission(only value)
*/
void printWorker(Worker worker, int index);
/*
printLaboratory
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print Product key(only value)
2- print Worker key(only value)
3- print Status(only value)
4- print Date(only value)
*/
void printLaboratory(Laboratory laboratory, int index);
/*
printOrderClient
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print Client key(only value)
2- print Worker key(only value)
3- print Date(only value)
4- print Order info key array with all values
5- print Build computer(true or false)
*/
void printOrderClient(OrderClient orderClient, int index);
/*
printProduct
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print Product name(only value)
2- print Selling price(only value)
3- print Production cost(only value)
4- print Category key(only value)
5- print Company(only value)
6- print Years(only value)
7- print minInventory(only value)
*/
void printProduct(Product product, int index);
/*
printClient
indexes:
printCode- print key of struct(with title)
0 - print all fields(without key of struct) with titles
1- print First name(only value)
2- print Last name(only value)
3- print Phone(only value)
4- print Email(only value)
5- print Address(only value)
*/
void printClient(Client client, int index);

#endif