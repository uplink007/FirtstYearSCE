#ifndef TaskRequester_H
#define TaskRequester_H

#include <fstream>
#include "SharedMemory.h"
#include "Task.h"
#include "Request.h"
#include "TaskResolver.h"



class TaskRequester:public Task{
string filename;
	public:
		TaskRequester(string _filename):filename(_filename){
		}
		~TaskRequester(){}
		void run(void*);
		int whoami(){return 0;}
};

#endif