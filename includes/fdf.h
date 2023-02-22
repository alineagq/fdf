/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:44:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/21 23:41:17 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_point
{
	int		value;
	char	*color;
}	t_point;

void	validate_map(int argc, char *map_name);
void	validate_input(int argc, char *map_name);
void	validate_map_type(char *map_name);
void	get_map_size(char *file);
int		get_value_y(char *file);
int		get_value_x(char *file);
void	raise_error(char *msg, int err);
int		ft_size(char *s, char c);
void	parsing_map(char *file, t_point **map);

#endif