#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        char *resstr = "HTTP/1.1 200 OK\n"
                "Content-Type: application/json\n"
                "Content-Length: %d\n"
                "\r\n"
                "%s\n";

        char *body = "{\"ok\":1}";

        printf(resstr, strlen(body), body);
        return EXIT_SUCCESS;
}
