#include "TaskResolver.h"

void TaskResolver::run(void*){

				int size = 0;
				char **arr = (char**)malloc(255*sizeof(char*)); 
	      		if(dnslookupAll(temp->domainName.c_str(), arr, 255, &size)== UTIL_FAILURE){
		  			fprintf(stderr, "faild to get dns for: %s\n", temp->domainName.c_str());
	   	   		}else{
	   	   			temp->ipArr=arr;
	   	   			temp->ipArrSize=size;
	   	  		}
	   	  		pthread_mutex_lock(&SharedMemory::domainsMutex);
	   	  		SharedMemory::domains--;
	   	  		pthread_cond_signal(&SharedMemory::domainsCond);
	   	  		cout<<temp->domainName<<",";
	   	  		for (int i = 0; i < (temp->ipArrSize=size); ++i)
	   	  		{
	   	  			if(i<(temp->ipArrSize)-1)
	   	  				cout<<temp->ipArr[i]<<",";
	   	  			else
	   	  				cout<<temp->ipArr[i];
	   	  		}
	   	  		cout<<endl;
	   	  		pthread_mutex_unlock(&SharedMemory::domainsMutex);
	   	  		SharedMemory::ipArrQ.enqueue(new TaskDumper(temp));

	}