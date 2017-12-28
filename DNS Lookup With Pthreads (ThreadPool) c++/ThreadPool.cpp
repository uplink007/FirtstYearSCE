#include "ThreadPool.h"
#include "SharedMemory.h"
#include "Task.h"


void* ThreadPool::run(void* queue){ 
	bool finsh=true;
	//int a=0;
	while(finsh||!(SharedMemory::ipArrQ.isempty())){
		pthread_mutex_lock(&SharedMemory::requestMutex);
		//cout<<"TaskResolver lock requestMutex\n";
		//cout<<SharedMemory::requests<<endl;
		if(SharedMemory::requests==0){
			finsh=false;
		}
		//cout<<"TaskResolver unlock requestMutex\n";
		pthread_mutex_unlock(&SharedMemory::requestMutex);
	//	cout<<!((MyQueue*)queue)->isempty()<<":"<<a++<<endl;
		if(!((MyQueue*)queue)->isempty()){
			Task* t=(Task*)((MyQueue*)queue)->dequeue();
			
			t->run(NULL);
			delete t;
		}else{
			usleep((rand()%100)*10000);
		}
	}
	return NULL;
}

	ThreadPool::ThreadPool(MyQueue* queueForThreads):queue(queueForThreads){
		size=MAX_RESOLVER_THREADS;
		threadPool=(pthread_t*)malloc(sizeof(pthread_t)*size);
	}
	ThreadPool::~ThreadPool(){
		if(threadPool){
			free(threadPool);
		}

	}
	void ThreadPool::threadPoolCreate(){
			for (int i = 0; i < size; ++i)
	{
		pthread_create(&threadPool[i], NULL, ThreadPool::run,queue);
	}


	}
	void ThreadPool::threadPoolJoin(){
		for (int i = 0; i < size; ++i)
		{
			pthread_join(threadPool[i], NULL);
		}
	}