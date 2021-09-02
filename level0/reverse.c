#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int     main(int argc, char **argv)
{
	uid_t	uid;
	gid_t	gid;
	char	*ptr;

    if (atoi(argv[1]) == 423)
    {
        ptr = strdup("/bin/sh");
        gid = getegid();
        uid = geteuid();
        setresgid(gid);
        setresuid(uid);
		execv("/bin/sh", &ptr);
    }
    else
    {
        write(1, "No !\n", 5);
    }
    return (0);
}
