/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_four_lower_command_2.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:45:12 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/24 13:45:13 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	quick_sort_four_size_lower_9(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.third < t.second && t.second < t.four && t.four < t.first)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.third < t.four && t.four < t.second && t.second < t.first)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_lower_10(stack_a, stack_b, \
		stack_command, sort_var);
}

void	quick_sort_four_size_lower_8(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.second < t.third && t.third < t.four && t.four < t.first)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var. flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.second < t.four && t.four < t.third && t.third < t.first)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_lower_9(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_lower_7(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.third < t.second && t.second < t.first && t.first < t.four)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var. flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (t.third < t.four && t.four < t.first && t.first < t.second)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_lower_8(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_lower_6(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.second < t.third && t.third < t.first && t.first < t.four)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.second < t.four && t.four < t.first && t.first < t.third)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_lower_7(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_lower_5(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.third < t.first && t.first < t.second && t.second < t.four)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (t.third < t.first && t.first < t.four && t.four < t.second)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_lower_6(stack_a, stack_b, stack_command, sort_var);
}
