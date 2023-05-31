/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:17:28 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 17:18:26 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	arr_len;
	char			*parr;

	i = 0;
	arr_len = (int)ft_strlen(s);
	if (arr_len < start || s[0] == 0)
	{
		parr = ft_strdup("");
		return (parr);
	}
	if (arr_len < start + len)
	{
		len = arr_len - start;
	}
	parr = (char *)malloc(len + 1);
	if (parr == 0)
		return (0);
	while (i < len && s[i + start])
	{
		parr[i] = s[i + start];
		i++;
	}
	parr[i] = 0;
	return (parr);
}
