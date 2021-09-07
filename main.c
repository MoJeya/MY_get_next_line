#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt",O_RDONLY);
	if (fd == -1)
	{
		write(3,"ERROR",5);
	}
	while ((str = get_next_line(fd)))
	{
		printf("%s\n",str);
		free(str);
	}
	system("leaks a.out");
	return (0);
}
