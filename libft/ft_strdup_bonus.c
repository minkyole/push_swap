/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:11 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/18 15:10:05 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strdup(const char *s1)
{
	unsigned long	len;
	unsigned long	i;
	char			*parr;

	i = 0;
	len = ft_strlen(s1);
	parr = (char *)malloc(len + 1);
	if (parr == 0)
		return (0);
	while (i < len)
	{
		parr[i] = s1[i];
		i++;
	}
	parr[i] = 0;
	return (parr);
}
