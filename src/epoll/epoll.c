#include <stdio.h>
#include <sys/epoll.h>

int main(int argc, char const *argv[]) {
	printf("%s\n", "epoll");
	int epollfd;
	epollfd = epoll_create(1024);
	printf("%d\n", epollfd);

	return 0;
}
