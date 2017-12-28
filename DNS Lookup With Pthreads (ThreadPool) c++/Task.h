#ifndef Task_H
#define Task_H

#include <string>

class Task{
public:
	Task(){}
	virtual ~Task(){}
	virtual void run(void*)=0;
	virtual int whoami()=0;
};

#endif