/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:04:50 by minkyole          #+#    #+#             */
/*   Updated: 2023/04/10 17:04:52 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_un_putnbr_fd(unsigned int n, int fd)
{
	long long	num;

	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	if (num < 10)
		write(fd, &"0123456789"[num], 1);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}

void	ft_putptr2(unsigned long long nb, int small)
{
	if (nb < 16)
	{
		if (small == 1)
			write(1, &"0123456789abcdef"[nb], 1);
		else if (small == 0)
			write(1, &"0123456789ABCDEF"[nb], 1);
	}
	else
	{
		ft_putptr2(nb / 16, small);
		ft_putptr2(nb % 16, small);
	}
}

int	ft_declen(long long num)
{
	long long			len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

int	ft_undeclen(long long num)
{
	long long			len;
	unsigned long long	temp_num;

	len = 0;
	temp_num = (unsigned long long) num;
	while (temp_num != 0)
	{
		temp_num = temp_num / 10;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}

int	ft_hexlen(long long num)
{
	long long			len;
	unsigned long long	temp_num;

	len = 0;
	temp_num = (unsigned long long) num;
	while (temp_num != 0)
	{
		temp_num = temp_num / 16;
		len++;
	}
	if (len == 0)
		return (1);
	return (len);
}
