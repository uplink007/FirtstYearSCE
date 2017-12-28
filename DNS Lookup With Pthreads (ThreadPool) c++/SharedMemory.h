#ifndef  SHAREDMEMORY_H
#define SHAREDMEMORY_H 
#include "MyQueue.h"
#include <string>
class SharedMemory{
private:
	SharedMemory(){}
public:
	static MyQueue fileQ; //holds file names
	static MyQueue domainQ; // holds domain names, recieved from the requester task.
	static MyQueue ipArrQ; // holds domain names and array of ips related to them, recieved from the resolver task.
	static char* output;
	static pthread_mutex_t outputFileMutex;
	static int requests;// number of files thats aren't completely proccessed yet. 
	static pthread_mutex_t requestMutex; //locks the requests variable.
	static int domains; // number of domains in the domain queue.
	static pthread_mutex_t domainsMutex; //locks the domains variable.
	static pthread_cond_t domainsCond; // used to send signal that a specific domain was proccessed.
	static void domainCondInit(); 
};
#endif