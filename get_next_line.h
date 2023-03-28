/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:27:17 by rapelcha          #+#    #+#             */
/*   Updated: 2022/12/03 09:48:51 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_var
{
	int		ver;
	char	*buffer;
	char	*temp;

}			t_var;

char	*get_next_line(int fd);
int		is_backslashn(char *str);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t len, size_t size);
void	*xfree(void *pointer);
char	*ft_strjoin(char *src1, char *src2);
void	*ft_bzero(void *pointer, size_t size);

#endif