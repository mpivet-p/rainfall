#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int       main(int argc, char **argv)
{
	char buf[66]; //esp+0x18 to esp+0x59
	char buf2[65]; //esp+0x42
	FILE *f_ptr; //esp+0x9c

	f_ptr = fopen("/home/user/end/.pass", "r");
	bzero(buf, 33);
	if (f_ptr != NULL && argv == 2)
	{
		fread(buf, 1, 66, f_ptr);
		buf[65] = 0;
		buf[atoi(argv[1])] = 0;
		fread(buf2, 1, 65, f_ptr);
		fclose(f_ptr);
		if (strcmp(buf, argv[1]) == 0)
		{
			execl("/bin/sh", "sh", NULL);
		}
		else
		{
			puts(buf + 66);
		}
	}
	else
	{
		return (-1);
	}
	return (0);
}
