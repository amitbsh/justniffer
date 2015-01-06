#include "protocol.h"

#include <errno.h>
#include "utilities.h"

static int write_to_fd(int fd, const double d) {
	if (write(fd, &d, sizeof(double)) == -1)
		return errno;
	return 0;
}

int write_to_fd(int fd, const string& str) {
	int length = str.length() + 1;
	if (write(fd, &length, sizeof(int)) == -1)
		return errno;
	if (write(fd, str.c_str(), length) == -1)
		return errno;
	return 0;
}

int write_to_fd(int fd, timeval t) {
	//not implemented
	/*
	 * use timestamp(t, fmt)
	 * or
	 * to_double(t)
	 */
	return 0;
}

int write_to_fd(int fd, void *p, unsigned long size) {
	if (write(fd, p, size) == -1)
		return errno;
	return 0;
}




