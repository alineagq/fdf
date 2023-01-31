/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:31:45 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/01/30 21:42:57 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	raise_error(char *msg)
{
	ft_printf("%s", msg);
	exit(1);
}

int	ft_size(char *s, char c)
{
	int		times;
	size_t	i;

	i = 0;
	times = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			times++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		times++;
	return (times);
}
