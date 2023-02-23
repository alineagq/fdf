/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:31:45 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 22:21:42 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	raise_error(char *msg, int err)
{
	errno = err;
	perror(msg);
	// ft_printf("Error: %s\n", strerror(err));
	exit(1);
}

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		raise_error("Program couldn't open the file", EBADF);
	return (fd);
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

char	*ft_strtok(char *str, const char *c)
{
	static char	*last_token = NULL;
	char		*result;

	if (str)
		last_token = str;
	if (!last_token || !*last_token)
		return (NULL);
	while (*last_token && ft_strchr(c, *last_token))
		last_token++;
	if (!*last_token)
	{
		last_token = NULL;
		return (NULL);
	}
	result = last_token;
	while (*last_token && !ft_strchr(c, *last_token))
		last_token++;
	if (*last_token)
	{
		*last_token = '\0';
		last_token++;
	}
	else
		last_token = NULL;
	return (result);
}
