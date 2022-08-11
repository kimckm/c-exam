#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	int sockfd, n;
	char recvline[4096 + 1];
	struct sockaddr_in servaddr;

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(61227);

	// 创建一个网际字节流套接字
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket error\n");
		return 1;
	}

	const char * addr = "127.0.0.1";

	if (inet_pton(AF_INET, addr, &servaddr.sin_addr) <= 0) {
		printf("地址格式有误 [%s]\n", addr);
		return 1;
	}

	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		printf("connect error\n");
	}

	const char * str = "hello";
	write(sockfd, str, strlen(str));
	sleep(5);

	const char * str2 = "abc";
	write(sockfd, str2, strlen(str2));
	sleep(5);

	close(sockfd);
	return 0;
}
