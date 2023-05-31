/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:43:57 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/16 20:37:37 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*parr;

	i = 0;
	parr = (char *)s;
	while (parr[i])
	{
		if (parr[i] == (char)c)
			return (parr + i);
		i++;
	}
	if (parr[i] == (char)c)
		return (parr + i);
	return ((void *)0);
}
