#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <string>

using namespace std;

int write_to_fd(int fd, const string& str);
int write_to_fd(int fd, timeval t);
int write_to_fd(int fd, void *p, unsigned long size);

#endif /* _PROTOCOL_H_ */
