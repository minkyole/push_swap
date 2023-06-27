/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_div.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:28:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 20:28:11 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_div_first(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	int	i;

	i = -1;
	init_pivot(stack_a, sort_var->size, sort_var);
	while (++i < sort_var->size)
	{
		if (stack_a->head->value < sort_var->first_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 2);
			rotate_stack(stack_b, stack_command, 2);
			sort_var->next_up_cnt++;
		}
		else if (stack_a->head->value < sort_var->second_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 2);
			sort_var->next_down_cnt++;
		}
		else
		{
			rotate_stack(stack_a, stack_command, 1);
			sort_var->current_up_cnt++;
		}
	}
}

void	stack_div_a(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	int	i;

	i = -1;
	init_pivot(stack_a, sort_var->size, sort_var);
	while (++i < sort_var->size)
	{
		if (stack_a->head->value < sort_var->first_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 2);
			sort_var->next_up_cnt++;
		}
		else if (stack_a->head->value < sort_var->second_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 2);
			rotate_stack(stack_b, stack_command, 2);
			sort_var->next_down_cnt++;
		}
		else
		{
			rotate_stack(stack_a, stack_command, 1);
			sort_var->current_up_cnt++;
		}
	}
}

void	stack_div_b(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	int	i;

	i = -1;
	init_pivot(stack_a, sort_var->size, sort_var);
	while (++i < sort_var->size)
	{
		if (stack_a->head->value >= sort_var->second_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			sort_var->next_up_cnt++;
		}
		else if (stack_a->head->value >= sort_var->first_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, 1);
			rotate_stack(stack_b, stack_command, 1);
			sort_var->next_down_cnt++;
		}
		else
		{
			rotate_stack(stack_a, stack_command, 2);
			sort_var->current_up_cnt++;
		}
	}
}
