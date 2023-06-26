/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:10:59 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 18:11:00 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_div(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	int	i;

	i = -1;
	init_pivot(stack_a, sort_var->size, sort_var);
	while (++i < sort_var->size)
		stack_div_command1(stack_a, stack_b, stack_command, sort_var);
}

void	stack_div_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	if (sort_var->upper % 2 == 1 && stack_a->head->value \
	< sort_var->first_pivot)
	{
		push_stack(stack_b, stack_a, stack_command, \
			(sort_var->flag % 2) + 1);
		sort_var->next_up_cnt++;
	}
	else if (sort_var->upper % 2 == 1 && stack_a->head->value \
	< sort_var->second_pivot)
	{
		push_stack(stack_b, stack_a, stack_command, \
			(sort_var->flag % 2) + 1);
		rotate_stack(stack_b, stack_command, (sort_var->flag % 2) + 1);
		sort_var->next_down_cnt++;
	}
	else
		stack_div_command2(stack_a, stack_b, stack_command, sort_var);
}

void	stack_div_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	if (sort_var->upper % 2 == 0 && \
		stack_a->head->value >= sort_var->second_pivot)
	{
		push_stack(stack_b, stack_a, stack_command, \
			(sort_var->flag % 2) + 1);
		sort_var->next_up_cnt++;
	}
	else if (sort_var->upper % 2 == 0 && stack_a->head->value \
	>= sort_var->first_pivot)
	{
		push_stack(stack_b, stack_a, stack_command, \
			(sort_var->flag % 2) + 1);
		rotate_stack(stack_b, stack_command, \
			(sort_var->flag % 2) + 1);
		sort_var->next_down_cnt++;
	}
	else
	{
		rotate_stack(stack_a, stack_command, sort_var->flag);
		sort_var->current_up_cnt++;
	}
}

void	stack_restore(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	if (sort_var->command == 1)
	{
		while (sort_var->upper != 1 && \
		sort_var->current_up_cnt - sort_var->rrr_cnt > 0)
		{
			reverse_rotate_stack(stack_a, stack_command, sort_var->flag);
			sort_var->current_up_cnt--;
		}
	}
	else if (sort_var->command == 2)
	{
		while (sort_var->next_up_cnt + sort_var->next_down_cnt != 0)
		{
			push_stack(stack_a, stack_b, stack_command, sort_var->flag);
			if (sort_var->next_up_cnt != 0)
				sort_var->next_up_cnt--;
			else if (sort_var->next_down_cnt != 0)
				sort_var->next_down_cnt--;
		}
	}
}

void	stack_rrr(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	sort_var->rrr_cnt = 0;
	while (sort_var->upper != 1 && \
	sort_var->current_up_cnt > sort_var->rrr_cnt && \
	sort_var->next_down_cnt > sort_var->rrr_cnt)
	{
		reverse_rotate_stack_all(stack_a, stack_b, stack_command);
		sort_var->rrr_cnt++;
	}
}
