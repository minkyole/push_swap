/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:42:31 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/28 13:20:09 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	size_t			j;
	int				len;

	i = 0;
	j = 0;
	if (ft_strlen(dest) >= size)
		return (ft_strlen(src) + size);
	else
		len = ft_strlen(dest) + ft_strlen(src);
	while (dest[i])
	{
		size--;
		i++;
	}
	while ((j + 1 < size && src[j]))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (len);
}
