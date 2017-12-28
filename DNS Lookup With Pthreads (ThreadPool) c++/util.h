#ifndef UTIL_H
#define UTIL_H

/* Define the following to enable debug statments */
//#define UTIL_DEBUG 0

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define UTIL_FAILURE -1
#define UTIL_SUCCESS 0

/* Fuction to return the first IP address found
 * for hostname. IP address returned as string
 * firstIPstr of size maxsize
 */
int dnslookup(const char* hostname,
	      char* firstIPstr,
	      int maxSize);

/* Looks up all the IP addresses and returns them in an array of Char*
 */
int dnslookupAll(const char* hostname,
	      char** ipArray,
	      int maxAddresses, 
	      int* addressCount);

#endif
