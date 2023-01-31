/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:10 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/30 21:49:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parsing_map(char *file)
{
	size_t	y;
	size_t	x;

	y = count_map_lines(file);
	x = get_value_x(file);
	ft_printf("x: %i y: %i\n", x, y);
	return (0);
}

int	count_map_lines(char *file)
{
	size_t	len;
	int		fd;
	char	*str;

	len = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		len++;
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	return (len);
	close(fd);
}

int	get_value_x(char *file)
{
	int		fd;
	char	*recebe;
	int		x;

	fd = open(file, O_RDONLY);
	recebe = get_next_line(fd);
	x = ft_size(recebe, ' ');
	free(recebe);
	close(fd);
	return (x);
}
