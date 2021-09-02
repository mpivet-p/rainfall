#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*p(void)
{
	char	buf[64]; //stack frame size is 0x68 (104)
	int		ret;

	fflush(stdout);
	gets(buf);
	if ((buf[80] & 0xB0000000) == 0xB0000000)
	{
		printf(buf);
		exit(1);
	}
	puts(buf);
	return(strdup(buf));
}

int		main(void)
{
	p();
}
