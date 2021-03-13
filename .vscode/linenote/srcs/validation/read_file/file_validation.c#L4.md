int	file_validation(char *str)
{
	char *extension;
	int str_len;
	int extension_len;
	int i;

	extension = ".cub";
	str_len = ft_strlen(str);
	extension_len = ft_strlen(extension);
	i = 1;
	while(i < 5)
	{
		if (str[str_len - i] == extension[extension_len - i])
		{
			printf("El char %c coincide\n", str[str_len - i]);
			i++;
		}
		else
		{
			printf("Map file extension ❌  \n");
			return (-1);
		}
	}
	printf("Map file extension ✅ \n");
	return (1);
}
