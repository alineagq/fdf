/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:10 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/21 23:46:24 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void parsing_map(char *file, t_point **map)
{

}

int	get_value_y(char *file)
{
	int		fd;
	int		count;
	char	buf;
	size_t	n;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		raise_error("Program couldn't open the file", EBADF);

	n = read(fd, &buf, 1);
	if (n == -1)
		raise_error("Program couldn't read the file", EBADF);
	while (n > 0)
	{
		if (buf == '\n')
			count++;
		n = read(fd, &buf, 1);
	}
	close(fd);
	return (count);
}

int	get_value_x(char *file)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	x = ft_size(line, ' ');
	free(line);
	close(fd);
	return (x);
}
