#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line = NULL;
	int		i = 1;
	int		fd = 0;

	if (argc == 2) 
	{
		fd = open(argv[1], O_RDONLY);
		printf("FD: %d\n", fd);
		printf("Buffer size: %d\n\n", BUFFER_SIZE);
		while (get_next_line(fd, &line) > 0)
		{
			printf("Line %d: %s\n", i, line);
			free (line);
			line = NULL;
			i++;
		}
		printf("Line %d: %s\n", i, line);
		free (line);
		close(fd);
		return (0);
	}
	
	printf("Wrong arguments\n");
	return (1);
}
