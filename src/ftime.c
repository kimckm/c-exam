#include <stdio.h>
#include <time.h>
#include <string.h>

/**
 * snprintf()，函数原型为int snprintf(char *str, size_t size, const char *format, ...)。
 * 将可变参数 “…” 按照format的格式格式化为字符串，然后再将其拷贝至str中。
 * 函数原型：int snprintf(char* dest_str,size_t size,const char* format,...);
 */
int main(int argc, char const *argv[]) {
	time_t rawtime;
	struct tm *timeinfo;
	char buff[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime (buff, sizeof(buff), "%Y/%m/%d %H:%M:%S", timeinfo);

	printf("%s\n", buff);
	return 0;
}
