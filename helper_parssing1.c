/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_parssing1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:27:44 by imiqor            #+#    #+#             */
/*   Updated: 2025/03/14 20:27:45 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    char  *tmp;

    if (!argv)
        return ;
    len  = ft_strlen(argv);
    tmp = ft_strrchr(argv, '/');
    if((ft_strncmp(argv+len-4,".ber",4)) || (ft_strlen(argv) <= 4)
        || (tmp && ft_strlen(ft_strrchr(tmp, '/')) <= 5))
    {
        write(1,"Error \n bad extension\n",23);
        exit(1);
    }
}
void check_argc(int argc)
{
    if(argc == 1)
    {
        write(1,"Error \nu should add the file that contains the map\n",52);
        exit(1);
    } 
}
int check_if_file_exist(char* argv)
{
    int fd;
    fd  = open(argv,O_RDONLY);
    if(fd < 0)
    {
        perror("Error\n");
        exit(1);
    }
    return fd;
}
void join_lines_error(char* s,char *str)
{
    write(2,"Error\n :invalid map has newlines\n",34);
    free(s);
    free(str);
    exit(1);
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
        if(!(ft_strncmp(s,"\n",1)))
        {
            join_lines_error(s,str);
        }
        if(s)
            str = ft_ssstrjoin(str,s);
        free(s);
    }
    if(!str)
    {
        write(1,"Error \nthe file is empty\n",26);
        exit(1);
    }
    return str;
}
