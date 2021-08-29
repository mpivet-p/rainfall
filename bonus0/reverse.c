#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	p(char *a, char *ask)
{
	char buf[4096];

	puts(ask);
	read(0, buf, 4096);
	*strchr(buf, '\n') = 0;
	strncpy(a, buf, 20);
}

void	pp(char *buf)
{
	char buf_a[20];	// 0xbffffb78
	char buf_b[20]; // 0xbffffb8c

	p(buf_a, " - ");
	p(buf_b, " - ");
	strcpy(buf, buf_a);
	strcpy(buf + strlen(buf), " ");
	strcat(buf, buf_b);
}

int		main(void)
{
	char buf[42];

	pp(buf);
	puts(buf);
	return (0);
}
