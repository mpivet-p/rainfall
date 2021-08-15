int     main(int argc, char **argv, char **envp)
{
	uid_t	uid;
	gid_t	gid;

    if (atoi(argv[1]) == 423)
    {
        ptr = strdup("/bin/sh");
        gid = getegid();
        uid = geteuid();
        setresgid(gid);
        setresuid(uid);
		execv(ptr, "/bin/sh");
    }
    else
    {
        write(1, "No !\n", 5);
    }
    return (0)
}
