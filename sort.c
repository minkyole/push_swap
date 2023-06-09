/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:32:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/05 20:32:12 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void mid_quick_sort(int *temp_stack, int left, int right)
{
	int low;
	int high;
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

int init_mid(t_dlist *stack_a)
{
	t_node *temp_node;
	int *temp_stack;
	int	idx;

	idx = 0;
	temp_node = stack_a->head;
	temp_stack = malloc(sizeof(int) * stack_a->size);
	while (idx < stack_a->size)
	{
		temp_stack[idx] = temp_node->value;
		temp_node = temp_node->next;
		idx++;
	}
	for (int i = 0; i < idx; i++)
		ft_printf("%d ", temp_stack[i]);
	ft_printf("\n");
	mid_quick_sort(temp_stack, 0, idx - 1);
	for (int i = 0; i < idx; i++)
		ft_printf("%d ", temp_stack[i]);
	ft_printf("\n");
	ft_printf("%d\n", temp_stack[idx / 2]);
	return (temp_stack[idx / 2]);
}

void quick_sort(t_dlist *stack_a, t_dlist *stack_b)
{
	int mid;
	int i;
	int	size_temp;

	i = 0;
	size_temp = stack_a->size;
	mid = init_mid(stack_a);

	while (i < size_temp)
	{
		ft_printf("-----stack_a-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b-----\n");
		dlist_print(stack_b);
		ft_printf("stack_a head value %d\n", stack_a->head->value);
		if (stack_a->head->value <= mid)
			push_stack(stack_b, stack_a, 2);
		else
			rotate_stack(stack_a, 1);
		i++;
		
	}
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
	ft_printf("%d\n", size_temp);

}

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a);
	else if (stack_a->size == 3)
		sort_three_size(stack_a);
	else
		quick_sort(stack_a, stack_b);
}

void	sort_two_size(t_dlist *stack_a)
{
	if (stack_a->head->value > stack_a->head->prev->value)
		swap_stack(stack_a, 1);
	else
		;
}

void	sort_three_size(t_dlist *stack_a)
{
	int first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->prev->value;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		swap_stack(stack_a, 1);
		rotate_stack(stack_a, 1);
	}
	else if (first > second && second < third && first < third)
		swap_stack(stack_a, 1);
	else if (first < second && second > third && first > third)
		reverse_rotate_stack(stack_a, 1);
	else if (first > second && second < third && first > third)
		rotate_stack(stack_a, 1);
	else if (first > second && second > third)
	{
		swap_stack(stack_a, 1);
		reverse_rotate_stack(stack_a, 1);
	}
	else
		ft_printf("swap error\n");
}
