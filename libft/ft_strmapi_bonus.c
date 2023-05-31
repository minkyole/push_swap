/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:15:38 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 12:31:56 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*parr;

	len = ft_strlen(s);
	parr = (char *)malloc(len + 1);
	if (parr == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		parr[i] = f(i, s[i]);
		i++;
	}
	parr[i] = 0;
	return (parr);
}
