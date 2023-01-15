char	*get_next_line(int fd)
{
	static char	*s;
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	s = read_file(fd, s);
	printf("\nvalue of s is:\n >>>\n%s\n<<<\n", s);
	ptr = get_line(s);
	printf("\nvalue of ptr is:\n {>>>}\n%s\n{<<<}\n", ptr);
	s = ft_cut(s);
	printf("\nvalue of new S is:\n (><)\n%s\n(><)\n", s);

	return (ptr);
}