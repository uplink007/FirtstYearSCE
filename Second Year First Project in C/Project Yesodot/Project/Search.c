/**
@athor:Sergey Shevchuck
@Vertion:1.0
@Date:13/12/2015
@Project:Beer Sheva Eight group
*/
#include"Search.h"
void searchCategory(CategoryArray categoryArray,Category** getCategory,int* getIndex, int key){
	if (categoryArray.category) {
		*getCategory = bsearchCategory(categoryArray.category, ZERO, categoryArray.size - ONE, key, getIndex);
	}
	else {
		*getCategory = NULL;
		*getIndex = 0;
	}
}
Category* bsearchCategory(Category** category, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (category[pivot]->categoryKey==key){//check if the value
		*getIndex=pivot;
		return category[pivot];
	}
	if(start >= end){//check if finish
		if(key>category[start]->categoryKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (category[pivot]->categoryKey>key)//send to right part
		return bsearchCategory(category, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchCategory(category, pivot+ONE,end,key,getIndex);
}

void searchClient(ClientArray clientArray,Client** getClient,int* getIndex, int key){
	if (clientArray.client) {
		*getClient = bsearchClient(clientArray.client, ZERO, clientArray.size - ONE, key, getIndex);
	}
	else {
		*getClient= NULL;
		*getIndex = 0;
	}
}
Client* bsearchClient(Client** client, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (client[pivot]->clientKey==key){//check if the value
		*getIndex=pivot;
		return client[pivot];
	}
	if(start >= end){//check if finish
		if(key>client[start]->clientKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (client[pivot]->clientKey>key)//send to right part
		return bsearchClient(client, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchClient(client, pivot+ONE,end,key,getIndex);
}

void searchOrderInfo(OrderInfoArray orderInfoArray,OrderInfo** getOrderInfo,int* getIndex, int key){
	if (orderInfoArray.orderInfo) {
		*getOrderInfo = bsearchOrderInfo(orderInfoArray.orderInfo, ZERO, orderInfoArray.size - ONE, key, getIndex);
	}
	else {
		*getOrderInfo = NULL;
		*getIndex = 0;
	}
}
OrderInfo* bsearchOrderInfo(OrderInfo** orderInfo, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (orderInfo[pivot]->orderInfoKey==key){//check if the value
		*getIndex=pivot;
		return orderInfo[pivot];
	}
	if(start >= end){//check if finish
		if(key>orderInfo[start]->orderInfoKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (orderInfo[pivot]->orderInfoKey>key)//send to right part
		return bsearchOrderInfo(orderInfo, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchOrderInfo(orderInfo, pivot+ONE,end,key,getIndex);
}

void searchOrderInventory(OrderInventoryArray orderInventoryArray,OrderInventory** getOrderInventory,int* getIndex, int key){
	if (orderInventoryArray.orderInventory) {
		*getOrderInventory = bsearchOrderInventory(orderInventoryArray.orderInventory, ZERO, orderInventoryArray.size - ONE, key, getIndex);
	}
	else {
		*getOrderInventory = NULL;
		*getIndex = 0;
	}
}
OrderInventory* bsearchOrderInventory(OrderInventory** orderInventory, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (orderInventory[pivot]->orderInventoryKey==key){//check if the value
		*getIndex=pivot;
		return orderInventory[pivot];
	}
	if(start >= end){//check if finish
		if(key>orderInventory[start]->orderInventoryKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (orderInventory[pivot]->orderInventoryKey>key)//send to right part
		return bsearchOrderInventory(orderInventory, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchOrderInventory(orderInventory, pivot+ONE,end,key,getIndex);
}

void searchWorker(WorkerArray workerArray,Worker** getWorker,int* getIndex, int key){
	if (workerArray.worker) {
		*getWorker = bsearchWorker(workerArray.worker, ZERO, workerArray.size - ONE, key, getIndex);
	}
	else {
		*getWorker = NULL;
		*getIndex = 0;
	}
}
Worker* bsearchWorker(Worker** worker, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (worker[pivot]->workerKey==key){//check if the value
		*getIndex=pivot;
		return worker[pivot];
	}
	if(start >= end){//check if finish
		if(key>worker[start]->workerKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (worker[pivot]->workerKey>key)//send to right part
		return bsearchWorker(worker, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchWorker(worker, pivot+ONE,end,key,getIndex);
}

void searchLaboratory(LaboratoryArray laboratoryArray,Laboratory** getLaboratory,int* getIndex, int key){
	if (laboratoryArray.laboratory) {
		*getLaboratory = bsearchLaboratory(laboratoryArray.laboratory, ZERO, laboratoryArray.size - ONE, key, getIndex);
	}
	else {
		*getLaboratory = NULL;
		*getIndex = 0;
	}
}
Laboratory* bsearchLaboratory(Laboratory** laboratory, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (laboratory[pivot]->laboratoryKey==key){//check if the value
		*getIndex=pivot;
		return laboratory[pivot];
	}
	if(start >= end){//check if finish
		if(key>laboratory[start]->laboratoryKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (laboratory[pivot]->laboratoryKey>key)//send to right part
		return bsearchLaboratory(laboratory, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchLaboratory(laboratory, pivot+ONE,end,key,getIndex);
}

void searchOrderClient(OrderClientArray orderClientArray,OrderClient** getOrderClient,int* getIndex, int key){
	if (orderClientArray.orderClient) {
		*getOrderClient = bsearchOrderClient(orderClientArray.orderClient, ZERO, orderClientArray.size - ONE, key, getIndex);
	}
	else {
		*getOrderClient = NULL;
		*getIndex = 0;
	}
}
OrderClient* bsearchOrderClient(OrderClient** orderClient, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (orderClient[pivot]->orderClientKey==key){//check if the value
		*getIndex=pivot;
		return orderClient[pivot];
	}
	if(start >= end){//check if finish
		if(key>orderClient[start]->orderClientKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (orderClient[pivot]->orderClientKey>key)//send to right part
		return bsearchOrderClient(orderClient, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchOrderClient(orderClient, pivot+ONE,end,key,getIndex);
}

void searchProduct(ProductArray productArray,Product** getProduct,int* getIndex, int key){
	if (productArray.product) {
		*getProduct = bsearchProduct(productArray.product, ZERO, productArray.size - ONE, key, getIndex);
	}
	else {
		*getProduct = NULL;
		*getIndex = 0;
	}
}
Product* bsearchProduct(Product** product, int start, int end, int key,int* getIndex){
	int pivot = (start + end) / TWO;//middle
	if (product[pivot]->productKey==key){//check if the value
		*getIndex=pivot;
		return product[pivot];
	}
	if (start >= end){//check if finish
		if(key>product[start]->productKey)
			*getIndex=start+ONE;
		else
			*getIndex=start;
		return NULL;
	}
	if (product[pivot]->productKey>key)//send to right part
		return bsearchProduct(product, start, pivot-ONE, key,getIndex);
	else//send to left part
		return  bsearchProduct(product, pivot+ONE,end,key,getIndex);
}