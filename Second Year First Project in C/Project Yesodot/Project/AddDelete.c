/**
@athor:Sergey Shevchuck
@Vertion:1.0
@Date:13/12/2015
@Project:Beer Sheva Eight group
*/
#include"AddDelete.h"
bool DeleteCategory(CategoryArray* categoryArray, int key){
	Category* temp;
	int index;
	searchCategory(*(categoryArray),&temp,&index,key);
	if (temp)
		return addDeleteCategory(categoryArray, delete, *temp);
	else
		return false;
}

bool addDeleteCategory(CategoryArray* categoryArray, addOrDelete addDelete,Category object){
	int index,i,j;
	Category* temp,**categoryArrayTemp;
	if(categoryArray->category==NULL && addDelete!=delete){
		categoryArray->size=addDelete;
		categoryArray->changed=true;
		categoryArray->category=malloc(sizeof(Category*)*categoryArray->size);
		if (categoryArray->category) {
			categoryArray->category[0] = copyConstructorCategory(&object);
			if (!categoryArray->category[0]) {
				free(categoryArray->category);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else{
		searchCategory(*categoryArray,&temp,&index,object.categoryKey);
		categoryArray->size+=addDelete;
		categoryArray->changed=true;
		categoryArrayTemp=malloc(sizeof(Category*)*categoryArray->size);
		if (categoryArrayTemp) {
			if (temp != NULL && addDelete==delete) {
				for (i = 0; i < index; i++) {
					categoryArrayTemp[i] = categoryArray->category[i];
					categoryArray->category[i] = NULL;
				}
				destructorCategory(categoryArray->category[i]);
				for (i ; i < categoryArray->size; i++) {
					categoryArrayTemp[i] = categoryArray->category[i+1];
					categoryArray->category[i+1] = NULL;
				}
			}
			else if (addDelete == add) {
				categoryArrayTemp[index] = copyConstructorCategory(&object);
				if (categoryArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						categoryArrayTemp[i] = categoryArray->category[i];
						categoryArray->category[i] = NULL;
					}
					for (i = i + 1,j=index; i < categoryArray->size; i++,j++) {
						categoryArrayTemp[i] = categoryArray->category[j];
						categoryArray->category[j] = NULL;
					}
				}
				else {
					free(categoryArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(categoryArray->category);
		categoryArray->category=categoryArrayTemp;
	}
	return true;
}

bool DeleteOrderInfo(OrderInfoArray* orderInfoArray, int key) {
	OrderInfo* temp;
	int index;
	searchOrderInfo(*(orderInfoArray), &temp, &index, key);
	if (temp)
		return addDeleteOrderInfo(orderInfoArray, delete, *temp);
	else
		return false;
}

bool addDeleteOrderInfo(OrderInfoArray* orderInfoArray, addOrDelete addDelete, OrderInfo object) {
	int index, i,j;
	OrderInfo* temp, **orderInfoArrayTemp;
	if (orderInfoArray->orderInfo == NULL && addDelete != delete) {
		orderInfoArray->size = addDelete;
		orderInfoArray->changed = true;
		orderInfoArray->orderInfo = malloc(sizeof(OrderInfo*)*orderInfoArray->size);
		if (orderInfoArray->orderInfo) {
			orderInfoArray->orderInfo[0] = copyConstructorOrderInfo(&object);
			if (!orderInfoArray->orderInfo[0]) {
				free(orderInfoArray->orderInfo);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchOrderInfo(*orderInfoArray, &temp, &index, object.orderInfoKey);
		orderInfoArray->size += addDelete;
		orderInfoArray->changed = true;
		orderInfoArrayTemp = malloc(sizeof(OrderInfo*)*orderInfoArray->size);
		if (orderInfoArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					orderInfoArrayTemp[i] = orderInfoArray->orderInfo[i];
					orderInfoArray->orderInfo[i] = NULL;
				}
				destructorOrderInfo(orderInfoArray->orderInfo[i]);
				for (i; i < orderInfoArray->size; i++) {
					orderInfoArrayTemp[i] = orderInfoArray->orderInfo[i + 1];
					orderInfoArray->orderInfo[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				orderInfoArrayTemp[index] = copyConstructorOrderInfo(&object);
				if (orderInfoArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						orderInfoArrayTemp[i] = orderInfoArray->orderInfo[i];
						orderInfoArray->orderInfo[i] = NULL;
					}
					for (i = i + 1,j=index; i < orderInfoArray->size; i++,j++) {
						orderInfoArrayTemp[i] = orderInfoArray->orderInfo[j];
						orderInfoArray->orderInfo[j] = NULL;
					}
				}
				else {
					free(orderInfoArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(orderInfoArray->orderInfo);
		orderInfoArray->orderInfo = orderInfoArrayTemp;
	}
	return true;
}

bool DeleteOrderInventory(OrderInventoryArray* orderInventoryArray, int key) {
	OrderInventory* temp;
	int index;
	searchOrderInventory(*(orderInventoryArray), &temp, &index, key);
	if (temp)
		return addDeleteOrderInventory(orderInventoryArray, delete, *temp);
	else
		return false;
}

bool addDeleteOrderInventory(OrderInventoryArray* orderInventoryArray, addOrDelete addDelete, OrderInventory object) {
	int index, i,j;
	OrderInventory* temp, **orderInventoryArrayTemp;
	if (orderInventoryArray->orderInventory == NULL && addDelete != delete) {
		orderInventoryArray->size = addDelete;
		orderInventoryArray->changed = true;
		orderInventoryArray->orderInventory = malloc(sizeof(OrderInventory*)*orderInventoryArray->size);
		if (orderInventoryArray->orderInventory) {
			orderInventoryArray->orderInventory[0] = copyConstructorOrderInventory(&object);
			if (!orderInventoryArray->orderInventory[0]) {
				free(orderInventoryArray->orderInventory);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchOrderInventory(*orderInventoryArray, &temp, &index, object.orderInventoryKey);
		orderInventoryArray->size += addDelete;
		orderInventoryArray->changed = true;
		orderInventoryArrayTemp = malloc(sizeof(OrderInventory*)*orderInventoryArray->size);
		if (orderInventoryArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					orderInventoryArrayTemp[i] = orderInventoryArray->orderInventory[i];
					orderInventoryArray->orderInventory[i] = NULL;
				}
				destructorOrderInventory(orderInventoryArray->orderInventory[i]);
				for (i; i < orderInventoryArray->size; i++) {
					orderInventoryArrayTemp[i] = orderInventoryArray->orderInventory[i + 1];
					orderInventoryArray->orderInventory[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				orderInventoryArrayTemp[index] = copyConstructorOrderInventory(&object);
				if (orderInventoryArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						orderInventoryArrayTemp[i] = orderInventoryArray->orderInventory[i];
						orderInventoryArray->orderInventory[i] = NULL;
					}
					for (i = i + 1,j=index; i < orderInventoryArray->size; i++,j++) {
						orderInventoryArrayTemp[i] = orderInventoryArray->orderInventory[j];
						orderInventoryArray->orderInventory[j] = NULL;
					}
				}
				else {
					free(orderInventoryArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(orderInventoryArray->orderInventory);
		orderInventoryArray->orderInventory = orderInventoryArrayTemp;
	}
	return true;
}


bool addDeleteWorker(WorkerArray* workerArray, addOrDelete addDelete, Worker object) {
	int index, i,j;
	Worker* temp, **workerArrayTemp;
	if (workerArray->worker == NULL && addDelete != delete) {
		workerArray->size = addDelete;
		workerArray->changed = true;
		workerArray->worker = malloc(sizeof(Worker*)*workerArray->size);
		if (workerArray->worker) {
			workerArray->worker[0] = copyConstructorWorker(&object);
			if (!workerArray->worker[0]) {
				free(workerArray->worker);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchWorker(*workerArray, &temp, &index, object.workerKey);
		workerArray->size += addDelete;
		workerArray->changed = true;
		workerArrayTemp = malloc(sizeof(Worker*)*workerArray->size);
		if (workerArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					workerArrayTemp[i] = workerArray->worker[i];
					workerArray->worker[i] = NULL;
				}
				destructorWorker(workerArray->worker[i]);
				for (i; i < workerArray->size; i++) {
					workerArrayTemp[i] = workerArray->worker[i + 1];
					workerArray->worker[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				workerArrayTemp[index] = copyConstructorWorker(&object);
				if (workerArrayTemp[index]) {
					for (i=0; i < index; i++) {
						workerArrayTemp[i] = workerArray->worker[i];
						workerArray->worker[i] = NULL;
					}
					for (i=i+1,j=index; i < workerArray->size; i++,j++) {
						workerArrayTemp[i] = workerArray->worker[j];
						workerArray->worker[j] = NULL;
					}
				}
				else {
					free(workerArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		printf("1\n");
		free(workerArray->worker);
		printf("2\n");
		workerArray->worker = workerArrayTemp;
	}
	return true;
}

bool DeleteWorker(WorkerArray* workerArray, int key) {
	Worker* temp;
	int index;
	searchWorker(*(workerArray), &temp, &index, key);
	if (temp)
		return addDeleteWorker(workerArray, delete, *temp);
	else
		return false;
}

bool addDeleteLaboratory(LaboratoryArray* laboratoryArray, addOrDelete addDelete, Laboratory object) {
	int index, i,j;
	Laboratory* temp, **laboratoryArrayTemp;
	if (laboratoryArray->laboratory == NULL && addDelete != delete) {
		laboratoryArray->size = addDelete;
		laboratoryArray->changed = true;
		laboratoryArray->laboratory = malloc(sizeof(Laboratory*)*laboratoryArray->size);
		if (laboratoryArray->laboratory) {
			laboratoryArray->laboratory[0] = copyConstructorLaboratory(&object);
			if (!laboratoryArray->laboratory[0]) {
				free(laboratoryArray->laboratory);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchLaboratory(*laboratoryArray, &temp, &index, object.laboratoryKey);
		laboratoryArray->size += addDelete;
		laboratoryArray->changed = true;
		laboratoryArrayTemp = malloc(sizeof(Laboratory*)*laboratoryArray->size);
		if (laboratoryArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					laboratoryArrayTemp[i] = laboratoryArray->laboratory[i];
					laboratoryArray->laboratory[i] = NULL;
				}
				destructorLaboratory(laboratoryArray->laboratory[i]);
				for (i; i < laboratoryArray->size; i++) {
					laboratoryArrayTemp[i] = laboratoryArray->laboratory[i + 1];
					laboratoryArray->laboratory[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				laboratoryArrayTemp[index] = copyConstructorLaboratory(&object);
				if (laboratoryArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						laboratoryArrayTemp[i] = laboratoryArray->laboratory[i];
						laboratoryArray->laboratory[i] = NULL;
					}
					for (i = i + 1,j=index; i < laboratoryArray->size; i++,j++) {
						laboratoryArrayTemp[i] = laboratoryArray->laboratory[j];
						laboratoryArray->laboratory[j] = NULL;
					}
				}
				else {
					free(laboratoryArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(laboratoryArray->laboratory);
		laboratoryArray->laboratory = laboratoryArrayTemp;
	}
	return true;
}

bool DeleteLaboratory(LaboratoryArray* laboratoryArray, int key) {
	Laboratory* temp;
	int index;
	searchLaboratory(*(laboratoryArray), &temp, &index, key);
	if (temp)
		return addDeleteLaboratory(laboratoryArray, delete, *temp);
	else
		return false;
}

bool addDeleteOrderClient(OrderClientArray* orderClientArray, addOrDelete addDelete, OrderClient object) {
	int index, i,j;
	OrderClient* temp, **orderClientArrayTemp;
	if (orderClientArray->orderClient == NULL && addDelete != delete) {
		orderClientArray->size = addDelete;
		orderClientArray->changed = true;
		orderClientArray->orderClient = malloc(sizeof(OrderClient*)*orderClientArray->size);
		if (orderClientArray->orderClient) {
			orderClientArray->orderClient[0] = copyConstructorOrderClient(&object);
			if (!orderClientArray->orderClient[0]) {
				free(orderClientArray->orderClient);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchOrderClient(*orderClientArray, &temp, &index, object.orderClientKey);
		orderClientArray->size += addDelete;
		orderClientArray->changed = true;
		orderClientArrayTemp = malloc(sizeof(OrderClient*)*orderClientArray->size);
		if (orderClientArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					orderClientArrayTemp[i] = orderClientArray->orderClient[i];
					orderClientArray->orderClient[i] = NULL;
				}
				destructorOrderClient(orderClientArray->orderClient[i]);
				for (i; i < orderClientArray->size; i++) {
					orderClientArrayTemp[i] = orderClientArray->orderClient[i + 1];
					orderClientArray->orderClient[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				orderClientArrayTemp[index] = copyConstructorOrderClient(&object);
				if (orderClientArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						orderClientArrayTemp[i] = orderClientArray->orderClient[i];
						orderClientArray->orderClient[i] = NULL;
					}
					for (i = i + 1,j=index; i < orderClientArray->size; i++,j++) {
						orderClientArrayTemp[i] = orderClientArray->orderClient[j];
						orderClientArray->orderClient[j] = NULL;
					}
				}
				else {
					free(orderClientArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(orderClientArray->orderClient);
		orderClientArray->orderClient = orderClientArrayTemp;
	}
	return true;
}

bool DeleteOrderClient(OrderClientArray* orderClientArray, int key) {
	OrderClient* temp;
	int index;
	searchOrderClient(*(orderClientArray), &temp, &index, key);
	if (temp)
		return addDeleteOrderClient(orderClientArray, delete, *temp);
	else
		return false;
}

bool addDeleteProduct(ProductArray* productArray, addOrDelete addDelete, Product object) {
	int index, i,j;
	Product* temp, **productArrayTemp;
	if (productArray->product == NULL && addDelete != delete) {
		productArray->size = addDelete;
		productArray->changed = true;
		productArray->product = malloc(sizeof(Product*)*productArray->size);
		if (productArray->product) {
			productArray->product[0] = copyConstructorProduct(&object);
			if (!productArray->product[0]) {
				free(productArray->product);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchProduct(*productArray, &temp, &index, object.productKey);
		productArray->size += addDelete;
		productArray->changed = true;
		productArrayTemp = malloc(sizeof(Product*)*productArray->size);
		if (productArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					productArrayTemp[i] = productArray->product[i];
					productArray->product[i] = NULL;
				}
				destructorProduct(productArray->product[i]);
				for (i; i < productArray->size; i++) {
					productArrayTemp[i] = productArray->product[i + 1];
					productArray->product[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				productArrayTemp[index] = copyConstructorProduct(&object);
				if (productArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						productArrayTemp[i] = productArray->product[i];
						productArray->product[i] = NULL;
					}
					for (i = i + 1,j=index; i < productArray->size; i++,j++) {
						productArrayTemp[i] = productArray->product[j];
						productArray->product[j] = NULL;
					}
				}
				else {
					free(productArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(productArray->product);
		productArray->product = productArrayTemp;
	}
	return true;
}

bool DeleteProduct(ProductArray* productArray, int key) {
	Product* temp;
	int index;
	searchProduct(*(productArray), &temp, &index, key);
	if (temp)
		return addDeleteProduct(productArray, delete, *temp);
	else
		return false;
}

bool addDeleteClient(ClientArray* clientArray, addOrDelete addDelete, Client object) {
	int index, i,j;
	Client* temp, **clientArrayTemp;
	if (clientArray->client == NULL && addDelete != delete) {
		clientArray->size = addDelete;
		clientArray->changed = true;
		clientArray->client = malloc(sizeof(Client*)*clientArray->size);
		if (clientArray->client) {
			clientArray->client[0] = copyConstructorClient(&object);
			if (!clientArray->client[0]) {
				free(clientArray->client);
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		searchClient(*clientArray, &temp, &index, object.clientKey);
		clientArray->size += addDelete;
		clientArray->changed = true;
		clientArrayTemp = malloc(sizeof(Client*)*clientArray->size);
		if (clientArrayTemp) {
			if (temp != NULL && addDelete == delete) {
				for (i = 0; i < index; i++) {
					clientArrayTemp[i] = clientArray->client[i];
					clientArray->client[i] = NULL;
				}
				destructorClient(clientArray->client[i]);
				for (i; i < clientArray->size; i++) {
					clientArrayTemp[i] = clientArray->client[i + 1];
					clientArray->client[i + 1] = NULL;
				}
			}
			else if (addDelete == add) {
				clientArrayTemp[index] = copyConstructorClient(&object);
				if (clientArrayTemp[index]) {
					for (i = 0; i < index; i++) {
						clientArrayTemp[i] = clientArray->client[i];
						clientArray->client[i] = NULL;
					}
					for (i = i + 1,j=index; i < clientArray->size; i++,j++) {
						clientArrayTemp[i] = clientArray->client[j];
						clientArray->client[j] = NULL;
					}
				}
				else {
					free(clientArrayTemp);
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
		free(clientArray->client);
		clientArray->client = clientArrayTemp;
	}
	return true;
}

bool DeleteClient(ClientArray* clientArray, int key) {
	Client* temp;
	int index;
	searchClient(*(clientArray), &temp, &index, key);
	if (temp)
		return addDeleteClient(clientArray, delete, *temp);
	else
		return false;
}
