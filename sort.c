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
	mid_quick_sort(temp_stack, 0, idx - 1);
	return (temp_stack[(idx - 1) / 2]);
}

void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, int *pivot_arr, int *pivot_idx, int size, int flag)
{
	int mid;
	int i;
	int push_cnt;
	int	rotate_cnt;

	i = 0;
	rotate_cnt = 0;
	push_cnt = 0;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		ft_printf("-----sort_a하는중-----\n");
		ft_printf("-----stack_a sort전-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b sort전-----\n");
		dlist_print(stack_b);
		ft_printf("-----size %d--------\n", size);
		sort_two_size(stack_a, 1);
		ft_printf("-----stack_a sort후-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b sort후-----\n");
		dlist_print(stack_b);
		ft_printf("-----size %d--------\n", size);
		return ;
	}
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
	ft_printf("-----size %d--------\n", size);
	mid = init_mid(stack_a, size);
	pivot_arr[*pivot_idx] = mid;
	*pivot_idx += 1;

	while (i < size)
	{
		if (stack_a->head->value < mid)
		{
			push_stack(stack_b, stack_a, 2);
			push_cnt++;
		}
		else if (stack_a->head->value == mid)
		{
			push_stack(stack_b, stack_a, 2);
			rotate_stack(stack_b, 2);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_a, 1);
			rotate_cnt++;
		}
		i++;
	}
	reverse_rotate_stack(stack_b, 2);
	quick_sort_a(stack_a, stack_b, pivot_arr, pivot_idx, size - push_cnt, 1);
	quick_sort_b(stack_a, stack_b, pivot_arr, pivot_idx, push_cnt);
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
	while (push_cnt != 0)
	{
		ft_printf("push stackb -> stack_a 하는중\n");
		push_stack(stack_a, stack_b, 1);
		push_cnt--;
	}
	while (rotate_cnt != 0 && flag == 2)
	{
		reverse_rotate_stack(stack_a, 1);
		rotate_cnt--;
	}
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
}

void quick_sort_b(t_dlist *stack_a, t_dlist *stack_b, int *pivot_arr, int *pivot_idx, int size)
{
	int mid;
	int i;
	int push_cnt;
	int	rotate_cnt;
	int rotate_flag;

	i = 0;
	push_cnt = 0;
	rotate_cnt = 0;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		ft_printf("-----sort_b하는중-----\n");
		ft_printf("-----stack_a sort전-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b sort전-----\n");
		dlist_print(stack_b);
		ft_printf("-----size %d--------\n", size);
		sort_two_size(stack_b, 2);
		ft_printf("-----stack_a sort후-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b sort후-----\n");
		dlist_print(stack_b);
		ft_printf("-----size %d--------\n", size);
		return ;
	}
	if (size == stack_b->size)
		rotate_flag = 1;
	else
		rotate_flag = 2;
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
	ft_printf("-----size %d--------\n", size);
	mid = init_mid(stack_b, size);
	pivot_arr[*pivot_idx] = mid;
	*pivot_idx += 1;

	while (i < size)
	{
		if (stack_b->head->value < mid)
		{
			push_stack(stack_a, stack_b, 1);
			push_cnt++;
		}
		else if (stack_b->head->value == mid)
		{
			push_stack(stack_a, stack_b, 1);
			rotate_stack(stack_a, 1);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_b, 2);
			rotate_cnt++;
		}
		i++;
	}
	reverse_rotate_stack(stack_a, 1);
//	ft_printf("--------quick_sort_b_재귀---------\n");
//	ft_printf("quick_sort_a, %d\n", push_cnt);
//	ft_printf("quick_sort_b, %d\n", size - push_cnt);
//	ft_printf("-------------------\n");
	quick_sort_a(stack_a, stack_b, pivot_arr, pivot_idx, push_cnt, 2);
	quick_sort_b(stack_a, stack_b, pivot_arr, pivot_idx, size - push_cnt);
	ft_printf("-----stack_a-----\n");
	dlist_print(stack_a);
	ft_printf("-----stack_b-----\n");
	dlist_print(stack_b);
	while (push_cnt != 0)
	{
		ft_printf("push stackA -> stack_b 하는중\n");
		push_stack(stack_b, stack_a, 2);
		push_cnt--;
	}
	while (rotate_flag == 2 && rotate_cnt != 0)
	{
		reverse_rotate_stack(stack_b, 2);
		rotate_cnt--;
	}
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

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	int *pivot_arr;
	int	pivot_idx;

	pivot_idx = 0;
	pivot_arr = malloc(sizeof(int) * stack_a->size);
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a, 1);
	else if (stack_a->size == 3)
		sort_three_size(stack_a);
	else
	{
		quick_sort_a(stack_a, stack_b, pivot_arr, &pivot_idx, stack_a->size, 1);
		ft_printf("-----stack_a-----\n");
		dlist_print(stack_a);
		ft_printf("-----stack_b-----\n");
		dlist_print(stack_b);
	}
}

void	sort_two_size(t_dlist *stack_a, int flag)
{
	if (flag == 1)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, 1);
	}
	else
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, 2);
	}
}

void	sort_three_size(t_dlist *stack_a)
{
	int first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
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
