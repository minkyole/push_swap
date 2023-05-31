/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:45:20 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/28 13:27:20 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	char			*parr;

	parr = (char *)s;
	i = 0;
	if (n == 0)
		return ((void *)0);
	while (i < n)
	{
		if (parr[i] == (char)c)
			return (&parr[i]);
		i++;
	}
	return ((void *)0);
}
