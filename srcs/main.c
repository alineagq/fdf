/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 23:42:59 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char    *file;
	t_point **map;
	int     cols;
    int     rows;
    void    *mlx_ptr;
    void    *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "euzinha");
	file = argv[1];
    cols = get_value_x(file);
    rows = get_value_y(file);
    validate_map(argc, file);
    map = parsing_map(file, rows, cols);
    for(int i = 0; i < rows; i*=5)
    {
        for(int j = 0; j < cols; j*=5)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, rows+i,cols+j , 0xFFFF00);
            ft_printf("rows %i, cols %i\n", i, j);
        }
    }
    // print_map(map, rows, cols);
    free_map(map, rows);
	mlx_loop(mlx_ptr);
    exit (0);
}
