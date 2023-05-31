/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:19:26 by minkyole          #+#    #+#             */
/*   Updated: 2023/04/21 18:28:01 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	((char *)dst)[i] = 0;
	return (dst);
}

int	check_count(char *parr, int *end, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (parr != NULL && parr[i])
		{
			if (parr[i] == '\n')
			{
				*end = i;
				return (1);
			}
			i++;
		}
		return (0);
	}
	else if (flag == 2)
	{
		while (parr != NULL && parr[i])
			i++;
		if (i == 0 || parr[i - 1] == '\n')
			return (0);
		*end = i - 1;
	}
	return (1);
}

char	*static_reset(char **parr)
{
	free(*parr);
	*parr = NULL;
	return (NULL);
}

int	ft_strlen2(char *parr)
{
	int	i;

	i = 0;
	while (parr && parr[i])
	{
		i++;
	}
	return (i);
}
