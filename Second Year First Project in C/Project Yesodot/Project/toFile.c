#define _CRT_SECURE_NO_WARNINGS
#include"toFile.h"
bool updateData(CategoryArray categoryArray, OrderInfoArray orderInfoArray, OrderInventoryArray orderInventoryArray, WorkerArray workerArray, LaboratoryArray laboratoryArray, OrderClientArray orderClientArray, ProductArray productArray, ClientArray clientArray) {
	if (categoryArray.changed && !updateCategory(categoryArray)) { return false; }
	if (orderInfoArray.changed&&!updateOrderInfo(orderInfoArray)) { return false; }
	if (orderInventoryArray.changed&&!updateOrderInventory(orderInventoryArray)) { return false; }
	if (workerArray.changed&&!updateWorker(workerArray)) { return false; }
	if (laboratoryArray.changed&&!updateLaboratory(laboratoryArray)) { return false; }
	if (orderClientArray.changed&&!updateOrderClient(orderClientArray)) { return false; }
	if (productArray.changed&&!updateProduct(productArray)) { return false; }
	if (clientArray.changed&&!updateClient(clientArray)) { return false; }
	return true;
}
bool updateCategory(CategoryArray categoryArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("Category.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", categoryArray.size);
	for (i; i < categoryArray.size; i++) {
		fprintf(ptr, "%d %d %s\n", categoryArray.category[i]->categoryKey, strlen(categoryArray.category[i]->categoryName), categoryArray.category[i]->categoryName);
	}
	fclose(ptr);
	return true;
}

bool updateOrderInfo(OrderInfoArray orderInfoArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("OrderInfo.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", orderInfoArray.size);
	for (i; i < orderInfoArray.size; i++) {
		fprintf(ptr, "%d %d %d %d\n", orderInfoArray.orderInfo[i]->orderInfoKey, orderInfoArray.orderInfo[i]->productKey, orderInfoArray.orderInfo[i]->pricePerItem, orderInfoArray.orderInfo[i]->quantity);
	}
	fclose(ptr);
	return true;
}

bool updateOrderInventory(OrderInventoryArray orderInventoryArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("OrderInventory.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", orderInventoryArray.size);
	for (i; i < orderInventoryArray.size; i++) {
		fprintf(ptr, "%d %d %d %d %d %d %d\n", orderInventoryArray.orderInventory[i]->orderInventoryKey, orderInventoryArray.orderInventory[i]->productKey, orderInventoryArray.orderInventory[i]->pricePerItem, orderInventoryArray.orderInventory[i]->quantity, orderInventoryArray.orderInventory[i]->date.day, orderInventoryArray.orderInventory[i]->date.month, orderInventoryArray.orderInventory[i]->date.year);
	}
	fclose(ptr);
	return true;
}

bool updateWorker(WorkerArray workerArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("Worker.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", workerArray.size);
	for (i; i < workerArray.size; i++) {
        fprintf(ptr, "%d %d %d %d %s %s %s %d\n", workerArray.worker[i]->workerKey, strlen(workerArray.worker[i]->firstName), strlen(workerArray.worker[i]->lastName), strlen(workerArray.worker[i]->password), workerArray.worker[i]->firstName, workerArray.worker[i]->lastName, workerArray.worker[i]->password, workerArray.worker[i]->premission);
	}
	fclose(ptr);
	return true;
}

bool updateLaboratory(LaboratoryArray laboratoryArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("Laboratory.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", laboratoryArray.size);
	for (i; i < laboratoryArray.size; i++) {
		fprintf(ptr, "%d %d %d %d %d %d %d %s\n", laboratoryArray.laboratory[i]->laboratoryKey, strlen(laboratoryArray.laboratory[i]->status), laboratoryArray.laboratory[i]->productKey, laboratoryArray.laboratory[i]->workerKey, laboratoryArray.laboratory[i]->entryDate.day, laboratoryArray.laboratory[i]->entryDate.month, laboratoryArray.laboratory[i]->entryDate.year, laboratoryArray.laboratory[i]->status);
	}
	fclose(ptr);
	return true;
}

bool updateOrderClient(OrderClientArray orderClientArray) {
	FILE *ptr = NULL;
	int i = 0;
	int j = 0;
	ptr = fopen("OrderClient.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", orderClientArray.size);
	for (i; i < orderClientArray.size; i++) {
		fprintf(ptr, "%d %d %d %d %d %d %d\n", orderClientArray.orderClient[i]->orderClientKey, orderClientArray.orderClient[i]->clientKey, orderClientArray.orderClient[i]->workerKey, orderClientArray.orderClient[i]->buildComputer, orderClientArray.orderClient[i]->date.day, orderClientArray.orderClient[i]->date.month, orderClientArray.orderClient[i]->date.year);
		fprintf(ptr, "%d", orderClientArray.orderClient[i]->orderInfoKeyArray.size);
		for (j = 0; j < orderClientArray.orderClient[i]->orderInfoKeyArray.size; j++) {
			fprintf(ptr, " %d", orderClientArray.orderClient[i]->orderInfoKeyArray.arr[j]);
		}
		fprintf(ptr, "\n");
	}
	fclose(ptr);
	return true;
}

bool updateProduct(ProductArray productArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("Product.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", productArray.size);
	for (i; i < productArray.size; i++) {
        fprintf(ptr, "%d %d %d %s %s %d %d %d %d %d %d\n", productArray.product[i]->productKey, strlen(productArray.product[i]->productName), strlen(productArray.product[i]->company), productArray.product[i]->productName, productArray.product[i]->company, productArray.product[i]->categoryKey, productArray.product[i]->productionCost, productArray.product[i]->sellingPrice, productArray.product[i]->years, productArray.product[i]->minInventory,productArray.product[i]->amount);
	}
	fclose(ptr);
	return true;
}

bool updateClient(ClientArray clientArray) {
	FILE *ptr = NULL;
	int i = 0;
	ptr = fopen("Client.txt", "w+");
	if (!ptr) {
		return false;
	}
	fprintf(ptr, "%d\n", clientArray.size);
	for (i; i < clientArray.size; i++) {
		fprintf(ptr, "%d %d %d %d %d %d %s %s %s %s %s\n", clientArray.client[i]->clientKey, strlen(clientArray.client[i]->firstName),strlen(clientArray.client[i]->lastName),strlen(clientArray.client[i]->phone), strlen(clientArray.client[i]->email) ,strlen(clientArray.client[i]->address),clientArray.client[i]->firstName, clientArray.client[i]->lastName,  clientArray.client[i]->phone, clientArray.client[i]->email,  clientArray.client[i]->address);
	}
	fclose(ptr);
	return true;
}
