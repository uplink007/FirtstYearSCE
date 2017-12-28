#ifndef TaskReslover_H
#define TaskReslover_H

#include <fstream>
#include "SharedMemory.h"
#include "Task.h"
#include "Request.h"
#include "TaskDumper.h"

extern "C" {
    #include "util.h"
}
using namespace std;
class TaskResolver:public Task{
	Request * temp;
public:
	TaskResolver(Request* _request):temp(_request){
		}
	~TaskResolver(){}
	void run(void*);
	int whoami(){return 1;}
};

#endif