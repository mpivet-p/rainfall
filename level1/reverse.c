void	run(void)
{
	fwrite("Good... Wait what?", 1, 13, stdout);
	system("/bin/sh");
}

int		main(void)
{
	char *buf[64];	

	return (gets(&buf));
}
