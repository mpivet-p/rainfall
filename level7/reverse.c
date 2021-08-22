#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *c;	//0x08049960

void	m(void) //0x80484f4
{
	printf("%s -%d\n", c, (int)time(0));
}

struct exploit {
	int one;
	char *ptr;
};

int		main(int argc, char **argv)
{
	struct exploit *a;
	struct exploit *b;

	a = malloc(8);					//0x0804a008
	a->one = 1;
	a->ptr = malloc(8);				//0x0804a018

	b = malloc(8);					//0x0804a028
	b->one = 2;
	b->ptr = malloc(8);				//0x0804a038

	strcpy(a->ptr, argv[1]);		//0x0804a018
	strcpy(b->ptr, argv[2]);		//0x0804a038
	fgets(c, 68, fopen("/home/user/level8/.pass", "r"));
	puts("~~"); // makes jmp to 0x08049928
}
