/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_four_upper_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:46:01 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/23 23:46:07 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	quick_sort_four_size_upper_4(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.third < t.first && t.first < t.four && t.four < t.second)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.four < t.first && t.first < t.third && t.third < t.second)
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
	else
		quick_sort_four_size_upper_5(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_upper_3(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.second < t.first && t.first < t.four && t.four < t.third)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.four < t.first && t.first < t.second && t.second < t.third)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_upper_4(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_upper_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first < t.third && t.third < t.four && t.four < t.second)
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (t.first < t.four && t.four < t.third && t.third < t.second)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_upper_3(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_upper_1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first < t.second && t.second < t.four && t.four < t.third)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (t.first < t.four && t.four < t.second && t.second < t.third)
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else
		quick_sort_four_size_upper_2(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first < t.second && t.second < t.third && t.third < t.four)
		return ;
	else if (t.four > t.first && t.four > t.second && t.four > t.third)
		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
	else
		quick_sort_four_size_upper_1(stack_a, stack_b, stack_command, sort_var);
}
