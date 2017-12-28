//queue.h
#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include "unistd.h"
#include "pthread.h"
using namespace std;
#define MAX_SIZE_OF_QUEUE 20
#define UNLIMITED -1

//TODO: thread safe mutexs
class MyQueue
{
private:
    struct Node {  //an entry in the queue.
        void *item;
        struct Node * next;
    };
    
    Node * front;                                               // pointer to front of Queue
    Node * rear;                                                // pointer to rear of Queue
    int count;                                                  // current number of items in Queue
    int qsize;                                            // maximum number of items in Queue
    pthread_mutex_t queueMutex;                             //queue mutex
   pthread_cond_t  queueCond;                               //condition for count=0. 
   

public:

    MyQueue(int size=MAX_SIZE_OF_QUEUE);
    ~MyQueue();
    bool isempty();
    bool isfull();
    int getAmount();
    bool enqueue(void *t);
    void* dequeue();
};

#endif /* MyQUEUE_H_ */

