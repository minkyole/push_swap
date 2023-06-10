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

int init_mid(t_dlist *stack_a, int size)
{
	t_node *temp_node;
	int *temp_stack;
	int	idx;

	idx = 0;
	temp_node = stack_a->head;
	temp_stack = malloc(sizeof(int) * size);
	while (idx < size)
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
	ft_printf("%d\n", temp_stack[(idx - 1) / 2]);
	return (temp_stack[(idx - 1) / 2]);
}

void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, int *pivot_arr, int *pivot_idx)
{
	int mid;
	int i;
	int	size_temp;

	i = 0;
	size_temp = stack_a->size;
	mid = init_mid(stack_a, size_temp);
	pivot_arr[*pivot_idx] = mid;
	*pivot_idx += 1;
	ft_printf("size_temp %d i %d pivot_idx %d", size_temp, i, *pivot_idx);

	while (i < size_temp)
	{
		ft_printf("-----stack_a-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b-----\n");
		dlist_print(stack_b);
		ft_printf("stack_a head value %d, mid %d\n", stack_a->head->value, mid);
		ft_printf("size_temp %d i %d\n", size_temp, i);
		if (stack_a->head->value < mid)
			push_stack(stack_b, stack_a, 2);
		else if (stack_a->head->value == mid)
		{
			push_stack(stack_b, stack_a, 2);
			rotate_stack(stack_b, 2);
		}
		else
			rotate_stack(stack_a, 1);
		i++;
	}
	
	reverse_rotate_stack(stack_b, 2);
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);

}

int check_size(t_dlist *stack_b, int *pivot_arr, int pivot_idx)
{
	int i = 0;
	t_node *temp_node;

	temp_node = stack_b->head;
	ft_printf("pivot_idx %d pivot_arr %d\n", pivot_idx, pivot_arr[pivot_idx]);
	while (temp_node->value != pivot_arr[pivot_idx] && i < stack_b->size)
	{
		temp_node = temp_node->next;
		i++;
	}
	return (i);
}

void quick_sort_b(t_dlist *stack_a, t_dlist *stack_b, int *pivot_arr, int *pivot_idx)
{
	int mid;
	int i;
	int	size_temp;
	int	rotate_cnt;

	i = 0;
	rotate_cnt = 0;
	if (pivot_idx == 0)
		size_temp = stack_b->size;
	else
		size_temp = check_size(stack_b, pivot_arr, *pivot_idx);
	ft_printf("size_temp %d\n\n", size_temp);
	if (size_temp == 1)
	{
		*pivot_idx += 1;
		pivot_arr[*pivot_idx] = stack_b->head->value;
		*pivot_idx += 1;
		return ;
	}
	else if (size_temp == 2)
	{
		if (stack_b->head->value < stack_b->head->next->value)
			swap_stack(stack_b, 2);
		*pivot_idx += 1;
		pivot_arr[*pivot_idx] = stack_b->head->next->value;
		*pivot_idx += 1;	
		pivot_arr[*pivot_idx] = stack_b->head->value;
		return ;
	}
	ft_printf("pivot_idx %d size_temp %d\n", *pivot_idx, size_temp);
	mid = init_mid(stack_b, size_temp);
	if (*pivot_idx != 0)
		*pivot_idx += 1;
	pivot_arr[*pivot_idx] = mid;
	*pivot_idx += 1;

	while (i < size_temp)
	{
		ft_printf("-----stack_a-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b-----\n");
		dlist_print(stack_b);
		ft_printf("stack_b head value %d, mid %d\n", stack_b->head->value, mid);
		if (stack_b->head->value < mid)
			push_stack(stack_a, stack_b, 1);
		else if (stack_b->head->value == mid)
		{
			push_stack(stack_a, stack_b, 1);
			rotate_stack(stack_a, 1);
		}
		else
		{
			rotate_stack(stack_b, 2);
			rotate_cnt++;
		}
		i++;
	}
	reverse_rotate_stack(stack_a, 1);
	while (rotate_cnt != 0)
	{
		reverse_rotate_stack(stack_b, 2);
		rotate_cnt--;
	}
}

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	int *pivot_arr;
	int	pivot_idx;

	pivot_idx = 0;
	pivot_arr = malloc(sizeof(int) * stack_a->size);
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a);
	else if (stack_a->size == 3)
		sort_three_size(stack_a);
	else
	{
		while (stack_a->size != 1)
			quick_sort_a(stack_a, stack_b, pivot_arr, &pivot_idx);
		pivot_idx--;
		while (pivot_idx >= 0 && pivot_arr[pivot_idx] == stack_b->head->value)
		{
			push_stack(stack_a, stack_b, 1);
			pivot_idx--;
		}
		quick_sort_b(stack_a, stack_b, pivot_arr ,&pivot_idx);
		ft_printf("pivot_idx %d stack_a head value %d\n", pivot_arr[pivot_idx], stack_b->head->value);
		if (pivot_idx <= 0)
			pivot_idx--;
		while (pivot_idx >= 0 && pivot_arr[pivot_idx] == stack_b->head->value)
		{
			push_stack(stack_a, stack_b, 1);
			pivot_idx--;
		}
		ft_printf("-----stack_a-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b-----\n");
		dlist_print(stack_b);
	}
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
