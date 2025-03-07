/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:55:27 by imiqor            #+#    #+#             */
/*   Updated: 2024/12/11 15:02:47 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *save, char *buff);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
char	*ft_strchr(char *str, int c);
char	*ft_extract_line(char *str);
char	*clean_save(char *buff);
char	*read_from_file(char *save, int fd);
char	*get_next_line(int fd);
#endif