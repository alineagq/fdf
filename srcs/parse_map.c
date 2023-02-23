/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:05:10 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 22:22:42 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**parsing_map(char *file, int rows, int cols)
{
	int		fd;
	char	*line;
	char	*value;
	int		i;
	int		j;
	t_point	**map;

	i = 0;
	j = 0;
	fd = ft_open(file);
	map = (t_point **)malloc(rows * sizeof(t_point *));
	while (i < rows)
	{
		map[i] = (t_point *)malloc(cols * sizeof(t_point));
		i++;
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		value = ft_strtok(line, " ");
		while (value != NULL)
		{
			map[i][j].value = atoi(value);
			map[i][j].color = NULL;
			value = ft_strtok(NULL, " ");
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (map);
}

void print_map(t_point **map, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("(%d", map[i][j].value);
            if (map[i][j].color != NULL)
            {
                printf(", %s)", map[i][j].color);
            }
            else
            {
                printf(")");
            }
        }
        printf("\n");
    }
}

void free_map(t_point **map, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
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
