#include <sys/select.h>
#include <sys/time.h>

int select(int maxfdp1,
	       fd_set *readset,
		   fd_set *writeset,
		   fd_set *exceptset,
           const struct timeval *timeout);
