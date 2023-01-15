#include "get_next_line_bonus.h"

int	main()
{
	int		fd;
	int		fdk;
	char	*nline;
	char	*nlinek;

	fd = open("test.txt", O_RDONLY);
	fdk = open("test2.txt", O_RDONLY);
		// write(1,"@", 1);
		nlinek = get_next_line(fd);
		nline = get_next_line(fdk);
		printf("<<%s>>", nline);
		printf("%s", nlinek);
	close(fd);

}
