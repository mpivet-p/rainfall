#include <stdio.h>
#include <stdlib.h>

int	m = 0;

void	v(void)
{
	char	buf[512];
	char	*ptr;

	ptr = fgets(buf, 512, stdin);
	printf(ptr);
	if (m == 64)
	{
		fwrite("Wait what?!\n", 1, 13, stdout);
		system("/bin/sh");
	}
}

int		main(void)
{
	v();
}
