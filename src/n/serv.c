#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int servfd_init()
{
        int servfd;
        struct sockaddr_in servaddr;

        servfd = socket(AF_INET, SOCK_STREAM, 0);

        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        servaddr.sin_port = htons(61227);

        bind(servfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
        listen(servfd, 10);

        return servfd;
}

void res_init(char *res) 
{
        char *resstr = "HTTP/1.1 200 OK\n"
                "Content-Type: application/json\n"
                "Content-Length: %d\n"
                "\r\n"
                "%s\n";

        char *body = "{\"ok\":1}";

        sprintf(res, resstr, strlen(body), body);
}

int main(int argc, char const *argv[]) 
{
        int servfd, connfd;
        struct sockaddr_in cliaddr;
        socklen_t len;

        servfd = servfd_init();
        len = sizeof(cliaddr);

        char res[4096];
        int reslen;

        res_init(res);
        reslen = strlen(res);

        for ( ; ; ) {
                connfd = accept(servfd, (struct sockaddr *) &cliaddr, &len);
                write(connfd, res, reslen);
                close(connfd);
        }

        close(servfd);
        return EXIT_SUCCESS;
}
