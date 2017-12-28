#ifndef TOFILE_H
#define TOFILE_H
#include"AddDelete.h"

bool updateData(CategoryArray, OrderInfoArray, OrderInventoryArray, WorkerArray, LaboratoryArray, OrderClientArray, ProductArray, ClientArray);

bool updateCategory(CategoryArray);

bool updateOrderInfo(OrderInfoArray);

bool updateOrderInventory(OrderInventoryArray);

bool updateWorker(WorkerArray);

bool updateLaboratory(LaboratoryArray);

bool updateOrderClient(OrderClientArray);

bool updateProduct(ProductArray);

bool updateClient(ClientArray);


#endif