/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:44:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/25 10:34:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

int		validate_input(int argc, char *map_name);
int		validate_map_type(char *map_name);
int		parsing_map(int fd);
void	raise_error(char *msg);

#endif