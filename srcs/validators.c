/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:15:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/08 05:34:39 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	validate_input(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Too many arguments.\n");
		else
			ft_printf("Missing map file.\n");
		return (0);
	}
	else
	{
		if (read(*argv[1], 0, 0))
			return (1);
		else
			return (0);
	}
}
