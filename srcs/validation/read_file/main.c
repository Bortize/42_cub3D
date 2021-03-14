#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	get_next_line(int fd, char **line);

int main(void)
{
	int 	fd;
	char	*line;
	int		devol;

	fd = open("main.c", O_RDONLY);
	if (fd == -1)
		printf("Error\n"); 
	while ((devol = get_next_line(fd, &line)) > 0)
	{
		printf("devol = %i\n", devol);
		free(line);
	}
		printf("devol = %i\n", devol);
		free(line);

	return (0);
}
