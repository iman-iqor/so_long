#include"header.h"

char	*ft_ssstrjoin(char *save, char *buff)
{
	int		len;
	char	*str;
	int	i;
	int	j;

	if (!save && !buff)
		return (NULL);
	if (!save && buff)
		return (ft_strdup(buff));
	if (save && !buff)
		return (ft_strdup(save));
	len = ft_strlen(save) + ft_strlen(buff);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (save[++i] && i < ft_strlen(save))
		str[i] = save[i];
	j = 0;
	while (buff[j] && j < ft_strlen(buff))
		str[i++] = buff[j++];
	str[i] = 0;
	free(save);
	return (str);
}

void check_extention(char *argv)
{
    int len;
    len  = ft_strlen(argv);
    if((ft_strncmp(argv+len-4,".ber",4)))
    {
        write(1,"bad extension\n",14);
        exit(1);
    }
}
void check_argc(int argc)
{
    if(argc == 1)
    {
        write(1,"u should add the file that contains the map\n",44);
        exit(1);
    } 
}
int check_if_file_exist(char* argv)
{
    int fd;
    fd  = open(argv,O_RDONLY);
    if(fd < 0)
    {
        perror("file");
        exit(1);
    }
    return fd;
}
char* join_lines(char* argv)
{
    char* s;
    char* str;
    int fd;
    str = NULL;
    s = "a";
    fd = check_if_file_exist(argv);
    while(s)
    {
        s = get_next_line(fd);
        if(s)
            str = ft_ssstrjoin(str,s);
        free(s);
    }
    if(!str)
    {
        write(1,"the file is empty\n",18);
        exit(1);
    }
    return str;
}
