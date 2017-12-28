#ifndef THREADPOOL_H
#define THREADPOOL_H
#include "MyQueue.h"
#define MAX_RESOLVER_THREADS 10
#define MIN_RESOLVER_THREADS 10

class ThreadPool
{
private:
	MyQueue* queue;
	pthread_t* threadPool;
	int size;
public:
	ThreadPool(MyQueue* queueForThreads);
	~ThreadPool();
	void threadPoolCreate();
	void threadPoolJoin();

	static void *run(void*);
	
};
#endif