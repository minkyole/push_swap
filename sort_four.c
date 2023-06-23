/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:24:01 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 17:24:02 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
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
	else if (four < first && four < second && four < third)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (third < first && third < second && third < four)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);	
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (second < first && second < third && second < four)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_upper(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}

void	sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
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
	else if (first > second && first > third && first > four)
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (second > first && second > third && second > four)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (third > first && third > second && third > four)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_three_size_lower(stack_a, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}

void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);
	if (t.first < t.second && t.second < t.third && t.third < t.four) // 1 2 3 4
		return ;
	else if (t.four > t.first && t.four > t.second && t.four > t.third) // * * * 4
		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
	else
		quick_sort_four_size_upper_1(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b ,t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_five	t;

	four_init(&t, stack_a);

	if (t.first > t.second && t.second > t.third && t.third > t.four) // 4 3 2 1
		return ;
	else if (t.four < t.first && t.four < t.second && t.four < t.third) // * * * 1
		quick_sort_three_size_lower(stack_a, stack_b, stack_command, sort_var);
	else
		quick_sort_four_size_lower_1(stack_a, stack_b, stack_command, sort_var);
	else if (first < second && second < third && third < four) // 1 2 3 4
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (first < second && second < four && four < third) // 1 2 4 3
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (first < third && third < second && second < four) // 1 3 2 4
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (first < four && four < second && second < third)  // 1 3 4 2
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (first < third && third < four && four < second) // 1 4 2 3
	{
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (first < four && four < third && third < second) // 1 4 3 2
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (second < first && first < third && third < four) // 2 1 3 4
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (second < first && first < four && four < third) // 2 1 4 3
	{
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (third < first && first < second && second < four) // 2 3 1 4
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (third < first && first < four && four < second) // 2 4 1 3
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (second < third && third < first && first < four) // 3 1 2 4
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (second < four && four < first && first < third) // 3 1 4 2
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (third < second && second < first && first < four) // 3 2 1 4
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command,sort_var. flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
	}
	else if (third < four && four < first && first < second) // 3 4 1 2
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack_all(stack_a, stack_b, stack_command);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (second < third && third < four && four < first) // 4 1 2 3
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command,sort_var. flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (second < four && four < third && third < first) // 4 1 3 2
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (third < second && second < four && four < first) // 4 2 1 3
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else if (third < four && four < second && second < first) // 4 3 1 2
	{
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
	}
	else
		ft_printf("error %d %d %d %d flag %d\n", first, second, third, four, sort_var.flag);
}

// void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var)
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
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
// 	else if (third > first && third > second && third > four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
// 	}
// 	else if (second > first && second > third && second > four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
// 	}
// 	else
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		rotate_stack(stack_a, stack_command, sort_var.flag);
// 		rotate_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
// 		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
// 		quick_sort_three_size_upper(stack_a, stack_b, stack_command, sort_var);
// 	}
// }

// void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var)
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
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		rotate_stack(stack_a, stack_command, sort_var.flag);
// 		rotate_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
// 		reverse_rotate_stack(stack_a, stack_command, sort_var.flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, sort_var);
// 	}
// 	else if (second < first && second < third && second < four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, sort_var);
// 	}
// 	else if (third < first && third < second && third < four)
// 	{
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		push_stack(stack_b, stack_a, stack_command, (sort_var.flag % 2) + 1);
// 		swap_stack(stack_a, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		push_stack(stack_a, stack_b, stack_command, sort_var.flag);
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, sort_var);
// 	}
// 	else
// 		quick_sort_three_size_lower(stack_a, stack_b, stack_command, sort_var);
// }
