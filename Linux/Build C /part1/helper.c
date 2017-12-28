#include "helper.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>

void solveQuadEq(float a, float b, float c, char *ans)
{
	double ans1, ans2;
	double tmp;
	
	tmp= pow(b,2)-(4*a*c);
	
	if(tmp<0)
	{	
		sprintf(ans, "No such X\n");
		return;
	}
	
	if(a!=0)
	{
		ans1= ((0-b) + sqrt(tmp)) / 2*a ;
		ans2= ((0-b) - sqrt(tmp)) / 2*a ;
		if (ans1 != ans2)
		{	
			sprintf(ans, "Ans 1: %.2lf\nAns 2: %.2lf\n", ans1, ans2);
			return;
		}
	}
	
	else if(b!=0)
		ans1= (0-c) / b ;
		
	else
		ans1= (0-c) ;
		
	sprintf(ans, "Ans: %.2lf\n", ans1);
	return;
}

void logging(char* msg)
{
	pid_t pid = getpid();
	pid_t ppid = getppid();
	uid_t uid = getuid();
	gid_t gid = getgid();

	printf("VERBOSE mode is enabled!\n");
	printf("pid = %d\n",pid);
	printf("ppid = %d\n",ppid);
	printf("uid = %d\n",uid);
	printf("gid = %d\n",gid);

	printf("Program output:\n%s", msg);
}

void clean_buffer()
{
	while((getchar())!='\n');
}