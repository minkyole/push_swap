/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:05:01 by minkyole          #+#    #+#             */
/*   Updated: 2023/04/10 17:05:02 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	print_d_i(va_list *print, int cnt, int precision, int *num)
{
	int	int_temp;
	int	len;
	int	i;

	i = 0;
	int_temp = va_arg(*print, int);
	len = ft_declen(int_temp);
	*num += len;
	while (cnt > len + i && cnt > precision + i)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		i++;
	}
	while (precision > len)
	{
		ft_putchar_fd('0', 1);
		*num += 1;
		precision--;
	}
	ft_putnbr_fd(int_temp, 1);
}

void	print_u(va_list *print, int cnt, int precision, int *num)
{
	unsigned int	unsigned_int_temp;
	int				len;
	int				i;

	i = 0;
	unsigned_int_temp = va_arg(*print, unsigned int);
	len = ft_undeclen(unsigned_int_temp);
	*num += len;
	while (cnt > len + i && cnt > precision + i)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		i++;
	}
	while (precision > len)
	{
		ft_putchar_fd('0', 1);
		*num += 1;
		precision--;
	}
	ft_un_putnbr_fd(unsigned_int_temp, 1);
}

void	print_small_x(va_list *print, int cnt, int precision, int *num)
{
	unsigned int	unsigned_int_temp;
	int				len;
	int				i;

	i = 0;
	unsigned_int_temp = va_arg(*print, unsigned int);
	len = ft_hexlen(unsigned_int_temp);
	*num += len;
	while (cnt > len + i && cnt > precision + i)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		i++;
	}
	while (precision > len)
	{
		ft_putchar_fd('0', 1);
		*num += 1;
		precision--;
	}
	ft_putptr2((long long)unsigned_int_temp, 1);
}		

void	print_big_x(va_list *print, int cnt, int precision, int *num)
{
	unsigned int	unsigned_int_temp;
	int				len;
	int				i;

	i = 0;
	unsigned_int_temp = va_arg(*print, unsigned int);
	len = ft_hexlen(unsigned_int_temp);
	*num += len;
	while (cnt > len + i && cnt > precision + i)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		i++;
	}
	while (precision > len)
	{
		ft_putchar_fd('0', 1);
		*num += 1;
		precision--;
	}
	ft_putptr2((long long)unsigned_int_temp, 0);
}

void	print_c(va_list *print, int cnt, int *num)
{
	char	char_temp;
	int		len;

	len = 1;
	*num += len;
	while (cnt > len)
	{
		ft_putchar_fd(' ', 1);
		*num += 1;
		len++;
	}
	char_temp = (char)va_arg(*print, int);
	ft_putchar_fd(char_temp, 1);
}
