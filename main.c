#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	/* code */
	int count = 0, err;
	const char* buf = "hello";
	const char* datafile = "test.data";

	int fd = open(datafile, O_CREATE|O_RDWR, S_IRUSR|S_IWUSR);

	if (fd != -1)
	{
		count = write(fd, buf, strlen(buf));
	}

	close(fd);

	printf("%d char has been written to file :%s \n", count, datafile);

	return 0;
}