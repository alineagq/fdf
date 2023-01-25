/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:10 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/25 12:22:56 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parsing_map(char *file)
{
	size_t	running_line;
	size_t	index;
	int		fd;

	index = 1;
	running_line = count_map_lines(file);
	fd = open(file, O_RDONLY);
	while (index <= running_line)
	{
		ft_printf("%s", get_next_line(fd));
		index++;
	}

	close(fd);
	return (0);
}

int	count_map_lines(char *file)
{
	size_t	len;
	int		fd;

	len = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		len++;
	free(get_next_line(fd));
	return (len);
	close(fd);
}
