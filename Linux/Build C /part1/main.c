#include "helper.h"
#include <stdio.h>

int main()
{
	float a,b,c;
	char ans[40];

	printf("Enter num for a: ");
	while (scanf("%f", &a) != 1)
	{
		clean_buffer();
		printf("a must be a number!\n");
		printf("Enter num for a: ");
	}
	clean_buffer();
	printf("Enter num for b: ");
	while (scanf("%f", &b) != 1 )
	{
		clean_buffer();
		printf("b must be a number!\n");
		printf("Enter num for b: ");
	}
	clean_buffer();
	printf("Enter num for c: ");
	while (scanf("%f", &c) != 1)
	{
		clean_buffer();
		printf("c must be a number!\n");
		printf("Enter num for c: ");
	}
	clean_buffer();

	solveQuadEq(a,b,c,ans);
	
	#ifdef VERBOSE_LOGGING
	logging(ans);
	#else
	printf("%s",ans);
	#endif
	
}
