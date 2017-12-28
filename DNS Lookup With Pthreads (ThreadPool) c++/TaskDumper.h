#ifndef TaskDumper_H
#define TaskDumper_H

#include <fstream>
#include "SharedMemory.h"
#include "Task.h"
#include "Request.h"

extern "C" {
    #include "util.h"
}
using namespace std;
class TaskDumper:public Task{
private:
	Request *temp;
public:
	TaskDumper(Request* _temp):temp(_temp){}
	 ~TaskDumper(){}
	void run(void*);
	int whoami(){return 3;}
};

#endif