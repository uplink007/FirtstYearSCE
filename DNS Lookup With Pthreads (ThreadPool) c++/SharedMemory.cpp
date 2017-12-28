#include "SharedMemory.h"
#define UNLIMITED -1
 MyQueue SharedMemory::fileQ;
 MyQueue SharedMemory::domainQ(UNLIMITED);
 MyQueue SharedMemory::ipArrQ(UNLIMITED);
 char* SharedMemory::output=NULL;
int SharedMemory::domains=0;
int SharedMemory::requests=0;
pthread_cond_t SharedMemory::domainsCond;
pthread_mutex_t SharedMemory::requestMutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t SharedMemory::domainsMutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t SharedMemory::outputFileMutex=PTHREAD_MUTEX_INITIALIZER;
// initialises the domainscond variable.
void SharedMemory::domainCondInit()
{
	pthread_cond_init(&SharedMemory::domainsCond, NULL);
}
