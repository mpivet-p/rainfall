char	*p(void)
{
	char	buf[80] //stack frame size is 0x68 (104)
	int		ret;

	fflush(stdout);
	gets(&buf)
	if (buf[80] & 0xb0000000)
	{
		printf(buf);
		exit(1);
	}
	puts(buf);
	return(strdup(buf));
}

int		main(void)
{
	return ((int)p());
}
