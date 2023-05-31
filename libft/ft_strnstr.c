/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:43:08 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/16 15:27:09 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;
	char	*to_find;

	str = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	if (to_find[0] == 0)
		return (str);
	while (*str && i < len)
	{
		j = 0;
		if (str[j] == to_find[j])
		{
			while (str[j] == to_find[j] && str[j] && to_find[j] && i + j < len)
				j++;
			if (to_find[j] == '\0')
				return (str);
		}
		str++;
		i++;
	}
	return ((void *)0);
}
