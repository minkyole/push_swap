/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:18:50 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/23 19:18:50 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_five_command_upper_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 3)
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 4)
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 5)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}
