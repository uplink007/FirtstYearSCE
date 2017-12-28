/*
Fifth homework in the operating systems curse
Athor 1: Sergey Shevchuck 
ID: 321274524
Athor 2: Yoel Dgani 
ID: 301071064
*/


#include "TaskRequester.h"
#include "TaskResolver.h"
#include "TaskDumper.h"
#include "ThreadPool.h"
#include "SharedMemory.h"


extern "C" {
    #include "util.h"
}


using namespace std;



int main(int argc,char* argv[]){
	SharedMemory::requests=argc-2;
	SharedMemory::domainCondInit();
	ifstream myFile(argv[argc-1]); //checks that the output file exist before executing.
	if(myFile.fail())
	{
		string s(argv[argc-1]);
    	string tmp="output file "+s+" was not found!\n";
    	const char* fml=tmp.c_str();
    	fputs(fml, stderr);
    	return 1;
	}
	SharedMemory::output=argv[argc-1];
	for (int i = 1; i < argc-1; ++i)
	{
		ifstream myFile(argv[i]); //checks that all input files exist before executing.
		if(myFile.fail()){//bad file name
			
			SharedMemory::requests--;
        	string s(argv[i]);
        	string tmp="input file "+s+" was not found!\n";
        	const char* fml=tmp.c_str();
        	fputs(fml, stderr);
    	}		
		else{//the file exist
				SharedMemory::fileQ.enqueue(new TaskRequester(argv[i]));
			}
	}

	ThreadPool Requester(&SharedMemory::fileQ);
	ThreadPool Resolver(&SharedMemory::domainQ);
	ThreadPool Dumper(&SharedMemory::ipArrQ);
	Requester.threadPoolCreate();
	Resolver.threadPoolCreate();
	Dumper.threadPoolCreate();
	Requester.threadPoolJoin();
	Resolver.threadPoolJoin();
	Dumper.threadPoolJoin();

	

return 0;
}