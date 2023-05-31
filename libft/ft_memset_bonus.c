/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:43:29 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/16 18:50:36 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	size_t			i;

	a = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = a;
		i++;
	}
	return (b);
}
