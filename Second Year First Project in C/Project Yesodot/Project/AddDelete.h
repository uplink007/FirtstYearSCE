/**
@athor:Sergey Shevchuck
@Vertion:1.0
@Date:13/12/2015
@Project:Beer Sheva Eight group
*/
#ifndef ADDDELETE_H
#define ADDDELETE_H
#include"Struct.h"
#include"Search.h"
/*
Function that add or delete one Category object to or from the array
@arg1 - pointer to Category Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
@return - true if succeeded false if doesn't
*/
bool addDeleteCategory(CategoryArray*, addOrDelete,Category object);

/*
Function that delete one Category object from array if the Key is known
@arg1 - pointer to Category Array
@arg2 - Key of the object to be deleted
@return - true if succeeded false if doesn't
*/
bool DeleteCategory(CategoryArray*, int key);

/*
Function that add or delete one OrderInfo object to or from the array
@arg1 - pointer to OrderInfo Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteOrderInfo(OrderInfoArray*, addOrDelete,OrderInfo object);

/*
Function that delete one OrderInfo object from array if the Key is known
@arg1 - pointer to OrderInfo Array
@arg2 - Key of the object to be deleted
*/
bool DeleteOrderInfo(OrderInfoArray*, int key);

/*
Function that add or delete one OrderInventory object to or from the array
@arg1 - pointer to OrderInventory Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteOrderInventory(OrderInventoryArray*, addOrDelete,OrderInventory object);


/*
Function that delete one OrderInventory object from array if the Key is known
@arg1 - pointer to OrderInventory Array
@arg2 - Key of the object to be deleted
*/
bool DeleteOrderInventory(OrderInventoryArray*, int key);

/*
Function that add or delete one Worker object to or from the array
@arg1 - pointer to Worker Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteWorker(WorkerArray*, addOrDelete,Worker object);

/*
Function that delete one Worker object from array if the Key is known
@arg1 - pointer to Worker Array
@arg2 - Key of the object to be deleted
*/
bool DeleteWorker(WorkerArray*, int key);

/*
Function that add or delete one Laboratory object to or from the array
@arg1 - pointer to Laboratory Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteLaboratory(LaboratoryArray*, addOrDelete,Laboratory object);

/*
Function that delete one Laboratory object from array if the Key is known
@arg1 - pointer to Laboratory Array
@arg2 - Key of the object to be deleted
*/
bool DeleteLaboratory(LaboratoryArray*, int key);

/*
Function that add or delete one OrderClient object to or from the array
@arg1 - pointer to OrderClient Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteOrderClient(OrderClientArray*, addOrDelete,OrderClient object);

/*
Function that delete one OrderClient object from array if the Key is known
@arg1 - pointer to OrderClient Array
@arg2 - Key of the object to be deleted
*/
bool DeleteOrderClient(OrderClientArray*, int key);

/*
Function that add or delete one Product object to or from the array
@arg1 - pointer to Product Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteProduct(ProductArray*, addOrDelete,Product object);

/*
Function that delete one Product object from array if the Key is known
@arg1 - pointer to Product Array
@arg2 - Key of the object to be deleted
*/
bool DeleteProduct(ProductArray*, int key);

/*
Function that add or delete one Client object to or from the array
@arg1 - pointer to Client Array
@arg2 - addDelete type parameter {add,delete}
@arg3 - object to be added or deleted
*/
bool addDeleteClient(ClientArray*, addOrDelete,Client object);

/*
Function that delete one Client object from array if the Key is known
@arg1 - pointer to Client Array
@arg2 - Key of the object to be deleted
*/
bool DeleteClient(ClientArray*, int key);
#endif