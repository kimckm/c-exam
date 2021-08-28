#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[]) {
	// 获取环境变量
	printf ("PATH\t= %s\n", getenv ("PATH"));
	printf ("LANG\t= %s\n", getenv ("LANG"));
	return 0;
}
