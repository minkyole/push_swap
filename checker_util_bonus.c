/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:53:32 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 15:53:33 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

void	error(int flag)
{
	if (flag == 1)
	{
		ft_printf("not digit\n");
		exit (1);
	}
	else if (flag == 2)
	{
		ft_printf("input error\n");
		exit (2);
	}
	else if (flag == 3)
	{
		ft_printf("Duplicate Value\n");
		exit (3);
	}
}

int	check_command_r(char *buff, size_t len, t_dlist *stack_a, t_dlist *stack_b)
{
	if (buff[1] == 'a')
		rotate_stack(stack_a);
	else if (buff[1] == 'b')
		rotate_stack(stack_b);
	else if (buff[1] == 'r' && len == 3)
		rotate_stack_all(stack_a, stack_b);
	else if (len == 4 && buff[1] == 'r' && buff[2] == 'a')
		reverse_rotate_stack(stack_a);
	else if (len == 4 && buff[1] == 'r' && buff[2] == 'b')
		reverse_rotate_stack(stack_b);
	else if (len == 4 && buff[1] == 'r' && buff[2] == 'r')
		reverse_rotate_stack_all(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	add_stack_a(char **argv, int i, t_dlist *stack_a)
{
	char	**temp_arr;
	int		j;
	int		temp_value;

	temp_arr = ft_split(argv[i], ' ');
	j = 0;
	while (temp_arr[j])
	{
		if (is_str_digit(temp_arr[j]))
			error(1);
		temp_value = ft_atoi(temp_arr[j]);
		if (temp_value > 2147483647 || temp_value < -2147483648)
			error(2);
		if (dlist_value_check(stack_a, temp_value))
			error(3);
		add_last_node(stack_a, temp_value);
		j++;
	}
	return (j);
}

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
