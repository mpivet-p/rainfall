#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	n()
{
	system("/bin/cat /home/user/level7/.pass");
}

void	m()
{
	puts("Nope");
}

int		main(int argc, char **argv)
{
	char	*ptr;
	char	*a;
	void	*func;

	a = malloc(64);
	func = malloc(4);
	//set func to m()
	ptr = argv[1];
	ptr += 4;
	strcpy(a, ptr);
	//call func();
}
