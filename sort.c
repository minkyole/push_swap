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

void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, int size, int upper)
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
		// ft_printf("-----sort_a하는중-----\n");
		// ft_printf("-----stack_a sort전-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort전-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d--------\n", size);
		if (upper % 2 == 1)
			sort_two_size(stack_a, 1);
		else if (upper % 2 == 0)
			sort_two_size(stack_a, 3);
		// ft_printf("-----stack_a sort후-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort후-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d upper %d--------\n", size, upper);
		return ;
	}
	else if (size == 3)
	{
		if (stack_a->size == 3 && upper % 2 == 1)
			sort_three_size_upper(stack_a, 1);
		else if (stack_a->size == 3 && upper % 2 == 0)
			sort_three_size_lower(stack_a, 1);
		else if (upper % 2 == 1)
			quick_sort_three_size_upper(stack_a, stack_b, 1);
		else if (upper % 2 == 0)
			quick_sort_three_size_lower(stack_a, stack_b, 1);
		return ;
	}
	/*
	else if (size == 4)
	{
		// ft_printf("-----sort_a하는중-----\n");
		// ft_printf("-----stack_a sort전-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort전-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d--------\n", size);
		if (stack_a->size == 4 && upper % 2 == 1)
			sort_four_size_upper(stack_a, 1);
		else if (stack_a->size == 4 && upper % 2 == 0)
			sort_four_size_lower(stack_a, 1);
		if (upper % 2 == 1)
			quick_sort_four_size_upper(stack_a, stack_b, 1);
		else if (upper % 2 == 0)
			quick_sort_four_size_lower(stack_a, stack_b, 1);
		// ft_printf("-----stack_a sort후-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort후-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d upper %d--------\n", size, upper);
		return ;
	}
	*/
	
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	// ft_printf("-----size %d upper %d-------\n", size, upper);
	mid = init_mid(stack_a, size);

	while (i < size)
	{
		if (upper % 2 == 1 && stack_a->head->value <= mid)
		{
			push_stack(stack_b, stack_a, 2);
			push_cnt++;
		}
		else if (upper % 2 == 0 && stack_a->head->value >= mid)
		{
			push_stack(stack_b, stack_a, 2);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_a, 1);
			rotate_cnt++;
		}
		i++;
	}
	while (upper != 1 && rotate_cnt != 0)
	{
		reverse_rotate_stack(stack_a, 1);
		rotate_cnt--;
	}
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	// ft_printf("-----rotate_cnt %d-----\n", rotate_cnt);
	quick_sort_a(stack_a, stack_b, size - push_cnt, upper);
	quick_sort_b(stack_a, stack_b, push_cnt, upper + 1);
	// ft_printf("-----rotate_cnt %d flag %d-----\n", rotate_cnt, flag);
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	while (push_cnt != 0)
	{
		// ft_printf("push stackb -> stack_a 하는중\n");
		push_stack(stack_a, stack_b, 1);
		push_cnt--;
	}
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
}

void quick_sort_b(t_dlist *stack_a, t_dlist *stack_b, int size, int upper)
{
	int mid;
	int i;
	int push_cnt;
	int	rotate_cnt;

	i = 0;
	push_cnt = 0;
	rotate_cnt = 0;
	if (size <= 1)
		return ;

	else if (size == 2)
	{
		// ft_printf("-----sort_b하는중-----\n");
		// ft_printf("-----stack_a sort전-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort전-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d--------\n", size);
		if (upper % 2 == 1)
			sort_two_size(stack_b, 2);
		else if (upper % 2 == 0)
			sort_two_size(stack_b, 4);
		// ft_printf("-----stack_a sort후-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort후-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d upper %d--------\n", size, upper);
		return ;
	}
	else if (size == 3)
	{
		if (stack_b->size == 3 && upper % 2 == 1)
			sort_three_size_upper(stack_b, 2);
		else if (stack_b->size == 3 && upper % 2 == 0)
			sort_three_size_lower(stack_b, 2);
		else if (upper % 2 == 1)
			quick_sort_three_size_upper(stack_b, stack_a, 2);
		else if (upper % 2 == 0)
			quick_sort_three_size_lower(stack_b, stack_a, 2);
		return ;
	}
	/*
	else if (size == 4)
	{
		// ft_printf("-----sort_b하는중-----\n");
		// ft_printf("-----stack_a sort전-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort전-----\n");
		// dlist_print(stack_b);
		// ft_printf("-----size %d--------\n", size);
		if (stack_b->size == 4 && upper % 2 == 1)
			sort_four_size_upper(stack_b, 2);
		else if (stack_b->size == 4 && upper % 2 == 0)
			sort_four_size_lower(stack_b, 2);
		else if (upper % 2 == 1)
			quick_sort_four_size_upper(stack_b, stack_a, 2);
		else if (upper % 2 == 0)
			quick_sort_four_size_lower(stack_b, stack_a, 2);
		// ft_printf("-----size %d upper %d--------\n", size, upper);
		// ft_printf("-----stack_a sort후-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b sort후-----\n");
		// dlist_print(stack_b);
		return ;
	}*/

	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	// ft_printf("-----size %d upper %d-------\n", size, upper);
	mid = init_mid(stack_b, size);

	while (i < size)
	{
		if (upper % 2 == 1 && stack_b->head->value <= mid)
		{
			push_stack(stack_a, stack_b, 1);
			push_cnt++;
		}
		else if (upper % 2 == 0 && stack_b->head->value >= mid)
		{
			push_stack(stack_a, stack_b, 1);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_b, 2);
			rotate_cnt++;
		}
		i++;
	}
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	while (rotate_cnt != 0)
	{
		reverse_rotate_stack(stack_b, 2);
		rotate_cnt--;
	}
	quick_sort_a(stack_a, stack_b, push_cnt, upper + 1);
	quick_sort_b(stack_a, stack_b, size - push_cnt, upper);
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
	while (push_cnt != 0)
	{
		// ft_printf("push stackA -> stack_b 하는중\n");
		push_stack(stack_b, stack_a, 2);
		push_cnt--;
	}
	// ft_printf("-----stack_a-----\n");
	// dlist_print(stack_a);
	// ft_printf("-----stack_b-----\n");
	// dlist_print(stack_b);
}

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	int	first;

	first = 1;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a, 1);
	else if (stack_a->size == 3)
		sort_three_size_upper(stack_a, 1);
	else if (stack_a->size == 4)
	{
		sort_four_size_upper(stack_a, 1);
	}
	else
	{
		quick_sort_a(stack_a, stack_b, stack_a->size, 1);
		// ft_printf("-----stack_a-----\n");
		// dlist_print(stack_a);
		// ft_printf("-----stack_b-----\n");
		// dlist_print(stack_b);
	}
}

void	sort_two_size(t_dlist *stack_a, int flag)
{
	if (flag == 1)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, 1);
	}
	else if (flag == 2)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, 2);
	}
	else if (flag == 3)
	{
		if (stack_a->head->value < stack_a->head->next->value)
			swap_stack(stack_a, 1);
	}
	else if (flag == 4)
	{
		if (stack_a->head->value < stack_a->head->next->value)
			swap_stack(stack_a, 2);
	}
}

void	sort_three_size_upper(t_dlist *stack_a, int flag)
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
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
	}
	else if (first > second && second < third && first < third)
		swap_stack(stack_a, flag);
	else if (first < second && second > third && first > third)
		reverse_rotate_stack(stack_a, flag);
	else if (first > second && second < third && first > third)
		rotate_stack(stack_a, flag);
	else if (first > second && second > third)
	{
		swap_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
}

void	sort_three_size_lower(t_dlist *stack_a, int flag)
{
	int first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first > second && second > third)
		return ;
	else if (first < second && second > third && first < third)
		rotate_stack(stack_a, flag);
	else if (first > second && second < third && first < third)
		reverse_rotate_stack(stack_a, flag);
	else if (first < second && second > third && first > third)
		swap_stack(stack_a, flag);
	else if (first > second && second < third && first > third)
	{
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
	}
	else if (first < second && second < third)
	{
		swap_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
}

void	quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, int flag)
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
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
	}
	else if (first > second && second < third && first < third)
		swap_stack(stack_a, flag);
	else if (first < second && second > third && first > third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
	}
	else if (first > second && second < third && first > third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
	else if (first > second && second > third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
}

void	quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, int flag)
{
	int first;
	int second;
	int third;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	if (first > second && second > third)
		return ;
	else if (first < second && second > third && first < third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
	else if (first > second && second < third && first < third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
	}
	else if (first < second && second > third && first > third)
		swap_stack(stack_a, flag);
	else if (first > second && second < third && first > third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
	}
	else if (first < second && second < third)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
	}
}

void	sort_four_size_upper(t_dlist *stack_a, int flag)
{
	int first;
	int second;
	int third;
	int four;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;

	if (first < second && second < third && third < four)
		return ;
	else if (four > first && four > second && four > third)
		sort_three_size_upper(stack_a, flag);
	else if (third > first && third > second && third > four)
	{
		reverse_rotate_stack(stack_a, flag);
		sort_three_size_upper(stack_a, flag);
	}
	else if (second > first && second > third && second > four)
	{
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		sort_three_size_upper(stack_a, flag);
	}
	else
	{
		rotate_stack(stack_a, flag);
		sort_three_size_upper(stack_a, flag);
	}
}

void	sort_four_size_lower(t_dlist *stack_a, int flag)
{
	int first;
	int second;
	int third;
	int four;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;

	if (first > second && second > third && third > four)
		return ;
	else if (first < second && first < third && first < four)
	{
		rotate_stack(stack_a, flag);
		sort_three_size_lower(stack_a, flag);
	}
	else if (second < first && second < third && second < four)
	{
		swap_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		sort_three_size_lower(stack_a, flag);
	}
	else if (third < first && third < second && third < four)
	{
		reverse_rotate_stack(stack_a, flag);
		sort_three_size_lower(stack_a, flag);
	}
	else
		sort_three_size_lower(stack_a, flag);
}

void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, int flag)
{
	int first;
	int second;
	int third;
	int four;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;

	if (first < second && second < third && third < four)
		return ;
	else if (four > first && four > second && four > third)
		quick_sort_three_size_upper(stack_a, stack_b, flag);
	else if (third > first && third > second && third > four)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		quick_sort_three_size_upper(stack_a, stack_b, flag);
	}
	else if (second > first && second > third && second > four)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		quick_sort_three_size_upper(stack_a, stack_b, flag);
	}
	else
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		swap_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
		quick_sort_three_size_upper(stack_a, stack_b, flag);
	}
}

void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, int flag)
{
	int first;
	int second;
	int third;
	int four;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;

	if (first > second && second > third && third > four)
		return ;
	else if (first < second && first < third && first < four)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		rotate_stack(stack_a, flag);
		rotate_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		swap_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
		reverse_rotate_stack(stack_a, flag);
		quick_sort_three_size_lower(stack_a, stack_b, flag);
	}
	else if (second < first && second < third && second < four)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		quick_sort_three_size_lower(stack_a, stack_b, flag);
	}
	else if (third < first && third < second && third < four)
	{
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		push_stack(stack_b, stack_a, (flag % 2) + 1);
		swap_stack(stack_a, flag);
		push_stack(stack_a, stack_b, flag);
		push_stack(stack_a, stack_b, flag);
		quick_sort_three_size_lower(stack_a, stack_b, flag);
	}
	else
		quick_sort_three_size_lower(stack_a, stack_b, flag);
}

// void	sort_four_size_lower(t_dlist *stack_a, int flag)
// {
// 	int first;
// 	int second;
// 	int third;
// 	int four;

// 	first = stack_a->head->value;
// 	second = stack_a->head->next->value;
// 	third = stack_a->head->next->next->value;
// 	four = stack_a->head->next->next->next->value;


// }

/////////////////////////////////////////////////////
/*
void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, int size, int upper)
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
		if (upper % 2 == 1)
			sort_two_size(stack_a, 1);
		else if (upper % 2 == 0)
			sort_two_size(stack_a, 3);
		return ;
	}
	else if (size == 3)
	{
		if (stack_a->size == 3 && upper % 2 == 1)
			sort_three_size_upper(stack_a, 1);
		else if (stack_a->size == 3 && upper % 2 == 0)
			sort_three_size_lower(stack_a, 1);
		else if (upper % 2 == 1)
			quick_sort_three_size_upper(stack_a, stack_b, 1);
		else if (upper % 2 == 0)
			quick_sort_three_size_lower(stack_a, stack_b, 1);
		return ;
	}
	mid = init_mid(stack_a, size);

	while (i < size)
	{
		if (upper % 2 == 1 && stack_a->head->value <= mid)
		{
			push_stack(stack_b, stack_a, 2);
			push_cnt++;
		}
		else if (upper % 2 == 0 && stack_a->head->value >= mid)
		{
			push_stack(stack_b, stack_a, 2);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_a, 1);
			rotate_cnt++;
		}
		i++;
	}
	if (upper != 1)
	{
		while (rotate_cnt != 0)
		{
			reverse_rotate_stack(stack_a, 1);
			rotate_cnt--;
		}
	}
	quick_sort_a(stack_a, stack_b, size - push_cnt, upper);
	quick_sort_b(stack_a, stack_b, push_cnt, upper + 1);
	while (push_cnt != 0)
	{
		push_stack(stack_a, stack_b, 1);
		push_cnt--;
	}
}

void quick_sort_b(t_dlist *stack_a, t_dlist *stack_b, int size, int upper)
{
	int mid;
	int i;
	int push_cnt;
	int	rotate_cnt;

	i = 0;
	push_cnt = 0;
	rotate_cnt = 0;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if (upper % 2 == 1)
			sort_two_size(stack_b, 2);
		else if (upper % 2 == 0)
			sort_two_size(stack_b, 4);
		return ;
	}
	else if (size == 3)
	{
		if (stack_b->size == 3 && upper % 2 == 1)
			sort_three_size_upper(stack_b, 2);
		else if (stack_b->size == 3 && upper % 2 == 0)
			sort_three_size_lower(stack_b, 2);
		else if (upper % 2 == 1)
			quick_sort_three_size_upper(stack_b, stack_a, 2);
		else if (upper % 2 == 0)
			quick_sort_three_size_lower(stack_b, stack_a, 2);
		return ;
	}
	mid = init_mid(stack_b, size);

	while (i < size)
	{
		if (upper % 2 == 1 && stack_b->head->value <= mid)
		{
			push_stack(stack_a, stack_b, 1);
			push_cnt++;
		}
		else if (upper % 2 == 0 && stack_b->head->value >= mid)
		{
			push_stack(stack_a, stack_b, 1);
			push_cnt++;
		}
		else
		{
			rotate_stack(stack_b, 2);
			rotate_cnt++;
		}
		i++;
	}
	while (rotate_cnt != 0)
	{
		reverse_rotate_stack(stack_b, 2);
		rotate_cnt--;
	}
	quick_sort_a(stack_a, stack_b, push_cnt, upper + 1);
	quick_sort_b(stack_a, stack_b, size - push_cnt, upper);
	while (push_cnt != 0)
	{
		push_stack(stack_b, stack_a, 2);
		push_cnt--;
	}
}
*/