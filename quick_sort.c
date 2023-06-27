/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:13:05 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 15:13:06 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	quick_sort_a_first(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist \
*stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, 1);
	if (quick_sort_size_check(stack_a, stack_b, stack_command, sort_var))
		return ;
	stack_div_first(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.current_up_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_b_push_a(stack_a, stack_b, stack_command, next_sort_var);
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_b_push_a(stack_a, stack_b, stack_command, next_sort_var);
}

void	quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist \
*stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, 1);
	if (quick_sort_size_check(stack_a, stack_b, stack_command, sort_var))
		return ;
	stack_div_a(stack_a, stack_b, stack_command, &sort_var);
	stack_rrr(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.current_up_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_b_push_a(stack_a, stack_b, stack_command, next_sort_var);
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_b_push_a(stack_a, stack_b, stack_command, next_sort_var);
}

void	quick_sort_b_push_a(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, 2);
	if (quick_sort_size_check(stack_b, stack_a, stack_command, sort_var))
		return ;
	stack_div_b(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	stack_rrr(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	next_sort_var.size = sort_var.current_up_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_b_push_a(stack_a, stack_b, stack_command, next_sort_var);
}
