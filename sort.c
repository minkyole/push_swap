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

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command)
{
	int	first;

	first = 1;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a, stack_command, 1);
	else if (stack_a->size == 3)
		sort_three_size_upper(stack_a, stack_command, 1);
	else if (stack_a->size == 4)
		sort_four_size_upper(stack_a, stack_b, stack_command, 1);
	else if (stack_a->size == 5)
		sort_five_size_upper(stack_a, stack_b, stack_command, 1);
	else
	{
		quick_sort_a(stack_a, stack_b, stack_command, stack_a->size, 1);
	}
}

void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper)
{
	int sort_b_up_cnt;
	int sort_b_down_cnt;
	int	sort_a_up_cnt;

	sort_a_up_cnt = 0;
	sort_b_up_cnt = 0;
	sort_b_down_cnt = 0;
	
	if (quick_sort_size_check(stack_a, stack_b, stack_command, size, upper, 1))
		return ;
	stack_div(stack_a, stack_b, stack_command, size, upper, &sort_b_up_cnt, &sort_b_down_cnt, &sort_a_up_cnt, 2);
	stack_restore(stack_a, stack_b, stack_command, upper, sort_b_up_cnt, sort_b_down_cnt, sort_a_up_cnt, 1, 1);
	quick_sort_a(stack_a, stack_b, stack_command, size - sort_b_up_cnt - sort_b_down_cnt, upper);
	quick_sort_b_up(stack_a, stack_b, stack_command, sort_b_up_cnt, upper + 1);
	quick_sort_b_down(stack_a, stack_b, stack_command, sort_b_down_cnt, upper + 1);
	stack_restore(stack_a, stack_b, stack_command, upper, sort_b_up_cnt, sort_b_down_cnt, sort_a_up_cnt, 2 ,1);
}

void quick_sort_b_up(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper)
{
	int sort_b_up_cnt;
	int sort_a_down_cnt;
	int	sort_a_up_cnt;

	sort_a_up_cnt = 0;
	sort_a_down_cnt = 0;
	sort_b_up_cnt = 0;

	if (quick_sort_size_check(stack_b, stack_a, stack_command, size, upper, 2))
		return ;
	stack_div(stack_b, stack_a, stack_command, size, upper, &sort_a_up_cnt, &sort_a_down_cnt, &sort_b_up_cnt, 1);
	quick_sort_a(stack_a, stack_b, stack_command, sort_a_up_cnt, upper + 1);
	quick_sort_a_down(stack_a, stack_b, stack_command, sort_a_down_cnt, upper + 1);
	stack_restore(stack_b, stack_a, stack_command, upper, sort_a_up_cnt, sort_a_down_cnt, sort_b_up_cnt, 1, 2);
	quick_sort_b_up(stack_a, stack_b, stack_command, size - sort_a_up_cnt - sort_a_down_cnt, upper);
	stack_restore(stack_b, stack_a, stack_command, upper, sort_a_up_cnt, sort_a_down_cnt, sort_b_up_cnt, 2, 2);
}

void quick_sort_b_down(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper)
{
	int i;
	int sort_b_up_cnt;
	int sort_a_down_cnt;
	int	sort_a_up_cnt;

	i = 0;
	sort_a_up_cnt = 0;
	sort_a_down_cnt = 0;
	sort_b_up_cnt = 0;

	while (i < size)
	{
		reverse_rotate_stack(stack_b, stack_command, 2);
		i++;
	}
	i = 0;
	if (quick_sort_size_check(stack_b, stack_a, stack_command, size, upper, 2))
		return ;
	stack_div(stack_b, stack_a, stack_command, size, upper, &sort_a_up_cnt, &sort_a_down_cnt, &sort_b_up_cnt, 1);
	quick_sort_a(stack_a, stack_b, stack_command, sort_a_up_cnt, upper + 1);
	quick_sort_a_down(stack_a, stack_b, stack_command, sort_a_down_cnt, upper + 1);
	stack_restore(stack_b, stack_a, stack_command, upper, sort_a_up_cnt, sort_a_down_cnt, sort_b_up_cnt, 1, 2);
	quick_sort_b_up(stack_a, stack_b, stack_command, size - sort_a_up_cnt - sort_a_down_cnt, upper);
	stack_restore(stack_b, stack_a, stack_command, upper, sort_a_up_cnt, sort_a_down_cnt, sort_b_up_cnt, 2, 2);
}

void quick_sort_a_down(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper)
{
	int	i;
	int sort_b_up_cnt;
	int sort_b_down_cnt;
	int	sort_a_up_cnt;

	i = 0;
	sort_a_up_cnt = 0;
	sort_b_up_cnt = 0;
	sort_b_down_cnt = 0;
	while (i < size)
	{
		reverse_rotate_stack(stack_a, stack_command, 1);
		i++;
	}
	if (quick_sort_size_check(stack_a, stack_b, stack_command, size, upper, 1))
		return ;
	stack_div(stack_a, stack_b, stack_command, size, upper, &sort_b_up_cnt, &sort_b_down_cnt, &sort_a_up_cnt, 2);
	stack_restore(stack_a, stack_b, stack_command, upper, sort_b_up_cnt, sort_b_down_cnt, sort_a_up_cnt, 1, 1);
	quick_sort_a(stack_a, stack_b, stack_command, size - sort_b_up_cnt - sort_b_down_cnt, upper);
	quick_sort_b_up(stack_a, stack_b, stack_command, sort_b_up_cnt, upper + 1);
	quick_sort_b_down(stack_a, stack_b, stack_command, sort_b_down_cnt, upper + 1);
	stack_restore(stack_a, stack_b, stack_command, upper, sort_b_up_cnt, sort_b_down_cnt, sort_a_up_cnt, 2 ,1);
}

// void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
// {
// 	int first;
// 	int second;
// 	int third;
// 	int four;

// 	first = stack_a->head->value;
// 	second = stack_a->head->next->value;
// 	third = stack_a->head->next->next->value;
// 	four = stack_a->head->next->next->next->value;

// 	if (first < second && second < third && third < four)
// 		return ;
// 	else if (four > first && four > second && four > third)
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, flag);
// 	else if (third > first && third > second && third > four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, flag);
// 	}
// 	else if (second > first && second > third && second > four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, flag);
// 	}
// 	else
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		rotate_stack(stack_a, stack_command, flag);
// 		rotate_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		swap_stack(stack_a, stack_command, flag);
// 		reverse_rotate_stack(stack_a, stack_command, flag);
// 		reverse_rotate_stack(stack_a, stack_command, flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, flag);
// 	}
// }

// void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
// {
// 	int first;
// 	int second;
// 	int third;
// 	int four;

// 	first = stack_a->head->value;
// 	second = stack_a->head->next->value;
// 	third = stack_a->head->next->next->value;
// 	four = stack_a->head->next->next->next->value;

// 	if (first > second && second > third && third > four)
// 		return ;
// 	else if (first < second && first < third && first < four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		rotate_stack(stack_a, stack_command, flag);
// 		rotate_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		swap_stack(stack_a, stack_command, flag);
// 		reverse_rotate_stack(stack_a, stack_command, flag);
// 		reverse_rotate_stack(stack_a, stack_command, flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, flag);
// 	}
// 	else if (second < first && second < third && second < four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, flag);
// 	}
// 	else if (third < first && third < second && third < four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		push_stack(stack_a, stack_b, stack_command, flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, flag);
// 	}
// 	else
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, flag);
// }