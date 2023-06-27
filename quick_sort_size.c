/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:44:15 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/19 01:44:16 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	quick_sort_size_check(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.size <= 1)
	{
		if (sort_var.flag == 2)
			push_stack(stack_b, stack_a, stack_command, 1);
		return (1);
	}
	else if (quick_sort_size_check_2(stack_a, stack_b, \
	stack_command, sort_var))
		return (1);
	else if (quick_sort_size_check_3(stack_a, stack_b, \
	stack_command, sort_var))
		return (1);
	else if (quick_sort_size_check_4(stack_a, stack_b, \
	stack_command, sort_var))
		return (1);
	else if (quick_sort_size_check_5(stack_a, stack_b, \
	stack_command, sort_var))
		return (1);
	return (0);
}

int	quick_sort_size_check_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.size == 2)
	{
		if (sort_var.upper % 2 == 1)
			sort_two_size(stack_a, stack_command, sort_var.flag);
		else if (sort_var.upper % 2 == 0)
			sort_two_size(stack_a, stack_command, sort_var.flag + 2);
		if (sort_var.flag == 2)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
		}
		return (1);
	}
	return (0);
}

int	quick_sort_size_check_3(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.size == 3)
	{
		if (stack_a->size == 3 && sort_var.upper % 2 == 1)
			sort_three_size_upper(stack_a, stack_command, sort_var.flag);
		else if (stack_a->size == 3 && sort_var.upper % 2 == 0)
			sort_three_size_lower(stack_a, stack_command, sort_var.flag);
		else if (sort_var.upper % 2 == 1)
			quick_sort_three_size_upper(stack_a, stack_b, \
			stack_command, sort_var);
		else if (sort_var.upper % 2 == 0)
			quick_sort_three_size_lower(stack_a, stack_b, \
			stack_command, sort_var);
		if (sort_var.flag == 2)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
		}
		return (1);
	}
	return (0);
}

int	quick_sort_size_check_4(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.size == 4)
	{
		if (stack_a->size == 4 && sort_var.upper % 2 == 1)
			sort_four_size_upper(stack_a, stack_b, stack_command, \
			sort_var.flag);
		else if (stack_a->size == 4 && sort_var.upper % 2 == 0)
			sort_four_size_lower(stack_a, stack_b, stack_command, \
			sort_var.flag);
		else if (sort_var.upper % 2 == 1)
			quick_sort_four_size_upper(stack_a, stack_b, stack_command, \
			sort_var);
		else if (sort_var.upper % 2 == 0)
			quick_sort_four_size_lower(stack_a, stack_b, stack_command, \
			sort_var);
		if (sort_var.flag == 2)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
		}
		return (1);
	}
	return (0);
}

int	quick_sort_size_check_5(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.size == 5)
	{
		if (stack_a->size == 5 && sort_var.upper % 2 == 1)
			sort_five_size_upper(stack_a, stack_b, stack_command, \
			sort_var);
		else if (stack_a->size == 5 && sort_var.upper % 2 == 0)
			sort_five_size_lower(stack_a, stack_b, stack_command, \
			sort_var);
		else if (sort_var.upper % 2 == 1)
			quick_sort_five_size_upper(stack_a, stack_b, stack_command, \
			sort_var);
		else if (sort_var.upper % 2 == 0)
			quick_sort_five_size_lower(stack_a, stack_b, stack_command, \
			sort_var);
		if (sort_var.flag == 2)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
			push_stack(stack_b, stack_a, stack_command, 1);
		}
		return (1);
	}
	return (0);
}
