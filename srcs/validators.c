/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:15:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/25 10:35:19 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	validate_input(int argc, char *map_name)
{
	if (argc > 2)
		raise_error("Too many arguments.\n");
	else
		raise_error("Missing map file.\n");
	if (read(*map_name, 0, 0) && validate_map_type(map_name))
		return (1);
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
