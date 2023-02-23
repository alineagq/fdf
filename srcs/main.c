/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 22:25:43 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char		*file;
	t_point		**map;
	int cols;
    int rows;

	file = argv[1];
    cols = get_value_x(file);
    rows = get_value_y(file);
    validate_map(argc, file);
    map = parsing_map(file, rows, cols);
    // print_map(map, rows, cols);
    free_map(map, rows);
    exit (0);
}
