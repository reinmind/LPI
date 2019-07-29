#include <cstdio>
#include <sys/stat.h>
#include <fcntl.h>
int 
main(int argc,char *argv[])
{	
	int inputFd, outputFd, openFlags;
	inputFd = open(argv[1],O_WRONLY);
	write(inputFd,argv[2],20);
	close(inputFd);	
	return 0;
}
