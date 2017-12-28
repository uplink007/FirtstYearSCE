/*
Assignment: 4
Campus: Beer Sheva
Author: Segey Shevchuk, ID: 321274524
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>		
/*************************************Define fixed numbers**********************************************************/
#define N 201
#define WORD 81
#define WORDSIZE 32
#define ROW 65
#define ROWSTART 44
#define SizeOfPointer_int 4
#define SizeOfDouble 8
#define SizeOfChar 1
enum smallInt{ZERO,ONE,TWO};
int getch (void);
/**********************************************Define functions names*************************************************/
void freeWord(char**);
void freeAll(char***);
void printDefenition(char*, int, int,int);
void start();
char*** Milon(int);
void printWord(char**);
void printAll(char***);
void repair(char***,int,int);
void repairWord(char*, int);
void repairDefenition(char*, int);
void arrInput(int*, int);
void swap(void*, void*, int);
void swapMilon(void*, int, int , int );
int compareWord(void*, void*);
void fastsort(void* , int , int , int , int(*cmp)(void*, void*), void(*swap)(void*, int,int ,int));
int delit(char*** );
int firstWord(char***, int , int );
void delitSeria(char*** , int , int , int*);
void arrayDefine(int* , int , int );
void* bSearch(void* , int , int , int , void* , int(*cmp)(void*, void*));
void search(char***);
int compareWordSearch(void*, void*);
void Continue();
/***********************************************************************************************/
int main(){
	/****************************************Main*******************************************************/
	start();//First function that make all the program
	return ZERO;
}
void start(){
	/**************************************Start function*********************************************************/
	char*** milon=NULL;
	int* arr=NULL;              //Define varables
	int milonSize = ZERO;
	printf("How many words do you want to insert the dictionary ?\nPlease enter a positive integer!!!\nNumber of words:\n");
	while (ONE != scanf("%d", &milonSize) || milonSize < ZERO){
		/**if the input is incorrect while dont end,correct is integer that big or equel than ZERO**/
		printf("Please enter a positive intager!!!\nNumber of words:\n");
		fflush(stdin);//Clean buffer
	}
	if (milonSize > ZERO){
		/**********If there is words in the Dictionary********/
		milon = Milon(milonSize);//Sending the size of the Dictionary and get the first pointer of the Dictionary
		arr = (int*)malloc(milonSize*sizeof(int));//Make arr to save the word order
		if (arr == NULL){
			freeAll(milon);//Free the memory from the heap
			printf("Can't allocate memory\n");
			exit(ONE);//Abort program
		}
		arrInput(arr, milonSize);//Input varaible from 1 to milonSize
		milon[milonSize + ONE] = (char**)arr;//Catch the first pointer of the arr array by casting
		repair(milon,ZERO,ZERO);//Repair all the word and definitions like needed
		fastsort(milon, ZERO, milonSize - ONE, sizeof(char**), compareWord, swapMilon);//Sort the words in the Dictionary by lexicography
		milonSize=delit(milon);//Delit words that apeare twice, free the memory that they used and realloc the arrays 
	}
	search(milon);//Serch function for the user
	if (milon != NULL){//Free the milon array from the heap
		freeAll(milon);//Free all the memory from the heap
	}
}
char*** Milon(int size){
	/******************Get a size of the Dictionary array and bild the array from the heap memory******************/
	int i, j, defenition;//Define variables
	char str[N];//Define temp array of chars N=201(The teacher said that i dont need to worry if the word input will be biger than 80 this why i use only one temp array)
	char*** milon = (char***)malloc((size+TWO)*sizeof(char**));//allocate memory from heap for the Dictionary , NULL and one place to catch the order array
	if (milon == NULL){//If allocation was faild
		printf("Can't allocate memory\n");
		exit(ONE);//Abort
	}
	for (i = ZERO; i < size; i++){
		/*************Fill in the Dictionary**************/
		printf("How many defenitions the %d word will have?\nPlease enter a positive integer!!!\nNumber of defeniotions:\n", i + ONE);
		while (ONE != scanf("%d", &defenition) || defenition < ZERO){//Scan the Defenition size:make shure that he will be right:intager biger or equel to zero
			printf("Please only a positive integer:\nNumber of defeniotions of the %d word:\n",i+ONE);//becase start i =0 is first word
			fflush(stdin);//Clean buffer
		}
		milon[i + 1] = NULL;//End of milon array
		milon[i] = (char**)malloc((defenition + TWO)*sizeof(char*));//Allocate memory from heap for the word,and definitions and NULL in the end
		if (milon[i] == NULL){//If allocation faild
			freeAll(milon);//Free the memory of the milon from heap
			printf("Can't allocate memory\n");
			exit(ONE);//Abort
		}
		for (j = ZERO; j <= defenition; j++){
			/****Fill the word and definitions****/
			if (j == ZERO){//get the word
				printf("(*WARNING* Max size of the word is 80,finish with ENTER!!!)\nEnter the %d word:\n",i+ONE);
				scanf("%s", str);//str-> temp array
			}
			else{//get the definition
				printf("(*WARNING* Max size of the defenition is 200,finish with ENTER!!!)\nEnter the %d defenition:\n", j);
				fflush(stdin);//Clean buffer
				gets(str);//str->temp array
			}
			milon[i][j + 1] = NULL;//End of milon[i] array
			milon[i][j] = (char*)malloc((strlen(str) + ONE)*sizeof(char));//Allocate memory from heap for the string
			if (milon[i][j] == NULL){//allocation faild
				freeAll(milon);//Free the memory from heap
				printf("Can't allocate memory\n");
				exit(ONE);//Abort
			}
			strcpy(milon[i][j], str);//coppy the string to the allocated array
		}
	}
	return milon;//return the first pointer for the array
}
void search(char*** milon){
	/*****Function that will get the word the user look for and find it in the Dictionary*****/
	char str[WORD];//Temp array
	char** bSerchWord;//temp pointer to get the bSearch pointer that catch the word or get NULL if there was not such word 
	int i=ZERO;//For counting the Dictionary size
	if (milon != NULL){//The dictionary isn't empty
		while (*(milon + i) != NULL){//Count Dictionary size
			i++;//i=i+1
		}
		do{
			/*********Scan from the user the word that he looking for and print if there is such word or the word is unknown**********/
			printf("What word are you looking for?\n*WARNING*\n1)To end input \"exit\"\n2)Max size: is 80 chars\n3)Finish with ENTER!!!))\nEnter word:\n");
			fflush(stdin);//Clean buffer
			scanf("%s", str);//str-> temp array
			if (ZERO != strcmp(str, "exit")){//cheack if the word is exit (exit :the word to end the program)
				repairWord(str, ZERO);//Repair the word if needed
				bSerchWord = (char**)bSearch(milon, ZERO, i - ONE, sizeof(char*), str, compareWordSearch);//Sending the word to the bainary search function
																										//if there is such word and NULL if the word is unknown
				printf("-------------------------------------------------------------------------------\n");//Just for me ))
				if (bSerchWord != NULL)//If there is such word sending the pointer to print function
					printWord(bSerchWord);//print function for printing the word
				else
					printf("Unknown word!\nTry again:\n");//If the word is Unkown
				Continue();//Just for me ))
			}
			else
				printf("Thank you for using our Dictionary!!!!\n");//The end of the program
		} while (ZERO != strcmp(str, "exit"));//Cheack if the user whant to exit to end the while loop
	}
	else{//If the dictionary is empty
		do{//get input from the user and print that the word is unknown becase that the dictionary is empty
			printf("What word are you looking for?\n*WARNING*\n1)To end input \"exit\"\n2)Max size: is 80 chars\n3)Finish with ENTER!!!))\nEnter word:\n");
			fflush(stdin);//Clean buffer
			scanf("%s", str);//str->temp array
			if (ZERO != strcmp(str, "exit")){//cheack if the word is exit (exit :the word to end the program)
				printf("-------------------------------------------------------------------------------\n");
				printf("Unknown word!\nTry again:\n");
				Continue();//Just for me ))
			}
			else
				printf("Thank you for using our Dictionary!!!!\n");//end of program
		} while (ZERO != strcmp(str, "exit"));//Cheack if the user whant to exit to end the while loop
	}
	bSerchWord = NULL;//clean the value of bSearchWord(I know that it is usless but any way for me 
}
void printAll(char*** milon){
	/*************Function for me to cheack all the dictionary words and definitions****************/
	int i;
	for (i = ZERO; *(milon + i) != NULL; i++){
		printWord(milon[i]);
	}
}
void printWord(char** word){
	/***********************Function that print a word from the dictionary with all the dedinitions*****************************/
	int i=ZERO;
	int row = ROWSTART;//to put \n where needed
	while (*(word + i++) != NULL);//Cheack the and of the array
	printf("Number of defenitions for the word \"%s\" is: %d\n", *(word + ZERO), i - TWO);//print the word
	for (i = ONE; *(word + i) != NULL; i++){//print the i definition
		printf("The %d defeniotion is:",i);
		printDefenition(*(word + i), ZERO, ZERO,row);//function to print the definitions(i didnt want to use puts() function , did one by mysalve
	}
}
void Continue(){//just for beter vizualization
	printf("Press any key to continue...");
	getch();
	fflush(stdin);//clean buffer
	printf("\n-------------------------------------------------------------------------------\n");
}
void printDefenition(char* defenition, int ch, int size,int row){
	/************************************************Function that print a Definition and get to the next line when needed****************/
	if (*(defenition + ch) == '\0'){
		printf("\n");
		return;
	}
	if (*(defenition + ch) == ' '&&size > row){//if it is close to the end of line in the consol screen
		printf(" \n");
		row = row + ROW;
	}
	else
		printf("%c",*(defenition + ch));
	printDefenition(defenition, ch + ONE, size + ONE,row);//recursion
}
void repair(char*** milon,int word,int defenition){
	/***************************Function that repair all the words and definitions in the dictionary***********************/
	if (*(milon + word) == NULL)//end of dictionary
		return;
	if (defenition == ZERO)//Mean that is the word
		repairWord(*(*(milon + word) + defenition), ZERO);
	else//mean that is a definiition
		repairDefenition(*(*(milon + word) + defenition), ZERO);
	if (*(*(milon + word) + defenition + ONE) == NULL){//cheack the end of definition
		word++;
		defenition = ZERO;
	}
	else
		defenition++;//next definition
	repair(milon, word, defenition);//recursion 
}

void repairWord(char* word,int ch){
	/************************Function that repair the word*********************/
	if (*(word + ch) == '\0')//end of the word
		return;
	if (ch == ZERO){//first char
		if (*(word + ch) > 'Z'){//from small to big
			*(word + ch) = *(word + ch) - WORDSIZE;//A-a 32 chars in the ASKII code
		}
	}
	else{
		if (*(word + ch) >= 'A'&&*(word + ch)<='Z'){//from big to small
			*(word + ch) = *(word + ch) - WORDSIZE;//A-a 32 chars in the ASKII code
		}
	}
	repairWord(word, ch + ONE);//recurtion
}
void repairDefenition(char* defenition, int ch){
	if (*(defenition + ch) == '\0')//end of string
		return;
	if (ch == ZERO){
		if (*(defenition + ch) > 'Z'){//first char
			*(defenition + ch) = *(defenition + ch) - WORDSIZE;//A-a 32 chars in the ASKII code
		}
	}
	else{
		if (*(defenition + ch) >= 'A'&&*(defenition + ch) <= 'Z'){//from big to small
			*(defenition + ch) = *(defenition + ch) + WORDSIZE;//A-a 32 chars in the ASKII code
		}
	}
	if (*(defenition + ch - TWO) == '.'&&*(defenition + ch - ONE )== ' '){//first char in the sentence
		*(defenition + ch) = *(defenition + ch) - WORDSIZE;//A-a 32 chars in the ASKII code
	}
	repairDefenition(defenition, ch + ONE);//recurtion
}

void freeWord(char** word){
	/****************Function that free memory from heap for a word*****************/
	int i ;
	for (i = ZERO; *(word + i) != NULL; i++){//end of definitions
		free(*(word + i));
	}
	free(word);//free word
}

void freeAll(char*** milon){
	/*******************Function that free the memory of all the dictionary***********************/
	int i;
	for (i = ZERO; *(milon + i) != NULL;i++){//end of the dictionary
		freeWord(*(milon + i));//function that free the word array
	}
	free(milon);//free the dictionary
}
void arrInput(int* arr,int size){
	/********************Input into the array int numbers form 1 to size***************/
	int i;
	for (i = ZERO; i < size; i++){
		arr[i] = i + ONE;
	}
}

void swapMilon(void* milon, int first,int last, int typeSize){
	/**********************Void function for the switch of two words in the dictionary*************************************/
	int i,*p;
	swap((char***)milon + first, (char***)milon + last, typeSize);//swap the words
	for (i = ZERO; ((char***)milon)[i] != NULL;){
		i++;
	}
	p=((int*)(*((char***)milon + i + ONE)));
	swap(p + first, p + last, sizeof(int));	//swap the int in the order array
}
void swap(void* a, void* b, int typeSize){//void function for switching values for two pointers
	int i;
	char temp;
	char* first = (char*)a;
	char* second = (char*)b;
	for (i = ZERO; i < typeSize; i++){//size of char,char*,int......
		temp = *(first + i);
		*(first + i) = *(second + i);
		*(second + i) = temp;
	}
}

int compareWord(void*first, void*second){
	/***********************Void function that compare two words and return -1 if first smaller 1 if bigger and 0 if equel*******************/
	return strcmp(**(char***)first, **(char***)second);
}
int compareWordSearch(void *first, void *second){
	/***********************Void function that compare two words and return -1 if first smaller 1 if bigger and 0 if equel*******************/
	return strcmp(**(char***)first, (char*)second);
}
void fastsort(void* milon, int left, int right, int sizeOfType, int(*cmp)(void*, void*), void(*swap)(void*, int ,int,int)){
	/********************************Function that sort arrays from small to big cmp-is compare function,swap is switching function***********************************************/
	int i, last;
	if (left >= right)//end case
		return;
	switch (sizeOfType){//cases for diferent types for be switching pivot= (left+right)/2
	case SizeOfPointer_int:{(*swap)((int*)milon , left, ((left + right) / TWO), sizeOfType);
		break;
	}
	case SizeOfDouble:{(*swap)((double*)milon, left, ((left + right) / TWO), sizeOfType);
		break;
	}
	case SizeOfChar:{(*swap)((char*)milon, left, ((left + right) / TWO), sizeOfType);
		break;
	}
	default:{
		printf("Un known type,cannt sort");//if the type of the array isnt int char double or pointer
		return;
	}
	}
	last = left;
	for (i = left + ONE; i <= right; i++){
		switch (sizeOfType){
			/**************Cases for compare and switch***************/
		case SizeOfPointer_int:{
			if (ZERO > (*cmp)(((int*)milon) + i, ((int*)milon) + left)){
				(*swap)((int*)milon , ++last,  i, sizeOfType);
			}
			break;
		}
		case SizeOfDouble:{
			if (ZERO > (*cmp)(((double*)milon) + i, ((double*)milon) + left)){
				(*swap)((double*)milon, ++last, i, sizeOfType);
			}
			break;
		}
		case SizeOfChar:{
			if (ZERO > (*cmp)(((char*)milon) + i, ((char*)milon) + left)){
				(*swap)((char*)milon, ++last, i, sizeOfType);
			}
			break;
		}
		default:{
			printf("Un known type,cannt sort");
			return;
		}
		}
	}
	switch (sizeOfType){
		/****************Switch back the pivot************************/
	case SizeOfPointer_int:{(*swap)((int*)milon , left, last, sizeOfType);
		break;
	}
	case SizeOfDouble:{(*swap)((double*)milon, left, last, sizeOfType);
		break;
	}
	case SizeOfChar:{(*swap)((char*)milon, left, last, sizeOfType);
		break;
	}
	default:{
		printf("Un known type,cannt sort");
		return;
	}
	}
	fastsort(milon, left, last - ONE, sizeOfType,  (*cmp), (*swap));//1 left array
	fastsort(milon, last + ONE, right, sizeOfType, (*cmp), (*swap));//2 right array
}
int delit(char*** milon){
	/********************Function that free the usles words and realloc the memory for the arrays****************************/
	int left, right,minWord;
	int *p,i=ZERO;
	while (*(milon + i++) != NULL){//calc the words in the array
	}
	if ((i - ONE) == ONE){//retunr if there is only one word 
		return ONE;
	}
	p = (int*)(*(milon + i));//get the order array
	for (left = ZERO, right = ONE; (*(milon + right) != NULL); ){
		/***********************going from the start up to the end of the words***********************************/
		if (ZERO == compareWord(milon + left, milon + right)){//check if the next word is similar
			while ((*(milon + right) != NULL) && (ZERO == compareWord(milon + right, milon + left))){//continiu cheaking for the similar words
				right++;
			}
			minWord = firstWord(milon, left, (right - ONE));//find the first word that was insorted and get the index
			swapMilon(milon, left, minWord, sizeof(char***));//swap it to the first place in the seria
			delitSeria(milon, ++left, right, p);//delit all the similar words exept the one that is in the first place
			right = left;
		}
		if (*(milon + right) != NULL){//to cheack if that is already the end of the array
			left = right;//contionyu from last right
			right = right + ONE;//next word
		}
	}
	for (i = ZERO; *(milon + i) != NULL; i++);//cheack the size of the new array(evry thing that was not delited moved and all the places in the end are NULL
	milon=realloc(milon, sizeof(char**)*(i + ONE));//realoc the array +two = one for the NULL
	free(p);//free the memory of the order array
	return i;//return new size
}
int firstWord(char*** milon, int left, int right){
	/*****************Function that help to find the word from seria of same words that was inputed first*******************************************/
	int min, i=ZERO;
	int *p;
	while (*(milon + i++) != NULL){//calc the word size
	}
	p = (int*)(*(milon + i));//get the order array
	min =left;//get the first index
	for (left=left+ONE; left <= right; left++){//cheack if there is smaller
		if (*(p + left) <*(p+min)){
			min = left;//get the new index
		}
	}
	return min;//return index for the first inputed word
}
void delitSeria(char*** milon,int left,int right,int *p){
	/*************************Function that Free all the same words and moving rest of the array to left********************************/
	int first = left,last=right;
	while (*(milon + last) != NULL){
		arrayDefine(p, first++, last++);//moving ints in the order array
	}
	first = left;
	last = right;
	for (; *(milon + right-ONE) !=NULL; left++, right++){//runing on the rest of the array
		if (left < last){//last is the last same word
			freeWord(*(milon + left));//free word
		}
		*(milon + left) = *(milon + right);//move the next one to the frst one place until the end of 
	}
	last = left-ONE;
	*(milon + last) = NULL;//end of the word array
	*(milon + last + ONE) = (char**)p;//catch the order array
	for (left = last + TWO; *(milon+left) != (char**)p; left++){//set rest of array to null
		*(milon + left) = NULL;
	}
	*(milon + left) = NULL;//set the last place in the word array to NULL
}

void arrayDefine(int* p, int first, int second){
	/***********Copy integer from second place to first place*************/
	p[first] = p[second];
}

void* bSearch(void* milon,int start,int end,int sizeOfType, void* word,int(*cmp)(void*,void*)){
	/*******************Void function that find a val in the array and return his address,if the val isnt in the array return NULL**********************************/
	int pivot = (start + end) / TWO;//set pivot
	switch (sizeOfType){//stop cases
	case SizeOfPointer_int:{//fro int,pointers 
		if (ZERO == (*cmp)((int*)milon + pivot, word)){
			return (void*)(((int*)milon + pivot));
		}
		break;
	}
	case SizeOfDouble:{//for double
		if (ZERO == (*cmp)((double*)milon + pivot, (double*)word)){
			return (void*)(((int*)milon + pivot));
		}
		break;
	}
	case SizeOfChar:{//for char
		if (ZERO == (*cmp)((char*)milon + pivot, (char*)word)){
			return (void*)(((int*)milon + pivot));
		}
		break;
	}
	default:{
		printf("Un known type,cannt search!!!");
		return NULL;
	}
	}
	if (start == end){//if the word isn't n the array
		return NULL;
	}
	switch (sizeOfType){//cases for the recurton
	case SizeOfPointer_int:{
		if (ZERO < (*cmp)((int*)milon + pivot, (int*)word)){//if the word in the right side of the array for int ,int*.....
			return bSearch(milon, start, pivot, sizeOfType, word, (*cmp));
		}
		else//left side
			return  bSearch(milon, pivot+ONE, end, sizeOfType, word, (*cmp));
		break;
	}
	case SizeOfDouble:{//if the word in the right side of the array for double
		if (ZERO < (*cmp)((double*)milon + pivot, (double*)word)){
			return bSearch(milon, start, pivot , sizeOfType, word, (*cmp));
		}
		else//left side
			return  bSearch(milon, pivot+ONE, end, sizeOfType, word, (*cmp));
		break;
	}
	case SizeOfChar:{//if the word in the right side of the array for chars
		if (ZERO < (*cmp)((char*)milon + pivot, (char*)word)){
			return bSearch(milon, start, pivot, sizeOfType, word, (*cmp));
		}
		else//left side
			return  bSearch(milon, pivot+ONE, end, sizeOfType, word, (*cmp));
		break;
	}
	default:{
		printf("Un known type,cannt search!!!");
		return NULL;
	}
	}
}
int getch (void)
{
        int ch;
        struct termios oldt, newt;

        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON|ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return ch;
}
//END