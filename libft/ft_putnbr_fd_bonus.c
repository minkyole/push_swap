/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:34 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/21 15:45:39 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_putnbr_fd(int n, int fd)
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
