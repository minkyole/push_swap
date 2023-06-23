/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:55:15 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/23 17:55:16 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
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
		sort_var.command = 1;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first > second && second < third && first < third)
	{
		sort_var.command = 2;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else
		quick_sort_three_size_upper2(stack_a, stack_b, \
		stack_command, sort_var);
}

void	quick_sort_three_size_upper2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first < second && second > third && first > third)
	{
		sort_var.command = 3;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first > second && second < third && first > third)
	{
		sort_var.command = 4;
		sort_three_command2(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first > second && second > third)
	{
		sort_var.command = 5;
		sort_three_command2(stack_a, stack_b, stack_command, sort_var);
	}
}

void	quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
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
	{
		sort_var.command = 4;
		sort_three_command2(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first > second && second < third && first < third)
	{
		sort_var.command = 3;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else
		quick_sort_three_size_lower2(stack_a, stack_b, \
		stack_command, sort_var);
}

void	quick_sort_three_size_lower2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first < second && second > third && first > third)
	{
		sort_var.command = 2;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first > second && second < third && first > third)
	{
		sort_var.command = 1;
		sort_three_command1(stack_a, stack_b, stack_command, sort_var);
	}
	else if (first < second && second < third)
	{
		sort_var.command = 5;
		sort_three_command2(stack_a, stack_b, stack_command, sort_var);
	}
}
