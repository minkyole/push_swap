/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:56:12 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/18 14:38:53 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoi(char *str)
{
	long long	num;
	int			plus;

	plus = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			plus = plus * -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (2147483648);
	while (*str >= '0' && *str <= '9')
	{
		num = ((num * 10) + (*str - '0'));
		if (num > 2147483647 || num < -2147483648)
			return (num);
		str++;
	}
	if (*str != '\0')
		return (2147483648);
	return (num * plus);
}
