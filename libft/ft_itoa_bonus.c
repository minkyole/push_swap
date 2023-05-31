/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:35:20 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 13:35:06 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int	ft_itoalen(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	temp;
	int			count;
	char		*parr;

	temp = n;
	count = ft_itoalen(temp);
	parr = (char *)malloc(count + 1);
	if (parr == 0)
		return (0);
	if (temp < 0)
	{
		temp = temp * -1;
		parr[0] = '-';
	}
	parr[count] = 0;
	count--;
	if (n == 0)
		parr[0] = '0';
	while (temp != 0)
	{
		parr[count] = temp % 10 + '0';
		temp = temp / 10;
		count--;
	}
	return (parr);
}
