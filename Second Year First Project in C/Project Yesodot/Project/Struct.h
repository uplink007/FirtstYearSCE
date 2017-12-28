#ifndef STRUCT_H
#define STRUCT_H
#include"stdlib.h"
#include"stdio.h"
#include"string.h"
typedef enum {delete = -1, add = 1 } addOrDelete;//for add delete functions
typedef enum { false, true } bool;//boolt type for true and false
typedef enum { ZERO=0, ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE} INT;//int ENUM
typedef enum {storekeeper, seller, technician, admin }WORKER;

typedef struct {
/**
day - numbers from 1 to 21
*/
	int day;
	int month;
	int year;

} Date;

typedef struct {
	int categoryKey;
	char* categoryName;
} Category;

typedef struct {
	int productKey;
	int orderInfoKey;
	int quantity;
	int pricePerItem;

} OrderInfo;

typedef struct {

	int productKey;
	int orderInventoryKey;
	int quantity;
	int pricePerItem;
	Date date;

} OrderInventory;

typedef struct {

	int workerKey;
	char* firstName;
	char* lastName;
	char* password;
	int premission;

} Worker;

typedef struct {
	int productKey;
	int laboratoryKey;
	int workerKey;
	char* status;
	Date entryDate;
} Laboratory;

typedef struct {
	int* arr;
	int size;

} OrderInfoKeyArray;

typedef struct {

	int clientKey;
	int workerKey;
	Date date;
	int orderClientKey;
	OrderInfoKeyArray orderInfoKeyArray;
	bool buildComputer;

} OrderClient;

typedef struct {
	int productKey;
	char *productName;
	int sellingPrice;
	int productionCost;
	int categoryKey;
	char* company;
	int years;
	int minInventory;
	int amount;
} Product;

typedef struct {
	int clientKey;
	char* firstName;
	char* lastName;
	char* phone;
	char* email;
	char* address;
} Client;

typedef struct {
	Category** category;
	int size;
	bool changed;
} CategoryArray;

typedef struct {
	OrderInfo** orderInfo;
	int size;
	bool changed;
} OrderInfoArray;

typedef struct {
	OrderInventory** orderInventory;
	int size;
	bool changed;
} OrderInventoryArray;

typedef struct {
	Worker** worker;
	int size;
	bool changed;
} WorkerArray;

typedef struct {
	Laboratory** laboratory;
	int size;
	bool changed;
} LaboratoryArray;

typedef struct {
	OrderClient** orderClient;
	int size;
	bool changed;
} OrderClientArray;

typedef struct {
	Product** product;
	int size;
	bool changed;
} ProductArray;

typedef struct {
	Client** client;
	int size;
	bool changed;
} ClientArray;

/*
Constructor for Category object
@arg1 - the key value
@arg2 - string for name value
@return - pointer to Category object
*/
Category* constructorCategory(int key, char* name);


/*
Copy constructor for Category object
@arg1 - Category object to copy
@return - pointer to Category object
*/
Category* copyConstructorCategory(Category* object);

/*
Destructor for Category object
*/
void destructorCategory(Category* category);

/*
Destructor for CategoryArray object
*/
void destructorCategoryArray(CategoryArray categoryArray);

/*
Constructor for OrderInfo object
@arg1 - the key value
@arg2 - the productKey value
@arg3 - the quantity value
@arg4 - the price per item value
@return - pointer to OrderInfo object
*/
OrderInfo* constructorOrderInfo(int orderInfoKey, int productKey,int quantity,int pricePerItem);


/*
Copy constructor for OrderInfo object
@arg1 - OrderInfo object to copy
@return - pointer to OrderInfo object
*/
OrderInfo* copyConstructorOrderInfo(OrderInfo* object);

/*
Destructor for OrderInfo object
*/
void destructorOrderInfo(OrderInfo* orderInfo);

/*
Destructor for OrderInfoArray object
*/
void destructorOrderInfoArray(OrderInfoArray orderInfoArray);

/*
Constructor for OrderInventory object
@arg1 - the key value
@arg2 - the productKey value
@arg3 - the quantity value
@arg4 - the price per item value
@arg5 - the date of the order
@return - pointer to OrderInventory object
*/
OrderInventory* constructorOrderInventory(int orderInventoryKey, int productKey, int quantity, int pricePerItem,Date date);

/*
Copy constructor for OrderInventory object
@arg1 - OrderInventory object to copy
@return - pointer to OrderInventory object
*/
OrderInventory* copyConstructorOrderInventory(OrderInventory* object);

/*
Destructor for OrderInventory object
*/
void destructorOrderInventory(OrderInventory* orderInventory);

/*
Destructor for OrderInventoryArray object
*/
void destructorOrderInventoryArray(OrderInventoryArray orderInventoryArray);

/*
Constructor for Worker object
@arg1 - the workerKey value
@arg2 - string for first name
@arg3 - string for last name
@arg4 - string for password
@arg5 - premission value
@return - pointer to Worker object
*/
Worker* constructorWorker(int workerKey, char* firstName, char* lastName, char* password,int premission);


/*
Copy constructor for Worker object
@arg1 - Worker object to copy
@return - pointer to Worker object
*/
Worker* copyConstructorWorker(Worker* object);

/*
Destructor for Worker object
*/
void destructorWorker(Worker* worker);

/*
Destructor for WorkerArray object
*/
void destructorWorkerArray(WorkerArray workerArray);

/*
Constructor for Laboratory object
@arg1 - the laboratoryKey value
@arg2 - the productKey value
@arg3 - the workerKey value
@arg4 - string for status
@arg5 - Date object
@return - pointer to Laboratory object
*/
Laboratory* constructorLaboratory(int laborotoryKey, int productKey, int workerKey, char* status,Date entryDate);


/*
Copy constructor for Laboratory object
@arg1 - Laboratory object to copy
@return - pointer to Laboratory object
*/
Laboratory* copyConstructorLaboratory(Laboratory* object);

/*
Destructor for Laboratory object
*/
void destructorLaboratory(Laboratory* laboratory);

/*
Destructor for LaboratoryArray object
*/
void destructorLaboratoryArray(LaboratoryArray laboratoryArray);

/*
Constructor for OrderClient object
@arg1 - the key value
@arg2 - the clientKey value
@arg3 - the workerKey value
@arg4 - the orderInfoKeyArray veraible
@arg5 - the date of the order
@arg6 - bool value(true if builComputer , false if not)
@return - pointer to OrderClient object
*/
OrderClient* constructorOrderClient(int orderClientKey, int clientKey, int workerKey, OrderInfoKeyArray orderInfoKeyArray, Date date, bool buildComputer);

/*
Copy constructor for OrderClient object
@arg1 - OrderClient object to copy
@return - pointer to OrderClient object
*/
OrderClient* copyConstructorOrderClient(OrderClient* object);

/*
Destructor for OrderClient object
*/
void destructorOrderClient(OrderClient* orderClient);

/*
Destructor for OrderClientArray object
*/
void destructorOrderClientArray(OrderClientArray orderClientArray);

/*
Constructor for Product object
@arg1 - the key value
@arg2 - the categoryKey value
@arg3 - the sellingPrice value
@arg4 - the productionCost value
@arg5 - the years of the garanty
@arg6 - the minimum value of the product in the inventory
@arg7 - the name of the product
@arg8 - the name of the company of the product
@arg9 - the amount of this product
@return - pointer to Product object
*/
Product* constructorProduct(int productKey, int categoryKey, int sellingPrice, int productionCost, int years, int minInventory, char *productName, char* company,int amount);

/*
Copy constructor for Product object
@arg1 - Product object to copy
@return - pointer to Product object
*/
Product* copyConstructorProduct(Product* object);

/*
Destructor for Product object
*/
void destructorProduct(Product* product);

/*
Destructor for ProductArray object
*/
void destructorProductArray(ProductArray productArray);

/*
Constructor for Client object
@arg1 - the clientKey value
@arg2 - string for first name
@arg3 - string for last name
@arg4 - string for phone
@arg5 - string for email
@arg6 - string for address
@return - pointer to Client object
*/
Client* constructorClient(int clientKey, char* firstName, char* lastName, char* phone, char* email, char* address);


/*
Copy constructor for Client object
@arg1 - Client object to copy
@return - pointer to Client object
*/
Client* copyConstructorClient(Client* object);

/*
Destructor for Client object
*/
void destructorClient(Client* client);

/*
Destructor for ClientArray object
*/
void destructorClientArray(ClientArray clientArray);


#endif
