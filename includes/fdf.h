/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:44:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/23 19:56:28 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../libs/printf/includes/ft_printf.h"
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
// # include <key_linux.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_point
{
	int		value;
	char	*color;
}	t_point;

typedef struct s_mlx
{
	char	*mlx;
	char	*win;
	int		cols;
	int		rows;
	char	*file;
}	t_mlx;

void	validate_map(int argc, char *map_name);
void	validate_input(int argc, char *map_name);
void	validate_map_type(char *map_name);
void	get_map_size(char *file);
int		get_value_y(char *file);
int		get_value_x(char *file);
void	raise_error(char *msg, int err);
int		ft_size(char *s, char c);
t_point	**parsing_map(char *file, int rows, int cols);
int		ft_open(char *file);
char	*ft_strtok(char *str, const char *c);
void	print_map(t_point **map, int rows, int cols);
void	free_map(t_point **map, int rows);

#endif