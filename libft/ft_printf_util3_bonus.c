/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:05:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/04/10 17:05:11 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	print_s(va_list *print, int cnt, int *num)
{
	char	*parr_temp;
	int		len;

	parr_temp = va_arg(*print, char *);
	if (parr_temp == NULL)
	{
		while (cnt > 6)
		{
			ft_putchar_fd(' ', 1);
			*num += 1;
			cnt--;
		}
		ft_putstr_fd("(null)", 1);
		*num += 6;
		return ;
	}
	len = ft_strlen(parr_temp);
	*num += len;
	while (cnt > len)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		len++;
	}
	ft_putstr_fd(parr_temp, 1);
}

void	print_p(va_list *print, int cnt, int *num)
{
	void	*ptr_temp;
	int		len;

	ptr_temp = va_arg(*print, void *);
	len = ft_hexlen((long long)&ptr_temp[0]);
	*num += len;
	if (len + 2 < cnt)
	{
		while (cnt > len + 2)
		{
			ft_putchar_fd(' ', 1);
			*num += 1;
			len++;
		}
	}
	ft_putstr_fd("0x", 1);
	*num += 2;
	ft_putptr2((unsigned long long)&ptr_temp[0], 1);
}

void	print_per(int cnt, int *num)
{
	(void) cnt;
	*num += 1;
	ft_putchar_fd('%', 1);
}
