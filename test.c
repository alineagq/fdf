/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:15:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 10:32:52 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"


char	*ft_strtok(char *str, const char *c);

int	main()
{
	char str[] = "0 10 20,0xFF0000 15,0xFF0000 12 15,0xFF0000 17,0xFF0000 20,0xFF0000 10  0";
	char *token = ft_strtok(str, " ,");

	while (token != NULL)
	{
		ft_printf("%s\n", token);
		token = ft_strtok(NULL, " ,");
	}
	return 0;
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

