#include <stdio.h>
#include <stdlib.h>

int	m;

void p(char *ptr)
{
	printf(ptr);
}

void n()
{
	char buf[512];

	fgets(buf, 512, stdin);
	p(buf);
	if (m == 16930116)
	{
		system("/bin/cat /home/user/level5/.pass");
	}
}

int	main(void)
{
	n();
}
