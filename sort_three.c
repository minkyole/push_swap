/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:03:00 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 17:03:01 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_three_size_upper(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		swap_stack(stack_a, stack_command, flag);
		rotate_stack(stack_a, stack_command, flag);
	}
	else if (first > second && second < third && first < third)
		swap_stack(stack_a, stack_command, flag);
	else if (first < second && second > third && first > third)
		reverse_rotate_stack(stack_a, stack_command, flag);
	else if (first > second && second < third && first > third)
		rotate_stack(stack_a, stack_command, flag);
	else if (first > second && second > third)
	{
		swap_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
	}
}

void	sort_three_size_lower(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first > second && second > third)
		return ;
	else if (first < second && second > third && first < third)
		rotate_stack(stack_a, stack_command, flag);
	else if (first > second && second < third && first < third)
		reverse_rotate_stack(stack_a, stack_command, flag);
	else if (first < second && second > third && first > third)
		swap_stack(stack_a, stack_command, flag);
	else if (first > second && second < third && first > third)
	{
		swap_stack(stack_a, stack_command, flag);
		rotate_stack(stack_a, stack_command, flag);
	}
	else if (first < second && second < third)
	{
		swap_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
	}
}

void	sort_three_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 1)
	{
		push_stack(stack_b, stack_a, stack_command, \
		(sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 2)
		swap_stack(stack_a, stack_command, sort_var.flag);
	else if (sort_var.command == 3)
	{
		push_stack(stack_b, stack_a, stack_command, \
		(sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, \
		(sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
}

void	sort_three_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 4)
	{
		push_stack(stack_b, stack_a, stack_command, \
		(sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 5)
	{
		push_stack(stack_b, stack_a, stack_command, \
		(sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
}
