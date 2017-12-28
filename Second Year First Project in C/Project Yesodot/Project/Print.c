#include "Print.h"

void printCategory(Category category, int index){
	switch (index){
	case printCode:
		printf("Category key: %d", category.categoryKey);
		break;
	case 0:
		printf("Category name: %s\n", category.categoryName);
		break;
	case 1:
		printf("%s", category.categoryName);
		break;
	default:
		printf("not exist");
		break;
	}
}

void printOrderInfo(OrderInfo orderInfo, int index){
	switch (index){
	case printCode:
		printf("Order info key: %d", orderInfo.orderInfoKey);
		break;
	case 0:
		printf("Order info key: %d\n", orderInfo.orderInfoKey);
		printf("Product Key: %d\n",orderInfo.productKey);
		printf("Quantity: %d\n", orderInfo.quantity);
		printf("Price per item: %d\n", orderInfo.pricePerItem);
		break;
	case 1:
		printf("%d", orderInfo.orderInfoKey);
		break;
	case 2:
		printf("%d", orderInfo.quantity);
		break;
	case 3:
		printf("%d", orderInfo.pricePerItem);
		break;
	default:
		printf("not exist");
		break;
	}
}

void printOrderInventory(OrderInventory orderInventory, int index){
	switch (index){
	case printCode:
		printf("Order inventory key: %d", orderInventory.orderInventoryKey);
		break;
	case 0:
		printf("Product key: %d\n", orderInventory.productKey);
		printf("Quantity: %d\n", orderInventory.quantity);
		printf("Price per item: %d\n", orderInventory.pricePerItem);
		printf("Date: %d/%d/%d\n", orderInventory.date.day, orderInventory.date.month, orderInventory.date.year);
		break;
	case 1:
		printf("%d", orderInventory.productKey);
		break;
	case 2:
		printf("%d", orderInventory.quantity);
		break;
	case 3:
		printf("%d", orderInventory.pricePerItem);
		break;
	case 4:
		printf("%d/%d/%d", orderInventory.date.day, orderInventory.date.month, orderInventory.date.year);
		break;
	default:
		printf("not exist");
		break;
	}
}


void printWorker(Worker worker, int index){
	switch (index){
	case printCode:
		printf("Worker key: %d", worker.workerKey);
		break;
	case 0:
        printf("Worker key: %d\n", worker.workerKey);
		printf("First name: %s\n", worker.firstName);
		printf("Last name: %s\n", worker.lastName);
		printf("Password: %s\n", worker.password);
		printf("Premission: %d\n", worker.premission);
		break;
	case 1:
		printf("%s", worker.firstName);
		break;
	case 2:
		printf("%s", worker.lastName);
		break;
	case 3:
		printf("%s", worker.password);
		break;
	case 4:
		printf("%d", worker.premission);
		break;
	default:
		printf("not exist");
		break;
	}
}

void printLaboratory(Laboratory laboratory, int index){
	switch (index){
	case printCode:
		printf("Laboratory key: %d", laboratory.laboratoryKey);
		break;
	case 0:
		printf("Product key: %d\n", laboratory.productKey);
		printf("Worker key: %d\n", laboratory.workerKey);
		printf("Status: %s\n", laboratory.status);
		printf("Date: %d/%d/%d\n", laboratory.entryDate.day, laboratory.entryDate.month, laboratory.entryDate.year);
		break;
	case 1:
		printf("%d", laboratory.productKey);
		break;
	case 2:
		printf("%d", laboratory.workerKey);
		break;
	case 3:
		printf("%s", laboratory.status);
		break;
	case 4:
		printf("%d/%d/%d", laboratory.entryDate.day, laboratory.entryDate.month, laboratory.entryDate.year);
		break;
	default:
		printf("not exist");
		break;
	}
}

void printOrderClient(OrderClient orderClient, int index){
	int i;
	switch (index){
	case printCode:
		printf("Order client key: %d", orderClient.orderClientKey);
		break;
	case 0:
		printf("Client key: %d\n", orderClient.clientKey);
		printf("Worker key: %d\n", orderClient.workerKey);
		printf("Date: %d/%d/%d\n", orderClient.date.day, orderClient.date.month, orderClient.date.year);
		printf("Order info key array: ");
		for (i = 0; i < orderClient.orderInfoKeyArray.size;i++)
			printf("%d ", orderClient.orderInfoKeyArray.arr[i]);
		printf("\n");
		if (orderClient.buildComputer)
			printf("Build computer: true\n");
		else
			printf("Build computer: false\n");
		break;
	case 1:
		printf("%d", orderClient.clientKey);
		break;
	case 2:
		printf("%d", orderClient.workerKey);
		break;
	case 3:
		printf("%d/%d/%d", orderClient.date.day, orderClient.date.month, orderClient.date.year);
		break;
	case 4:
		for (i = 0; i < orderClient.orderInfoKeyArray.size; i++)
			printf("%d ", orderClient.orderInfoKeyArray.arr[i]);
		break;
	case 5:
		if (orderClient.buildComputer)
			printf("true");
		else
			printf("false");
		break;
	default:
		printf("not exist");
		break;
	}
}

void printProduct(Product product, int index){
	switch (index){
	case printCode:
		printf("Product key: %d", product.productKey);
		break;
	case 0:
		printf("Product name: %s\n", product.productName);
		printf("Selling price: %d\n", product.sellingPrice);
		printf("Production cost: %d\n", product.productionCost);
		printf("Category key: %d\n", product.categoryKey);
		printf("Company: %s\n", product.company);
		printf("Years: %d\n", product.years);
		printf("Minimum: %d\n", product.minInventory);
		printf("Amount: %d\n",product.amount);
		break;
	case 1:
		printf("%s", product.productName);
		break;
	case 2:
		printf("%d", product.sellingPrice);
		break;
	case 3:
		printf("%d", product.productionCost);
		break;
	case 4:
		printf("%d", product.categoryKey);
		break;
	case 5:
		printf("%s", product.company);
		break;
	case 6:
		printf("%d", product.years);
		break;
	case 7:
		printf("%d", product.minInventory);
		break;
    case 8:
        printf("%d", product.amount);
		break;
	default:
		printf("not exist");
		break;
	}
}

void printClient(Client client, int index){
	switch (index){
	case printCode:
		printf("Client key: %d", client.clientKey);
		break;
	case 0:
		printf("Client key: %d\n", client.clientKey);
		printf("First name: %s\n", client.firstName);
		printf("Last name: %s\n", client.lastName);
		printf("Phone: %s\n", client.phone);
		printf("Email: %s\n", client.email);
		printf("Address: %s\n", client.address);
		break;
	case 1:
		printf("%s", client.firstName);
		break;
	case 2:
		printf("%s", client.lastName);
		break;
	case 3:
		printf("%s", client.phone);
		break;
	case 4:
		printf("%s", client.email);
		break;
	case 5:
		printf("%s", client.address);
		break;
	default:
		printf("not exist");
		break;
	}
}
