/**
@athor:Sergey Shevchuck
@Vertion:1.0
@Date:13/12/2015
@Project:Beer Sheva Eight group
*/
#ifndef SEARCH_H
#define SEARCH_H
#include"Struct.h"

/*
Function to find a Category object with a category Key arg
@arg1 - Category Array object
@arg2 - pointer to Category pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchCategory(CategoryArray ,Category** getCategory,int* getIndex, int key);

/*
Function to find a Category object with a category Key arg
@arg1 - Category pointer array of pointers to a Category objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the Category object or NULL if the key doesn't exist
*/
Category* bsearchCategory(Category**, int start, int end, int key,int* getIndex);
/*
Function to find a OrderInfo object with a OrderInfo Key arg
@arg1 - OrderInfo Array object
@arg2 - pointer to OrderInfo pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchOrderInfo(OrderInfoArray,OrderInfo** getOrderInfo,int* getIndex, int key);

/*
Function to find a OrderInfo object with a OrderInfo Key arg
@arg1 - OrderInfo pointer array of pointers to a OrderInfo objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the OrderInfo object or NULL if the key doesn't exist
*/
OrderInfo* bsearchOrderInfo(OrderInfo**, int start, int end, int key,int* getIndex);

/*
Function to find a OrderInventory object with a OrderInventory Key arg
@arg1 - OrderInventory Array object
@arg2 - pointer to OrderInventory pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchOrderInventory(OrderInventoryArray, OrderInventory** getOrderInventory, int* getIndex, int key);

/*
Function to find a OrderInventory object with a OrderInventory Key arg
@arg1 - OrderInventory pointer array of pointers to a OrderInventory objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the OrderInventory object or NULL if the key doesn't exist
*/
OrderInventory* bsearchOrderInventory(OrderInventory**, int start, int end, int key,int* getIndex);

/*
Function to find a Worker object with a Worker Key arg
@arg1 - Worker Array object
@arg2 - pointer to Worker pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchWorker(WorkerArray, Worker** getWorker, int* getIndex, int key);

/*
Function to find a Worker object with a Worker Key arg
@arg1 - Worker pointer array of pointers to a Worker objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the Worker object or NULL if the key doesn't exist
*/
Worker* bsearchWorker(Worker**, int start, int end, int key,int* getIndex);

/*
Function to find a Laboratory object with a Laboratory Key arg
@arg1 - Laboratory Array object
@arg2 - pointer to Laboratory pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchLaboratory(LaboratoryArray, Laboratory** getLaboratory, int* getIndex, int key);

/*
Function to find a Laboratory object with a Laboratory Key arg
@arg1 - Laboratory pointer array of pointers to a Laboratory objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the Laboratory object or NULL if the key doesn't exist
*/
Laboratory* bsearchLaboratory(Laboratory**, int start, int end, int key,int* getIndex);

/*
Function to find a OrderClient object with a OrderClient Key arg
@arg1 - OrderClient Array object
@arg2 - pointer to OrderClient pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchOrderClient(OrderClientArray, OrderClient** getOrderClient, int* getIndex, int key);

/*
Function to find a OrderClient object with a OrderClient Key arg
@arg1 - OrderClient pointer array of pointers to a OrderClient objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the OrderClient object or NULL if the key doesn't exist
*/
OrderClient* bsearchOrderClient(OrderClient**, int start, int end, int key,int* getIndex);

/*
Function to find a Product object with a Product Key arg
@arg1 - Product Array object
@arg2 - pointer to Product pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchProduct(ProductArray, Product** getProduct, int* getIndex, int key);

/*
Function to find a Product object with a Product Key arg
@arg1 - Product pointer array of pointers to a Product objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the Product object or NULL if the key doesn't exist
*/
Product* bsearchProduct(Product**, int start, int end, int key,int* getIndex);

/*
Function to find a Client object with a Client Key arg
@arg1 - Client Array object
@arg2 - pointer to Client pointer (The Key object will be saved in this parameter)
***arg2 == NULL if the object isn't exist***
@arg3 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if arg2 == NULL then arg3 will save the index to a place that object with the key could be placed to save sort array***
@arg3 - integer that get the Key of the object that we want to find in the array
*/
void searchClient(ClientArray, Client** getClient, int* getIndex, int key);

/*
Function to find a Client object with a Client Key arg
@arg1 - Client pointer array of pointers to a Client objects
@arg2 - start index of the array in default need to be ZERO
@arg3 - end index of the array in default need to be (size-ONE)
@arg4 - integer that get the Key to find in the array
@arg5 - pointer to an integer variable (The Key object index in array will be saved in this parameter)
***if returnd NULL then arg5 will save the index to a place that object with the key could be placed to save sort array***
@return - pointer to the Client object or NULL if the key doesn't exist
*/
Client* bsearchClient(Client**, int start, int end, int key,int* getIndex);
#endif
