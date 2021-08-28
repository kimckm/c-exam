#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(int argc, char const *argv[]) {
	char *str = "hello world.";
	unsigned int i = 0;
	char *c = "bkk陈";

	printf("int_max = %u\n", UINT_MAX);
	printf("int s \t= %lu\n", sizeof(int));
	printf("long s \t= %lu\n", sizeof(long));
	printf("size \t= %lu\n", sizeof(str));
	printf("len \t= %lu\n", strlen(str));
	printf("char \t= %s\n", c);
	printf("s len \t= %lu\n", strlen(c));

	return 0;
}
