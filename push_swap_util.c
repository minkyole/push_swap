/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:57:25 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:57:26 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
			;
		else
			return (1);
		i++;
	}
	return (0);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	add_stack_a(char **argv, int i, t_dlist *stack_a)
{
	char		**temp_arr;
	int			j;
	long long	temp_value;

	temp_arr = ft_split(argv[i], ' ');
	j = 0;
	while (temp_arr[j])
	{
		if (is_str_digit(temp_arr[j]))
			error();
		temp_value = ft_atoi(temp_arr[j]);
		if (temp_value > 2147483647 || temp_value < -2147483648)
			error();
		if (dlist_value_check(stack_a, temp_value))
			error();
		add_last_node(stack_a, temp_value);
		free(temp_arr[j]);
		j++;
	}
	free(temp_arr[j]);
	free(temp_arr);
	return (j);
}
