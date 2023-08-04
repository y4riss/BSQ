/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylassiry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:25:25 by ylassiry          #+#    #+#             */
/*   Updated: 2022/08/10 20:30:17 by ylassiry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	g_buff[BUFF_SIZE];
char	g_line[BUFF_SIZE];
char	*g_first_line;
int		**g_cache;
char	**g_matrix;

int	ft_valid_map(int fd)
{
	int	line_count;

	line_count = 0;
	if (ft_read(fd, &line_count, 0, 0) == 0)
		return (0);
	if (line_count == 1 || count_lines(g_first_line) != line_count - 1)
		return (0);
	if (g_matrix == NULL)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	fd;
	int	i;

	i = 0;
	if (ac == 1)
	{
		if (ft_valid_map(0))
			print_matrix();
		else
			write(2, "map error\n", 10);
	}
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1 || !ft_valid_map(fd))
			write(2, "map error\n", 10);
		else
			print_matrix();
		if (i < ac - 1)
			ft_putstr("\n");
		close(fd);
	}
	return (0);
}
