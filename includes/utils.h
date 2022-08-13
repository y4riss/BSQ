/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:25:05 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 09:54:32 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>
# define BUFF_SIZE 100000

char	g_buff[BUFF_SIZE];
char	g_line[BUFF_SIZE];
char	*g_first_line;
int		**g_cache;
char	**g_matrix;
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
void	ft_putstr(char *s);
int		ft_read(int fd, int *line_count, int i, int j);
void	create_matrix(int line_count, int *j);
int		check_lines(char *line, int line_count, int *initial_length);
int		check_first_line(char *line);
int		valid_chars(char c);
int		valid_line(char *line, int initial_length);
int		count_lines(char *line);
int		maximal_square(int matrix_size, int matrix_col_size);
void	print_matrix(void);
#endif
