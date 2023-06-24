/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:24:01 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 17:24:02 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	four_init(t_five *t, t_dlist *stack_a)
{
	t->first = stack_a->head->value;
	t->second = stack_a->head->next->value;
	t->third = stack_a->head->next->next->value;
	t->four = stack_a->head->next->next->next->value;
}

void	sort_four_size_upper_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.second < t.first && t.second < t.third && t.second < t.four)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}

void	sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first < t.second && t.second < t.third && t.third < t.four)
		return ;
	else if (t.four < t.first && t.four < t.second && t.four < t.third)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (t.third < t.first && t.third < t.second && t.third < t.four)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
		sort_four_size_upper_2(stack_a, stack_b, stack_command, flag);
}

void	sort_four_size_lower_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.third > t.first && t.third > t.second && t.third > t.four)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}

void	sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first > t.second && t.second > t.third && t.third > t.four)
		return ;
	else if (t.first > t.second && t.first > t.third && t.first > t.four)
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (t.second > t.first && t.second > t.third && t.second > t.four)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
		sort_four_size_lower_2(stack_a, stack_b, stack_command, flag);
}
