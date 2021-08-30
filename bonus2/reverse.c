#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int language = 1;

void	greetuser(char *buf)
{
	char out_buf[72]; //ebp-0x48

	if (language == 1)
	{
		strcpy(out_buf, "Hyvää päivää ");// Really strange way to do it in asm
	}
	else if (language == 2)
	{
		strcpy(out_buf, "Goedemiddag! ");// Really strange way to do it in asm
	}
	else if (language == 0)
	{
		strcpy(out_buf, "Hello ");// Really strange way to do it in asm
	}
	strcat(out_buf, buf); //ebp-0x48 ebp+0x8
	puts(out_buf);
}

int		main(int argc, char **argv)
{
	char	buf[72]; //0xbffff670
	char	*lang_ptr;

	if (argc != 3)
		return (1);
	memset(buf, 0, 19);
	strncpy(buf, argv[1], 40);
	strncpy(buf + 40, argv[2], 32); //0xbffff648
	if ((lang_ptr = getenv("LANG")) != NULL)
	{
		if (memcmp(lang_ptr, "fi", 2) == 0)
		{
			language = 1;
		}
		else if (memcmp(lang_ptr, "nl", 2) == 0)
		{
			language = 2;
		}
	}
	//memcpy();
	greetuser(buf);
}
