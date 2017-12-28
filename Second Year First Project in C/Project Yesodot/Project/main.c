
#define _CRT_SECURE_NO_WARNINGS


#include "toFile.h"
#include "fromFile.h"
#include"Print.h"
#include"time.h"


#define PASSWORD 50
#define STRING 200
#define PRODUCTARRAY_SIZE 200
#define CATEGORY_SIZE 100
bool login(WorkerArray,Worker**);
bool printTree(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);


//activities
bool addNewProduct(ProductArray*,CategoryArray*); //17
bool addNewCategory(CategoryArray*);//20
bool printAllCategories(CategoryArray*);//34
bool printAllProductsForMinInventroy(ProductArray*);//19
bool removeProdcutFromTheShelf(ProductArray*);//18
bool printClientOrderByRangeOfDate(OrderClientArray*,OrderInfoArray*);//32
bool addNewOrderInventory(OrderInventoryArray*, ProductArray*);//25
bool addNewClient(ClientArray*);//4
bool showOrderInventory(OrderInventoryArray* orderInventoryArray);//6

void editOrderInventory(OrderInventoryArray*, int);

bool addNewWorker(WorkerArray*);//28
bool showWorker(WorkerArray* workerArray, int premission);//29-M,33-REST

bool editWorker(WorkerArray* workerArray, int);

void PrintSoldProductsInTheMonth(OrderInfoArray*, OrderClientArray*, ProductArray*);//16
bool ShowProduct(ProductArray*,int);//38-READ,23-M
bool productsOfCategory(CategoryArray* ,ProductArray* );//21
bool editProduct(ProductArray* productArray, int index);
bool addToCart(Product*, OrderInfoArray*, int* orderInfoKey);
bool SellProduct(ProductArray*, ClientArray*,OrderClientArray*,OrderInfoArray*,Worker*, int*,int size,bool);

bool showOrderInventoryReadOnly(OrderInventoryArray* orderInventoryArray);//35
bool completeMinInventoryOrders(OrderInventoryArray* orderInventoryArray,ProductArray* productArray,int* allow);//10
bool makeOrderInventory(OrderInventoryArray* orderInventoryArray,ProductArray* productArray);
bool getOrderInventoryToProducts(OrderInventoryArray* orderInventoryArray,ProductArray* productArray,int* allow);//11
bool showAllProductsFromTheShop(ProductArray* ,CategoryArray* ,ClientArray* ,OrderClientArray* ,OrderInfoArray* ,Worker* );//12,36,37
bool printAllProductsFromTheShop(ProductArray*,CategoryArray*);//27


bool sellItem(ProductArray*,CategoryArray*,ClientArray*,OrderClientArray*,OrderInfoArray*,Worker*);//1
bool sellItemByBuild(ProductArray*,CategoryArray*,ClientArray*,OrderClientArray*,OrderInfoArray*,Worker*);//2




//Ariel
bool repairProduct(ProductArray* productArray, LaboratoryArray* laboratoryArray, WorkerArray* workerArray, Worker* worker);//3
bool addItemInLaboratory(ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user);
bool editItemInLaboratory(ProductArray* productArray, LaboratoryArray* laboratoryArray, WorkerArray* workerArray);
void showItemsInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray);//13
void showItemInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray, int index);//9
bool showItemsInLaboratoryWithTime(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray); //14
bool showDelayItemInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray);//15
Date addDaysToDate(Date date, int days);
bool isLeapYear(int year);
int differenceBetweenTwoDates(Date date1, Date date2);

//new
bool printBuildableOrders(OrderInfoArray* orderInfoArray, OrderClientArray* orderClientArray);//24





//menu
bool administrationM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool laboratoryM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool reports(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool inventories(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool productsM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool warehouseM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool storeM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool sellingM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool sellingReportsM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool clientsM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool usersM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool adminReportsM(CategoryArray*, WorkerArray*, ClientArray*, OrderInfoArray*, OrderInventoryArray*, OrderClientArray*, ProductArray*, LaboratoryArray*, Worker*);
bool laboratoryReportsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user);
bool laboratoryRepairsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user);


bool showOrderClient(OrderClientArray*,OrderInfoArray*,ProductArray*,ClientArray*,int);//22 -M, 39 - READ
bool showClient(ClientArray*,int permission);//5 - M,S ,40-READ
bool editClient(ClientArray*,int);
bool printAllClients(ClientArray*);//30 - M,S,T
bool printAllWorkers(WorkerArray*);//31 - M


//new
bool printOrderInventoryByRangeOfDate(OrderInventoryArray*);//26 every one
void printExpense(OrderInventoryArray* orderinventory);//8 administrator
void printEarning(OrderClientArray* orderClientArray, OrderInfoArray* orderInfoArray, ProductArray* productArray);//7 administrator








typedef struct {
	int index;
	char string[STRING];
} Tuple;
typedef struct {
	Tuple** arr;
	int size;
}StringTupleArray;
void swapTuple(Tuple** first, Tuple** second);
/*
int i;
StringTupleArray temp;
temp.size = workerArray->size;
temp.arr = malloc(sizeof(Tuple*)*temp.size);
for (i = 0; i < temp.size; i++) {
temp.arr[i] = malloc(sizeof(Tuple));
strcpy(temp.arr[i]->string, workerArray->worker[i]->firstName);
temp.arr[i]->index = i;
}
quickSortStrings(&temp, ZERO, temp.size - ONE);
for (i = 0; i < temp.size; i++) {
printf("%s---->%d\n", temp.arr[i]->string,temp.arr[i]->index);
}
for (i = 0; i < temp.size; i++) {
free(temp.arr[i]);
}
free(temp.arr);
*/
void quickSortStrings(StringTupleArray* stringTupleArray, int left, int right);
/*
int** tmp;
tmp = malloc(sizeof(int*)*(orderInfoArray->size));
for (i = 0; i < orderInfoArray->size; i++) {
tmp[i] = malloc(sizeof(int) * 2);
tmp[i][0] = orderInfoArray->orderInfo[i]->pricePerItem;
tmp[i][1] = i;
}
quickSortInts(&tmp, ZERO, orderInfoArray->size - ONE);
for (i = 0; i < orderInfoArray->size; i++) {
printf("%d---->%d\n", tmp[i][0],tmp[i][1]);
}
for (i = 0; i < orderInfoArray->size; i++) {
free(tmp[i]);
}
free(tmp);
*/
void quickSortInts(int*** arr, int left, int right);
void swapInts(int** first, int** second);


void quickSortStrings(StringTupleArray* stringTupleArray, int left, int right) {
	int i, last;
	if (left >= right)//end case
		return ;

	swapTuple(&stringTupleArray->arr[left], &stringTupleArray->arr[((left + right) / TWO)]);
	last = left;
	for (i = left + ONE; i <= right; i++) {
		if (0 > strcmp(stringTupleArray->arr[i]->string, stringTupleArray->arr[left]->string)) {
			swapTuple(&stringTupleArray->arr[++last], &stringTupleArray->arr[i]);
		}
	}
	swapTuple(&stringTupleArray->arr[left], &stringTupleArray->arr[last]);
	quickSortStrings(stringTupleArray, left, last - ONE);//1 left array
	quickSortStrings(stringTupleArray, last + ONE, right);//2 right array
}
void swapTuple(Tuple** first, Tuple** second) {
	Tuple* temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

void swapInts(int** first, int** second) {
	int* temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

void quickSortInts(int*** arr, int left, int right) {
	int i, last;
	if (left >= right)//end case
		return;

	swapInts(&(*arr)[left], &(*arr)[((left + right) / TWO)]);
	last = left;
	for (i = left + ONE; i <= right; i++) {
		if ((*arr)[i][0]< (*arr)[left][0]) {
			swapInts(&(*arr)[++last], &(*arr)[i]);
		}
	}
	swapInts(&(*arr)[left], &(*arr)[last]);
	quickSortInts(arr, left, last - ONE);//1 left array
	quickSortInts(arr, last + ONE, right);//2 right array
}







/*
#define ? 176
#define ? 177
#define ? 178
*/

//helper functions
bool checkDate(Date d1);
int compareDates(Date d1,Date d2);



int main() {
	Worker* user;
	bool flagFail = false, flagPremition = true;
	CategoryArray categoryArray;
	categoryArray.category = NULL;

	OrderInfoArray orderInfoArray;
	orderInfoArray.orderInfo = NULL;

	OrderInventoryArray orderInventoryArray;
	orderInventoryArray.orderInventory = NULL;

	WorkerArray workerArray;
	workerArray.worker = NULL;

	LaboratoryArray laboratoryArray;
	laboratoryArray.laboratory = NULL;

	OrderClientArray orderClientArray;
	orderClientArray.orderClient = NULL;

	ProductArray productArray;
	productArray.product = NULL;

	ClientArray clientArray;
	clientArray.client = NULL;
	flagFail = initData(&categoryArray, &orderInfoArray, &orderInventoryArray, &workerArray, &laboratoryArray, &orderClientArray, &productArray, &clientArray);

	flagPremition = login(workerArray, &user);
	//SellProduct(&productArray,&clientArray, &orderClientArray, &orderInfoArray, user, arr,11, false);
	//showAllProductsFromTheShop(&productArray,&categoryArray,&clientArray,&orderClientArray,&orderInfoArray,user);
	//printAllProductsFromTheShop(&productArray,&categoryArray);
    //sellItem(&productArray,&categoryArray,&clientArray,&orderClientArray,&orderInfoArray,user);
    //sellItemByBuild(&productArray,&categoryArray,&clientArray,&orderClientArray,&orderInfoArray,user);
    //productsOfCategory(&categoryArray,&productArray);
    //showOrderClient(&orderClientArray,&orderInfoArray,&productArray,&clientArray,user->premission);
    //showClient(&clientArray,user->premission);
    //printAllClients(&clientArray);
    //printAllWorkers(&workerArray);




	if (flagPremition && flagFail) {
		flagFail = printTree(&categoryArray, &workerArray, &clientArray, &orderInfoArray, &orderInventoryArray, &orderClientArray, &productArray, &laboratoryArray, user);
	}

	updateData(categoryArray, orderInfoArray, orderInventoryArray, workerArray, laboratoryArray, orderClientArray, productArray, clientArray);
	destructorCategoryArray(categoryArray);
	destructorOrderInfoArray(orderInfoArray);
	destructorOrderInventoryArray(orderInventoryArray);
	destructorWorkerArray(workerArray);
	destructorLaboratoryArray(laboratoryArray);
	destructorOrderClientArray(orderClientArray);
	destructorProductArray(productArray);
	destructorClientArray(clientArray);
	return !flagFail;
}

bool login(WorkerArray workerArray,Worker** user) {
	int userKey=0,index,userInput = 0;
	char password[PASSWORD],c;
	do {
		if (userInput > 0) {
			printf("Wrong input,you have %d tries left", THREE - userInput);
		}
		printf("Enter userKey:\n");
		if(userInput)
			while ((c = getchar()) != '\n');
		userInput++;

		fflush(stdin);
	} while (userInput<FOUR && scanf("%d", &userKey)!=ONE);
	if (userInput > THREE) {
		return false;
	}
	printf("Enter password:\x1b[30m\n");
	scanf("%s",password);
	printf("\x1b[0m\n");
	searchWorker(workerArray, user, &index, userKey);
	if (*user == NULL) {
		printf("There is no such worker in the system!!!\n");
		return false;
	}
	if (strcmp((*user)->password,password)) {
		printf("Wrong password!!!\n");
		return false;
	}
	return true;
}

bool printTree(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {


	int choice;
	char c;
	bool exitFlag = false;
	bool flag = true;
	do {
		printf("\x1b[32mWelcome to AMTS store system!!!\n");
		printf("\x1b[31m**********************************************************************************************\n");
		printf("\x1b[31m**                      \x1b[36m ______   __       __  ________   ______         _   _              \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m  _______________ \x1b[36m    /      \\ |  \\     /  \\|        \\ /      \\ \x1b[34m      |*\\_/*|________     \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m |  ___________  |\x1b[36m |  $$$$$$\\| $$\\   /  $$ \\$$$$$$$$|  $$$$$$\\    \x1b[34m   ||_/-\\_|______  |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m | |           | | \x1b[36m| $$__| $$| $$$\\ /  $$$   | $$   | $$___\\$$     \x1b[34m  | |           | |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m | | \x1b[31m  0   0 \x1b[34m  | |\x1b[36m | $$    $$| $$$$\\  $$$$   | $$    \\$$    \\     \x1b[34m   | | \x1b[31m  0   0 \x1b[34m  | |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m | |     -     | | \x1b[36m| $$$$$$$$| $$\\$$ $$ $$   | $$    _\\$$$$$$\\    \x1b[34m   | |     -     | |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m | |   \\___/   | |\x1b[36m | $$  | $$| $$ \\$$$| $$   | $$   |  \\__| $$    \x1b[34m   | |   \\___/   | |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m | |___     ___| | \x1b[36m| $$  | $$| $$  \\$ | $$   | $$    \\$$    $$      \x1b[34m | |___________| |    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m |_____|\\_/|_____| \x1b[36m \\$$   \\$$ \\$$      \\$$    \\$$     \\$$$$$$  \x1b[34m      |_______________|    \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m   _|__|/ \\|_|_........................................................._|________|_      \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m  / ********** \\                                                    \x1b[34m   / ********** \\     \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m/  ************  \\                                                \x1b[34m   /  ************  \\   \x1b[31m**\n");
		printf("\x1b[31m**\x1b[34m-------------------                                               \x1b[34m  --------------------  \x1b[31m**\n");
		printf("\x1b[31m**********************************************************************************************\x1b[0m\n");
		printf("Choose what department you want to enter:\n0-Exit\n1-Shop\n2-Warehouse\n");
		if (user->premission)
			printf("3-Laboratory\n4-Administration\n");
		printf("Enter yor choice here:");//user->premission==0 => Technician
		while (1 != scanf("%d", &choice) || !(choice == 0 || choice == 1 || choice == 2 || (choice == 3 && user->premission != storekeeper) || (user->premission != storekeeper&&choice == 4))) {
			printf("Wrong input try again\nEnter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0==choice)
			exitFlag = true;
		if (!exitFlag) {

        if(choice == 1)
            flag = storeM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(choice == 4)
            flag = administrationM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(choice == 2)
            flag = warehouseM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(choice == 3)
            flag = laboratoryM(categoryArray,workerArray,clientArray,orderInfoArray,orderInventoryArray,orderClientArray,productArray,laboratoryArray,user);
		}
	} while (!exitFlag && flag);
	return flag;
}

//if order inventory array is not empty
bool showOrderInventory(OrderInventoryArray* orderInventoryArray){
    int i,index,option,orderInventoryKey;
    OrderInventory* tmp = NULL;
    int size = orderInventoryArray->size;


    printf("***********************************\n");
    printf("Show order inventory\n");
    printf("***********************************\n");


    if(size != 0){

        printf("Please choose between 2 options:\n1.Get order inventory by key.\n2.Show all inventory orders and pick a key\n");

        if (1 != scanf("%d", &option)) {
            printf("The input is wrong. returning to the main menu\n");
            return true;
        }


        if(option == 1){
            printf("Please enter the order inventory key that you want to get:\nEnter the key here:");
            if (1 != scanf("%d", &orderInventoryKey)) {
                printf("The input is wrong please come back when u have the order inventory key\n");
                return true;
            }

            searchOrderInventory(*orderInventoryArray,&tmp,&index,orderInventoryKey);
            if(tmp == NULL){
                printf("Order inventory key does not exist. Returning to the main menu\n");
                return true;
            }
        }


        if(option == 2){
            for(i=0; i < orderInventoryArray->size;i++){
                printf("___________________________\n");
                printf("Order inventory number %d:\n",i);
                printOrderInventory(*(orderInventoryArray->orderInventory[i]),0);
                printf("___________________________\n");
            }
            printf("Please choose the number of the order inventory:\n");
            do{
                if (1 != scanf("%d", &option)) {
                    printf("The input is wrong. returning to the main menu\n");
                    return true;
                }
                if( option > orderInventoryArray->size - 1 || option < 0 ){
                    printf("You picked a wrong number. returning to the main menu\n");
                    return true;
                }
            }while( option > orderInventoryArray->size - 1 || option <0 );
            index = option;
        }
        printf("________________________\n");
        printf("You choose the following order inventory:\n");
        printOrderInventory(*(orderInventoryArray->orderInventory[index]),0);
        printf("________________________\n");
        printf("Editing order inventory...\n");
        editOrderInventory(orderInventoryArray,index);
        printf("The edited order inventory is:\n");
        printf("________________________\n");
        printOrderInventory(*(orderInventoryArray->orderInventory[index]),0);
        printf("________________________\n");


    }
    else{
        printf("There are no orders\n");
    }

    printf("Press any key to continue...\n");
    getchar();
    getchar();

    return true;

}



bool checkDate(Date d1){
    int days = 31;
    if (d1.month < 1 || d1.month > 12) {
        return 0;
    }
    if (d1.day < 1) {
        return 0;
    }


    if (d1.month == 2) {
        days = 28;
        if (d1.year % 400 == 0 || (d1.year % 4 == 0 && d1.year % 100 != 0)) {
            days = 29;
        }
    } else if (d1.month == 4 || d1.month == 6 || d1.month == 9 || d1.month == 11) {
        days = 30;
    }

    if (d1.day > days) {
        return 0;
    }
    return 1;

}

//returns -1 if d2 is bigger, 1 if d1 is bigger, 0 if they are equal
int compareDates(Date d1,Date d2){

    if (d1.year < d2.year)
       return -1;

    else if (d1.year > d2.year)
       return 1;

    if (d1.year == d2.year)
    {
         if (d1.month < d2.month)
              return -1;
         else if (d1.month > d2.month)
              return 1;
         else if (d1.day < d2.day)
              return -1;
         else if(d1.day > d2.day)
              return 1;
         else
              return 0;
    }
    return 0;
}

bool printClientOrderByRangeOfDate(OrderClientArray* orderClientArray,OrderInfoArray* orderInfoArray){

    printf("***********************************\n");
    printf("Printing client order by date range\n");
    printf("***********************************\n");

    int i,j,index;
    OrderClient* orderClient = NULL;
   OrderInfo* orderInfo = NULL;
    Date d1,d2,tmp;

    printf("Please enter 2 Dates:format(day month year)\n");
    printf("Please enter the first date\n");
    if (3 != scanf("%d %d %d",&(d1.day),&(d1.month),&(d1.year) )) {
        printf("The input is wrong please come back when u have the product key\n");
        return true;
    }
    printf("Please enter the second date\n");
    if (3 != scanf("%d %d %d",&(d2.day),&(d2.month),&(d2.year) )) {
        printf("The input is wrong please come back when u have the product key\n");
        return true;
    }
    //checking if the dates are valid
    if(!checkDate(d1) || !checkDate(d2)){
        printf("One of the dates you entered is not a valid date! Returning to the main menu\n");
        return true;
    }
    if(compareDates(d1,d2) == 1){
        tmp = d1;
        d1 = d2;
        d2 = tmp;
    }

    printf("Printing all the orders in the range:\n");
    for(i = 0;i<orderClientArray->size;i++){
            orderClient = orderClientArray->orderClient[i];
            if(compareDates(orderClient->date,d1) >=0 && compareDates(orderClient->date,d2) <= 0){
                printf("****************************************\n");
                printOrderClient(*orderClient,0);

                for(j = 0; j<orderClient->orderInfoKeyArray.size;j++){
                    searchOrderInfo(*orderInfoArray,&orderInfo,&index,orderClient->orderInfoKeyArray.arr[j]);
                    if(orderInfo){
                        printf("____________________________________________\n");
                        printOrderInfo(*orderInfo,0);
                        printf("____________________________________________\n");
                    }
                }
                printf("****************************************\n");
            }
    }
    return true;
}

bool removeProdcutFromTheShelf(ProductArray* productArray){

    printf("***********************************\n");
    printf("Removing product from the shelf\n");
    printf("***********************************\n");

    int productKey;
    int index;
    Product* tmp = NULL;
    printf("Please enter the product key for the item you wish to remove from the shelf:\n");
    if (1 != scanf("%d", &productKey)) {
        printf("The input is wrong please come back when u have the product key\n");
        return true;
    }

    searchProduct(*productArray,&tmp,&index,productKey);
    if(tmp == NULL){
        printf("Product does not exist. You will return to the main menu\n");
        return true;
    }
    printf("Removing product: ");
    printProduct(*tmp,1);
    printf("\n");
    tmp->amount = 0;

    return true;

}

bool printAllProductsForMinInventroy(ProductArray* productArray){

    printf("***********************************\n");
    printf("Printing all Products that need to be resupplied\n");
    printf("***********************************\n");

    int i;
    Product* product = NULL;

    for(i = 0; i< productArray->size;i++){
        product = productArray->product[i];
        if(product->minInventory >product->amount){
            printf("**********************************************\n");
            printf("Category key: ");
            printProduct(*product,4);
            printf("\n");
            printf("Category name: ");
            printProduct(*product,1);
            printf("\n");
            printf("**********************************************\n");
        }
    }

    return true;

}

bool printAllCategories(CategoryArray* categoryArray){

    printf("***********************************\n");
    printf("Printing all categories\n");
    printf("***********************************\n");

    int i;
    printf("Printing all the categories:\n");
    for(i = 0; i < categoryArray->size;i++){
        printf("%d.",i + 1);
        printCategory(*categoryArray->category[i],0);
    }
    return true;
}

bool addNewCategory(CategoryArray* categoryArray){

    printf("***********************************\n");
    printf("Adding new category\n");
    printf("***********************************\n");

    int categoryKey;
    Category *tmp = NULL;
    char categoryName[STRING];
    bool flag = false;
    char ch,c;
    int index;
    int i = 0;

    do{
        fflush(stdin);
        printf("Please enter the category key that you want to add:\nEnter the key here:");
		if (1 != scanf("%d", &categoryKey)) {
			printf("The input is wrong please come back when u have the product key\n");
			return true;
		}
        printf("Are you sure?(y-yes,n-no):");
		while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &ch) || !(ch == 'y' || ch == 'n')) {
			if (ch != '\n')
				printf("wrong input try again\n");
			while ((c = getchar()) != '\n');
		}
		if (ch == 'y')
			flag = true;
    }while(!flag);
    //searching if the key exists
    searchCategory(*categoryArray,&tmp,&index,categoryKey);
    if (tmp) {
        printf("The category key already exists,you will be now returned to the main menu.");
		return true;
	}

    flag = true;
	fflush(stdin);

    printf("Please enter the category name you want to add:(press 0 to return to the main menu)\n");
    scanf("%s",categoryName);
    if(strcmp(categoryName,"0") == 0){
        printf("Returning to main menu\n");
        return true;
    }

    //searching if the category name already exists
    while( categoryArray->size > i && flag){
        if(strcmp(categoryName,categoryArray->category[i]->categoryName) == 0)
            flag = false;
        i++;
    }
    if(flag == false){
        printf("Category already exists. You will now return the the main menu.");
        return true;
    }

    //building the new category
    tmp = constructorCategory(categoryKey,categoryName);
	if (tmp) {
		flag = addDeleteCategory(categoryArray,add,*tmp);
		destructorCategory(tmp);
	}
	else{
		return false;
	}
	return flag;

}


/*Have to be Category*/
bool addNewProduct(ProductArray* productArray,CategoryArray* categoryArray) {

    printf("***********************************\n");
    printf("Adding new product\n");
    printf("***********************************\n");

	int productKey,index;
	bool flag = false;
	char chr,c;
	char productName[STRING];
	int sellingPrice;
	int productionCost;
	int categoryKey;
	char company[STRING];
	int years;
	int minInventory;
	int amount;
	Product* temp=NULL;
	Category* tempCategory=NULL;
	do {
		fflush(stdin);
		printf("Please enter the product key that you want to add:\nEnter the key here:");
		if (1 != scanf("%d", &productKey)) {
			printf("The input is wrong please come back when u have the product key\n");
			return true;
		}
		printf("Are you sure?(y-yes,n-no):");
		while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			if (chr != '\n')
				printf("wrong input try again\n");
			while ((c = getchar()) != '\n');
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	searchProduct(*productArray,&temp,&index,productKey);
	if (temp) {
		printf("The product already exist,you will be now returned to the main menu.");
		return true;
	}
	flag = false;
	fflush(stdin);
	do {
		printf("Please enter rest details:\nProductName:");
		scanf("%s", productName);
		printf("Company:");
		scanf("%s", company);
		printf("Selling price:");
		while (1 != scanf("%d", &sellingPrice)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Production cost:");
		while (1 != scanf("%d", &productionCost)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Garanty years:(number)");
		while (1 != scanf("%d", &years)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Minimum inventory store:");
		while (1 != scanf("%d", &minInventory)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Amount of the product:");
		while (1 != scanf("%d", &amount)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Category key:\nChoose from existed:\n");
		for (index = 0; index < categoryArray->size; index++) {
			printCategory(*categoryArray->category[index], 0);
			printf("-");
			printCategory(*categoryArray->category[index], -1);
			printf("\n");
		}
		do {
			while (1 != scanf("%d", &categoryKey)) {
				printf("wrong input try again");
				while ((c = getchar()) != '\n');
			}
			searchCategory(*categoryArray, &tempCategory, &index, categoryKey);
			if (!tempCategory) {
				printf("wrong input try again");
				fflush(stdin);
			}
		} while (!tempCategory);

		printf("Product key:%d\nProduct name:%s\nProduct company:%s\nSelling price:%d\nProduction cost:%d\nGaranty years:%d\nMininum inventory:%d\nAmount:%d\nCategory key:%d\nAre you shure?(y-yes,n-no):",productKey,productName,company,sellingPrice,productionCost,years,minInventory,amount,categoryKey);
		while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	flag = false;
	temp = constructorProduct(productKey, categoryKey, sellingPrice, productionCost, years, minInventory, productName, company, amount);
	if (temp) {
		flag = addDeleteProduct(productArray, add, *temp);
		destructorProduct(temp);
	}
	else{
		return false;
	}
	return flag;
}


/*Have to be products*/
bool addNewOrderInventory(OrderInventoryArray* orderInventoryArray, ProductArray* productArray) {

    printf("***********************************\n");
    printf("Adding new order inventory\n");
    printf("***********************************\n");


	int orderInventoryKey, index;
	bool flag = false;
	char chr,c;
	int pricePerItem;
	int productKey;
	int quantity;
	Date date;
	date.day = 0;
	date.month = 0;
	date.year = 0;
	OrderInventory* temp = NULL;
	Product* tempProduct = NULL;
	do {
		fflush(stdin);
		printf("Please enter the order inventory key that you want to add:\nEnter the key here:");
		if (1 != scanf("%d", &orderInventoryKey)) {
			printf("The input is wrong please come back when u have the order inventory key\n");
			return true;
		}
		printf("Are you sure?(y-yes,n-no):");
		while ((c = getchar()) != '\n');
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			if(chr!='\n')
				printf("wrong input try again\n");
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	searchOrderInventory(*orderInventoryArray, &temp, &index, orderInventoryKey);
	if (temp) {
		printf("The order already exist,you will be now returned to the main menu.");
		return true;
	}
	flag = false;
	fflush(stdin);
	do {
		printf("Product key:\nChoose from existed:\n");
		for (index = 0; index < productArray->size; index++) {
			printProduct(*productArray->product[index], 0);
			printf("-");
			printProduct(*productArray->product[index], -1);
			printf("\n");
		}
		do {
			while (1 != scanf("%d", &productKey)) {
				printf("wrong input try again");
				while ((c = getchar()) != '\n');
			}
			searchProduct(*productArray, &tempProduct, &index, productKey);
			if (!tempProduct) {
				printf("wrong input try again");
				fflush(stdin);
			}
		} while (!tempProduct);
		pricePerItem = tempProduct->sellingPrice;
		printf("Quantity of the products:");
		while (1 != scanf("%d", &quantity)) {
			printf("wrong input try again");
			while ((c = getchar()) != '\n');
		}
		printf("Order Inventory key:%d\nProductKey:%d\nProduct quantity:%d\nPrice per item:%d\nAre you shure?(y-yes,n-no):", orderInventoryKey, productKey, quantity, pricePerItem);
		while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			printf("wrong input try again");
			fflush(stdin);
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	flag = false;
	temp = constructorOrderInventory(orderInventoryKey, productKey, quantity, pricePerItem, date);
	if (temp) {
		flag = addDeleteOrderInventory(orderInventoryArray, add, *temp);
		destructorOrderInventory(temp);
	}
	else {
		return false;
	}
	return flag;
}



bool addNewClient(ClientArray* clientArray) {

    printf("***********************************\n");
    printf("Adding new client\n");
    printf("***********************************\n");


	int clientKey, index;
	bool flag = false;
	char firstName[STRING];
	char lastName[STRING];
	char phone[STRING];
	char email[STRING];
	char address[STRING];
	char chr,c;
	Client* temp;
	do {
		fflush(stdin);
		printf("Please enter the client key that you want to add:\nEnter the key here:");
		if (1 != scanf("%d", &clientKey)) {
			printf("The input is wrong please come back when u have the client key\n");
			return true;
		}
		printf("Are you sure?(y-yes,n-no):");
        while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			if(chr!='\n')
				printf("wrong input try again\n");
			fflush(stdin);
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	searchClient(*clientArray, &temp, &index, clientKey);
	if (temp) {
		printf("The client already exist,you will be now returned to the main menu.");
		return true;
	}
	flag = false;
	fflush(stdin);
	do {
		printf("Please enter rest details:\nFirst Name:");
		scanf("%s", firstName);
		printf("Last Name:");
		scanf("%s", lastName);
		printf("Phone:");
		scanf("%s", phone);
		printf("Email:");
		scanf("%s", email);
		printf("Address:");
		scanf("%s", address);
		printf("Client key:%d\nFirst name:%s\nLast Name:%s\nPhone number:%s\nEmail:%s\nAddress:%s\nAre you shure?(y-yes,n-no):", clientKey, firstName, lastName, phone, email, address);
        while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			printf("wrong input try again");
			fflush(stdin);
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	flag = false;
	temp = constructorClient(clientKey, firstName, lastName, phone, email, address);
	if (temp) {
		flag = addDeleteClient(clientArray, add, *temp);
		destructorClient(temp);
	}
	else {
		return false;
	}
	return flag;
}


bool addNewWorker(WorkerArray* workerArray) {

    printf("***********************************\n");
    printf("Adding new worker\n");
    printf("***********************************\n");



	char password[STRING];
	int permission;
	int workerKey, index;
	bool flag = false;
	char firstName[STRING];
	char lastName[STRING];
	char chr,c;
	Worker* temp;

	do {
		fflush(stdin);
		printf("Please enter the worker key that you want to add:\nEnter the key here:");
		if (1 != scanf("%d", &workerKey)) {
			printf("The input is wrong please come back when u have the worker key\n");
			return true;
		}
		printf("Are you sure?(y-yes,n-no):");
        while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			if (chr != '\n')
				printf("wrong input try again\n");
			fflush(stdin);
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);

	searchWorker(*workerArray, &temp, &index, workerKey);
	if (temp) {
		printf("The worker already exist,you will be now returned to the main menu.");
		return true;
	}
	flag = false;
	fflush(stdin);
	do {
		printf("Please enter rest details:\nFirst Name:");
		scanf("%s", firstName);
		printf("Last Name:");
		scanf("%s", lastName);
		printf("Password:");
		scanf("%s", password);
		printf("Permission:");
		scanf("%d", &permission);
		printf("Worker key:%d\nFirst name:%s\nLast Name:%s\nPassword number:%s\nPermission:%d\nAre you sure?(y-yes,n-no):", workerKey, firstName, lastName, password,permission);
        while((c = getchar()) != '\n');
		fflush(stdin);
		while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
			if (chr != '\n')
				printf("wrong input try again\n");
			fflush(stdin);
		}
		if (chr == 'y')
			flag = true;
	} while (!flag);
	flag = false;
	temp = constructorWorker(workerKey,firstName,lastName,password,permission);
	if (temp) {
		flag = addDeleteWorker(workerArray, add, *temp);
		destructorWorker(temp);
	}
	else {
		return false;
	}
	return flag;
}










void editOrderInventory(OrderInventoryArray* orderInventoryArray,int index) {
 bool flag = false;
 char c;
 int choice,choice2;



 do {
  printf("Choose what deteil you want to change:\n0 - Exit\n1 - Quantity\n2 - Price per item\nEneter your choice here:");
  while (1 != scanf("%d", &choice) || !(choice ==0 || choice == 1 || choice == 2)) {
   printf("Wrong input,try again\nEneter your choice here:");
   while ((c = getchar()) != '\n');
   fflush(stdin);
  }
  if (!choice) {
   flag = true;
  }
  if (!flag) {
   switch (choice) {
   case ONE: {
    printf("Quantity:\nEneter new quantity here:");
    while (1 != scanf("%d", &choice2)) {
     printf("Wrong input,try again\nEneter new quantity here:");
     while ((c = getchar()) != '\n');
     fflush(stdin);
    }
    orderInventoryArray->orderInventory[index]->quantity = choice2;
    orderInventoryArray->changed = true;
    break;
   }
   case TWO: {
    printf("Price per item:\nEneter new price here:");
    while (1 != scanf("%d", &choice2)) {
     printf("Wrong input,try again\nEneter new price here:");
     while ((c = getchar()) != '\n');
     fflush(stdin);
    }
    orderInventoryArray->orderInventory[index]->pricePerItem = choice2;
    orderInventoryArray->changed = true;
    break;
   }
   }
  }
 } while (!flag);
}






bool showWorker(WorkerArray* workerArray, int premission){
	int index, workerKey, option;
	Worker* tmp = NULL;
	int size = workerArray->size;
	bool flag = true;
	//char tmpStr[STRING];
	//int tempInt;

	printf("***********************************\n");
	printf("Show worker\n");
	printf("***********************************\n");


	if (size != 0){

		printf("Please enter a worker key:\n");

		if (1 != scanf("%d", &workerKey)) {
			printf("The input is wrong. returning to the main menu\n");
			return true;
		}
		searchWorker(*workerArray, &tmp, &index, workerKey);
		if (tmp != NULL && premission != admin){
			printWorker(*tmp, 0);
			return true;
		}
		if (tmp == NULL && premission != admin){
			printf("Worker key does not exist, returning to main menu\n");
			return true;
		}
		if (tmp == NULL){
			printf("Worker key does not exist.\nPlease choose between 2 options:\n1.Add a worker.\n2.return to main menu\n");
			if (1 != scanf("%d", &option)) {
				printf("The input is wrong. returning to the main menu\n");
				return true;
			}
			if (option == 1){
				if (addNewWorker(workerArray))
					return true;
				else
					return false;
			}
			printf("returning to the main menu\n");
			return true;
		}
		printWorker(*tmp, 0);
		printf("Please choose between 2 options:\n1.edit the worker details.\n2.return to main menu\n");
		if (1 != scanf("%d", &option)) {
			printf("The input is wrong. returning to the main menu\n");
			return true;
		}
		if (option == 1){
			flag=editWorker(workerArray, index);
		}
		return true;

	}
	printf("No worker to show.\n");
	if (premission != admin){
		printf("returning to the main menu\n");
		return true;
	}
	printf("Please choose between 2 options:\n1.Add a worker.\n2.return to main menu\n");
	if (1 != scanf("%d", &option)) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	if (option == 1){
		flag = addNewWorker(workerArray);
	}
	printf("returning to the main menu\n");
	return flag;
}


bool editWorker(WorkerArray* workerArray, int index){
	bool exitFlag = false,flag=true;
	int option;
	char c;
	char tmpStr[STRING];
	int tempInt;
	do {
		printf("Choose what deteil you want to change:\n0 - Exit\n1 - First name\n2 -Last name\n3 -Password\n4 -Premission\nEneter your choice here:");
		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2 || option == 3 || option == 4)) {
			printf("Wrong input,try again\nEneter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (!option) {
			exitFlag = true;
		}
		if (!exitFlag) {
			switch (option) {
			case ONE: {
				printf("First name:\nEneter new First name here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new First name here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(workerArray->worker[index]->firstName);
				workerArray->worker[index]->firstName = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!workerArray->worker[index]->firstName) {
					printf("Error:editWorker:firstName\n");
					flag = false;
				}
				strcpy(workerArray->worker[index]->firstName, tmpStr);
				workerArray->changed = true;
				break;
			}
			case TWO: {
				printf("Last name:\nEneter new last name here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new last name here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(workerArray->worker[index]->lastName);
				workerArray->worker[index]->lastName = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!workerArray->worker[index]->lastName) {
					printf("Error:editWorker:lastName\n");
					flag = false;
				}
				strcpy(workerArray->worker[index]->lastName, tmpStr);
				workerArray->changed = true;
				break;
			}
			case THREE: {
				printf("Password:\nEneter new Password here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new password here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(workerArray->worker[index]->password);
				workerArray->worker[index]->password = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!workerArray->worker[index]->password) {
					printf("Error:editWorker:password\n");
					flag = false;
				}
				strcpy(workerArray->worker[index]->password, tmpStr);
				workerArray->changed = true;
				break;
			}
			case FOUR: {
				printf("Premission:\nEneter new premission here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new premission here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				workerArray->worker[index]->premission = tempInt;
				workerArray->changed = true;
				break;
			}
			}
		}
	} while (!exitFlag);
	return flag;
}












//everyone
bool storeM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){

    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("Store Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n0. exit.\n1. Selling. \n2. Selling Reports\nEnter your choice here: ");
        while (1 != scanf("%d", &option)  || (option !=0 && option != 1 && option !=2) ) {
        printf("Wrong input try again\nEnter yor choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
		}


        if(option == 0)
            exitFlag = true;
        if(option == 1)//everyone
            flag = sellingM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(option == 2)//everyone
            flag = sellingReportsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);

    }while(!exitFlag && flag);

    return true;

}

bool administrationM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){

    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("Administration Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n0. exit.\n1. Clients. \n2. Users\n3. Administrative Reports.\n");
        while (1 != scanf("%d", &option)  || !(option == 0 || option == 1 || option == 2 || (option == 3 && user->premission != storekeeper))) {
        printf("Wrong input try again\nEnter yor choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
		}

        if(option == 0)
            exitFlag = true;
        if(option == 1)
            flag = clientsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(option == 3)
            flag = adminReportsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
        if(option == 2)
            flag = usersM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);

    }while(!exitFlag && flag);

    return flag;

}






//S- everything,T-showSellable,showProduct,showOrderClient,K-SHOWSELLABLE,SHOWORDERCLIENT
bool sellingM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){
	int c, option;
	bool exitFlag = false, flag = true;
	printf("***********************************************************************\n");
	printf("Selling Menu:\n");
	printf("***********************************************************************\n");

	do {
		printf("Please pick one option:\n0-exit.\n1-ShowOrderClient. \n2-Show sellable items\n");
		if(user->premission != storekeeper)
            printf("3-Show product\n");
		if (user->premission == admin || user->premission == seller)
			printf("4-Sell a computer by build.\n5-sell Items\n");
		printf("Enter your choice here:");//user->premission==0 => Technician
		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2 || (option == 3 && user->premission != storekeeper) || (option == 4 && (user->premission != storekeeper && user->premission != technician)) || (option == 4 && (user->premission != storekeeper && user->premission != technician)))) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == option)
			exitFlag = true;
		if (!exitFlag) {
            switch (option) {
            case 1: flag = showOrderClient(orderClientArray,orderInfoArray,productArray,clientArray,user->premission);
                break;
            case 2:
                if(user->premission == storekeeper || user->premission == technician)
                    flag = printAllProductsFromTheShop(productArray,categoryArray);
                else flag = showAllProductsFromTheShop(productArray,categoryArray,clientArray,orderClientArray,orderInfoArray,user);
                break;
            case 3: flag = ShowProduct(productArray,user->premission);
                break;
            case 4: flag = sellItemByBuild(productArray,categoryArray,clientArray,orderClientArray,orderInfoArray,user);
                break;
            case 5: flag = sellItem(productArray,categoryArray,clientArray,orderClientArray,orderInfoArray,user);
                break;
            default:printf("Error option\n");
            }
		}
	} while (!exitFlag&&flag);
	return flag;

}

//K-PRINTSELLABLEITEMS,ORDERCLIENTRANGE,T - DOESNT SEE PRINTSOLDBYDATE,
bool sellingReportsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){


    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("Selling Reports Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n");
        printf("0. exit.\n");
        printf("1. Print sellable items\n");
		printf("2. Reports of client orders by range\n");
        if(user->premission != storekeeper){
            printf("3. Print products of a category\n");
            printf("4. Print products to build by a range of dates\n");
        }
        if(user->premission == admin)
            printf("5. Print all the sold products of a month\n");

        while (1 != scanf("%d", &option)  || !(option == 0 || option == 1 || option == 2 ||(option == 3 && user->premission !=storekeeper) || (option == 4 && user->premission !=storekeeper) || (option == 5 &&user->premission == admin ))) {
        printf("Wrong input try again\nEnter yor choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
		}

        if(option == 0)
            exitFlag = true;
		if (option == 1)
			flag = printAllProductsFromTheShop(productArray,categoryArray);
        if(option == 2)
            flag = printClientOrderByRangeOfDate(orderClientArray,orderInfoArray);
        if(option == 3)
            flag = productsOfCategory(categoryArray,productArray);
        if(option == 4)
            flag = printBuildableOrders(orderInfoArray,orderClientArray);
        if(option == 5)
            PrintSoldProductsInTheMonth(orderInfoArray,orderClientArray,productArray);
        exitFlag = true;
    }while(!exitFlag && flag);

    return flag;

}




//done
bool clientsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){

    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("Clients Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n");
		printf("0. exit.\n");
        printf("1. Show client\n");
        if(user->premission == admin || user->premission == seller){
            printf("2. Add new client.\n");
        }

        while (1 != scanf("%d", &option)  || !(option == 0 || option == 1 || (option == 2 && (user->premission == admin || user->premission == seller)))) {
        printf("Wrong input try again\nEnter your choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
		}

        if(option == 0)
            exitFlag = true;
        if(option == 1)
            flag = showClient(clientArray,user->premission);
        if(option == 2)
            flag = addNewClient(clientArray);

        exitFlag = true;
    }while(!exitFlag && flag);

    return flag;


}

bool usersM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){
    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("usersM Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n");
        printf("0. exit.\n");
        printf("1. Show Worker.\n");
        if(user->premission == admin){
            printf("2. Add new user.\n");
        }

        while (1 != scanf("%d", &option)  || !(option == 0 || option == 1 || (option == 2 && user->premission == admin))) {
        printf("Wrong input try again\nEnter your choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
		}

        if(option == 0)
            exitFlag = true;
        if(option == 2)
            flag = addNewWorker(workerArray);
		if (option == 1)
			flag = showWorker(workerArray, user->premission);
        exitFlag = true;
    }while(!exitFlag && flag);

    return flag;


}

//done
bool adminReportsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user){

    int c,option;
    bool exitFlag = false,flag = true;
    printf("***********************************************************************\n");
    printf("Administration Reports Menu:\n");
    printf("***********************************************************************\n");

    do{
        printf("Please pick one option:\n");
        printf("0. exit.\n");
        printf("1-Show All clients\n");
        if(user->premission == admin){
            printf("2-Print the earnings from a range of dates.\n");
            printf("3-Print the expenses from a range of dates");
            printf("4-Print all users\n");
        }

        while (1 != scanf("%d", &option)  || !(option == 0 || option == 1 || (option == 2 && user->premission == admin ||(option == 3 && user->premission == admin) ||(option == 4 && user->premission == admin)))) {
            printf("Wrong input try again\nEnter your choice here:");
            while ((c = getchar()) != '\n');
            fflush(stdin);
		}

        if(option == 0)
            exitFlag = true;
        if(option == 1)
            flag = printAllClients(clientArray);
        if(option == 2)
            printEarning(orderClientArray,orderInfoArray,productArray);
        if(option == 3)
            printExpense(orderInventoryArray);
        if(option == 4)
            flag = printAllWorkers(workerArray);

        exitFlag = true;
    }while(!exitFlag && flag);

    return flag;
}







bool warehouseM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {
	int choice;
	char c;
	bool exitFlag = false, flag = true;
	do {
		printf("Welcome to Warehouse!!!\n");
		printf("Choose what menu you want to enter:\n0-Exit\n1-Reports\n2-Inventories\n");
		if (user->premission == 3)
			printf("3-Products\n");
		printf("Enter your choice here:");//user->premission==0 => Technician
		while (1 != scanf("%d", &choice) || !(choice == 0 || choice == 1 || choice == 2 || (choice == 3 && user->premission == 3))) {
			printf("Wrong input try again\nEnter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == choice)
			exitFlag = true;
		if (!exitFlag) {
			if (flag&&choice == 1)
				flag = reports(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
			if (flag&&choice == 2)
				flag = inventories(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
			if (user->premission == admin || user->premission == storekeeper) {
				if (flag&&choice == 3)
					flag = productsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
			}
		}
	} while (!exitFlag&&flag);
	return flag;

}

//done
bool reports(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {
	int choice;
	char c;
	bool exitFlag = false, flag = true;
	do {
		printf("Welcome to Reports!!!\n");
		printf("Choose what report you want:\n0-Exit\n1-Print all categories\n2-Print all the order inventories by range of dates\n");
		if (user->premission == 3 || user->premission == 0)
			printf("3-Print all products for that need to be resupplied\n");
		printf("Enter your choice here:");//user->premission==0 => Technician
		while (1 != scanf("%d", &choice) || !(choice == 0 || choice == 1 || choice == 2 || (choice == 3 && (user->premission == admin ||user->premission ==storekeeper)))) {
			printf("Wrong input try again\nEnter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == choice)
			exitFlag = true;
		if (!exitFlag) {
			if (flag&&choice == 1) {
				flag = printAllCategories(categoryArray);
				exitFlag = true;
			}
			if (flag&&choice == 2) {
				flag = printOrderInventoryByRangeOfDate(orderInventoryArray);
				exitFlag = true;
			}
			if (user->premission == admin || user->premission == storekeeper) {
				if (flag&&choice == 2) {
					flag = printAllProductsForMinInventroy(productArray);
					exitFlag = true;
				}
			}
		}
	} while (!exitFlag && flag);
	return flag;

}
//done
bool inventories(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {
	int choice;
	char c;
	int allow = 1;
	bool exitFlag = false, flag = true;
	do {
		printf("Welcome to Inventories!!!\n");
		printf("Choose what report you want:\n0-Exit\n1-Show order inventory\n");
		if (user->premission == admin || user->premission == storekeeper)
			printf("2-Add new order inventory\n3-Generate Inventory Orders to resupply \n4-Buy products from the order inventory\n");
		if (allow == 0) {
			printf("***Warning***--->You cann't exit until initiate option 4!!!!!!\n");
			exitFlag = false;
		}
		printf("Enter yor choice here:");//user->premission==0 => Technician
		while (1 != scanf("%d", &choice) || !(choice == 0 || choice == 1 || ((choice == 2||choice==3||choice==4 )&&( user->premission == 3 || user->premission == 0)))) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == choice)
			exitFlag = true;
		if (!exitFlag) {
			if (flag&&choice == 1) {
                if(user->premission == admin || user->premission == storekeeper)
                    flag = showOrderInventory(orderInventoryArray);
                else flag = showOrderInventoryReadOnly(orderInventoryArray);
				exitFlag = true;
			}
			if (user->premission == admin || user->premission == storekeeper) {
				if (flag&&choice == 2) {
					if (productArray->size)
						flag = addNewOrderInventory(orderInventoryArray, productArray);
					else
						printf("There is no products in the system!!!\n");
					exitFlag = true;
				}
				if (flag&&choice == 3) {
					flag = completeMinInventoryOrders(orderInventoryArray, productArray, &allow);
				}
				if (flag&&choice == 4) {
					flag = getOrderInventoryToProducts(orderInventoryArray, productArray, &allow);
				}
			}
		}
	} while ((!allow || !exitFlag ) && flag);
	return flag;
}

//done
bool productsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {
	int choice;
	char c;
	bool exitFlag = false, flag = true;
	do {
		printf("Welcome to Products!!!\n");
		printf("Choose what option you want:\n0-Exit\n1-Add new product\n2-Remove prodcut from the shelf\n3-Add new category\nEnter yor choice here:");
		while (1 != scanf("%d", &choice) || !(choice == 0 || choice == 1 || choice == 2 || choice == 3)) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == choice)
			exitFlag = true;
		if (!exitFlag) {
			if (flag&&choice == 2) {
				flag = addNewCategory(categoryArray);
				exitFlag = true;
			}
			if (flag&&choice == 1) {
				if (categoryArray->size)
					flag = addNewOrderInventory(orderInventoryArray, productArray);
				else
					printf("There is no categories in the system!!!\n");
				exitFlag = true;
			}
			if (flag&&choice == 3) {
				flag = removeProdcutFromTheShelf(productArray);
				exitFlag = true;
			}
		}
	} while (!exitFlag && flag);
	return flag;
}


void PrintSoldProductsInTheMonth(OrderInfoArray* orderInfoArray, OrderClientArray* orderClientArray, ProductArray* productArray) {
	Date startDate, endDate;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	startDate.day = 1;
	endDate.day = tm.tm_mday;
	startDate.month = tm.tm_mon + 1;
	endDate.month = startDate.month;
	startDate.year = tm.tm_year + 1900;
	endDate.year = startDate.year;
	int i = 0;
	OrderInfo* tempOrderInfo;
	Product* tempProduct;

	int index;
	for (i = 0; i < orderClientArray->size; i++) {
		int j = 0;
		if (compareDates(orderClientArray->orderClient[i]->date, startDate) == 1 && compareDates(orderClientArray->orderClient[i]->date, endDate) == -1 || !compareDates(orderClientArray->orderClient[i]->date, startDate) || !compareDates(orderClientArray->orderClient[i]->date, endDate)) {
			for (j = 0; j < orderClientArray->orderClient[i]->orderInfoKeyArray.size; j++) {
				searchOrderInfo(*orderInfoArray, &tempOrderInfo, &index, orderClientArray->orderClient[i]->orderInfoKeyArray.arr[j]);
				if (tempOrderInfo) {
					searchProduct(*productArray, &tempProduct, &index, tempOrderInfo->productKey);
					if (tempProduct) {
						if(!j)
							printf("****************************************\n");
						printProduct(*tempProduct, printCode);
						printf("\n");
						printProduct(*tempProduct, 1);
						printf("\n");
						printOrderInfo(*tempOrderInfo, 2);
						printf("\n");
						printOrderInfo(*tempOrderInfo, 3);
						printf("\n");
						printf("****************************************\n");
					}
					else {
						printf("Unknown ProductKey\n");
					}
				}
				else {
					printf("Unknown OrderInfoKey\n");
				}
			}
		}
	}
}

bool ShowProduct(ProductArray* productArray,int premission) {

		int index, productKey, option;
	Product* tmp = NULL;
	int size = productArray->size;
	bool flag = true;
	char c;

	printf("***********************************\n");
	printf("Show product\n");
	printf("***********************************\n");


	if (size != 0){

		printf("Please enter a product key:\n");

		if (1 != scanf("%d", &productKey)) {
			while ((c = getchar()) != '\n');
			printf("The input is wrong. returning to the Selling Menu menu.\nPress any key...\n");
			getchar();
			return true;
		}
		searchProduct(*productArray, &tmp, &index, productKey);
		if (tmp != NULL){
			printProduct(*tmp, 0);
			while ((c = getchar()) != '\n');
			printf("Press any key...");
			getchar();
		}
		else {
			printf("There is no such product.Return to selling menu.");
			while ((c = getchar()) != '\n');
			printf("Press any key...");
			getchar();
		}
		if (tmp != NULL&&premission==seller||premission==admin) {
			printf("Please choose between 2 options:\n1.edit the product details.\n2.return to selling Menu\n");
			while (1 != scanf("%d", &option)||!(option==1||option==2)) {
				printf("The input is wrong. returning to the Selling Menu.\nPress any key...\n");
				while ((c = getchar()) != '\n');
				getchar();
				return true;
			}
			if (option == 1) {
				flag=editProduct(productArray, index);
			}
		}
		return flag;
	}
	printf("No product to show.\n");
	printf("returning to the Selling Menu\n");
	return true;
}

bool editProduct(ProductArray* productArray, int index) {
	bool flag = false;
	int option;
	char c;
	char tmpStr[STRING];
	int tempInt;
	do {
		printf("Choose what deteil you want to change:\n0 -Exit\n1 -Product name\n2 -Company\n3 -Selling price\n4 -Production cost\n5 -Years\n6 -Min inventory\n7 -Amount\nEneter your choice here:");
		while (1 != scanf("%d", &option) || !(option >= ZERO && option < EIGHT)) {
			printf("Wrong input,try again\nEneter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (!option) {
			flag = true;
		}
		if (!flag) {
			switch (option) {
			case ONE: {
				printf("Product name:\nEneter new Product name here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new Product name here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(productArray->product[index]->productName);
				productArray->product[index]->productName = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!productArray->product[index]->productName) {
					printf("Error:editProduct:Product name malloc\n");
					return false;
				}
				strcpy(productArray->product[index]->productName, tmpStr);
				productArray->changed = true;
				break;
			}
			case TWO: {
				printf("Company:\nEneter new Company here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new Company here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(productArray->product[index]->company);
				productArray->product[index]->company = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!productArray->product[index]->company) {
					printf("Error:editProduct:Company malloc\n");
					return false;
				}
				strcpy(productArray->product[index]->company, tmpStr);
				productArray->changed = true;
				break;
			}
			case THREE: {
				printf("Selling price:\nEneter new selling price here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new selling price here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				productArray->product[index]->sellingPrice = tempInt;
				productArray->changed = true;
				break;
			}
			case FOUR: {
				printf("Production cost:\nEneter new production cost here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new production cost here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				productArray->product[index]->productionCost = tempInt;
				productArray->changed = true;
				break;
			}
			case FIVE: {
				printf("Years:\nEneter new amount of years here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new amount of years here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				productArray->product[index]->years = tempInt;
				productArray->changed = true;
				break;
			}
			case SIX: {
				printf("Min inventory:\nEneter new min inventory here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new min inventory here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				productArray->product[index]->minInventory = tempInt;
				productArray->changed = true;
				break;
			}
			case SEVEN: {
				printf("Amount:\nEneter new amount here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new amount here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				productArray->product[index]->amount = tempInt;
				productArray->changed = true;
				break;
			}
			}
		}
	} while (!flag);
	return flag;

}




bool productsOfCategory(CategoryArray* categoryArray,ProductArray* productArray){


    char c;
    int i,option;
    printAllCategories(categoryArray);
    bool found = false;



    printf("***********************************\n");
    printf("Products of Category!\n");
    printf("***********************************\n");

    printf("Please pick a category index");
    while ((c = getchar()) != '\n');
    while (1 != scanf("%d", &option) || !(option > 0 && option <=categoryArray->size)) {
        printf("Wrong input,try again\nEneter your choice here:");
        while ((c = getchar()) != '\n');
    }


    for(i = 0;i<productArray->size;i++){

        if(productArray->product[i]->categoryKey == categoryArray->category[option - 1]->categoryKey){
            printf("__________________________________\n");
            printProduct(*productArray->product[i],0);
            found = true;
        }

    }
    if(found != true){
        printf("__________________________________\n");
        printf("No products in this category\n");
    }
    printf("__________________________________\n");


    return true;

}



//TODO: add the functions to the menu

bool makeOrderInventory(OrderInventoryArray* orderInventoryArray,ProductArray* productArray){

    int i,key = orderInventoryArray->size + 1;
    Product* product = NULL;
    OrderInventory* order = NULL;
    Date date;
    date.day = 0;
    date.month = 0;
    date.year = 0;


    for(i = 0; i< productArray->size;i++){
        product = productArray->product[i];
        if(product->minInventory >product->amount){

            order = constructorOrderInventory(key,product->productKey,product->minInventory - product->amount,product->productionCost,date);
            if(order == NULL)
                return false;
            addDeleteOrderInventory(orderInventoryArray,add,*order);
			destructorOrderInventory(order);
            key++;
        }
    }

    return true;

}




bool getOrderInventoryToProducts(OrderInventoryArray* orderInventoryArray,ProductArray* productArray,int* allow){


    Date currentDate,date;
    OrderInventory* order = NULL;
    Product* product = NULL;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    currentDate.day = tm.tm_mday;
    currentDate.month = tm.tm_mon + 1;
    currentDate.year = tm.tm_year + 1900;
    int option,i,index;
    char c;

    printf("***********************************\n");
    printf("Get order inventory to products!\n");
    printf("***********************************\n");

    for(i =0;i<orderInventoryArray->size;i++){
        order = orderInventoryArray->orderInventory[i];
        date = order->date;
        if(date.day == 0 && date.month ==0 && date.year == 0){
            printf("__________________________________\n");
            printOrderInventory(*order,0);
            printf("__________________________________\n");
        }
    }

    printf("Press 1 to allow it, press 0 to exit\n");
    while ((c = getchar()) != '\n');
    while (1 != scanf("%d", &option) || !(option == 1 || option == 0)) {
        printf("Wrong input,try again\nEneter your choice here:");
		while ((c = getchar()) != '\n');
    }

    if(option == 0)
        return true;

    *allow = 1;

    for(i =0;i<orderInventoryArray->size;i++){
        order = orderInventoryArray->orderInventory[i];
        date = order->date;
        if(date.day == 0 && date.month ==0 && date.year == 0){
            //getting the product
            searchProduct(*productArray,&product,&index,order->productKey);
            product->amount = product->minInventory;
            order->date = currentDate;
        }
    }


    return true;


}



bool completeMinInventoryOrders(OrderInventoryArray* orderInventoryArray,ProductArray* productArray,int* allow){

    int option;
    char c;
    printf("***********************************\n");
    printf("Complete min inventory orders!\n");
    printf("***********************************\n");

    if(*allow == 0){
        printf("You cannot use this function again without calling the resupply function!\n");
        return true;
    }



    if(printAllProductsForMinInventroy(productArray) == false)
        return false;


    printf("Press 1 to allow it, press 0 to exit\n");
    while ((c = getchar()) != '\n');
    while (1 != scanf("%d", &option) || !(option == 1 || option == 0)) {
        printf("Wrong input,try again\nEneter your choice here:");
		while ((c = getchar()) != '\n');
    }
    if(option == 0)
        return true;

    *allow = 0;

    return makeOrderInventory(orderInventoryArray,productArray);



}



bool showOrderInventoryReadOnly(OrderInventoryArray* orderInventoryArray){

    int i,index,option,orderInventoryKey;
    OrderInventory* tmp = NULL;
    int size = orderInventoryArray->size;


    printf("***********************************\n");
    printf("Show order inventory\n");
    printf("***********************************\n");

    if(size != 0){

        printf("Please choose between 2 options:\n1.Get order inventory by key.\n2.Show all inventory orders and pick a key\n");

        if (1 != scanf("%d", &option)) {
            printf("The input is wrong. returning to the main menu\n");
            return true;
        }


        if(option == 1){
            printf("Please enter the order inventory key that you want to get:\nEnter the key here:");
            if (1 != scanf("%d", &orderInventoryKey)) {
                printf("The input is wrong please come back when u have the order inventory key\n");
                return true;
            }

            searchOrderInventory(*orderInventoryArray,&tmp,&index,orderInventoryKey);
            if(tmp == NULL){
                printf("Order inventory key does not exist. Returning to the main menu\n");
                return true;
            }
        }


        if(option == 2){
            for(i=0; i < orderInventoryArray->size;i++){
                printf("___________________________\n");
                printf("Order inventory number %d:\n",i);
                printOrderInventory(*(orderInventoryArray->orderInventory[i]),0);
                printf("___________________________\n");
            }
            printf("Please choose the number of the order inventory:\n");
            do{
                if (1 != scanf("%d", &option)) {
                    printf("The input is wrong. returning to the main menu\n");
                    return true;
                }
                if( option > orderInventoryArray->size - 1 || option < 0 ){
                    printf("You picked a wrong number. returning to the main menu\n");
                    return true;
                }
            }while( option > orderInventoryArray->size - 1 || option <0 );
            index = option;
        }
        printf("You choose the following order inventory:\n");
        printOrderInventory(*(orderInventoryArray->orderInventory[index]),0);

    }
    else{
        printf("There are no orders\n");
    }


    printf("Press any key to continue...\n");
    getchar();
    getchar();

    return true;
}







bool showAllProductsFromTheShop(ProductArray* productArray,CategoryArray* categoryArray,ClientArray* clientArray,OrderClientArray* orderClientArray,OrderInfoArray* orderInfoArray,Worker* worker){


    char c;
    bool flag = true;
    int i,option,index,choice;
    StringTupleArray temp;
    int** tmp=NULL;
    Category* category= NULL;
    //index array of product
    int productIndex[1];
    printf("***********************************\n");
    printf("Products in the shop!\n");
    printf("***********************************\n");


    printf("Please pick a sorting method\n");
    printf("0.exit\n1.by key\n2.by name\n3.cost\n4.by category\n5.by company\n");
    while ((c = getchar()) != '\n');
    while (1 != scanf("%d", &option) || !(option ==0 || option == 1 || option == 2 || option == 3 || option == 4 || option == 5)) {
        printf("Wrong input,try again\nEneter your choice here:");
		while ((c = getchar()) != '\n');
    }


    switch (option){
    case ZERO:
        return flag;
        break;
    case 1://by key
        break;
    case 2://by name
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, productArray->product[i]->productName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);

        break;
    case 3://by cost
        tmp = malloc(sizeof(int*)*(productArray->size));
        for (i = 0; i < productArray->size; i++) {
        tmp[i] = malloc(sizeof(int) * 2);
        tmp[i][0] = productArray->product[i]->sellingPrice;
        tmp[i][1] = i;
        }
        quickSortInts(&tmp, ZERO, productArray->size - ONE);
        break;
    case 4://by category
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            searchCategory(*categoryArray,&category,&index,productArray->product[i]->categoryKey);
            strcpy(temp.arr[i]->string, category->categoryName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);
        break;
    case 5://by company
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, productArray->product[i]->company);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);
        break;
    }


    if(option == 0)
        return true;


    if(option == 1){
        for(i = 0;i<productArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[i],0);
        }
        printf("__________________________________\n");

        if(worker->premission == seller || worker->premission == admin){
            printf("Please enter your product here:");
            if(worker->premission == seller)
                printf("to sell:");
            while ((c = getchar()) != '\n');
            while (1 != scanf("%d", &option) || !(option > 0 && option <= productArray->size)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
            }
            if(worker->premission == admin){
                printf("1.Do you want to sell the product\n2.Do you want to edit the product?\nPlease enter your choice here: ");
                while ((c = getchar()) != '\n');
                while (1 != scanf("%d", &choice) || !(choice == 1 || choice == 2)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
                }
                if(choice == 1){
                    productIndex[0] = option - 1;
                    if(productArray->product[option - 1]->amount == 0 ){
                        printf("The amount of the product is 0! cannot sell! return to the menu\n");
                    }
                    else{
                        flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,false);
                    }
                }
                if(choice == 2)
                    flag = editProduct(productArray,option - 1);
            }
            if(worker->premission == seller){
                productIndex[0] = option - 1;
                if(productArray->product[option - 1]->amount == 0 ){
                    printf("The amount of the product is 0! cannot sell! return to the menu\n");
                }
                else{
                    flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,false);
                }
            }

        }

    }

    if(option == 2 || option ==4 || option == 5){

        for(i = 0;i<temp.size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[temp.arr[i]->index],0);
        }
        printf("__________________________________\n");

        if(worker->premission == seller || worker->premission == admin){
            printf("Please enter your product here:");
            if(worker->premission == seller)
                printf("to sell:");
            while ((c = getchar()) != '\n');
            while (1 != scanf("%d", &option) || !(option > 0 && option <= productArray->size)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
            }
            if(worker->premission == admin){
                printf("1.Do you want to sell the product\n2.Do you want to edit the product?\nPlease enter your choice here: ");
                while (1 != scanf("%d", &choice) || !(choice == 1 || choice == 2)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
                }
                if(choice == 1){
                    productIndex[0] = temp.arr[option - 1]->index;
                    if(productArray->product[temp.arr[option - 1]->index]->amount == 0 ){
                        printf("The amount of the product is 0! cannot sell! return to the menu\n");
                    }
                    else{
                        flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,0);
                    }
                }
                if(choice == 2)
                    flag = editProduct(productArray,option - 1);
            }
            if(worker->premission == seller){
                productIndex[0] = option - 1;
                if(productArray->product[option - 1]->amount == 0 ){
                    printf("The amount of the product is 0! cannot sell! return to the menu\n");
                }
                else{
                    flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,false);
                }
            }

        }

        for (i = 0; i < temp.size; i++) {
            free(temp.arr[i]);
        }
        free(temp.arr);
    }
    else if(option != 1){

        for(i = 0;i<productArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[tmp[i][1]],0);
        }
        printf("__________________________________\n");


        if(worker->premission == seller || worker->premission == admin){
            printf("Please enter your product here:");
            if(worker->premission == seller)
                printf("to sell:");
            while ((c = getchar()) != '\n');
            while (1 != scanf("%d", &option) || !(option > 0 && option <= productArray->size)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
            }
            if(worker->premission == admin){
                printf("1.Do you want to sell the product\n2.Do you want to edit the product?\nPlease enter your choice here: ");
                while (1 != scanf("%d", &choice) || !(choice == 1 || choice == 2)) {
                printf("Wrong input,try again\nPlease enter your choice here:");
				while ((c = getchar()) != '\n');
                }
                if(choice == 1){
                    productIndex[0] = temp.arr[option - 1]->index;
                    if(productArray->product[temp.arr[option - 1]->index]->amount == 0 ){
                        printf("The amount of the product is 0! cannot sell! return to the menu\n");
                    }
                    else{
                        flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,false);
                    }
                }
                if(choice == 2)
                    flag = editProduct(productArray,option - 1);
            }
            if(worker->premission == seller){
                productIndex[0] = option - 1;
                if(productArray->product[option - 1]->amount == 0 ){
                    printf("The amount of the product is 0! cannot sell! return to the menu\n");
                }
                else{
                    flag = SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,1,false);
                }
            }

        }

        for (i = 0; i < productArray->size; i++) {
            free(tmp[i]);
        }
        free(tmp);
    }



    return flag;

}


bool addToCart(Product* product, OrderInfoArray* orderInfoArray, int* orderInfoKey) {
	OrderInfo* tempOrderInfo = NULL;
	if (orderInfoArray->size) {
		*orderInfoKey = orderInfoArray->orderInfo[orderInfoArray->size - 1]->orderInfoKey + 1;
	}
	else {
		*orderInfoKey = 1;
	}
	tempOrderInfo = constructorOrderInfo(*orderInfoKey, product->productKey, 1, product->sellingPrice);
	if (tempOrderInfo) {
		addDeleteOrderInfo(orderInfoArray, add, *tempOrderInfo);
		destructorOrderInfo(tempOrderInfo);
		product->amount--;
	}
	else {
		return false;
	}
	return true;
}

bool SellProduct(ProductArray* productArray,ClientArray* clientArray, OrderClientArray* orderClientArray, OrderInfoArray* orderInfoArray,Worker* user, int* indexProductArray,int size,bool buildFlag) {
	int price = 0,i;
	int clientKey;
	char c;
	Client* tmp=NULL;
	OrderClient* orderClient = NULL;
	bool flag = true,exitFlag=true;
	int workerKey=user->workerKey;
	Date date;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	date.day = tm.tm_mday;
	date.month = tm.tm_mon+1;
	date.year = tm.tm_year + 1900;
	int orderClientKey;
	bool buildComputer=buildFlag;
	OrderInfoKeyArray orderInfoKeyArray;
	orderInfoKeyArray.arr= malloc(sizeof(int)*size);
	if (!orderInfoKeyArray.arr) {
		printf("Error:SellProduct:orderInfoKeyArray.arr malloc\n");
		return false;
	}
	else {
		orderInfoKeyArray.size = size;
	}
	if (orderClientArray->size) {
		orderClientKey=orderClientArray->orderClient[orderClientArray->size - 1]->orderClientKey + 1;
	}
	else {
		orderClientKey = ONE;
	}
	for (i = 0; i < size&&flag; i++) {
		if (productArray->product[indexProductArray[i]]->amount>0) {
			flag = addToCart(productArray->product[indexProductArray[i]], orderInfoArray, &orderInfoKeyArray.arr[i]);
			if (flag) {
				printProduct(*productArray->product[indexProductArray[i]], ONE);
				printf("------Price:%d\n", productArray->product[indexProductArray[i]]->sellingPrice);
				price += productArray->product[indexProductArray[i]]->sellingPrice;
			}
		}
		else{
		}
	}
	if (flag) {
		printf("Your Cart is ready.\nFinal price:%d\n", price);
		do {
			while ((c = getchar()) != '\n');
			printf("Please enter client key:");
			if (1 != scanf("%d", &clientKey)) {
				printf("The input is wrong.\n");
				while ((c = getchar()) != '\n');
				exitFlag = false;
			}
			else {
				exitFlag = true;
			}
			if (exitFlag) {
				searchClient(*clientArray, &tmp, &i, clientKey);
				if (!tmp) {
					printf("There is no such client!!!\n");
					flag = addNewClient(clientArray);
					exitFlag = false;
				}
				else {
					exitFlag = true;
					orderClient = constructorOrderClient(orderClientKey, tmp->clientKey, workerKey, orderInfoKeyArray, date, buildComputer);
					flag = addDeleteOrderClient(orderClientArray, add, *orderClient);
					destructorOrderClient(orderClient);
				}
			}
		} while (!exitFlag&&flag);
		printf("************************************************\n");
		printf("\x1b[32Thank you for your purchase\x1b[0\n");
		printf("************************************************\n");
	}
	return flag;
}





bool printAllProductsFromTheShop(ProductArray* productArray,CategoryArray* categoryArray){


    char c;
    int i,option,index;
    StringTupleArray temp;
    int** tmp=NULL;
    Category* category= NULL;
    bool flag = true;
    printf("***********************************\n");
    printf("Products in the shop!\n");
    printf("***********************************\n");


    printf("Please pick a sorting method\n");
    printf("0.exit\n1.by key\n2.by name\n3.cost\n4.by category\n5.by company\n");
    while ((c = getchar()) != '\n');
    while (1 != scanf("%d", &option) || !(option ==0 || option == 1 || option == 2 || option == 3 || option == 4 || option == 5)) {
        printf("Wrong input,try again\nEneter your choice here:");
		while ((c = getchar()) != '\n');//moshiko changed
    }



    switch (option){
    case ZERO:
        return flag;
        break;
    case 1://by key
        break;
    case 2://by name
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, productArray->product[i]->productName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);

        break;
    case 3://by cost
        tmp = malloc(sizeof(int*)*(productArray->size));
        for (i = 0; i < productArray->size; i++) {
        tmp[i] = malloc(sizeof(int) * 2);
        tmp[i][0] = productArray->product[i]->sellingPrice;
        tmp[i][1] = i;
        }
        quickSortInts(&tmp, ZERO, productArray->size - ONE);
        break;
    case 4://by category
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            searchCategory(*categoryArray,&category,&index,productArray->product[i]->categoryKey);
            strcpy(temp.arr[i]->string, category->categoryName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);
        break;
    case 5://by company
        temp.size = productArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, productArray->product[i]->company);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);
        break;
    }


    if(option == 0)
        return true;


    if(option == 1){
        for(i = 0;i<productArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[i],0);
        }
        printf("__________________________________\n");


    }

    if(option == 2 || option ==4 || option == 5){

        for(i = 0;i<temp.size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[temp.arr[i]->index],0);
        }
        printf("__________________________________\n");


        for (i = 0; i < temp.size; i++) {
            free(temp.arr[i]);
        }
        free(temp.arr);
    }
    else if(option != 1){

        for(i = 0;i<productArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printProduct(*productArray->product[tmp[i][1]],0);
        }
        printf("__________________________________\n");


        for (i = 0; i < productArray->size; i++) {
            free(tmp[i]);
        }
        free(tmp);
    }


    return flag;

}




bool sellItem(ProductArray* productArray,CategoryArray* categoryArray,ClientArray* clientArray,OrderClientArray* orderClientArray,OrderInfoArray* orderInfoArray,Worker* worker){

    char c;
    int option;
    bool flag = false,buyAgain = true,exitFlag = false;
    int productIndexWithAmount[PRODUCTARRAY_SIZE] = {0};
    int productIndex[PRODUCTARRAY_SIZE];
    char name[STRING];
    bool found_name = false;
    int size = 0;
    int product_key;
    int index = -1;
    int i;
    Product* product = NULL;


    while(buyAgain && !flag && !exitFlag){
        printf("Please pick a selling method\n");
        printf("0.exit\n1.by showing all the items\n2.by product key\n3.by name\n");
        while ((c = getchar()) != '\n');
        while (1 != scanf("%d", &option) || !(option ==0 || option == 1 || option == 2 || option == 3)) {
            while ((c = getchar()) != '\n');
            printf("Wrong input,try again\nEnter your choice here:");
        }

        switch (option){
        case 0:
            exitFlag = true;
            break;
        case 1:
            for(i = 0;i<productArray->size;i++){
                printf("__________________________________\n*** -- %d -- *** \n",i + 1);
                printProduct(*productArray->product[i],0);
            }
            printf("__________________________________\n");

            printf("Please pick a product to sell:");
            while (1 != scanf("%d", &index) && !(index > 0 && index <= productArray->size)) {
                printf("Wrong input,try again\nEnter new product index here:");
                while ((c = getchar()) != '\n');
					fflush(stdin);
            }
            index--;

            break;
        case 2:
            printf("Please enter a product key to sell:");
            while (1 != scanf("%d", &product_key) ) {
                printf("Wrong input,try again\nEnter new product index here:");
                while ((c = getchar()) != '\n');
					fflush(stdin);
            }
            searchProduct(*productArray,&product,&index,product_key);
            if (product == NULL)
                index = -1;

            break;
        case 3:
				printf("Please enter the name of the product to sell:");
				while (1 != scanf("%s", name)) {
					printf("Wrong input,try again\nEnter new Company here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}

                for(i = 0;i<productArray->size&&!found_name;i++){
                    if(strcmp(productArray->product[i]->productName,name) == true){
                        found_name = true;
                        index = i;
                    }
                }

                if(!found_name){
                    printf("Name not found!\n");
                    index = -1;
                }

            break;
        }

        if(index != -1){
            productIndexWithAmount[index]++;
            if(productArray->product[index]->amount >= productIndexWithAmount[index] ){
                productIndex[size] = index;
                size++;
            }
            else{
                printf("You cannot add more of this item!\n");
            }
        }

        if(exitFlag == false){
            printf("Do you want to buy another item?\n");
            printf("1.Yes\n2.No\n");
            while ((c = getchar()) != '\n');
            while (1 != scanf("%d", &option) || !(option == 1 || option == 2)) {
                printf("Wrong input,try again\nEnter your choice here:");
                while ((c = getchar()) != '\n');
            }


            if(option == 2)
                buyAgain = false;
        }
    }

    if(size == 0)
        return true;

    return SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,size,false);


}


bool sellItemByBuild(ProductArray* productArray,CategoryArray* categoryArray,ClientArray* clientArray,OrderClientArray* orderClientArray,OrderInfoArray* orderInfoArray,Worker* worker){


    bool* categoryBuild = malloc(sizeof(bool)*categoryArray->size);
    if(categoryBuild == NULL)
        return false;
    bool exitFlag = false;
    bool flag = true;
    bool hasProduct = false;
    int option;
    char c;
    int productIndex[PRODUCTARRAY_SIZE];
    int size = 0;
    int i,j,index;

    //choosing categories
    while(exitFlag == false){
        printAllCategories(categoryArray);
        printf("Please choose a category\n");
        while (1 != scanf("%d", &option) || !(option >0 && option <= categoryArray->size)) {
            while ((c = getchar()) != '\n');
            printf("Wrong input,try again\nEnter your choice here:");
        }
        categoryBuild[option - 1] = true;

        printf("Do you want to choose another category?\n");
        printf("1.Yes\n2.No\n");
        while (1 != scanf("%d", &option) || !(option == 1 || option == 2)) {
            printf("Wrong input,try again\nEnter your choice here:");
            while ((c = getchar()) != '\n');
        }

        if(option == 2)
            exitFlag = true;
    }

    for(i = 0;i<categoryArray->size&&flag ;i++){
        hasProduct = false;
        if(categoryBuild[i] == true){
            //printing category
            printCategory(*categoryArray->category[i],0);
            for(j=0;j<productArray->size;j++){
                if(productArray->product[j]->categoryKey == categoryArray->category[i]->categoryKey){
                    hasProduct = true;
                    printf("__________________________________\nIndex: %d - ",j);
                    printProduct(*productArray->product[j],0);
                }
            }
            if(hasProduct == true){
                printf("Please pick a product to sell:");
                while (1 != scanf("%d", &index) || !(index > 0 && index <= productArray->size) || !(productArray->product[index]->categoryKey == categoryArray->category[i]->categoryKey)) {
                    printf("Wrong input,try again\nEnter new product index here:");
                    while ((c = getchar()) != '\n');
                        fflush(stdin);
                }

                productIndex[size]=index;
                size++;
            }
            else{
                printf("Sorry. No products for this category yet!\n");
            }

            printf("__________________________________\n");
        }

    }

    free(categoryBuild);
    if(size == 0)
        return true;
    printf("Building order...\n");
    return SellProduct(productArray,clientArray,orderClientArray,orderInfoArray,worker,productIndex,size,true);
}



//*****************************************************new code (i+1) in ariel code deleted


bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	return (year % 4 == 0);
}
Date addDaysToDate(Date date, int days) {
	Date newDate;
	int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = 0, month = 0, year = 0, daysToAdvance,i;
	day = date.day;
	month = date.month;
	year = date.year;
	daysToAdvance = days;
	for ( i = 0; i<daysToAdvance; i++)
	{
		day++;
		if (day > daysPerMonth[month - 1] || (month == 2 && day == 29 && !isLeapYear(year)))
		{
			day = 1;
			month++;
			if (month == 13)
			{
				month = 1;
				year++;
			}
		}
	}
	newDate.day = day;
	newDate.month = month;
	newDate.year = year;
	return newDate;
}
//returns date1-date2 or date2-date1
int differenceBetweenTwoDates(Date date1, Date date2) {
	int days = 0;
	Date temp;
	if (compareDates(date1, date2) == -1) {
		temp = date1;
		date1 = date2;
		date2 = temp;
	}
	while (compareDates(date1, date2) != 0) {
		days++;
		date2 = addDaysToDate(date2, 1);
	}
	return days;

}



bool repairProduct(ProductArray* productArray, LaboratoryArray* laboratoryArray, WorkerArray* workerArray, Worker* worker) {
	int choice;
	printf("Please choose between 2 options:\n1.Add a item to laboratory.\n2.Edit status\n");
	if (1 != scanf("%d", &choice)) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	if (choice == add)
		return addItemInLaboratory(productArray, laboratoryArray, worker);
	if (choice == 2) //edit
		return editItemInLaboratory(productArray, laboratoryArray, workerArray);
	printf("choice is not valid,returning to the main menu\n");
	return true;
}

bool addItemInLaboratory(ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* worker) {
	int index;
	Product* productTemp;
	int laborotoryKey, productKey;
	Date entryDate;
	bool flag = false;
	char chr, c;
	Laboratory* temp;
	printf("***********************************\n");
	printf("Add repair product\n");
	printf("***********************************\n");

	printf("Enter product key:\n");
	if (1 != scanf("%d", &productKey)) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	searchProduct(*productArray, &productTemp, &index, productKey);
	if (productTemp != NULL) {
		do {
			fflush(stdin);
			printf("Please enter a laborotory key that you want to add:\nEnter the key here:");
			if (1 != scanf("%d", &laborotoryKey)) {
				printf("The input is wrong please come back when u have the product key\n");
				return true;
			}
			printf("Are you sure?(y-yes,n-no):");
			while ((c = getchar()) != '\n');
			fflush(stdin);
			while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
				printf("wrong input try again\n");
				fflush(stdin);
			}
			if (chr == 'y')
				flag = true;
		} while (!flag);
		searchLaboratory(*laboratoryArray, &temp, &index, laborotoryKey);
		if (temp) {
			printf("The key already exist,you will be now returned to the main menu.");
			return true;
		}
		fflush(stdin);
		printf("Please enter date:");
		if (3 != scanf("%d %d %d", &(entryDate.day), &(entryDate.month), &(entryDate.year))) {
			printf("The input is wrong ,returning to the main menu\n");
			return true;
		}
		//checking if the dates are valid
		if (!checkDate(entryDate)) {
			printf("Date you entered is not a valid date! Returning to the main menu\n");
			return true;
		}
		temp = constructorLaboratory(laborotoryKey, productKey, worker->workerKey, "notFix", entryDate);
		if (temp) {
			flag = addDeleteLaboratory(laboratoryArray, add, *temp);
			destructorLaboratory(temp);
			printf("Item was added, you will be now returned to the main menu.\n");
			printf("***********************************\n");
			return true;
		}
		else {
			printf("Item was not added, you will be now returned to the main menu.\n");
			printf("***********************************\n");
			return false;
		}
	}
	printf("We dont fix this product, returning to the main menu\n");
	return true;



}


bool editItemInLaboratory(ProductArray* productArray, LaboratoryArray* laboratoryArray, WorkerArray* workerArray) {
	int index;
	char chr, c;
	Laboratory* laboratory = NULL;
	int choice;
	printf("***********************************\n");
	printf("Edit repair product\n");
	printf("***********************************\n");

	printf("Please choose between 2 options:\n1.Search a item by key.\n2.list of items.\n");
	if (1 != scanf("%d", &choice)) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	if (choice == 1) {
		printf("Please enter a laboratory key:\n");
		if (1 != scanf("%d", &choice)) {
			printf("The input is wrong. returning to the main menu\n");
			return true;
		}
		searchLaboratory(*laboratoryArray, &laboratory, &index, choice);
		if (laboratory != NULL) {
			showItemInLaboratory(laboratoryArray, productArray, workerArray, index);
			if (strcmp(laboratory->status, "Fix") == 0) {
				printf("***********************************\n");
				printf("Item was fixed, returning to the main menu\n");
				return true;
			}
			printf("Are you sure to change status to fix?(y-yes,n-no):\n");
			while ((c = getchar()) != '\n');
			fflush(stdin);
			while (1 != scanf("%c", &chr) || !(chr == 'y' || chr == 'n')) {
				printf("wrong input try again\n");
				fflush(stdin);
			}
			if (chr == 'y') {
				laboratoryArray->changed = true;
				free(laboratory->status);
				laboratory->status = (char*)malloc(4);
				if (laboratory->status) {
					strcpy(laboratory->status, "Fix");
					printf("status changed, returning to the main menu\n");
					return true;
				}
				return false;
			}
			else {
				printf("status not changed, returning to the main menu\n");
				return true;
			}
		}
		printf("The key is not exist. returning to the main menu\n");
		return true;
	}
	if (choice == 2) {
		showItemsInLaboratory(laboratoryArray, productArray, workerArray);
		printf("Please enter a laboratory key\n");
		if (1 != scanf("%d", &choice)) {
			printf("The input is wrong. returning to the main menu\n");
			return true;
		}
		else {
			searchLaboratory(*laboratoryArray, &laboratory, &index, choice);
			if (laboratory) {
				if (strcmp(laboratory->status, "Fix") == 0) {
					printf("The key is not exist. returning to the main menu\n");
					return true;
				}
				laboratoryArray->changed = true;
				free(laboratory->status);
				laboratory->status = (char*)malloc(4);
				if (laboratory->status) {
					strcpy(laboratory->status, "Fix");
					printf("status changed, returning to the main menu\n");
					return true;
				}
				return false;
			}
			printf("The key is not exist. returning to the main menu\n");
			return true;
		}
	}
	else {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	return true;


}

void showItemsInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray) {

	printf("***********************************\n");
	printf("Printing all Products in laboratory\n");
	printf("***********************************\n");

	int i, j;
	Laboratory* laboratory = NULL;

	for (i = 0; i< laboratoryArray->size; i++) {
		laboratory = laboratoryArray->laboratory[i];
		if (strcmp(laboratory->status, "notFix") == 0) {
			printf("**********************************************\n");
			printLaboratory(*laboratory, -1);
			printf("\nDate entry: ");
			printLaboratory(*laboratory, 4);//date
			printf("\n");
			for (j = 0; j < productArray->size && productArray->product[j]->productKey != laboratory->productKey; j++);
			printf("Product name: ");
			printProduct(*(productArray->product[j]), 1);
			printf("\n");

			for (j = 0; j < workerArray->size && workerArray->worker[j]->workerKey != laboratory->workerKey; j++);
			printf("Name of worker: ");
			printWorker(*(workerArray->worker[j]), 1);
			printf(" ");
			printWorker(*(workerArray->worker[j]), 2);
			printf("\n");
			printf("**********************************************\n");
		}
	}


}
void showItemInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray, int index) {
	int j;
	Laboratory* laboratory = laboratoryArray->laboratory[index];
	printf("***********************************\n");
	printf("Printing a Product in laboratory\n");
	printf("***********************************\n");
	printLaboratory(*laboratory, -1);
	printf("\nDate entry: ");
	printLaboratory(*laboratory, 4);//date
	printf("\n");
	for (j = 0; j < productArray->size && productArray->product[j]->productKey != (*laboratory).productKey; j++);
	printf("Product name: ");
	printProduct(*(productArray->product[j]), 1);
	printf("\n");
	for (j = 0; j < workerArray->size && workerArray->worker[j]->workerKey != (*laboratory).workerKey; j++);
	printf("Name of worker: ");
	printWorker(*(workerArray->worker[j]), 1);
	printf(" ");
	printWorker(*(workerArray->worker[j]), 2);
	printf("\n");
	printf("***********************************\n");

}
bool showItemsInLaboratoryWithTime(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray) {
	Date today;
	int i, j;
	Laboratory* laboratory = NULL;
	printf("***********************************\n");
	printf("Printing all Products in laboratory with time\n");
	printf("***********************************\n");
	printf("Please enter date of today:");
	if (3 != scanf("%d %d %d", &(today.day), &(today.month), &(today.year))) {
		printf("The input is wrong ,returning to the main menu\n");
		return true;
	}
	//checking if the dates are valid
	if (!checkDate(today)) {
		printf("Date you entered is not a valid date! Returning to the main menu\n");
		return true;
	}
	for (i = 0; i< laboratoryArray->size; i++) {
		laboratory = laboratoryArray->laboratory[i];
		if (strcmp(laboratory->status, "notFix") == 0) {
			printf("**********************************************\n");
			printLaboratory(*laboratory, -1);
			printf("\nTime in laboratory: %d days\n", differenceBetweenTwoDates(laboratory->entryDate, today));
			for (j = 0; j < productArray->size && productArray->product[j]->productKey != laboratory->productKey; j++);
			printf("Product name: ");
			printProduct(*(productArray->product[j]), 1);
			printf("\n");
			for (j = 0; j < workerArray->size && workerArray->worker[j]->workerKey != laboratory->workerKey; j++);
			printf("Name of worker: ");
			printWorker(*(workerArray->worker[j]), 1);
			printf(" ");
			printWorker(*(workerArray->worker[j]), 2);
			printf("\n");
			printf("**********************************************\n");
		}
	}
	return true;
}

bool showDelayItemInLaboratory(LaboratoryArray* laboratoryArray, ProductArray* productArray, WorkerArray* workerArray) {
	Date today;
	int i, j;
	Laboratory* laboratory = NULL;
	int days, difference;
	printf("***********************************\n");
	printf("Printing all Products in laboratory over several days\n");
	printf("***********************************\n");
	printf("Please enter date of today:");
	if (3 != scanf("%d %d %d", &(today.day), &(today.month), &(today.year))) {
		printf("The input is wrong ,returning to the main menu\n");
		return true;
	}
	//checking if the dates are valid
	if (!checkDate(today)) {
		printf("Date you entered is not a valid date! Returning to the main menu\n");
		return true;
	}
	printf("Enter minimum days:\n");
	if (1 != scanf("%d", &days)) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	if (days < 0) {
		printf("The input is wrong. returning to the main menu\n");
		return true;
	}
	for (i = 0; i< laboratoryArray->size; i++) {
		laboratory = laboratoryArray->laboratory[i];
		if (strcmp(laboratory->status, "notFix") == 0) {
			difference = differenceBetweenTwoDates(laboratory->entryDate, today);
			if (difference >= days) {
				printf("**********************************************\n");
				printLaboratory(*laboratory, -1);
				printf("\nTime in laboratory: %d days\n", difference);
				for (j = 0; j < productArray->size && productArray->product[j]->productKey != laboratory->productKey; j++);
				printf("Product name: ");
				printProduct(*(productArray->product[j]), 1);
				printf("\n");
				for (j = 0; j < workerArray->size && workerArray->worker[j]->workerKey != laboratory->workerKey; j++);
				printf("Name of worker: ");
				printWorker(*(workerArray->worker[j]), 1);
				printf(" ");
				printWorker(*(workerArray->worker[j]), 2);
				printf("\n");
				printf("**********************************************\n");
			}
		}
	}
	return true;
}


bool printBuildableOrders(OrderInfoArray* orderInfoArray, OrderClientArray* orderClientArray) {

	int i = 0, size = 0, temp,temp2;
	int** arr;
	Date today;
	OrderInfo *tempOrderInfo=NULL;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	today.day = tm.tm_mday;
	today.month = tm.tm_mon + 1;
	today.year = tm.tm_year + 1900;
		printf("***********************************\n");
	printf("Printing all Products in laboratory for building by date.\n");
	printf("***********************************\n");
	while (i < orderClientArray->size) {
		if (orderClientArray->orderClient[i++]->buildComputer) {
			size++;
		}
	}
	arr = malloc(sizeof(int*)*size);
	if (!arr) {
		return false;
	}
	for (i = 0; i < size; i++) {
		arr[i] = malloc(sizeof(int)*TWO);
		if (!arr[i]) {
			while (--i > -1) {
				free(arr[i]);
			}
			free(arr);
			return false;
		}
	}
	i = 0;
	temp = size;
	while (i < orderClientArray->size  &&size) {
		if (orderClientArray->orderClient[i]->buildComputer) {
			arr[--temp][0] = differenceBetweenTwoDates(orderClientArray->orderClient[i]->date, today);
			arr[temp][1] =i;
		}
		i++;
	}
	quickSortInts(&arr, ZERO, size - ONE);
	for (i =size-1; i>=0 ; i--) {
		printf("\x1b[31m************ -- %d -- ************\x1b[0m\n", size-i);
		printOrderClient(*orderClientArray->orderClient[arr[i][1]], printCode);
		printf("\n");
		printOrderClient(*orderClientArray->orderClient[arr[i][1]],3);
		printf("\n");
		for (temp = 0; temp < orderClientArray->orderClient[arr[i][1]]->orderInfoKeyArray.size; temp++) {
			searchOrderInfo(*orderInfoArray, &tempOrderInfo, &temp2, orderClientArray->orderClient[arr[i][1]]->orderInfoKeyArray.arr[temp]);
			if (!tempOrderInfo) {
				printf("There is no orderInfoKey--%d\n", orderClientArray->orderClient[arr[i][1]]->orderInfoKeyArray.arr[temp]);
			}
			else {
				printf("\x1b[34m**********************************\x1b[0m\n");
				printOrderInfo(*tempOrderInfo, 0);
				printf("\x1b[34m**********************************\x1b[0m\n");
			}
		}
		printf("\x1b[31m**********************************\x1b[0m\n");
	}
	for (i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);
	return true;
}


bool showOrderClient(OrderClientArray* orderClientArray,OrderInfoArray* orderInfoArray,ProductArray* productArray,ClientArray* clientArray,int permission){

    bool flag = true;
    int option,index;
    OrderClient* orderClient = NULL;
    OrderInfo* orderInfo = NULL;
    Product* product = NULL;
    Client* client = NULL;
    char c;
    int j;

    printf("Please enter the client order key you want to review\n");
    while (1 != scanf("%d", &option)) {
        printf("Wrong input,try again\nEnter your choice here:");
        while ((c = getchar()) != '\n');
    }


    searchOrderClient(*orderClientArray,&orderClient,&index,option);
    if(orderClient == NULL){
        printf("No such order client key exists! returning to the menu!\n");
        printf("Please press enter to exit\n");
        while ((c = getchar()) != '\n');
        return flag;
    }

    if(permission != admin && permission != seller){
        printf("Reviewing the client order!\n");
        printf("****************************************\n");
        printOrderClient(*orderClient,0);

        for(j = 0; j<orderClient->orderInfoKeyArray.size;j++){
            searchOrderInfo(*orderInfoArray,&orderInfo,&index,orderClient->orderInfoKeyArray.arr[j]);
            if(orderInfo){
                printf("____________________________________________\n");
                printOrderInfo(*orderInfo,0);
                searchProduct(*productArray,&product,&index,orderInfo->productKey);
                if(product != NULL)
                    printProduct(*product,0);
                printf("____________________________________________\n");
            }
        }
        printf("****************************************\n");
    }
    else{
        printf("0 - Exit.\n1 - Edit order.\n2 - Review Order.\nPlease pick one of the options above:");
        while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2)) {
            printf("Wrong input,try again\nEnter your choice here:");
            while ((c = getchar()) != '\n');
        }
        if(option == 2){
            printf("Reviewing the client order!\n");
            printf("****************************************\n");
            printOrderClient(*orderClient,0);

            for(j = 0; j<orderClient->orderInfoKeyArray.size;j++){
                searchOrderInfo(*orderInfoArray,&orderInfo,&index,orderClient->orderInfoKeyArray.arr[j]);
                if(orderInfo){
                    printf("____________________________________________\n");
                    printOrderInfo(*orderInfo,0);
                    searchProduct(*productArray,&product,&index,orderInfo->productKey);
                    if(product != NULL)
                        printProduct(*product,0);
                    printf("____________________________________________\n");
                }
            }
            printf("****************************************\n");
        }
        if(option == 1){
            printf("The order client:\n");
            printOrderClient(*orderClient,0);
            printf("Editing the order client!\n");
            printf("Do you want to edit the client ID? 1 - yes, 2 - No\n");
            while (1 != scanf("%d", &option) || !(option == 1 || option == 2)) {
                printf("Wrong input,try again\nEnter your choice here:");
                while ((c = getchar()) != '\n');
            }
            if(option == 1){
                printf("Please enter the new client ID:");
                while (1 != scanf("%d", &option) ) {
                    printf("Wrong input,try again\nEnter your choice here:");
                    while ((c = getchar()) != '\n');
                }
                searchClient(*clientArray,&client,&index,option);
                if(client == NULL){
                    printf("No such ID! cannot change the client ID!\n");
                }
                else{
                    orderClient->clientKey = option;
                }
            }
            printf("Do you want to change the build status? 1 - yes, 2 - No\n");
            while (1 != scanf("%d", &option) || !(option == 1 || option == 2)) {
                printf("Wrong input,try again\nEnter your choice here:");
                while ((c = getchar()) != '\n');
            }
            if(option == 1){
                orderClient->buildComputer = !orderClient->buildComputer;
                printf("Done changing the build computer status!\n");
            }
        }
    }

    printf("Please press enter to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');
    return true;

}

bool showClient(ClientArray* clientArray,int permission){

	int index, clientKey, option;
	Client* tmp = NULL;
	int size = clientArray->size;
	bool flag = true;
    char c;

	printf("***********************************\n");
	printf("Show Client\n");
	printf("***********************************\n");

	if (size != 0){

		printf("Please enter a client ID:\n");

		if (1 != scanf("%d", &clientKey)) {
			printf("The input is wrong. returning to the main menu\n");
            printf("Please press enter to exit\n");
            while ((c = getchar()) != '\n');
			while ((c = getchar()) != '\n');
			return true;
		}
		searchClient(*clientArray, &tmp, &index, clientKey);
		if (tmp != NULL && permission != admin){
			printClient(*tmp, 0);
            printf("Please press enter to exit\n");
            while ((c = getchar()) != '\n');
			while ((c = getchar()) != '\n');
			return true;
		}
		if (tmp == NULL && permission != admin){
			printf("Client ID does not exist, returning to main menu\n");
            printf("Please press enter to exit\n");
            while ((c = getchar()) != '\n');
            while ((c = getchar()) != '\n');
			return true;
		}
		if (tmp == NULL){
			printf("Client key does not exist.\nPlease choose between 2 options:\n1.Add a client.\n2.return to main menu\n");
			if (1 != scanf("%d", &option)) {
				printf("The input is wrong. returning to the main menu\n");
                printf("Please press enter to exit\n");
                while ((c = getchar()) != '\n');
				while ((c = getchar()) != '\n');
				return true;
			}
			if (option == 1){
				if (addNewClient(clientArray)){
                    printf("Please press enter to exit\n");
                    while ((c = getchar()) != '\n');
                    while ((c = getchar()) != '\n');
					return true;
				}
				else
					return false;
			}
			printf("returning to the main menu\n");
			printf("Please press enter to exit\n");
            while ((c = getchar()) != '\n');
            while ((c = getchar()) != '\n');
			return true;
		}
		printClient(*tmp, 0);
		printf("Please choose between 2 options:\n1.edit the client details.\n2.return to main menu\n");
		if (1 != scanf("%d", &option)) {
			printf("The input is wrong. returning to the main menu\n");
            printf("Please press enter to exit\n");
            while ((c = getchar()) != '\n');
            while ((c = getchar()) != '\n');
			return true;
		}
		if (option == 1){
			flag=editClient(clientArray, index);
		}
        printf("Please press enter to exit\n");
        while ((c = getchar()) != '\n');
        while ((c = getchar()) != '\n');
		return true;

	}
	printf("No Client to show.\n");
	if (permission != admin){
		printf("returning to the main menu\n");
        printf("Please press enter to exit\n");;
        while ((c = getchar()) != '\n');
        while ((c = getchar()) != '\n');
		return true;
	}
	printf("Please choose between 2 options:\n1.Add a client.\n2.return to main menu\n");
	if (1 != scanf("%d", &option)) {
		printf("The input is wrong. returning to the main menu\n");
        printf("Please press enter to exit\n");
        while ((c = getchar()) != '\n');
        while ((c = getchar()) != '\n');
		return true;
	}
	if (option == 1){
		flag = addNewClient(clientArray);
	}
	printf("returning to the main menu\n");
    printf("Please press enter to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');
	return flag;

}


bool editClient(ClientArray* clientArray,int index){

	bool exitFlag = false,flag=true;
	int option;
	char c;
	char tmpStr[STRING];
	int tempInt;
	do {
		printf("Choose what detail you want to change:\n0 - Exit\n1 - First name\n2 -Last name\n3 -Phone number\n4 -Email\n5 - Address\n6 - ID\nEnter your choice here:");
		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6)) {
			printf("Wrong input,try again\nEneter your choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (!option) {
			exitFlag = true;
		}
		if (!exitFlag) {
			switch (option) {
			case ONE: {
				printf("First name:\nEnter new First name here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new First name here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(clientArray->client[index]->firstName);
				clientArray->client[index]->firstName = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!clientArray->client[index]->firstName) {
					printf("Error:editClient:firstName\n");
					flag = false;
				}
				strcpy(clientArray->client[index]->firstName, tmpStr);
				clientArray->changed = true;
				break;
			}
			case TWO: {
				printf("Last name:\nEnter new last name here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new last name here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(clientArray->client[index]->lastName);
				clientArray->client[index]->lastName = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!clientArray->client[index]->lastName) {
					printf("Error:editClient:lastName\n");
					flag = false;
				}
				strcpy(clientArray->client[index]->lastName, tmpStr);
				clientArray->changed = true;
				break;
			}
			case THREE: {
				printf("Phone number:\nEnter new Phone number here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new phone number here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(clientArray->client[index]->phone);
				clientArray->client[index]->phone = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!clientArray->client[index]->phone) {
					printf("Error:editClient:phone\n");
					flag = false;
				}
				strcpy(clientArray->client[index]->phone, tmpStr);
				clientArray->changed = true;
				break;
			}
			case FOUR: {
				printf("Email:\nEnter new email here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new email here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(clientArray->client[index]->email);
				clientArray->client[index]->email = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!clientArray->client[index]->email) {
					printf("Error:editClient:email\n");
					flag = false;
				}
				strcpy(clientArray->client[index]->email, tmpStr);
				clientArray->changed = true;
				break;
			}
			case FIVE: {
				printf("Address:\nEnter new Address here:");
				while (1 != scanf("%s", tmpStr)) {
					printf("Wrong input,try again\nEnter new email here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				free(clientArray->client[index]->address);
				clientArray->client[index]->address = (char*)malloc((sizeof(char)*strlen(tmpStr)) + 1);
				if (!clientArray->client[index]->address) {
					printf("Error:editClient:Address\n");
					flag = false;
				}
				strcpy(clientArray->client[index]->address, tmpStr);
				clientArray->changed = true;
				break;
			}
			case SIX: {
				printf("ID:\nEneter new client ID here:");
				while (1 != scanf("%d", &tempInt)) {
					printf("Wrong input,try again\nEnter new client ID here:");
					while ((c = getchar()) != '\n');
					fflush(stdin);
				}
				clientArray->client[index]->clientKey = tempInt;
				clientArray->changed = true;
				break;
			}

			}
		}
	} while (!exitFlag);
	return flag;

}

bool printAllClients(ClientArray* clientArray){

    int i,option;
    StringTupleArray temp;
    char c;

    if(clientArray->size == 0){
        printf("No Clients!\n");
        printf("Please enter any key to exit\n");
        while ((c = getchar()) != '\n');
        while ((c = getchar()) != '\n');
    }

    printf("Choose sorting method!\n1- By last name.\n2- By ID\n0- Exit\nChoose:");
    while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2)) {
        printf("Wrong input,try again\nEneter your choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
    }

    if(option == 1){
        temp.size = clientArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, clientArray->client[i]->lastName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);


        for(i = 0;i<temp.size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printClient(*clientArray->client[temp.arr[i]->index],0);
        }
        printf("__________________________________\n");

        for (i = 0; i < temp.size; i++) {
            free(temp.arr[i]);
        }
        free(temp.arr);
    }
    if(option == 2){
        for(i = 0;i<clientArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printClient(*clientArray->client[i],0);
        }
        printf("__________________________________\n");
    }


    printf("Please enter any key to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');

    return true;
}


bool printAllWorkers(WorkerArray* workerArray){

    int i,option;
    StringTupleArray temp;
    char c;

    if(workerArray->size == 0){
        printf("No workers!\n");
        printf("Please enter any key to exit\n");
        while ((c = getchar()) != '\n');
        while ((c = getchar()) != '\n');
    }

    printf("Choose sorting method!\n1- By last name.\n2- By ID\n0- Exit\nChoose:");
    while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2)) {
        printf("Wrong input,try again\nEneter your choice here:");
        while ((c = getchar()) != '\n');
        fflush(stdin);
    }

    if(option == 1){
        temp.size = workerArray->size;
        temp.arr = malloc(sizeof(Tuple*)*temp.size);
        for (i = 0; i < temp.size; i++) {
            temp.arr[i] = malloc(sizeof(Tuple));
            strcpy(temp.arr[i]->string, workerArray->worker[i]->lastName);
            temp.arr[i]->index = i;
        }
        quickSortStrings(&temp, ZERO, temp.size - ONE);


        for(i = 0;i<temp.size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printWorker(*workerArray->worker[temp.arr[i]->index],0);
        }
        printf("__________________________________\n");

        for (i = 0; i < temp.size; i++) {
            free(temp.arr[i]);
        }
        free(temp.arr);
    }
    if(option == 2){
        for(i = 0;i<workerArray->size;i++){
        printf("__________________________________\n*** -- %d -- *** \n",i + 1);
        printWorker(*workerArray->worker[i],0);
        }
        printf("__________________________________\n");
    }

    printf("Please enter any key to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');

    return true;

}

bool printOrderInventoryByRangeOfDate(OrderInventoryArray* orderInventoryArray) {
	printf("***********************************\n");
	printf("Printing Inventory order by date range\n");
	printf("***********************************\n");

	int i, j=0, index;
	Date d1, d2, tmp;
	char c;
	bool flag = true;
	int** arr=NULL;
	printf("Please enter 2 Dates:format(day month year)\n");
	printf("Please enter the first date\n");
	if (3 != scanf("%d %d %d", &(d1.day), &(d1.month), &(d1.year))) {
		printf("The input is wrong. Try again later\n");
		return true;
	}
	printf("Please enter the second date\n");
	if (3 != scanf("%d %d %d", &(d2.day), &(d2.month), &(d2.year))) {
		printf("The input is wrong. Try again later\n");
		return true;
	}
	//checking if the dates are valid
	if (!checkDate(d1) || !checkDate(d2)) {
		printf("One of the dates you entered is not a valid date! Returning to the main menu\n");
		return true;
	}
	if (compareDates(d1, d2) == 1) {
		tmp = d1;
		d1 = d2;
		d2 = tmp;
	}
	printf("Choose what how do you want the printed items:\n0-Exit\n1-By date sort\n2-By product key sort\n3-By order inventory sort\n");
	printf("Enter yor choice here:");//user->premission==0 => Technician
	while (1 != scanf("%d", &index) || !(index == 0 || index == 1 || index == 2 || index == 3) ){
		printf("Wrong input try again\nEnter your choice here:");
		while ((c = getchar()) != '\n');
		fflush(stdin);
	}
	if (index) {
		arr=malloc(sizeof(int*)*(orderInventoryArray->size));
		if (arr==NULL) {
			printf("Error:malloc:printOrderInventoryByRangeOfDate:arr\n");
			return false;
		}
		for (i = 0; i < orderInventoryArray->size; i++) {
			arr[i] = malloc(sizeof(int) * 2);
			if (arr[i]==NULL) {
				printf("Error:malloc:printOrderInventoryByRangeOfDate:arr[%d]\n",i);
				for (i = i - 1; i >= 0; i--) {
					free(arr[i]);
				}
				free(arr);
				return false;
			}
		}
		switch (index) {

		case ONE: {
			while (j < orderInventoryArray->size) {
					arr[j][0] = differenceBetweenTwoDates(orderInventoryArray->orderInventory[j]->date, d2);
					arr[j][1] = j;
				j++;
			}
			quickSortInts(&arr, ZERO, orderInventoryArray->size-ONE);

			break;
		}

		case TWO: {
			for (j = 0; j < orderInventoryArray->size; j++) {
				arr[j] = malloc(sizeof(int) * 2);
				arr[j][0] = orderInventoryArray->orderInventory[j]->productKey;
				arr[j][1] = j;
			}
			quickSortInts(&arr, ZERO, orderInventoryArray->size - ONE);
			break;
		}
		default: {
			for (j = 0; j < orderInventoryArray->size; j++) {
				arr[j] = malloc(sizeof(int) * 2);
				arr[j][0] = orderInventoryArray->orderInventory[j]->orderInventoryKey;
				arr[j][1] = j;
			}
		}
		}



	}
	else {
		return true;
	}
	printf("\x1b[34m***********************************\x1b[0m\n");
	for (i = 0; i < orderInventoryArray->size; i++) {
		//cheak valid range
		if ((compareDates(orderInventoryArray->orderInventory[arr[i][1]]->date, d1) == 1 && compareDates(orderInventoryArray->orderInventory[arr[i][1]]->date, d2) == -1) || compareDates(orderInventoryArray->orderInventory[arr[i][1]]->date, d1) == 0 || compareDates(orderInventoryArray->orderInventory[arr[i][1]]->date, d2) == 0) {
			printOrderInventory(*orderInventoryArray->orderInventory[arr[i][1]], printCode);
			printf("\n");
			printOrderInventory(*orderInventoryArray->orderInventory[arr[i][1]],0);
			printf("Arriving status:arrived\n");
			printf("\x1b[34m***********************************\x1b[0m\n");
		}
	}
	for (i = 0; i < orderInventoryArray->size; i++) {
		free(arr[i]);
	}
	free(arr);

    printf("Please enter any key to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');

	return flag;
}

void printExpense(OrderInventoryArray* orderInventoryArray) {
	printf("***********************************\n");
	printf("Printing orders and the total expense by date range\n");
	printf("***********************************\n");

	int i, sum = 0;
	Date d1, d2, tmp;
	char c;
	printf("Please enter 2 Dates:format(day month year)\n");
	printf("Please enter the first date\n");
	if (3 != scanf("%d %d %d", &(d1.day), &(d1.month), &(d1.year))) {
		while ((c = getchar()) != '\n');
		fflush(stdin);
		printf("The input is wrong. Try again later\n");
		return ;
	}
	printf("Please enter the second date\n");
	if (3 != scanf("%d %d %d", &(d2.day), &(d2.month), &(d2.year))) {
		while ((c = getchar()) != '\n');
		fflush(stdin);
		printf("The input is wrong. Try again later\n");
		return ;
	}
	//checking if the dates are valid
	if (!checkDate(d1) || !checkDate(d2)) {
		printf("One of the dates you entered is not a valid date! Returning to the main menu\n");
		return;
	}
	if (compareDates(d1, d2) == 1) {
		tmp = d1;
		d1 = d2;
		d2 = tmp;
	}

	printf("\x1b[34m***********************************\x1b[0m\n");
	for (i = 0; i < orderInventoryArray->size; i++) {
		//cheak valid range
		if ((compareDates(orderInventoryArray->orderInventory[i]->date, d1) == 1 && compareDates(orderInventoryArray->orderInventory[i]->date, d2) == -1) || compareDates(orderInventoryArray->orderInventory[i]->date, d1) == 0 || compareDates(orderInventoryArray->orderInventory[i]->date, d2) == 0) {
			printOrderInventory(*orderInventoryArray->orderInventory[i], 0);
			printf("\x1b[34m***********************************\x1b[0m\n");
			sum += (orderInventoryArray->orderInventory[i]->quantity)*(orderInventoryArray->orderInventory[i]->pricePerItem);
		}
	}

	printf("The total expense in the date range(from %d/%d/%d to %d/%d/%d) is:%d", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year, sum);
	printf("\x1b[34m***********************************\x1b[0m\n");

    printf("Please enter any key to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');
}


void printEarning(OrderClientArray* orderClientArray, OrderInfoArray* orderInfoArray,ProductArray* productArray) {
	printf("***********************************\n");
	printf("Printing sold products and the total price for all by the date range\n");
	printf("***********************************\n");

	int i, sum = 0,temp,temp2;
	Date d1, d2, tmp;
	char c;
	OrderInfo* tempOrderInfo=NULL;
	Product* productTemp = NULL;
	printf("Please enter 2 Dates:format(day month year)\n");
	printf("Please enter the first date\n");
	if (3 != scanf("%d %d %d", &(d1.day), &(d1.month), &(d1.year))) {
		while ((c = getchar()) != '\n');
		fflush(stdin);
		printf("The input is wrong. Try again later\n");
		return;
	}
	printf("Please enter the second date\n");
	if (3 != scanf("%d %d %d", &(d2.day), &(d2.month), &(d2.year))) {
		while ((c = getchar()) != '\n');
		fflush(stdin);
		printf("The input is wrong. Try again later\n");
		return;
	}
	//checking if the dates are valid
	if (!checkDate(d1) || !checkDate(d2)) {
		printf("One of the dates you entered is not a valid date! Returning to the main menu\n");
		return;
	}
	if (compareDates(d1, d2) == 1) {
		tmp = d1;
		d1 = d2;
		d2 = tmp;
	}

	for (i = 0; i <orderClientArray->size; i++) {
		if ((compareDates(orderClientArray->orderClient[i]->date, d1) == 1 && compareDates(orderClientArray->orderClient[i]->date, d2) == -1)
			|| compareDates(orderClientArray->orderClient[i]->date, d1) == 0
			|| compareDates(orderClientArray->orderClient[i]->date, d2) == 0) {

			printf("\x1b[31m************ -- %d -- ************\x1b[0m\n", i + 1);
			printOrderClient(*orderClientArray->orderClient[i], printCode);
			printf("\n");
			printf("Client ID:");
			printOrderClient(*orderClientArray->orderClient[i], 1);
			printf("\n");
            printf("Worker Id:");
			printOrderClient(*orderClientArray->orderClient[i], 2);
			printf("\n");
			printf("Order Date:");
			printOrderClient(*orderClientArray->orderClient[i], 3);
			printf("\nBuild computer = ");
			printOrderClient(*orderClientArray->orderClient[i], 5);
			printf("\n");
			for (temp = 0; temp < orderClientArray->orderClient[i]->orderInfoKeyArray.size; temp++) {
				searchOrderInfo(*orderInfoArray, &tempOrderInfo, &temp2, orderClientArray->orderClient[i]->orderInfoKeyArray.arr[temp]);
				if (!tempOrderInfo) {
					printf("There is no orderInfoKey--%d\n", orderClientArray->orderClient[i]->orderInfoKeyArray.arr[temp]);
				}
				else {
					searchProduct(*productArray, &productTemp, &temp2, tempOrderInfo->productKey);
					if (!productTemp) {
						printf("There is no productKey--%d\n", tempOrderInfo->productKey);
					}
					else {
						printf("\x1b[34m**********************************\x1b[0m\n");
						printProduct(*productTemp, 0);
						printf("\x1b[34m**********************************\x1b[0m\n");
						sum += (productTemp->sellingPrice)*(tempOrderInfo->quantity);
					}
				}
			}
			printf("\x1b[31m**********************************\x1b[0m\n");
			printf("Total sum is: %d\n",sum);
			printf("\x1b[31m**********************************\x1b[0m\n");
		}
	}

    printf("Please enter any key to exit\n");
    while ((c = getchar()) != '\n');
    while ((c = getchar()) != '\n');

}




bool laboratoryM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {
	int c, option;
	bool exitFlag = false, flag = true;
	printf("***********************************************************************\n");
	printf("Laboratory Menu:\n");
	printf("***********************************************************************\n");

	do {
		printf("Please pick one option:\n0-exit.\n1-Repairs. \n2-Laboratory reports.\n");
		printf("Enter your choice here:");
		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2)) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (0 == option)
			exitFlag = true;
		if (!exitFlag) {
			switch (option) {
			case 1: flag = laboratoryRepairsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
				break;
			case 2:
				flag = laboratoryReportsM(categoryArray, workerArray, clientArray, orderInfoArray, orderInventoryArray, orderClientArray, productArray, laboratoryArray, user);
				break;
			default:printf("Error option\n");
			}
		}
	} while (!exitFlag&&flag);
	return flag;
}



bool laboratoryReportsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {


	int c, option;
	bool exitFlag = false, flag = true;
	printf("***********************************************************************\n");
	printf("Laboratory Reports Menu:\n");
	printf("***********************************************************************\n");

	do {
		printf("Please pick one option:\n");
		printf("0. exit.\n");
		printf("1. show items in laboratory\n");
		printf("2. show items in laboratory per time\n");
		printf("3. show delay item in laboratory\n ");

		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2 || option == 3)) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (option == 0)
			exitFlag = true;
		if (option == 1) {
			showItemsInLaboratory(laboratoryArray, productArray, workerArray);
			flag = true;
		}
		if (option == 2)
			flag = showItemsInLaboratoryWithTime(laboratoryArray, productArray, workerArray);
		if (option == 3)
			flag = showDelayItemInLaboratory(laboratoryArray, productArray, workerArray);
	} while (!exitFlag && flag);

	return flag;
}

bool laboratoryRepairsM(CategoryArray* categoryArray, WorkerArray* workerArray, ClientArray* clientArray, OrderInfoArray* orderInfoArray, OrderInventoryArray* orderInventoryArray, OrderClientArray* orderClientArray, ProductArray* productArray, LaboratoryArray* laboratoryArray, Worker* user) {

	int c, option, choice, index;
	Laboratory* laboratory;
	bool exitFlag = false, flag = true;
	printf("***********************************************************************\n");
	printf("Laboratory Repairs Menu:\n");
	printf("***********************************************************************\n");
	do {
		printf("Please pick one option:\n");
		printf("0. exit.\n");
		printf("1. Repair product.\n");
		printf("2. Show item in laboratory.\n");

		while (1 != scanf("%d", &option) || !(option == 0 || option == 1 || option == 2)) {
			printf("Wrong input try again\nEnter yor choice here:");
			while ((c = getchar()) != '\n');
			fflush(stdin);
		}
		if (option == 0)
			exitFlag = true;
		if (option == 1) {
			flag = repairProduct(productArray, laboratoryArray, workerArray, user);
		}
		if (option == 2) {
			printf("Please enter a laboratory key:\n");
			if (1 != scanf("%d", &choice)) {
				printf("The input is wrong. returning to the main menu\n");
			}
			else {
				searchLaboratory(*laboratoryArray, &laboratory, &index, choice);
				if (laboratory != NULL) {
					showItemInLaboratory(laboratoryArray, productArray, workerArray, index);
				}
				else {
					printf("The key is not exist. returning to the main menu\n");
				}
			}
			flag = true;
		}

	} while (!exitFlag && flag);

	return flag;
}


