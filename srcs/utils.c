/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:31:45 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 14:50:15 by aqueiroz         ###   ########.fr       */
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
	static char	*buf;
	char		*token;
	char		*result;

	if (!str)
		return (NULL);
	buf = malloc (ft_strlen(str) + 1);
	if (buf == NULL)
		return (NULL);
	ft_strlcpy(buf, str, ft_strlen(str));
	while (*buf != '\0' && ft_strchr(c, *buf) != NULL)
		buf++;
	if (*buf == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	token = buf;
	while (*token != '\0' && ft_strchr(c, *token) == NULL)
		token++;
	*token = '\0';
	result = buf;
	buf = token + 1;
	return (result);
}

