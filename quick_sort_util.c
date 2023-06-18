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

int	quick_sort_size_check(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper, int flag)
{
	if (size <= 1)
		return (1);
	else if (size == 2)
	{
		if (upper % 2 == 1)
			sort_two_size(stack_a, stack_command, flag);
		else if (upper % 2 == 0)
			sort_two_size(stack_a, stack_command, flag + 2);
		return (1);
	}
	else if (size == 3)
	{
		if (stack_a->size == 3 && upper % 2 == 1)
			sort_three_size_upper(stack_a, stack_command, flag);
		else if (stack_a->size == 3 && upper % 2 == 0)
			sort_three_size_lower(stack_a, stack_command, flag);
		else if (upper % 2 == 1)
			quick_sort_three_size_upper(stack_a, stack_b, stack_command, flag);
		else if (upper % 2 == 0)
			quick_sort_three_size_lower(stack_a, stack_b, stack_command, flag);
		return (1);
	}
	else if (size == 4)
	{
		if (stack_a->size == 4 && upper % 2 == 1)
			sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		else if (stack_a->size == 4 && upper % 2 == 0)
			sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		else if (upper % 2 == 1)
			quick_sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		else if (upper % 2 == 0)
			quick_sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		return (1);
	}
	else if (size == 5)
	{
		if (stack_a->size == 5 && upper % 2 == 1)
			sort_five_size_upper(stack_a, stack_b, stack_command, flag);
		else if (stack_a->size == 5 && upper % 2 == 0)
			sort_five_size_lower(stack_a, stack_b, stack_command, flag);
		else if (upper % 2 == 1)
			quick_sort_five_size_upper(stack_a, stack_b, stack_command, flag);
		else if (upper % 2 == 0)
			quick_sort_five_size_lower(stack_a, stack_b, stack_command, flag);
		return (1);
	}
	return (0);
}

void	stack_div(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper,\
int *sort_b_up_cnt, int *sort_b_down_cnt, int *sort_a_up_cnt, int flag)
{
	int first_pivot;
	int second_pivot;
	int i;

	i = 0;
	init_pivot(stack_a, size, &first_pivot, &second_pivot);
	while (i < size)
	{
		if (upper % 2 == 1 && stack_a->head->value < first_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, flag);
			*sort_b_up_cnt += 1;
		}
		else if (upper % 2 == 1 && stack_a->head->value < second_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, flag);
			rotate_stack(stack_b, stack_command, flag);
			*sort_b_down_cnt += 1;
		}
		else if (upper % 2 == 0 && stack_a->head->value >= second_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, flag);
			*sort_b_up_cnt += 1;
		}
		else if (upper % 2 == 0 && stack_a->head->value >= first_pivot)
		{
			push_stack(stack_b, stack_a, stack_command, flag);
			rotate_stack(stack_b, stack_command, flag);
			*sort_b_down_cnt += 1;
		}
		else
		{
			if (flag == 2)
				rotate_stack(stack_a, stack_command, 1);
			else if (flag == 1)
				rotate_stack(stack_a, stack_command, 2);
			*sort_a_up_cnt += 1;
		}
		i++;
	}
}

void	stack_restore(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int upper,\
int sort_b_up_cnt, int sort_b_down_cnt, int sort_a_up_cnt, int flag, int command)
{
	if (flag == 1)
	{
		while (upper != 1 && sort_a_up_cnt != 0)
		{
			reverse_rotate_stack(stack_a, stack_command, command);
			sort_a_up_cnt--;
		}
	}
	else if (flag == 2)
	{
		while (sort_b_up_cnt + sort_b_down_cnt != 0)
		{
			push_stack(stack_a, stack_b, stack_command, command);
			if (sort_b_up_cnt != 0)
				sort_b_up_cnt--;
			else if (sort_b_down_cnt != 0)
				sort_b_down_cnt--;
		}
	}
}
