#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char	*line;
	int		fd;
	int		i;

	//line = NULL;
	printf("V------------------------------------------------------V\n");
	printf("V--------------NARCO MANIAC TEST CASES-----------------V\n");
	printf("V------------------------------------------------------V\n\n\n");

	printf("V------------------------------------------------------V\n");
	printf("V-----------------TEST 1: UBER NONE--------------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V------ create file with 'touch > uber_none.txt'-------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V---------Test case expectation: Line 1: (null)--------V\n");
	printf("V------------------------------------------------------V\n\n");

	i = 1;
	if (!(fd = open("uber_none.txt", O_RDONLY)))
		return (-1);
	printf("FD: %d\n", fd);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);
	close(fd);

	printf("\n\n");
	printf("V------------------------------------------------------V\n");
	printf("V-----------------TEST 2: DEPESH EB MODE---------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V--------------file with a text inside and-------------V\n");
	printf("V-------------'write-only' permissions set-------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V---------Test case expectation: Line 1: (null)--------V\n");
	printf("V------------------------------------------------------V\n\n");

	i = 1;
	if (!(fd = open("depesh-eb-mode.txt", O_RDONLY)))
		return (-1);
	printf("FD: %d\n", fd);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		i++;
	}
	printf("Line %d: %s\n", i, line);
	//free (line);
	close(fd);

	printf("\n\n");
	printf("V------------------------------------------------------V\n");
	printf("V-----------TEST 3: HIT ME BABY ONE MORE TIME----------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V--------------Test file long.txt is valid-------------V\n");
	printf("V----------But some mentally deceased person-----------V\n");
	printf("V------call function again after EOF was returned------V\n");
	printf("V----------just before closing FD. Even twice.---------V\n");
	printf("V-------How 'bout no, you crazy Dutch bastard!---------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V------Test case expectation: 2 more empty lines ------V\n");
	printf("V------------------------------------------------------V\n\n");

	i = 1;
	if (!(fd = open("long.txt", O_RDONLY)))
		return (-1);
	printf("FD: %d\n", fd);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);

	get_next_line(fd, &line);
	printf("Line %d: %s\n", i, line);
	free (line);
	get_next_line(fd, &line);
	printf("Line %d: %s\n", i, line);
	free (line);

	close(fd);

	printf("\n\n");
	printf("V------------------------------------------------------V\n");
	printf("V---------------TEST 4: WHEREVER YOU ARE---------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V-------------Test file long1.txt is valid-------------V\n");
	printf("V------------it was linked with a soft link------------V\n");
	printf("V--------------------link-to-long1.txt-----------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V----Test case expectation: standard gnl behavior -----V\n");
	printf("V------------------------------------------------------V\n\n");

	i = 1;
	if (!(fd = open("link-to-long1.txt", O_RDONLY)))
		return (-1);
	printf("FD: %d\n", fd);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);
	close(fd);

printf("\n\n");
	printf("V------------------------------------------------------V\n");
	printf("V-------------------TEST 5: GO HARDER------------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V----------Test file empty_lines.txt is vali-----------V\n");
	printf("V-----------------it was hardlinked to ----------------V\n");
	printf("V---------------empty_lines_hardlink.txt---------------V\n");
	printf("V------------------------------------------------------V\n");
	printf("V----Test case expectation: standard gnl behavior -----V\n");
	printf("V------------------------------------------------------V\n\n");

	i = 1;
	if (!(fd = open("empty_lines_hardlink.txt", O_RDONLY)))
		return (-1);
	printf("FD: %d\n", fd);
	printf("Buffer size: %d\n\n", BUFFER_SIZE);
	while (get_next_line(fd, &line) > 0)
	{
		printf("Line %d: %s\n", i, line);
		free (line);
		i++;
	}
	printf("Line %d: %s\n", i, line);
	free (line);
	close(fd);





	return (0);
}
