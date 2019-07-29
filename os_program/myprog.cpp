#include <gnu/libc-version.h>
#include <iostream>
int main(){
	std::cout << gnu_get_libc_version() << std::endl;
	return 0;
}
