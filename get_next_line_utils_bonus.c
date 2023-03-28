/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:27:14 by rapelcha          #+#    #+#             */
/*   Updated: 2022/12/04 09:54:38 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_backslashn(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t len, size_t size)
{
	char	*str;

	str = malloc(len * size);
	if (!str)
		return (str = xfree(str));
	str = ft_bzero(str, len * size);
	return (str);
}

void	*xfree(void *pointer)
{
	if (pointer)
		free(pointer);
	return (NULL);
}

char	*ft_strjoin(char *src1, char *src2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src2)
		return (NULL);
	res = ft_calloc(ft_strlen(src1) + ft_strlen(src2) + 1, sizeof(char));
	if (!res)
		return (res = xfree(res));
	while (src1 && src1[i] != '\0')
	{
		res[i] = src1[i];
		i++;
	}
	while (src2[j] != '\0')
	{
		res[i] = src2[j];
		i++;
		j++;
	}
	return (src1 = xfree(src1), res);
}
