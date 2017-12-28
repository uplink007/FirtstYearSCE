//queue.cpp
#include "MyQueue.h"

	//constructor
	MyQueue::MyQueue(int size){

    	qsize = size;
		front = nullptr;
		rear = nullptr;
		count=0;
		pthread_mutex_init(&queueMutex,NULL);
		pthread_cond_init(&queueCond, NULL);
    }
    //destructor                                
    MyQueue::~MyQueue(){
		Node * temp;						// create temporary address store
		while(front != (void *) 0)			// while the queue is not empty
		{
			temp = front;
			front = front->next;			// advance the front object to the next
			delete temp;					// delete the temporary data
		}
		pthread_mutex_destroy(&queueMutex);
    }
    //check if queue is empty
    bool MyQueue::isempty(){
		pthread_mutex_lock(&queueMutex);
		bool ans= count == 0;
		pthread_mutex_unlock(&queueMutex);
		return ans;
    }
    //check if queue is full
    bool MyQueue::isfull() {
		pthread_mutex_lock(&queueMutex);
		bool ans;
		if(qsize!=UNLIMITED)
			ans=count == qsize;
		else{
			ans=false;
		}
		pthread_mutex_unlock(&queueMutex);
		return ans;
    } 
    //return number of entries in queue 
    int MyQueue::getAmount(){
    	pthread_mutex_lock(&queueMutex);
		int ans=count;
		pthread_mutex_unlock(&queueMutex);
		return ans;
    } 
    //add entry to queue                           
    bool MyQueue::enqueue(void *t){
		pthread_mutex_lock(&queueMutex);
		if(count == qsize)	
		{					// if queue is full halt queuing
			return false;
		}

		Node * add = new Node;				// create node
		add->item = t;					// set node pointers
		add->next = nullptr;				// or nullptr;
		count++;
		if (front == nullptr)			// if queue is empty,
			front = add;					// place item at front
		else
			rear->next = add;				// else place at rear
		rear = add;							// have rear point to new node
		pthread_cond_signal(&queueCond);
		pthread_mutex_unlock(&queueMutex);
		return true;
    } 
    //return the entry in the front of the queue and remove it from the queue
    void* MyQueue::dequeue(){
    	pthread_mutex_lock(&queueMutex);
		 while (count == 0) {
	        pthread_cond_wait(&queueCond, &queueMutex);
	     }

		if(front == nullptr)				// front node is empty, queue is empty
		{
			return NULL;
		}
		void* ans =front->item;
							
		count--;							// decrement item count
		front = front->next; 				// reset front to next item   0x7ffff654b700

		if (count == 0)						// if the queue is now empty set rear to point to nothing
			rear = nullptr;
		pthread_mutex_unlock(&queueMutex);

		return ans;
    }
