/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:28:38 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 20:28:40 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	mid_quick_sort(int *temp_stack, int left, int right)
{
	int	low;
	int	high;
	int	pivot;

	if (left >= right)
		return ;
	low = left + 1;
	high = right;
	pivot = temp_stack[left];
	while (1)
	{
		while (temp_stack[low] < pivot && low <= right)
			low++;
		while (temp_stack[high] > pivot && high > left)
			high--;
		if (low >= high)
			break ;
		ft_swap(&temp_stack[low], &temp_stack[high]);
	}
	ft_swap(&temp_stack[left], &temp_stack[high]);
	mid_quick_sort(temp_stack, left, high);
	mid_quick_sort(temp_stack, high + 1, right);
}

void	init_pivot(t_dlist *stack_a, int size, t_sort_var *sort_var)
{
	t_node	*temp_node;
	int		*temp_stack;
	int		idx;

	idx = 0;
	temp_node = stack_a->head;
	temp_stack = malloc(sizeof(int) * size);
	if (temp_stack == NULL)
		error();
	while (idx < size)
	{
		temp_stack[idx] = temp_node->value;
		temp_node = temp_node->next;
		idx++;
	}
	mid_quick_sort(temp_stack, 0, idx - 1);
	sort_var->first_pivot = temp_stack[(idx / 3)];
	sort_var->second_pivot = temp_stack[(((idx / 3) * 2))];
	free(temp_stack);
}

void	sort_var_init(t_sort_var *sort_var, int flag)
{
	sort_var->current_up_cnt = 0;
	sort_var->next_up_cnt = 0;
	sort_var->next_down_cnt = 0;
	sort_var->flag = flag;
}
