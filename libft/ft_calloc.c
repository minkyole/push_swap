/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:24:17 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/18 14:43:43 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*parr;
	size_t	i;

	i = 0;
	parr = (char *)malloc(size * count);
	if (parr == NULL)
		return ((void *)0);
	while (i < size * count)
	{
		parr[i] = 0;
		i++;
	}
	return (parr);
}
