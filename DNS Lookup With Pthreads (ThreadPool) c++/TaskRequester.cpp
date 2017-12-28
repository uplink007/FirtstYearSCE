#include "TaskRequester.h"

void TaskRequester::run(void*){

		int domSize =0; //counter for domains from this specific file that havent been proccesssed yet.
		ifstream file(filename.c_str());
		if(file.is_open()){
			string line;
			while ( getline (file,line) )
		    {
		    
		    	Request *temp=new Request();
		    	temp->domainName=line;
		        temp->ipArr=NULL;
		        temp->ipArrSize=0;
		        
		        while(SharedMemory::domainQ.isfull()){
		        	
		        	usleep((rand()%100)*100);
		        }
		   		SharedMemory::domainQ.enqueue(new TaskResolver(temp));
		   		pthread_mutex_lock(&SharedMemory::domainsMutex);
		   	
		   		SharedMemory::domains++;
		   		domSize++; 
		   		pthread_mutex_unlock(&SharedMemory::domainsMutex);
			}
			file.close();	
		}else{
			cerr<<"file:"<<filename<<" cann't be opend"<<endl;
		}
		pthread_mutex_lock(&SharedMemory::domainsMutex);
		//if a signal from the resolver is lost, and the domSize>0, but there are no domains in the domain queue the file is considered finished.
		//
		while(SharedMemory::domains && domSize){//wait for all domains to compleat to go for next task
			pthread_cond_wait(&SharedMemory::domainsCond, &SharedMemory::domainsMutex);
			domSize--;
		}
		pthread_mutex_unlock(&SharedMemory::domainsMutex);
		pthread_mutex_lock(&SharedMemory::requestMutex);
		SharedMemory::requests--;
		pthread_mutex_unlock(&SharedMemory::requestMutex);

}