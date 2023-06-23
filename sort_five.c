/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:56 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 17:26:57 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_five_command_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 1)
	{
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 2)
	{
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}

void	sort_five_command_lower_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 4)
	{
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 5)
	{
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}

void	sort_five_command_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	if (sort_var.command == 1)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 2)
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (sort_var.command == 3)
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
}

void	sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
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
	if (++sort_var.command, t.five < t.first && t.five < t.second \
	&& t.five < t.third && t.five < t.four)
		sort_five_command_upper(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command, t.four < t.first && t.four < t.second \
	&& t.four < t.third && t.four < t.five)
		sort_five_command_upper(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command, t.third < t.first && t.third < t.second \
	&& t.third < t.four && t.third < t.five)
		sort_five_command_upper_2(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command, t.second < t.first && t.second < t.third \
	&& t.second < t.four && t.second < t.five)
		sort_five_command_upper_2(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command)
		sort_five_command_upper_2(stack_a, stack_b, stack_command, sort_var);
}

void	sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
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
	if (++sort_var.command && t.first > t.second && t.first > t.third \
	&& t.first > t.four && t.first > t.five)
		sort_five_command_lower(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.second > t.first && t.second > t.third \
	&& t.second > t.four && t.second > t.five)
		sort_five_command_lower(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.third > t.first && t.third > t.second \
	&& t.third > t.four && t.third > t.five)
		sort_five_command_lower(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command && t.four > t.first && t.four > t.second \
	&& t.four > t.third && t.four > t.five)
		sort_five_command_lower_2(stack_a, stack_b, stack_command, sort_var);
	else if (++sort_var.command)
		sort_five_command_lower_2(stack_a, stack_b, stack_command, sort_var);
}
