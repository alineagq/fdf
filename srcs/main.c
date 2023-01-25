/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/25 12:27:04 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	main(int argc, char *argv[])
{
	char	*file;

	file = argv[1];
	validate_input(argc, file);
	parsing_map(file);
	exit (0);
}
