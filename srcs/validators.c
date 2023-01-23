/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:15:34 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/23 20:56:40 by aqueiroz         ###   ########.fr       */
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
		exit(0);
	}
	else
	{
		if (read(*argv[1], 0, 0))
			return (1);
		else
			exit(0);
	}
}
