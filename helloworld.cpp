#include <iostream>
#include <cstdio>
int main(){
	FILE* f = fopen("hello.txt","w+");
	const char* something_to_say = "HelloWorld!";
	fwrite(something_to_say,sizeof(char),20,f);
	fclose(f);
	return 0;
}
