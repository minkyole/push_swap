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

void	error(void)
{
	ft_printf("Error\n");
	exit (1);
}

int	check_command_r(char *buff, size_t len, t_dlist *stack_a, t_dlist *stack_b)
{
	if (buff[1] == 'a' && buff[2] == '\n')
		rotate_stack(stack_a);
	else if (buff[1] == 'b' && buff[2] == '\n')
		rotate_stack(stack_b);
	else if (buff[1] == 'r' && buff[2] == '\n')
		rotate_stack_all(stack_a, stack_b);
	else if (buff[1] == 'r' && buff[2] == 'a' && buff[3] == '\n')
		reverse_rotate_stack(stack_a);
	else if (len == 4 && buff[1] == 'r' && buff[2] == 'b' && buff[3] == '\n')
		reverse_rotate_stack(stack_b);
	else if (len == 4 && buff[1] == 'r' && buff[2] == 'r' && buff[3] == '\n')
		reverse_rotate_stack_all(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	add_stack_a(char **argv, int i, t_dlist *stack_a)
{
	char		**temp_arr;
	int			j;
	long long	temp_value;

	temp_arr = ft_split(argv[i], ' ');
	if (!temp_arr)
		error();
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
