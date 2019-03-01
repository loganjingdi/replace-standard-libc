#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>

#define LIBC_PATH "/lib/libc.so.6.1"

ssize_t write(int fd, const void* buf, ssize_t count)
{
	void *hook_handle;
	int result;
	ssize_t (*write)(int, const void*, ssize_t);

	dlerror();
	/* open the standard libc.so.6.1  and in RTLD_LAZY(RTLD_NOW is also provided) */
	hook_handle = dlopen(LIBC_PATH, RTLD_LAZY);

	assert( hook_handle != NULL);


	printf("----------hello from jdliu-------------\n");

	result = write(fd, buf ,count);

	dlclose(hook_handle);

	return result ;
}