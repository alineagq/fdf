/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz < aqueiroz@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:20:35 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/02/22 10:29:16 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtok(char *str, const char c)
{
	static char	*buf;
	char		*token;
	char		*result;

	if (!str)
		return (NULL);
	buffer = malloc (ft_strlen(str) + 1);
	if (buffer == NULL)
		return (NULL);
	ft_strcpy(buffer, str);
	while (*buffer != '\0' && ft_strchr(c, *buffer) != NULL)
		buffer++;
	if (*buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	token = buffer;
	while (*token != '\0' && ft_strchr(c, *token) == NULL)
		token++;
	*token = '\0';
	result = buffer;
	buffer = token + 1;
	return (result);
}
