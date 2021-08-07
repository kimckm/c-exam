#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
	// 为了执行网络I/O，一个进程必须做的第一件事情就是调用socket函数，指定期望的通信协议类型。
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("sockfd=%d\n", sockfd);
	return 0;
}
