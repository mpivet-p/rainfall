int		main(void)
{
	char	buf[36];
	int		nbr;

	if ((nbr = atoi(argv[1])) <= 9)
	{
		return (1);
	}
	memcpy(buf, argv[2], nbr * 4);
	if (nbr != 0x574f4c46) //1464814662
	{
		execl("/bin/sh", "sh", 0)
	}
	return (0);
}
