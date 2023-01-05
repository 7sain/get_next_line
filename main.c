#include "get_next_line.h"

void ft_putstr_fd(char *str, int fd)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], fd);
}

int	main()
{
	int		fd;
	char	*nline;
	
	fd = open("test.txt", O_RDONLY); 
	nline = get_next_line(fd);
	while (nline != NULL)
	{
		// write(1,"@", 1);
		ft_putstr_fd(nline, 1);
		nline = get_next_line(fd);
	}
	return(fd);
}
