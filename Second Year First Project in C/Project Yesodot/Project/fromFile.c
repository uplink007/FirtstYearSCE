#define _CRT_SECURE_NO_WARNINGS
#include "fromFile.h"


bool initData(CategoryArray* categoryArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, WorkerArray* workerArray, LaboratoryArray* laboratoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, ClientArray* clientArray) {

	if (!initCategory(categoryArray))
		return false;
	if (!initOrderInfo(orderInfoArray))
		return false;

	if (!initOrderInventory(orderInventoryArray))
		return false;

    if (!initWorker(workerArray))
        return false;

    if (!initLaboratory(laboratoryArray))
        return false;

    if (!initProduct(productArray))
        return false;

    if(!initOrderClient(orderClientArray))
        return false;

   if (!initClient(clientArray))
        return false;


	printf("DATA LOADED SUCCESSFULLY\n");
	return true;
}

bool isEmpty(FILE *file){
	long savedOffset = ftell(file);
	fseek(file, 0, SEEK_END);
	if (ftell(file) == 0)
	{
		return true;
	}

	fseek(file, savedOffset, SEEK_SET);
	return false;
}


bool initCategory(CategoryArray* categoryArray){

	FILE *ptr = NULL;
	int key;
	int nameSize;
	char* name = NULL;
	int i = 0;
	bool flag = true;
	int size;


    categoryArray->category = NULL;
    categoryArray->changed = false;
    categoryArray->size = 0;

	ptr = fopen("Category.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}
	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	categoryArray->size = size;
	//initiating the array
	categoryArray->category = malloc(sizeof(Category*)*categoryArray->size);
	if (categoryArray->category == NULL)
		return false;
	while (i < categoryArray->size && flag){
		if (fscanf(ptr, "%d %d ", &key, &nameSize) != 2)
			flag = false;
		else{
			name = malloc(sizeof(char) * nameSize + 1);
			if (name == NULL)
				flag = false;
			else{
				if (fscanf(ptr, "%s", name) != 1){
                    if(i != 0)
                        destructorCategoryArray(*categoryArray);
					flag = false;
				}
				else{
					categoryArray->category[i] = constructorCategory(key, name);
				}
			}
		}
        free(name);
		i++;
	}
    categoryArray->changed = true;
    fclose(ptr);
	return flag;
}



bool initOrderInfo(OrderInfoArray* orderInfoArray){

	FILE *ptr = NULL;
	bool flag = true;
	int i = 0;
	int orderInfoKey, productKey, quantity, pricePerItem;
	int size;

    orderInfoArray->orderInfo = NULL;
    orderInfoArray->changed = false;
    orderInfoArray->size = 0;


	ptr = fopen("OrderInfo.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}

	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	orderInfoArray->size = size;
	//initiating the array
	orderInfoArray->orderInfo = malloc(sizeof(OrderInfo*)*orderInfoArray->size);
	if (orderInfoArray->orderInfo == NULL)
		return false;
	while (i < orderInfoArray->size && flag){
		if (fscanf(ptr, "%d  %d   %d  %d ", &orderInfoKey, &productKey, &pricePerItem, &quantity) != 4){
			flag = false;
            if(i != 0)
                destructorOrderInfoArray(*orderInfoArray);
		}
		else{
			orderInfoArray->orderInfo[i] = constructorOrderInfo(orderInfoKey, productKey, quantity, pricePerItem);
		}

		i++;
	}

    orderInfoArray->changed = true;
    fclose(ptr);
	return flag;

}

bool initOrderInventory(OrderInventoryArray* orderInventoryArray){

	FILE *ptr = NULL;
	bool flag = true;
	int i = 0;
	int orderInventoryKey, productKey, quantity, pricePerItem;
	Date date;
    int size;
    orderInventoryArray->orderInventory = NULL;
    orderInventoryArray->changed = false;
    orderInventoryArray->size = 0;


	ptr = fopen("OrderInventory.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}

	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	//getting the size of the array
	orderInventoryArray->size = size;
	//initiating the array
	orderInventoryArray->orderInventory = malloc(sizeof(OrderInventory*)*orderInventoryArray->size);
	if (orderInventoryArray->orderInventory == NULL)
		return false;

	while (i < orderInventoryArray->size && flag){
		if (fscanf(ptr, "%d  %d   %d  %d  %d  %d %d ", &orderInventoryKey, &productKey, &quantity, &pricePerItem, &(date.day),&(date.month),&(date.year)) != 7){
			flag = false;
            if(i != 0)
                destructorOrderInventoryArray(*orderInventoryArray);
		}
		else{
			orderInventoryArray->orderInventory[i] = constructorOrderInventory(orderInventoryKey, productKey, quantity, pricePerItem, date);
		}

		i++;
	}
    orderInventoryArray->changed = true;
    fclose(ptr);
	return flag;


}

bool initWorker(WorkerArray* workerArray) {


	FILE *ptr = NULL;
	int key;
	int fnameSize;
	int lnameSize;
	int passwordSize;
	int premission;
	char* fname = NULL;
	char* lname = NULL;
	char* password = NULL;
	int i = 0;
	bool flag = true;
	int size;

    workerArray->worker = NULL;
    workerArray->changed = false;
    workerArray->size = 0;

	ptr = fopen("Worker.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}


	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	workerArray->size = size;
	//initiating the array
	workerArray->worker = malloc(sizeof(Worker*)*workerArray->size);
	if (workerArray->worker == NULL)
		return false;

    while(i < workerArray->size && flag){

            //getting the worker key,first name size, last name size and password size
		if (fscanf(ptr, "%d %d %d %d ", &key, &fnameSize, &lnameSize, &passwordSize) != 4){
            if(i != 0)
                destructorWorkerArray(*workerArray);
			flag = false;
		}


        else{
            //allocating memory for the first name,last name and password
			fname = malloc(sizeof(char) * fnameSize + 1);
			if (fname == NULL){
                if(i != 0)
                    destructorWorkerArray(*workerArray);
				flag = false;
			}

            lname = malloc(sizeof(char) * lnameSize + 1);
			if (lname == NULL){
			    free(fname);
			    if(i != 0)
                    destructorWorkerArray(*workerArray);
				flag = false;

			}

			password = malloc(sizeof(char) * passwordSize + 1);
			if (password == NULL){
                free(fname);
                free(lname);
                if(i != 0)
                    destructorWorkerArray(*workerArray);
				flag = false;
			}

            if (flag == true){
                if (fscanf(ptr, "%s %s %s %d", fname, lname, password, &premission) != 4){
                    flag = false;
                    free(fname);
                    free(lname);
                    free(password);
                    if(i != 0)
                        destructorWorkerArray(*workerArray);
                }
                else{
                    //adding the worker to the array
                    workerArray->worker[i] = constructorWorker(key, fname, lname, password, premission);
                }
            }
        }
        free(fname);
        free(lname);
        free(password);
        i++;
    }


    workerArray->changed = true;
    fclose(ptr);
    return flag;


}

bool initLaboratory(LaboratoryArray* laboratoryArray){

	FILE *ptr = NULL;
	bool flag = true;
	int i = 0;
	int laboratoryKey, productKey, workerKey, statusSize, day, month, year;
    char* status;
	Date date;
	int size;

    laboratoryArray->laboratory = NULL;
    laboratoryArray->changed = false;
    laboratoryArray->size = 0;


	ptr = fopen("Laboratory.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}


	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;

	laboratoryArray->size = size;
	//initiating the array
	laboratoryArray->laboratory = malloc(sizeof(Laboratory*)*laboratoryArray->size);

    while(i < laboratoryArray->size && flag){

        if(fscanf(ptr,"%d %d %d %d %d %d %d",&laboratoryKey,&statusSize,&productKey,&workerKey,&day,&month,&year) != 7){
            if(i != 0)
                destructorLaboratoryArray(*laboratoryArray);
            flag = false;
        }

        status = malloc(sizeof(char) * statusSize + 1);
        if(status == NULL){
            if(i != 0)
                destructorLaboratoryArray(*laboratoryArray);
            flag = false;
        }
        else{
            if(fscanf(ptr,"%s",status) != 1){
                free(status);
                if(i != 0)
                destructorLaboratoryArray(*laboratoryArray);
                flag = false;
            }
            else{
            date.day = day;
            date.month = month;
            date.year = year;
            laboratoryArray->laboratory[i] =constructorLaboratory(laboratoryKey, productKey, workerKey, status,date);
            }
        }
        free(status);
        i++;
    }
    laboratoryArray->changed = true;
    fclose(ptr);
    return flag;
}

bool initOrderClient(OrderClientArray* orderClientArray){
	FILE *ptr = NULL;
	bool flag = true;
	int i = 0,j = 0;
	Date date;
	int size;
	OrderInfoKeyArray infoArray;
    int orderClientKey,clientKey,workerKey,buildComputer,day,month,year;
    orderClientArray->orderClient = NULL;
    orderClientArray->changed = false;
    orderClientArray->size = 0;


	ptr = fopen("OrderClient.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}


	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;

	orderClientArray->size = size;
	//initiating the array
	orderClientArray->orderClient = malloc(sizeof(OrderClient*)*orderClientArray->size);

    while ( i < orderClientArray->size && flag){
            j = 0;
            if(fscanf(ptr,"%d %d %d %d %d %d %d %d", &orderClientKey,&clientKey,&workerKey,&buildComputer,&day,&month,&year,&(infoArray.size)) != 8){
                if(i != 0 )
                    destructorOrderClientArray(*orderClientArray);
                flag = false;
            }
            else{
                //initializing orderInfoKeyArray
                infoArray.arr = malloc(sizeof(int)*infoArray.size);
                if(infoArray.arr == NULL){
                    if(i != 0)
                        destructorOrderClientArray(*orderClientArray);
                    flag = false;
                }

                while( j < infoArray.size && flag ){
                    if(fscanf(ptr,"%d",&(infoArray.arr[j])) != 1){
                        flag = false;
                        if( i != 0)
                            destructorOrderClientArray(*orderClientArray);
                        free(infoArray.arr);
                    }
                    j++;
                }

                if(flag == true){
                    date.day = day;
                    date.month = month;
                    date.year = year;
                    orderClientArray->orderClient[i] = constructorOrderClient(orderClientKey,clientKey,workerKey,infoArray,date,buildComputer);
                }

            }
			free(infoArray.arr);
        i++;
    }

    orderClientArray->changed = true;
    fclose(ptr);
    return flag;

}



bool initProduct(ProductArray* productArray){

    FILE *ptr = NULL;
	bool flag = true;
		int productKey, sellingPrice, productionCost, categoryKey, years, minInventory, amount, nameSize, companySize;
	char *productName=NULL, *company=NULL;
    int size;
	int i = 0;


    productArray->product = NULL;
    productArray->changed = false;
    productArray->size = 0;

	ptr = fopen("Product.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}

	//getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	productArray->size = size;
	//initiating the array
	productArray->product = malloc(sizeof(Product*)*productArray->size);

    while(i < productArray->size && flag){

        if(fscanf(ptr,"%d %d %d",&productKey, &nameSize, &companySize)!= 3){
            if(i != 0)
                destructorProductArray(*productArray);
            flag = false;
        }
        else{
            //allocating memory for the first name,last name and password
			productName = malloc(sizeof(char) * nameSize + 1);
			if (productName == NULL){
			    if(i != 0)
                    destructorProductArray(*productArray);
				flag = false;
			}

            company = malloc(sizeof(char) * companySize + 1);
			if (company == NULL){
			    free(productName);
			    if(i != 0)
                    destructorProductArray(*productArray);
				flag = false;
			}

			if (flag == true){
                if(fscanf(ptr,"%s %s %d %d %d %d %d %d",productName,company,&categoryKey,&productionCost,&sellingPrice,&years,&minInventory, &amount) != 8){
                    free(productName);
                    free(company);
                    if(i != 0)
                        destructorProductArray(*productArray);
                    flag = false;

                }
                else{
                    productArray->product[i] = constructorProduct(productKey,categoryKey,sellingPrice,productionCost,years,minInventory,productName,company,amount);
                }
			}
        }

        free(productName);
        free(company);
        i++;
    }

    productArray->changed = true;
    fclose(ptr);
    return flag;
}

bool initClient(ClientArray* clientArray){


    FILE *ptr = NULL;
	bool flag = true;

    int clientKey,fnameSize,lnameSize,phoneSize,emailSize,addressSize;
	char* firstName=NULL;
	char* lastName = NULL;
	char* phone = NULL;
	char* email = NULL;
	char* address = NULL;
    int size;
	int i = 0;

    clientArray->client = NULL;
    clientArray->changed = false;
    clientArray->size = 0;
	ptr = fopen("Client.txt", "a+");
	if (!ptr) {
		return false;
	}
	if (isEmpty(ptr)){
		return true;
	}


    //getting the size of the array
	if(fscanf(ptr,"%d",&size)!=1)
        return false;
	clientArray->size = size;
	//initiating the array
	clientArray->client = malloc(sizeof(Client*)*clientArray->size);

    while( i < clientArray->size && flag){
        if(fscanf(ptr,"%d %d %d %d %d %d",&clientKey,&fnameSize,&lnameSize,&phoneSize,&emailSize,&addressSize) != 6){
            if(i != 0)
                destructorClientArray(*clientArray);
            flag = false;
        }
        else{
            //allocating memory for the first name,last name and password
			firstName = malloc(sizeof(char) * fnameSize + 1);
			if (firstName == NULL){
			    if(i != 0)
                    destructorClientArray(*clientArray);
				flag = false;
			}

            lastName = malloc(sizeof(char) * lnameSize + 1);
			if (lastName == NULL){
			    free(firstName);
			    if(i != 0)
                    destructorClientArray(*clientArray);
				flag = false;
			}

            //allocating memory for the first name,last name and password
			phone = malloc(sizeof(char) * phoneSize + 1);
			if (phone == NULL){
                free(firstName);
                free(lastName);
                if(i != 0)
                    destructorClientArray(*clientArray);
				flag = false;
			}

            email = malloc(sizeof(char) * emailSize + 1);
			if (email == NULL){
                free(firstName);
                free(lastName);
                free(phone);
                if(i != 0)
                    destructorClientArray(*clientArray);
				flag = false;
			}

            address = malloc(sizeof(char) * addressSize + 1);
            if( address == NULL){
                free(firstName);
                free(lastName);
                free(phone);
                free(email);
                if(i != 0)
                    destructorClientArray(*clientArray);
                flag = false;
            }

            if ( flag == true){
                if(fscanf(ptr, "%s %s %s %s %s",firstName,lastName,phone,email,address) != 5){
                    free(firstName);
                    free(lastName);
                    free(phone);
                    free(email);
                    free(address);
                    if(i != 0)
                        destructorClientArray(*clientArray);
                    flag = false;
                }
            else{
                clientArray->client[i] = constructorClient(clientKey,firstName,lastName,phone,email,address);
            }
            }


        }

        free(firstName);
        free(lastName);
        free(phone);
        free(email);
        free(address);
        i++;
    }


    clientArray->changed = true;
    fclose(ptr);
    return flag;
}
