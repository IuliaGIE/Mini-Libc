// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *ptr)
{
	/* TODO: Implement open system call. */
	int ret = syscall(__NR_write, 1, ptr, strlen(ptr) + 1);
	ret = syscall(__NR_write, 1, "\n", 1);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
