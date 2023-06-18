/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:26:56 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 17:26:57 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	quick_sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, t_sort_element sort_element)
{
	int first;
	int second;
	int third;
	int four;
	int five;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;
	five = stack_a->head->next->next->next->next->value;

	if (first < second && second < third && third < four && four < five)
		return ;
	else if (five > first && five > second && five > third && five > four)
		quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_element);
	else if (four > first && four > second && four > third && four > five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_element);
	}
	else if (third > first && third > second && third > four && third > five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_element);
	}
	else if (second > first && second > third && second > four && second > five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_element);
	}
	else if (first > second && first > third && first > four && first > five)
	{
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_upper(stack_a, stack_b, stack_command, sort_element);
	}
	else
		ft_printf("test1 %d %d %d %d %d\n", first, second, third, four, five);
}

void	quick_sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b ,t_command_dlist *stack_command, t_sort_element sort_element)
{
	int first;
	int second;
	int third;
	int four;
	int	five;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;
	five = stack_a->head->next->next->next->next->value;

	if (first > second && second > third && third > four && four > five)
		return ;
	else if (five < first && five < second && five < third && five < four)
		quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_element);
	else if (four < first && four < second && four < third && four < five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_element);
	}
	else if (third < first && third < second && third < four && third < five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_element);
	}
	else if (second < first && second < third && second < four && second < five)
	{
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_element);
	}
	else if (first < second && first < third && first < four && first < five)
	{
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_b, stack_a, stack_command, (sort_element.flag % 2) + 1);
		swap_stack(stack_a, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		push_stack(stack_a, stack_b, stack_command, sort_element.flag);
		quick_sort_four_size_lower(stack_a, stack_b, stack_command, sort_element);
	}
	else
		ft_printf("test %d %d %d %d %d\n", first, second, third, four, five);
}

void	sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
{
	int first;
	int second;
	int third;
	int four;
	int five;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;
	five = stack_a->head->next->next->next->next->value;

	if (first < second && second < third && third < four && four < five)
		return ;
	else if (five < first && five < second && five < third && five < four)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (four < first && four < second && four < third && four < five)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (third < first && third < second && third < four && third < five)
	{
		rotate_stack(stack_a, stack_command, flag);
		rotate_stack(stack_a, stack_command, flag);	
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (second < first && second < third && second < four && second < five)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_upper(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}

void	sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag)
{
	int first;
	int second;
	int third;
	int four;
	int five;

	first = stack_a->head->value;
	second = stack_a->head->next->value;
	third = stack_a->head->next->next->value;
	four = stack_a->head->next->next->next->value;
	five = stack_a->head->next->next->next->next->value;
	if (first > second && second > third && third > four && four > five)
		return ;
	else if (first > second && first > third && first > four && first > five)
	{
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (second > first && second > third && second > four && second > five)
	{
		swap_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (third > first && third > second && third > four && third > five)
	{
		rotate_stack(stack_a, stack_command, flag);
		rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else if (four > first && four > second && four > third && four > five)
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
	else
	{
		reverse_rotate_stack(stack_a, stack_command, flag);
		push_stack(stack_b, stack_a, stack_command, (flag % 2) + 1);
		sort_four_size_lower(stack_a, stack_b, stack_command, flag);
		push_stack(stack_a, stack_b, stack_command, flag);
	}
}
