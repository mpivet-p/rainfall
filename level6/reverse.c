#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef void(*func)(void);

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
	char	*arg_ptr;
	char	*a;
	func	*func_ptr;

	a = malloc(64);
	func_ptr = malloc(4);
	*func_ptr = (void*)m;
	arg_ptr = argv[1];
	arg_ptr += 4;
	strcpy(a, arg_ptr);
	(**func_ptr)();
}
