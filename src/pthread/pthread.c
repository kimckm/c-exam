#include <pthread.h>
#include <stdio.h>

void *myf(void *args) {
        printf("myf = %d\n", pthread_self());
		printf("args = %s\n", args);
        sleep(3);
        pthread_exit("Thank you for the CPU time.");
}

int main(int argc, char *argv[]) {
        printf("pid = %ld\n", pthread_self());

        pthread_t tid;

        char message[] = "Hello Thread!";

        int rs = pthread_create(&tid, NULL, myf, (void *) message);
	pthread_join(tid, NULL);
        printf("pthread_create_rs = %d\n", rs);
}
