#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *auth;		// 0x8049aac
char *service;	// 0x8049ab0

int		main(void)
{
	char buf[128];

	for (;;)
	{
		printf("%p, %p \n", auth, service);
		if (fgets(buf, 128, stdin) == NULL)
			break ;
		if (strncmp("auth ", buf, 5) == 0)
		{
			auth = malloc(4);	
			strcpy(auth, buf);
		}
		if (strncmp("reset", buf, 5) == 0)		//0x804881f
		{
			free(auth);
		}
		if (strncmp("service", buf, 6) == 0)	//0x8048825
		{
			service = strdup(buf + 7);
		}
		if (strncmp("login", buf, 7) == 0 && auth[32] != 0)		//0x804882d
		{
			system("/bin/sh");					//0x8048833
		}
	}
	fwrite("Password:\n", 1, 10, stdout);
}
