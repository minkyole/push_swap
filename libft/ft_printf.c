/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:09:30 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/03 20:52:55 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_conversion(t_print_member *member, va_list *print, int i)
{
	member->precision = 0;
	if (member->input_msg[i + 1] == '.')
	{
		i++;
		while (ft_isdigit(member->input_msg[i + 1]))
			member->precision = ((member->precision * 10) + \
					(member->input_msg[++i] - '0'));
	}
	if (member->input_msg[i + 1] == 'd' || member->input_msg[i + 1] == 'i')
		print_d_i(print, member->cnt, member->precision, &member->len);
	if (member->input_msg[i + 1] == 'u')
		print_u(print, member->cnt, member->precision, &member->len);
	if (member->input_msg[i + 1] == 'x')
		print_small_x(print, member->cnt, member->precision, &member->len);
	if (member->input_msg[i + 1] == 'X')
		print_big_x(print, member->cnt, member->precision, &member->len);
	if (member->input_msg[i + 1] == 'c')
		print_c(print, member->cnt, &member->len);
	if (member->input_msg[i + 1] == 's')
		print_s(print, member->cnt, &member->len);
	if (member->input_msg[i + 1] == '%')
		print_per(member->cnt, &member->len);
	if (member->input_msg[i + 1] == 'p')
		print_p(print, member->cnt, &member->len);
	return (++i);
}

int	ft_printf(const char *msg, ...)
{
	int				i;
	va_list			print;
	t_print_member	member;

	member.input_msg = (char *)msg;
	member.len = 0;
	i = -1;
	va_start(print, msg);
	while (member.input_msg[++i])
	{
		member.cnt = 0;
		if (member.input_msg[i] == '%')
		{	
			while (ft_isdigit(member.input_msg[i + 1]))
				member.cnt = ((member.cnt * 10) + \
						(member.input_msg[++i] - '0'));
			i = print_conversion(&member, &print, i);
			member.len--;
		}
		else
			ft_putchar_fd(member.input_msg[i], 1);
		member.len++;
	}
	va_end(print);
	return (member.len);
}
