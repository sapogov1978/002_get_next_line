#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char	*line;
	int		i = 1;
	int		fd3;
	int 	fd2;
	int		fd;

	//fd = 0;
	// line = NULL;

	fd = open("test_file.txt", O_RDONLY);
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

	i = 1;
	fd2 = open("test_cases/64bit_paragraph.txt", O_RDONLY);
	printf("\n\nFD2: %d\n", fd2);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd2, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		line = NULL;
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);
	close(fd2);

	i = 1;
	fd3 = open("test_cases/fewchar_perline.txt", O_RDONLY);
	printf("\n\nFD3: %d\n", fd3);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd3, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		line = NULL;
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);
	close(fd3);

	return (0);
}
