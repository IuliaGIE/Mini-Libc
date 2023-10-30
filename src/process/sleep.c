#include <sys/stat.h>
#include <internal/types.h>
#include <unistd.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;

    // initializez timpul pt sleep
    req.tv_sec = seconds;

    // ciclez pana cand se duce timpul
    while (nanosleep(&req, &rem) == -1 && errno == EINTR) {
        req = rem;
    }

    return rem.tv_sec;
}
