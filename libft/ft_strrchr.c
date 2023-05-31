/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:43:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/16 20:41:34 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*parr;
	int		equl;

	i = 0;
	equl = -1;
	parr = (char *)s;
	while (parr[i])
	{
		if (parr[i] == (char)c)
		{
			equl = i;
		}
		i++;
	}
	if (parr[i] == (char)c)
		return (parr + i);
	if (equl != -1)
		return (parr + equl);
	return ((void *)0);
}
