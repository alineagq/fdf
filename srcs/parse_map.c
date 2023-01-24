/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:10 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/23 21:34:40 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parsing_map(int fd)
{
	char	*line;
	char	**splitted;

	line = get_next_line(fd);
	splitted = ft_split(line, ' ');
	ft_printf("%s\n%s", line, splitted[0]);
	close(fd);
	return (0);
}
