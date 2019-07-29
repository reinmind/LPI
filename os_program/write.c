#include <sys/stat.h>
#include <fcntl.h>
int write(int,char *,int);
int close(int);
int main(int argc,char * argv[]){
	int fd;
	fd = open("data",O_WRONLY);
	write(fd,"Hello,raspberry pi!\n",20);
	close(fd);
	return 0;
}
