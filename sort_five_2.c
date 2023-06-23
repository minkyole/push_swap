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

void	quick_sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	t.first = stack_a->head->value;
	t.second = stack_a->head->next->value;
	t.third = stack_a->head->next->next->value;
	t.four = stack_a->head->next->next->next->value;
	t.five = stack_a->head->next->next->next->next->value;
	sort_var.command = 0;
	if (t.first < t.second && t.second < t.third && t.third < \
	t.four && t.four < t.five)
		return ;
	else if (++sort_var.command && t.four > t.first && t.four > t.second \
	&& t.four > t.third && t.four > t.five)
		quick_sort_five_command1(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.third > t.first && t.third > t.second \
	&& t.third > t.four && t.third > t.five)
		quick_sort_five_command1(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.second > t.first && t.second > t.third \
	&& t.second > t.four && t.second > t.five)
		quick_sort_five_command2(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.first > t.second && t.first > t.third \
	&& t.first > t.four && t.first > t.five)
		quick_sort_five_command2(stack_a, stack_b, stack_command, sort_var);
	quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	t.first = stack_a->head->value;
	t.second = stack_a->head->next->value;
	t.third = stack_a->head->next->next->value;
	t.four = stack_a->head->next->next->next->value;
	t.five = stack_a->head->next->next->next->next->value;
	sort_var.command = 0;
	if (t.first > t.second && t.second > t.third && t.third > \
	t.four && t.four > t.five)
		return ;
	else if (++sort_var.command && t.four < t.first && t.four < t.second \
	&& t.four < t.third && t.four < t.five)
		quick_sort_five_command1(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.third < t.first && t.third < t.second \
	&& t.third < t.four && t.third < t.five)
		quick_sort_five_command1(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.second < t.first && t.second < t.third \
	&& t.second < t.four && t.second < t.five)
		quick_sort_five_command2(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.first < t.second && t.first < t.third \
	&& t.first < t.four && t.first < t.five)
		quick_sort_five_command2(stack_a, stack_b, stack_command, sort_var);
	quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_five_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 1)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 2)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}

void	quick_sort_five_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 3)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 4)
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}

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
