#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <string.h>

#define MAX_EVENTS 500

int main(int argc, char const *argv[]) {
    int sockfd, connfd, epollfd;
	struct epoll_event event;
    struct epoll_event event_list[MAX_EVENTS];
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_len;
	char recvline[4096 + 1];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(61227);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	listen(sockfd, 5);

	epollfd = epoll_create(1024);

	event.events = EPOLLIN | EPOLLET;
	event.data.fd = sockfd;
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event) < 0) {
	    printf("epoll add fail : fd = %d\n", sockfd);
		return -1;
	}

    while(1) {
	    int nfds = epoll_wait(epollfd, event_list, MAX_EVENTS, 3000);
		printf("nfds=%d\n", nfds);
		for (int i = 0; i < nfds; i++) {
		    if (event_list[i].data.fd == sockfd) {
			    connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
				if (connfd < 0) {
				    perror("connfd < 0");
					return -1;
				}
				event.events = EPOLLIN | EPOLLET;
				event.data.fd = connfd;
				epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &event);
			} else if (event_list[i].events & EPOLLRDHUP) {
				printf("EPOLLRDHUP");
			} else if (event_list[i].events & EPOLLIN) {
			    int len = read(event_list[i].data.fd, recvline, 4096);
				if (len > 0) {
					char *strp = malloc(len);
					memcpy(strp, recvline, len);
					printf("len=%d, recv=%s\n", len, strp);
				}

			}
		}
	}

	return 0;
}
