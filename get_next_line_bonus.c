/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:27:09 by rapelcha          #+#    #+#             */
/*   Updated: 2022/12/04 10:09:33 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_bzero(void *pointer, size_t size)
{
	while (size--)
		((char *)pointer)[size] = 0;
	return (pointer);
}

char	*ft_trimstorage(char *storage)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	if (*storage == '\0')
		return (storage = xfree(storage));
	while (storage[i])
		if (storage[i++] == '\n')
			break ;
	res = ft_calloc(ft_strlen(storage) - i + 1, sizeof(char));
	while (storage[i] != '\0')
	{
		res[j] = storage[i];
		i++;
		j++;
	}
	return (storage = xfree(storage), res);
}

char	*ft_writeres(char *storage)
{
	char	*res;
	size_t	len;

	len = 0;
	while (storage[len] != '\n' && storage[len] != '\0')
		len++;
	if (storage[len] == '\n')
		len++;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (res = xfree(res));
	while (len--)
		res[len] = storage[len];
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	t_var		t_var;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_calloc(1, sizeof(char));
	t_var.ver = 1;
	t_var.buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (t_var.ver > 0 && (is_backslashn(storage[fd]) == 0))
	{
		t_var.buffer = ft_bzero(t_var.buffer, BUFFER_SIZE);
		t_var.ver = read(fd, t_var.buffer, BUFFER_SIZE);
		if (t_var.ver <= 0)
			break ;
		storage[fd] = ft_strjoin(storage[fd], t_var.buffer);
	}
	t_var.buffer = xfree(t_var.buffer);
	if (t_var.ver < 0 || (t_var.ver <= 0 && *storage[fd] == '\0'))
		return (storage[fd] = xfree(storage[fd]), NULL);
	t_var.buffer = ft_writeres(storage[fd]);
	storage[fd] = ft_trimstorage(storage[fd]);
	return (t_var.buffer);
}
