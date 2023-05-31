/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:42:46 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/28 13:06:35 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	i;
	int				src_size;

	src_size = 0;
	i = 0;
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	while (i < size)
	{
		dest[i] = src[i];
		if (i == size - 1)
			dest[size - 1] = 0;
		if (src[i] == 0)
			break ;
		i++;
	}
	return (src_size);
}
