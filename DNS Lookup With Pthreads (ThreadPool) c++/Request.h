#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

class Request
{
public:
	string domainName;
	char** ipArr;
	int ipArrSize;
};

#endif 