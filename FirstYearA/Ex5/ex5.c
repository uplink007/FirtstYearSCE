/*
Assignment: 5
Campus: Beer Sheva
Author: Segey Shevchuk, ID: 321274524
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*******************************Define enum and FIXed numbers****************************/
enum integers{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,ELEVEN};
#define ID TEN
#define TEMP 201
#define NUMBER_OF_HOBIES 10
#define MIN_AGE 18
#define MAX_AGE 100
typedef enum{ False, True }boolean;
/**************************************Struct user**********************************************/
typedef struct user{
	char id[ID];
	char *pfirst;
	char* plast;
	int age;
	char gender;
	char* username;
	char* password;
	char* description;
	char* hobbies[FOUR];//get the pointer of the array
	short hobbiesNumbers[FOUR];//save the number of the hobbie
    struct user* next;//next user
}user;
/*************************************Define functions***********************************************/
boolean Main();
void start(user**, boolean*,boolean*);
boolean addNewMember(user**,user**);
boolean digits(char*);
void nullUser(user*);
void logIn(user*,user**);
void hobis(user*,int,char**);
boolean inputFile(user*,int*,int);
void freeUser(user*);
boolean output(user**,int*);
void printUser(user*);
void Tafrit(user*,user* );
void freeAllUsers(user*);
void printAll(user*);
void loveSearch(user* , user*  );
void printLove(user*);
/********************Const global char arrays that include the hobbies********************************/
const char tv_shows[NINE] ="TV Shows";
const char movies[SEVEN] = "Movies";
const char gym[FOUR] = "Gym";
const char basketball[ELEVEN] = "Basketball";
const char baseball[NINE] = "Baseball";
const char bicycle[EIGHT] = "Bicycle";
const char poetry[SEVEN] = "Poetry";
const char books[SIX] = "Books";
const char drawing[EIGHT] = "Drawing";
const char theatre[EIGHT] = "Theatre";
/**************main function*****************/
int main(){
	return Main();//return ZERO if all denamic arrays was allocated well,else return ONE
}//end main
boolean Main(){
	/**************First function of the Dating program*****************/
	boolean alloc = True,newUser=False,flag;//boolean flags ,alloc-for dinamic arrays fail,newUser-for adding to the input.bin,flag-for exit
	int temp,calcIn=ZERO,before=ZERO;//temp-for error option,calcIn,how many chars inputed to the file,before-to now how many users in the input.bon file allready and how many need to add
	user* head=NULL;//the head pointer of the struct array
	alloc=output(&head,&before);//get the users from the input.bin file,return false if there was problem,true if every thing was fine
						
	if(alloc)//check if Flase or true
		start(&head,&newUser,&alloc);//Tafrit knisa
	if(newUser&&alloc&&head!=NULL)//input new user to the file before exit
		do{
		flag = inputFile(head,&calcIn,before);//if not every thing was writen return false,else return true
		if (!flag){//if was problem
			printf("Adding the new user in to the data base faild!!!\nDo you want to try again?\n1-YES\n2-NO\n");//1 try again 2 exit without save
			while (ONE != scanf("%d", &temp) || temp != TWO || temp != ONE){
				printf("Wrong choise!!!\nTry again:\n");//wrong input
			}
			switch (temp){
			case ONE://try again
				break;
			case TWO:
				flag = True;//exit
				break;
			}
		}
		}while(!flag);//while flag!= True
	if (head != NULL){
		freeAllUsers(head);//free all the data base from heap
		head = NULL;
	}
	return(!alloc);//if alloc true return ZERO,else return ONE
}//end Main
void start(user** head,boolean* newUser,boolean* alloc){
	/****************function to log in or make new user***************/
	int option;//defien int variable for option
	user* tafritUser=NULL;//to log in the new user
	printf("Log in-1\nNew member-2\nPlease choose 1 or 2:\n");
	while (ONE != scanf("%d", &option) || option < ONE || option>TWO||(*head==NULL&&option==1)){
		if (*head == NULL&&option==ONE)//there is no users in the data base
			printf("You cann't log in becase there is no users in the data base!!!\n");
		else
			printf("Bad choise, please enter again:\n");
		fflush(stdin);
	}
	switch (option){//1- log in ,2- nadd new user
	case TWO: {
		*newUser = True;
		*alloc=addNewMember(head,&tafritUser);//return True if the creation was fine, else return False
		break;
	}
	case ONE:{
		if(alloc&&*head!=NULL)//if alloc is fine and the data base isn't empty
			logIn(*head,&tafritUser);
		break;
	default:
		break;
	}
	}
	Tafrit(*head,tafritUser);//search system
}//end start
boolean addNewMember(user** head,user** tafritUser){
	/**************Function that make a new user and add him to the struct chain*****************/
	user* curent =*head;//instolized to first user
	user* userTemp;//define struct for new user
	char temp;
	boolean flag = True;//for ID cheack
	userTemp = (user*)malloc(sizeof(user));//get the stract from heap
	if (userTemp == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;//alloc=False
	}
	nullUser(userTemp);//NULL new user pointers
	char strTemp[TEMP];//temp array of 201 chars
	if (*head == NULL){//if the new user is first one
		curent = userTemp;
		*head = curent;
	}
	else{
		while (curent->next != NULL){//get to the last user
			curent = curent->next;
		}
		curent->next = userTemp;//join him to the data base
		curent = userTemp;
	}

	printf("Please enter your ID:\n");
	fflush(stdin);
	gets(strTemp);//ID
	flag = digits(strTemp);
	while (NINE != strlen(strTemp)||flag!=True){
		printf("Wrong ID,please try again:\n");
		fflush(stdin);
		gets(strTemp);
		flag = digits(strTemp);
	}
	strcpy(curent->id, strTemp);
	printf("Please enter your First Name(MAX 10 chars):\n");
	while (ONE != scanf("%s%c", strTemp, &temp) && strlen(strTemp)>TEN || temp != '\n'){//first name
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	curent->pfirst = (char*)malloc((strlen(strTemp) + ONE)*sizeof(char));
	if (curent->pfirst == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	strcpy(curent->pfirst, strTemp);
	printf("Please enter your Last Name(MAX 10 chars):\n");
	while (ONE != scanf("%s%c", strTemp, &temp) && strlen(strTemp)>TEN || temp != '\n'){//last name
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	curent->plast = (char*)malloc((strlen(strTemp) + ONE)*sizeof(char));
	if (curent->plast == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	strcpy(curent->plast, strTemp);
	printf("Enter your age(MIN=18,MAX=100:\n");
	while (ONE != scanf("%d%c", &curent->age, &temp) && (curent->age < MIN_AGE || curent->age>MAX_AGE) || temp != '\n'){//age min 18 - max 100
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	printf("Please enter your gender(M-Male,F-Female):\n");
	while (TWO != scanf("%c%c", &(curent->gender),&temp) || ((curent->gender) != 'M' || (curent->gender) != 'F'&&temp!='\n')){//gender M or F
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	printf("Enter your User Name(MIN 5 chars,MAX 10 chars,first char have to be a letter):\n");
	while (ONE != scanf("%s%c", strTemp, &temp) && strlen(strTemp)>TEN || strlen(strTemp)<FIVE || (*(strTemp + ONE)<'A' || *(strTemp + ONE)>'Z'&&*(strTemp + ONE)<'a' || *(strTemp + ONE)>'z') || temp != '\n'){//User name
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	curent->username = (char*)malloc((strlen(strTemp) + ONE)*sizeof(char));
	if (curent->username == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	strcpy(curent->username, strTemp);
	printf("Enter your Password(MAX 6 chars):\n");
	while (ONE != scanf("%s%c", strTemp, &temp) && strlen(strTemp)>SIX  || temp != '\n'){//password max 6 chars
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	curent->password = (char*)malloc((strlen(strTemp) + ONE)*sizeof(char));
	if (curent->username == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	strcpy(curent->password, strTemp);
	printf("Please enter your description(MAX 200 chars):\n");
	gets(strTemp);//description
	curent->description = (char*)malloc((strlen(strTemp) + ONE)*sizeof(char));
	if (curent->description == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	strcpy(curent->description, strTemp);
	hobis(curent, ZERO, NULL);//sending to the hobbies function
	printf("Hi %s, welcome to SCE Dating site!!!\n", curent->pfirst);
	*tafritUser = curent;//the user that will log in to the system
	return True;//everything was fine return True
}//end addNewMember 
void hobis(user* curent,int hobie,char** temp){
	/***********************function that pointer at choosen hobbies arrays from global consts**********************/
	int i;
	char tempCh;
	if (hobie == FOUR)//stop condition
		return;
	if (temp == NULL){//Instolize array
		char* tempT[] = { (char*)tv_shows, (char*)movies, (char*)gym, (char*)basketball, (char*)baseball, (char*)bicycle, (char*)poetry, (char*)books, (char*)drawing, (char*)theatre };
		temp = tempT;
	}
	printf("Please choose your favorite hobie:\n");
	for (i = ONE; i <= NUMBER_OF_HOBIES; i++){
		if (*(temp+(i-ONE))!=NULL)
			printf("%d-%s\n",i,*(temp + i-ONE));//print the one that wasn't choosed before
	}
	printf("Your choise is:\n");
	while ((ONE != scanf("%d%c", &i, &tempCh) &&( i > NUMBER_OF_HOBIES || i < ONE)) || tempCh != '\n'){//from 1-10
		printf("Wrong input ,try again:\n");
		fflush(stdin);
	}
	switch (i){
	case ONE:{
		curent->hobbies[hobie] = (char*)tv_shows;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = ONE;//save the hobbie number 
		temp[ZERO] = NULL;					//delit the hobbie from next printf
		break;
	}
	case TWO:{
		curent->hobbies[hobie] = (char*)movies;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = TWO;//save the hobbie number
		temp[ONE] = NULL;//delit the hobbie from next printf
		break;
	}
	case THREE:{
		curent->hobbies[hobie] = (char*)gym;//point to the hobbie
		curent->hobbiesNumbers[hobie] = THREE;//save the hobbie number 
		temp[TWO] = NULL;//delit the hobbie from next printf
		break;
	}
	case FOUR:{
		curent->hobbies[hobie] = (char*)basketball;//point to the hobbie
		curent->hobbiesNumbers[hobie] = FOUR;//save the hobbie number 
		temp[THREE] = NULL;//delit the hobbie from next printf
		break;
	}
	case FIVE:{
		curent->hobbies[hobie] = (char*)baseball;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = FIVE;//save the hobbie number
		temp[FOUR] = NULL;//delit the hobbie from next printf
		break;
	}
	case SIX:{
		curent->hobbies[hobie] = (char*)bicycle;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = SIX;//save the hobbie number 
		temp[FIVE] = NULL;//delit the hobbie from next printf
		break;
	}
	case SEVEN:{
		curent->hobbies[hobie] = (char*)poetry;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = SEVEN;//save the hobbie number 
		temp[SIX] = NULL;//delit the hobbie from next printf
		break;
	}
	case EIGHT:{
		curent->hobbies[hobie] = (char*)books;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = EIGHT;//save the hobbie number 
		temp[SEVEN] = NULL;//delit the hobbie from next printf
		break;
	}
	case NINE:{
		curent->hobbies[hobie] = (char*)drawing;//point to the hobbie 
		curent->hobbiesNumbers[hobie] = NINE;//save the hobbie number 
		temp[EIGHT] = NULL;//delit the hobbie from next printf
		break;
	}
	case TEN:{
		curent->hobbies[hobie] = (char*)theatre;//point to the hobbie
		curent->hobbiesNumbers[hobie] = TEN;//save the hobbie number 
		temp[NINE] = NULL;//delit the hobbie from next printf
		break;
	}
	default:
		return;
	}
	hobis(curent, hobie + ONE, temp);//recurtion call for next hobbie
}//end hobbies

void nullUser(user* puser){
	//NULL all user pointers
	puser->pfirst = NULL;
	puser->plast = NULL;
	puser->username = NULL;
	puser->password = NULL;
	puser->description = NULL;
	puser->next = NULL;
}//end nullUser
boolean digits(char* str){
	/***********************Cheack if there was only digits in the string*****************************/
	int i;
	for (i = ZERO; *(str + i) != '\0'; i++){
		if (*(str + i) < '0' || *(str + i) > '9')
			return False;
	}
	return True;
}//end digits
void logIn(user* head,user** tafritUser){
	/*************************Function that get user name and password and cheack if you are in the data base************************/
	char tempUser[ELEVEN], tempPass[SEVEN];//temp arrays for input
	user*temp;
	boolean flag=False;
	do{
		printf("Please user name + password.\nUsername:\n");
		fflush(stdin);
		gets(tempUser);
		printf("Password:\n");
		fflush(stdin);
		gets(tempPass);
		for (temp=head; temp != NULL; temp = temp->next){//runing on the struct chain
			if (!strcmp(tempUser, temp->username) && !strcmp(tempPass, temp->password)){//cheack if that is the user
				flag = True;
				*tafritUser = temp;//save user*
			}
		}
		if (flag == False){
			printf("User name or password don't exist in the system, please try again!!!");
		}
	} while (!flag);//stop condition
	printf("Hello %s %s.\n", (*(tafritUser))->pfirst, (*(tafritUser))->plast);//Hello masage
}//end logIn
boolean inputFile(user* head,int* calcIn,int before){//calcIn-if was fail,save the number of chars thet needed to be delited,before-save the user count before the first new user 
	/***********************************Function that save the data base in the input.bin file and return if succseeded****************************/
	user* temp=head;
	FILE* fuser;
	int calc = ZERO,i;//calc- calculate the needed amount of chars that need to add to the file
	short len[FIVE];
	short page;
	char pgender;
	float ch = (float)1.1;//inputed between 2 users
	fuser = fopen("input.bin", " a + b");
	if (fuser == NULL){
		printf("Cann't open file!!!\n");
		return False;
	}
	fseek(fuser, ZERO, SEEK_SET);
	if(fread(&pgender,sizeof(char),ONE,fuser)){//cheack if the file are new or have already information
		fseek(fuser, ZERO, SEEK_END);
		fwrite(&ch, sizeof(float), ONE, fuser);
	}
	fseek(fuser, EIGHT*sizeof(char)*(*calcIn), SEEK_END);//move amount of bits that needed to be delited
	*calcIn = ZERO;//calcIn=0 
	for (i = ZERO; i < before; i++){//get to the first new user
		temp = temp->next;
	}
	for (temp; temp != NULL; temp = temp->next){//input information (1 run = 1 user)
		len[ZERO] = strlen(temp->pfirst) + ONE;
		len[ONE] = strlen(temp->plast) + ONE;
		len[TWO] = strlen(temp->username) + ONE;
		len[THREE] = strlen(temp->password) + ONE;
		len[FOUR] = strlen(temp->description) + ONE;
		page = temp->age;
		pgender = temp->gender;
		*calcIn += fwrite(temp->id, sizeof(char), strlen(temp->id), fuser);//ID
		calc = calc + strlen(temp->id);
		*calcIn += fwrite(len + ZERO, sizeof(short), ONE, fuser)*TWO;//size of first name
		calc = calc + TWO;
		*calcIn += fwrite(temp->pfirst, sizeof(char), strlen(temp->pfirst), fuser);//first name
		calc = calc + strlen(temp->pfirst);
		*calcIn += fwrite(len + ONE, sizeof(short), ONE, fuser)*TWO;//size of last name
		calc = calc + TWO;
		*calcIn += fwrite(temp->plast, sizeof(char), strlen(temp->plast), fuser);//last name
		calc = calc + strlen(temp->plast);
		*calcIn += fwrite(&page, sizeof(short), ONE, fuser)*TWO;//age
		calc = calc + TWO;
		*calcIn += fwrite(&pgender, sizeof(char), ONE, fuser);//gender
		calc = calc + ONE;
		*calcIn += fwrite(len + TWO, sizeof(short), ONE, fuser)*TWO;//size of user name
		calc = calc + TWO;
		*calcIn += fwrite(temp->username, sizeof(char), strlen(temp->username), fuser);//user name
		calc = calc + strlen(temp->username);
		*calcIn += fwrite(len + THREE, sizeof(short), ONE, fuser)*TWO;//size of password
		calc = calc + TWO;
		*calcIn += fwrite(temp->password, sizeof(char), strlen(temp->password), fuser);//password
		calc = calc + strlen(temp->password);
		*calcIn += fwrite(len + FOUR, sizeof(short), ONE, fuser)*TWO;//size of description
		calc = calc + TWO;
		*calcIn += fwrite(temp->description, sizeof(char), strlen(temp->description), fuser);//description
		calc = calc + strlen(temp->description);
		*calcIn += fwrite(temp->hobbiesNumbers, sizeof(short), FOUR, fuser)*TWO;//hobbies nummbers
		calc = calc + EIGHT;
		if (temp->next != NULL){//if there is one more user 1.1 float,if there is not than EOF
			*calcIn += fwrite(&ch, sizeof(float), ONE, fuser)*FOUR;//flag
			calc = calc + FOUR;
		}
	}
	fclose(fuser);
	if (*calcIn == calc)//cheack if all the information inputed
		return True;
	else
		return False;
}//end inputFile
boolean output(user** head,int* before){//before- save the amount of user inputed,return boolean if file opened, all the bits was outputed and dinamic arrays was builed without problems
	/**************************Function that output the information from input.bin to the stract chain**************************************/
	user* curent;
	FILE* fuser;
	int calcAll = ZERO, calc = ZERO;//calcAll-amount of all bytes in the file,calc- amount of outputed bytes
	float ch;//cheack if there is one more to output
	short temp;
	int i;
	char tempCh;
	*head = (user*)malloc(sizeof(user));//define new user
	if (head == NULL){
		printf("Cann't allocate memory!!!\n");
		return False;
	}
	nullUser(*head);//null new user
	curent = *head;//point to first
	fuser = fopen("input.bin", "a+b");
	if (fuser == NULL){
		printf("Cann't open file!!!\n");
		return False;
	}
	fseek(fuser, ZERO, SEEK_SET);
	while (fread(&tempCh, sizeof(char), ONE, fuser)){//amount of bytes in the file
		calcAll++;
	}
	fseek(fuser, ZERO, SEEK_SET);
	if (ZERO == fread(&ch, sizeof(char), ONE, fuser)){//if the file is empty
		fclose(fuser);
		free(*head);
		*head = NULL;
		return True;
	}
	else
		fseek(fuser, ZERO, SEEK_SET);//set to start point
	while (curent != NULL){//stop condition
		calc+=fread(curent->id, sizeof(char), NINE, fuser);//ID
		curent->id[NINE] = '\0';//end string
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//size of first name
		curent->pfirst = (char*)malloc(temp--*sizeof(char));//define array
		if (curent->pfirst == NULL){
			printf("Cann't allocate memory!!!\n");
			return False;
		}
		calc += fread(curent->pfirst, sizeof(char), temp, fuser);//first name 
		curent->pfirst[temp] = '\0';//end string
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//size of last name
		curent->plast = (char*)malloc(temp--*sizeof(char));//define array
		if (curent->plast == NULL){
			printf("Cann't allocate memory!!!\n");
			return False;
		}
		calc += fread(curent->plast, sizeof(char), temp, fuser);//last name
		curent->plast[temp] = '\0';//end string
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//age
		curent->age = temp;
		calc += fread(&tempCh, sizeof(char), ONE, fuser);//gender
		curent->gender = tempCh;
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//size of user name
		curent->username = (char*)malloc(temp--*sizeof(char));//define array
		if (curent->username == NULL){
			printf("Cann't allocate memory!!!\n");
			return False;
		}
		calc += fread(curent->username, sizeof(char), temp, fuser);//user name
		curent->username[temp] = '\0';//end string
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//size of password
		curent->password = (char*)malloc(temp--*sizeof(char));//define array
		if (curent->password == NULL){
			printf("Cann't allocate memory!!!\n");
			return False;
		}
		calc += fread(curent->password, sizeof(char), temp, fuser);//password
		curent->password[temp] = '\0';//end string
		calc += fread(&temp, sizeof(short), ONE, fuser)*TWO;//size of description
		curent->description = (char*)malloc(temp--*sizeof(char));//define array
		if (curent->description == NULL){
			printf("Cann't allocate memory!!!\n");
			return False;
		}
		calc += fread(curent->description, sizeof(char), temp, fuser);//description
		curent->description[temp] = '\0';//end string
		calc += fread(curent->hobbiesNumbers, sizeof(short), FOUR, fuser)*TWO;//hobbies numbers
		for (i = ZERO; i < FOUR; i++){//point to the hobbie global const arrays
			switch (*(curent->hobbiesNumbers+i)){
			case ONE:{
				curent->hobbies[i] = (char*)tv_shows;//1
				break;
			}
			case TWO:{
				curent->hobbies[i] = (char*)movies;//2
				break;
			}
			case THREE:{
				curent->hobbies[i] = (char*)gym;//3
				break;
			}
			case FOUR:{
				curent->hobbies[i] = (char*)basketball;//4
				break;
			}
			case FIVE:{
				curent->hobbies[i] = (char*)baseball;//5
				break;
			}
			case SIX:{
				curent->hobbies[i] = (char*)bicycle;//6
				break;
			}
			case SEVEN:{
				curent->hobbies[i] = (char*)poetry;//7
				break;
			}
			case EIGHT:{
				curent->hobbies[i] = (char*)books;//8
				break;
			}
			case NINE:{
				curent->hobbies[i] = (char*)drawing;//9
				break;
			}
			case TEN:{
				curent->hobbies[i] = (char*)theatre;//10
				break;
			}
			}
		}
		if (0 < fread(&ch, sizeof(float), ONE, fuser)){//if there is one more user
			calc += FOUR;
			curent->next = (user*)malloc(sizeof(user));//define next user
			if (curent->next == NULL){
				printf("Cann't allocate memory!!!\n");
				return False;
			}
		}
		else
			curent->next = NULL;//that is the last user to output
		curent = curent->next;
		(*before)++;//amount of outputed users
	}
	fclose(fuser);
	if (calcAll != calc){//cheack if all data was outputed
		printf("Not all data base was inputed from the file!!!\n");
		return False;
	}
	return True;
}//end outputFile
void printAll(user* head){
	/********************print all users*****************/
	user* temp;
	if (head != NULL){
		for (temp = head; temp != NULL; temp = temp->next){
			printUser(temp);
		}
	}
}//end printAll
void printUser(user* curent){
	/***********************print one user******************/
	puts(curent->id);
	puts(curent->pfirst);
	puts(curent->plast);
	printf("%d\n%c\n", curent->age, curent->gender);
	puts(curent->username);
	puts(curent->password);
	puts(curent->description);
	puts(*(curent->hobbies + ZERO));
	puts(*(curent->hobbies + ONE));
	puts(*(curent->hobbies + TWO));
	puts(*(curent->hobbies + THREE));
	printf("%p\n", curent->next);
}//end printUser
void freeUser(user* temp){
	/**********************free pointers from one struct from the heap***************************/
	if (temp != NULL){
		if (temp->pfirst != NULL)
			free(temp->pfirst);
		if (temp->plast != NULL)
			free(temp->plast);
		if (temp->username != NULL)
			free(temp->username);
		if (temp->password != NULL)
			free(temp->password);
		if (temp->description != NULL)
			free(temp->description);
	}
}//end freeUser
void freeAllUsers(user* head){
	/**********************Free all memory from the heap that was used*********************/
	user* temp;
	for (head; head != NULL; head){
		freeUser(head);
		temp = head;
		head = head->next;
		free(temp);
		temp = NULL;
	}
	head = NULL;
}//end of freeAllUsers
void Tafrit(user* head,user* curent){
	/********************************************Function that have 2 options , search or leave***********************************/
	int option;
	printf("1-Search love\n2-EXIT\nEnter your choice\n");
	while(ONE != scanf("%d", &option) || (option <ONE || option > TWO)){
		printf("Bad choice, please enter again:\n");
		fflush(stdin);
	}
	if (option > ZERO && option < THREE){
		switch (option){
		case ONE:loveSearch(head, curent);//search
			break;
		case TWO://leave
			break;
		}
	}
}//end Tafrit
void loveSearch(user* head, user* curent){
	/********************************Function that search the oposit gender between the user inputed range*****************************************/
	user* temp = head;
	int min, max,counter,i,j;
	boolean flag = False;
	printf("Please enter age range(18-100):\nMIN age:\n");
	scanf("%d", &min);
	printf("MAX age(not smaller than %d):\n",min);
	scanf("%d", &max);
	for (temp; temp != NULL; temp = temp->next){//go from first to last
		if (temp != curent){//skim the user him self
			if (temp->gender != curent->gender&&temp->age >= min&&temp->age <= max){
				counter = ZERO;
				for (i = ZERO; i < FOUR; i++){
					for (j = ZERO; j < FOUR; j++){
						if ((curent->hobbiesNumbers)[i] == (temp->hobbiesNumbers)[j]){
							counter++;
							if (counter >= TWO){
								flag = True;//if there was at least one found
							}
						}
					}
				}
				if (counter > ONE){
					printLove(temp);//print the founded user
					printf("\n\n");
				}
			}
		}
	}
	if (flag != True)//print if there was'n mutches at all
		printf("There is no love for you hear!!!\n");
	Tafrit(head, curent);//back to Tafrit function
}//end loveSearch
void printLove(user* love){
	/********************Function that print one user that mutch the search*********************/
	printf("Name: %s %s.\nAge: %d.\nDescription: ", love->pfirst, love->plast,love->age);
	puts(love->description);
	printf("Hobbies: %s, %s, %s, %s\n", *(love->hobbies + ZERO), *(love->hobbies + ONE), *(love->hobbies + TWO), *(love->hobbies + THREE));
}//end printLove