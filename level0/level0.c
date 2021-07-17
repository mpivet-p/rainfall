int     main(int argc, char **argv, char **envp)
{
    if (atoi(argv[1]) != 423)
    {
        ptr = strdup("/bin/sh");
        getegid();
        geteuid();
        setresgid();
        setresuid();
        return (execve(ptr));
    }
    else
    {
        write(1, "No !\n", 5);
    }
    return (0)
}
