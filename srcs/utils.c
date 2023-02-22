/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:31:45 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/21 19:45:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	raise_error(char *msg, int err)
{
	errno = err;
	perror(msg);
	ft_printf("Error: %s\n", strerror(err));
	exit(1);
}

int	ft_size(char *s, char c)
{
	int	times;

	times = (*s && *s != c);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s++ == c)
		{
			times++;
			while (*s && *s == c)
				s++;
		}
	}
	if (s[-1] == c)
		times--;
	return (times + 1);
}

