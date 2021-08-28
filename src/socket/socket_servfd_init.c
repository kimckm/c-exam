/*
 * 函数原型
 * int socket(int family, int type, int protocol);
 *
 * family 指明协议族；
 * type 指明套接字类型；
 * protocol 应设为协议类型常值。或者设为 0, 以选择所给定的family和type组合的系统默认值。
 */
#include <sys/socket.h>
#include <netinet/in.h>

/* 初始化 Socket  */
int socket_servfd_init(int port)
{
	int servfd;
	struct sockaddr_in servaddr;

	// AF_INET IPv4协议
	// SOCK_STREAM 字节流套接字
	servfd = socket(AF_INET, SOCK_STREAM, 0);

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);

	// bind函数把一个本地协议地址赋予一个套接字。
	bind(servfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	// 把主动套接字转换为被动套接字，并指明内核应该为相应套接字排队的最大连接个数。
	listen(servfd, 10);

	return servfd;
}
