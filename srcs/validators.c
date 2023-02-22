/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:15:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/21 19:42:02 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	validate_map(int argc, char *map_name)
{
	validate_input(argc, map_name);
	validate_map_type(map_name);
}

void	validate_input(int argc, char *map_name)
{
	if (argc == 1)
		raise_error("Missing map file.\n", ENOENT);
	if (argc > 2)
		raise_error("Too many arguments.\n", E2BIG);
	if (!(read(*map_name, 0, 0)))
		raise_error("Map invalid.\n", EBADF);
}

void	validate_map_type(char *map_name)
{
	size_t	len;
	char	*extention_file;

	len = ft_strlen(map_name);
	extention_file = ft_substr(map_name, (len - 4), len);
	if (ft_strncmp(extention_file, ".fdf", 4) != 0)
		raise_error("Wrong file extention. \n", ENOEXEC);
	free(extention_file);
}
