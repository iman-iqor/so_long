/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:56:11 by imiqor            #+#    #+#             */
/*   Updated: 2024/12/10 10:27:41 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13847748
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
char	*clean_buffer(char *buff);
char	*read_from_file(char *save, int fd);
char	*get_next_line(int fd);

#endif