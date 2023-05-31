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

int	ft_atoi(const char *str)
{
	int		num;
	int		plus;
	char	*pstr;

	plus = 1;
	num = 0;
	pstr = (char *)str;
	while ((*pstr >= 9 && *pstr <= 13) || *pstr == 32)
		pstr++;
	if (*pstr == '+' || *pstr == '-')
	{
		if (*pstr == '-')
			plus = plus * -1;
		pstr++;
	}
	while (*pstr >= '0' && *pstr <= '9')
	{
		num = ((num * 10) + (*pstr - '0'));
		pstr++;
	}
	if (plus == -1)
		num = num * -1;
	return (num);
}
