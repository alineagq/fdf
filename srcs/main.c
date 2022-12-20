/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2022/12/19 21:00:53 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	quadradao(void *mlx, void *win, int x, int y, int color)
{
	int	oto_x;
	int	oto_y = 0;

	while (oto_y < 50)
	{
        oto_x = 0;
		while (oto_x < 50)
		{
			my_mlx_pixel_put(mlx, oto_x + x, oto_y + y, color);
            oto_x++;
		}
		oto_y++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	quadradao(&img, mlx_win, 10, 10, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
