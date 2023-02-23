/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/23 20:12:38 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_hook(int keycode, void *param);

int	main(int argc, char *argv[])
{
	t_point	**map;
	t_mlx	mlx;

	mlx.file = argv[1];
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "euzinha");
	mlx.cols = get_value_x(mlx.file);
	mlx.rows = get_value_y(mlx.file);
	validate_map(argc, mlx.file);
	map = parsing_map(mlx.file, mlx.rows, --mlx.cols);
	// print_map(map, mlx.rows, mlx.cols);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, my_hook, NULL);
	// mlx_key_hook(mlx.win, key_hook, &mlx);
	free_map(map, mlx.rows);
	mlx_loop(mlx.mlx);
	exit (0);
}

int my_hook(int keycode, void *param)
{
    // Handle the keypress event
	if (keycode == 65307 || keycode == 27)
		exit(0);
    printf("Keycode %d pressed!\n", keycode);
    
    // Return 0 to indicate that the event was handled successfully
    return (0);
}
