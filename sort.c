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

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a);
	else if (stack_a->size == 3)
		sort_three_size(stack_a);
	else
		;
	(void)stack_b;
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
