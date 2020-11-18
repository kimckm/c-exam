#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	printf("PATH=%s\n", getenv("PATH"));
	return 0;
}
