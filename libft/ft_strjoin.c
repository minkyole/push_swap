/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:09:41 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/28 21:05:50 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		all_len;
	char	*parr;

	all_len = 0;
	if (s2 == NULL)
		return ((char *)s1);
	else if (s1 == NULL)
	{
		parr = malloc(ft_strlen(s2) + 1);
		if (parr == 0)
			return (0);
		ft_memcpy(parr, (char *)s2, ft_strlen(s2) + 1);
		free ((char *)s2);
		return (parr);
	}
	all_len += ft_strlen(s1) + ft_strlen(s2);
	parr = malloc(all_len + 1);
	if (parr == 0)
		return (0);
	ft_memcpy(parr, (char *)s1, ft_strlen(s1));
	ft_memcpy(parr + ft_strlen(s1), (char *)s2, ft_strlen(s2) + 1);
	free ((char *)s1);
	free ((char *)s2);
	return (parr);
}
