/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:44:25 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/23 21:16:51 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libs/printf/includes/ft_printf.h"
# include "../libs/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

int	validate_input(int argc, char *map_name);
int	validate_map_type(char *map_name);
int	parsing_map(int fd);

#endif