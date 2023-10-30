#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int ret = syscall(__NR_nanosleep, req, rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
