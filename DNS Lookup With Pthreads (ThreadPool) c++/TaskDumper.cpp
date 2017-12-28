#include "TaskDumper.h"


void TaskDumper::run(void*){
				pthread_mutex_lock(&SharedMemory::outputFileMutex);
				
				ofstream myfile; 
	      		myfile.open (SharedMemory::output,ios_base::app);

		   			
		   			string toPrint=temp->domainName;
		   			if(!temp->ipArrSize){
		   				toPrint=toPrint+',';
		   			}
		   			for (int i = 0; i < temp->ipArrSize; ++i)
		   			{
		   				toPrint =toPrint+", "+temp->ipArr[i];
		   			}
		   			toPrint=toPrint+"\n";
		   			myfile << toPrint;

	   			 myfile.close();
	   			 delete temp;
	   			 pthread_mutex_unlock(&SharedMemory::outputFileMutex);

	}