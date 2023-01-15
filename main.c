#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*nline;

	fd = open("out.txt", O_RDONLY); 
	nline = get_next_line(fd);
	while (nline != NULL)
	{
		// write(1,"@", 1);
		printf("%s", nline);
		free(nline);
		nline = get_next_line(fd);
	}
	return(fd);
}
