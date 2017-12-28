#define _CRT_SECURE_NO_WARNINGS
#include"Struct.h"

Category* constructorCategory(int key, char* name) {
	Category* temp = malloc(sizeof(Category));
	if (temp) {
		temp->categoryKey = key;
		temp->categoryName = malloc(sizeof(char)*(strlen(name) + ONE));
		if(temp->categoryName)
			strcpy(temp->categoryName, name);
		else {
			free(temp);
			return NULL;
		}
	}
	return temp;
}

Category* copyConstructorCategory(Category* object) {
	return constructorCategory(object->categoryKey, object->categoryName);
}

void destructorCategory(Category* category){
	free(category->categoryName);
	free(category);
}

void destructorCategoryArray(CategoryArray categoryArray) {
	int i = 0;
	if (categoryArray.size) {
		for (i; i < categoryArray.size; i++) {
			destructorCategory(categoryArray.category[i]);
		}
		free(categoryArray.category);
	}
}

OrderInfo* constructorOrderInfo(int orderInfoKey, int productKey, int quantity, int pricePerItem) {
	OrderInfo* temp = malloc(sizeof(OrderInfo));
	if (temp) {
		temp->orderInfoKey = orderInfoKey;
		temp->productKey = productKey;
		temp->quantity = quantity;
		temp->pricePerItem = pricePerItem;
	}
	return temp;
}

OrderInfo* copyConstructorOrderInfo(OrderInfo* object) {
	OrderInfo* temp = malloc(sizeof(OrderInfo));
	if (temp) {
		temp->orderInfoKey = object->orderInfoKey;
		temp->productKey = object->productKey;
		temp->quantity = object->quantity;
		temp->pricePerItem = object->pricePerItem;
	}
	return temp;
}

void destructorOrderInfo(OrderInfo* orderInfo) {
	free(orderInfo);
}

void destructorOrderInfoArray(OrderInfoArray orderInfoArray) {
	int i = 0;
	if (orderInfoArray.size) {
		for (i; i < orderInfoArray.size; i++) {
			destructorOrderInfo(orderInfoArray.orderInfo[i]);
		}
		free(orderInfoArray.orderInfo);
	}
}

OrderInventory* constructorOrderInventory(int orderInventoryKey, int productKey, int quantity, int pricePerItem,Date date) {
	OrderInventory* temp = malloc(sizeof(OrderInventory));
	if (temp) {
		temp->orderInventoryKey = orderInventoryKey;
		temp->productKey = productKey;
		temp->quantity = quantity;
		temp->pricePerItem = pricePerItem;
		temp->date.day = date.day;
		temp->date.month = date.month;
		temp->date.year = date.year;
	}
	return temp;
}

OrderInventory* copyConstructorOrderInventory(OrderInventory* object) {
	OrderInventory* temp = malloc(sizeof(OrderInventory));
	if (temp) {
		temp->orderInventoryKey = object->orderInventoryKey;
		temp->productKey = object->productKey;
		temp->quantity = object->quantity;
		temp->pricePerItem = object->pricePerItem;
		temp->date.day = object->date.day;
		temp->date.month = object->date.month;
		temp->date.year = object->date.year;
	}
	return temp;
}

void destructorOrderInventory(OrderInventory* orderInventory) {
	free(orderInventory);
}

void destructorOrderInventoryArray(OrderInventoryArray orderInventoryArray) {
	int i = 0;
	if (orderInventoryArray.size) {
		for (i; i < orderInventoryArray.size; i++) {
			destructorOrderInventory(orderInventoryArray.orderInventory[i]);
		}
		free(orderInventoryArray.orderInventory);
	}
}

Worker* constructorWorker(int workerKey, char* firstName, char* lastName, char* password, int premission) {
	Worker* temp = malloc(sizeof(Worker));
	if (temp) {
		temp->workerKey = workerKey;
		temp->premission = premission;
		temp->firstName = malloc(sizeof(char)*(strlen(firstName) + ONE));
		if (temp->firstName)
			strcpy(temp->firstName, firstName);
		else {
			free(temp);
			return NULL;
		}
		temp->lastName = malloc(sizeof(char)*(strlen(lastName) + ONE));
		if (temp->lastName)
			strcpy(temp->lastName, lastName);
		else {
			free(temp->firstName);
			free(temp);
			return NULL;
		}
		temp->password = malloc(sizeof(char)*(strlen(password) + ONE));
		if (temp->password)
			strcpy(temp->password, password);
		else {
			free(temp->firstName);
			free(temp->lastName);
			free(temp);
			return NULL;
		}
	}
	return temp;
}

Worker* copyConstructorWorker(Worker* object) {
	return constructorWorker(object->workerKey, object->firstName, object->lastName, object->password, object->premission);
}

void destructorWorker(Worker* worker) {
	free(worker->firstName);
	free(worker->lastName);
	free(worker->password);
	free(worker);
}

void destructorWorkerArray(WorkerArray workerArray) {
	int i = 0;
	if (workerArray.size) {
		for (i; i < workerArray.size; i++) {
			destructorWorker(workerArray.worker[i]);
		}
		free(workerArray.worker);
	}
}


Laboratory* constructorLaboratory(int laboratoryKey, int productKey, int workerKey, char* status, Date entryDate) {
	Laboratory* temp = malloc(sizeof(Laboratory));
	if (temp) {
		temp->laboratoryKey = laboratoryKey;
		temp->productKey = productKey;
		temp->workerKey = workerKey;
		temp->entryDate.day = entryDate.day;
		temp->entryDate.month = entryDate.month;
		temp->entryDate.year = entryDate.year;
		temp->status = malloc(sizeof(char)*(strlen(status) + ONE));
		if (temp->status)
			strcpy(temp->status, status);
		else {
			free(temp);
			return NULL;
		}
	}
	return temp;
}

Laboratory* copyConstructorLaboratory(Laboratory* object) {
	return constructorLaboratory(object->laboratoryKey, object->productKey, object->workerKey, object->status, object->entryDate);
}

void destructorLaboratory(Laboratory* laboratory) {
	free(laboratory->status);
	free(laboratory);
}

void destructorLaboratoryArray(LaboratoryArray laboratoryArray) {
	int i = 0;
	if (laboratoryArray.size) {
		for (i; i < laboratoryArray.size; i++) {
			destructorLaboratory(laboratoryArray.laboratory[i]);
		}
		free(laboratoryArray.laboratory);
	}
}

OrderClient* constructorOrderClient(int orderClientKey, int clientKey, int workerKey, OrderInfoKeyArray orderInfoKeyArray, Date date, bool buildComputer) {
	int i = 0;
	OrderClient* temp = malloc(sizeof(OrderClient));
	if (temp) {
		temp->orderClientKey = orderClientKey;
		temp->clientKey = clientKey;
		temp->workerKey = workerKey;
		temp->date.day = date.day;
		temp->date.month = date.month;
		temp->date.year = date.year;
		temp->buildComputer = buildComputer;
		temp->orderInfoKeyArray.arr= malloc(sizeof(int)*orderInfoKeyArray.size);
		if (temp->orderInfoKeyArray.arr) {
			for (i; i < orderInfoKeyArray.size; i++) {
				temp->orderInfoKeyArray.arr[i] = orderInfoKeyArray.arr[i];
			}
			temp->orderInfoKeyArray.size = orderInfoKeyArray.size;
		}
		else {
			free(temp);
			return NULL;
		}
	}
	return temp;
}

OrderClient* copyConstructorOrderClient(OrderClient* object) {
	return constructorOrderClient(object->orderClientKey, object->clientKey, object->workerKey, object->orderInfoKeyArray, object->date, object->buildComputer);
}

void destructorOrderClient(OrderClient* orderClient) {
	free(orderClient->orderInfoKeyArray.arr);
	free(orderClient);
}

void destructorOrderClientArray(OrderClientArray orderClientArray) {
	int i = 0;
	if (orderClientArray.size) {
		for (i; i < orderClientArray.size; i++) {
			destructorOrderClient(orderClientArray.orderClient[i]);
		}
		free(orderClientArray.orderClient);
	}
}

Product* constructorProduct(int productKey, int categoryKey, int sellingPrice, int productionCost, int years, int minInventory, char *productName, char* company,int amount) {
	Product* temp = malloc(sizeof(Product));
	if (temp) {
		temp->productKey = productKey;
		temp->categoryKey = categoryKey;
		temp->sellingPrice = sellingPrice;
		temp->productionCost = productionCost;
		temp->years = years;
		temp->minInventory = minInventory;
		temp->amount = amount;
		temp->productName = malloc(sizeof(char)*(strlen(productName) + ONE));
		if (temp->productName)
			strcpy(temp->productName, productName);
		else {
			free(temp);
			return NULL;
		}
		temp->company = malloc(sizeof(char)*(strlen(company) + ONE));
		if (temp->company)
			strcpy(temp->company, company);
		else {
			free(temp->productName);
			free(temp);
			return NULL;
		}
	}
	return temp;
}

Product* copyConstructorProduct(Product* object) {
	return constructorProduct(object->productKey, object->categoryKey, object->sellingPrice, object->productionCost, object->years, object->minInventory, object->productName, object->company, object->amount);
}

void destructorProduct(Product* product) {
	free(product->company);
	free(product->productName);
	free(product);
}

void destructorProductArray(ProductArray productArray) {
	int i = 0;
	if (productArray.size) {
		for (i; i < productArray.size; i++) {
			destructorProduct(productArray.product[i]);
		}
		free(productArray.product);
	}
}

Client* constructorClient(int clientKey, char* firstName, char* lastName, char* phone, char* email, char* address) {
	Client* temp = malloc(sizeof(Client));
	if (temp) {
		temp->clientKey = clientKey;
		temp->firstName = malloc(sizeof(char)*(strlen(firstName) + ONE));
		if (temp->firstName)
			strcpy(temp->firstName, firstName);
		else {
			free(temp);
			return NULL;
		}
		temp->lastName = malloc(sizeof(char)*(strlen(lastName) + ONE));
		if (temp->lastName)
			strcpy(temp->lastName, lastName);
		else {
			free(temp->firstName);
			free(temp);
			return NULL;
		}
		temp->phone = malloc(sizeof(char)*(strlen(phone) + ONE));
		if (temp->phone)
			strcpy(temp->phone, phone);
		else {
			free(temp->firstName);
			free(temp->lastName);
			free(temp);
			return NULL;
		}
		temp->email = malloc(sizeof(char)*(strlen(email) + ONE));
		if (temp->email)
			strcpy(temp->email, email);
		else {
			free(temp->firstName);
			free(temp->lastName);
			free(temp->phone);
			free(temp);
			return NULL;
		}
		temp->address = malloc(sizeof(char)*(strlen(address) + ONE));
		if (temp->address)
			strcpy(temp->address, address);
		else {
			free(temp->firstName);
			free(temp->lastName);
			free(temp->phone);
			free(temp->email);
			free(temp);
			return NULL;
		}
	}
	return temp;
}

Client* copyConstructorClient(Client* object) {
	return constructorClient(object->clientKey, object->firstName, object->lastName, object->phone, object->email, object->address);
}

void destructorClient(Client* client) {
	free(client->firstName);
	free(client->lastName);
	free(client->phone);
	free(client->email);
	free(client->address);
	free(client);
}

void destructorClientArray(ClientArray clientArray) {
	int i = 0;
	if (clientArray.size) {
		for (i; i < clientArray.size; i++) {
			destructorClient(clientArray.client[i]);
		}
		free(clientArray.client);
	}
}
