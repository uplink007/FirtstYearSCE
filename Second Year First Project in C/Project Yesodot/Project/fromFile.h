#ifndef FROM_FILE_H
#define FROM_FILE_H

#include "toFile.h"


bool initData(CategoryArray*, OrderInfoArray*, OrderInventoryArray*, WorkerArray*, LaboratoryArray*, OrderClientArray*, ProductArray*, ClientArray*);

bool initCategory(CategoryArray*);

bool initOrderInfo(OrderInfoArray*);

bool initOrderInventory(OrderInventoryArray*);

bool initWorker(WorkerArray*);

bool initLaboratory(LaboratoryArray*);

bool initOrderClient(OrderClientArray*);

bool initProduct(ProductArray*);

bool initClient(ClientArray*);

bool isEmpty(FILE *file);

#endif