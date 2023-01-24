/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:15:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/23 21:29:45 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	validate_input(int argc, char *map_name)
{
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Too many arguments.\n");
		else
			ft_printf("Missing map file.\n");
		exit(0);
	}
	else
	{
		if (read(*map_name, 0, 0) && validate_map_type(map_name))
			return (1);
		else
			exit(0);
	}
}

int	validate_map_type(char *map_name)
{
	size_t	len;
	char	*extention_file;

	len = ft_strlen(map_name);
	extention_file = ft_substr(map_name, (len - 4), len);
	if (ft_strncmp(extention_file, ".fdf", 4) != 0)
	{
		ft_printf("Wrong file extention. \n");
		exit(0);
	}
	return (1);
}
