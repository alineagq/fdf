/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:40:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/09 21:56:30 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		vertical_len;

	vertical_len = 0;
	if (validate_input(argc, argv))
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd))
			vertical_len++;
		close(fd);
		ft_printf("%d", vertical_len);
	}
	return (0);
}
