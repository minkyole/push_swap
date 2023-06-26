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

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command)
{
	t_sort_var	sort_var;

	sort_var.upper = 1;
	sort_var.size = stack_a->size;
	sort_var.flag = 1;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
		sort_two_size(stack_a, stack_command, 1);
	else if (stack_a->size == 3)
		sort_three_size_upper(stack_a, stack_command, 1);
	else if (stack_a->size == 4)
		sort_four_size_upper(stack_a, stack_b, stack_command, 1);
	else if (stack_a->size == 5)
		sort_five_size_upper(stack_a, stack_b, stack_command, sort_var);
	else
		quick_sort_a(stack_a, stack_b, stack_command, sort_var);
}

void	quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist \
*stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, &next_sort_var, 1);
	if (quick_sort_size_check(stack_a, stack_b, stack_command, sort_var))
		return ;
	stack_div(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_b_up(stack_a, stack_b, stack_command, next_sort_var);
	stack_rrr(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.rrr_cnt = sort_var.rrr_cnt;
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_b_down(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 1;
	stack_restore(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.size - \
	sort_var.next_up_cnt - sort_var.next_down_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 2;
	stack_restore(stack_a, stack_b, stack_command, &sort_var);
}

void	quick_sort_b_up(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, &next_sort_var, 2);
	if (quick_sort_size_check(stack_b, stack_a, stack_command, sort_var))
		return ;
	stack_div(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	stack_rrr(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.rrr_cnt = sort_var.rrr_cnt;
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_a_down(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 1;
	stack_restore(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.size - \
	sort_var.next_up_cnt - sort_var.next_down_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_b_up(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 2;
	stack_restore(stack_b, stack_a, stack_command, &sort_var);
}

void	quick_sort_b_down(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, &next_sort_var, 2);
	while (++next_sort_var.cnt < sort_var.size - sort_var.rrr_cnt)
		reverse_rotate_stack(stack_b, stack_command, 2);
	if (quick_sort_size_check(stack_b, stack_a, stack_command, sort_var))
		return ;
	sort_var.next_down_cnt = 0;
	stack_div(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	stack_rrr(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.rrr_cnt = sort_var.rrr_cnt;
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_a_down(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 1;
	stack_restore(stack_b, stack_a, stack_command, &sort_var);
	next_sort_var.size = sort_var.size - \
	sort_var.next_up_cnt - sort_var.next_down_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_b_up(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 2;
	stack_restore(stack_b, stack_a, stack_command, &sort_var);
}

void	quick_sort_a_down(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var)
{
	t_sort_var	next_sort_var;

	sort_var_init(&sort_var, &next_sort_var, 1);
	while (++next_sort_var.cnt < sort_var.size - sort_var.rrr_cnt)
		reverse_rotate_stack(stack_a, stack_command, 1);
	if (quick_sort_size_check(stack_a, stack_b, stack_command, sort_var))
		return ;
	stack_div(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.next_up_cnt;
	next_sort_var.upper = sort_var.upper + 1;
	quick_sort_b_up(stack_a, stack_b, stack_command, next_sort_var);
	stack_rrr(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.rrr_cnt = sort_var.rrr_cnt;
	next_sort_var.size = sort_var.next_down_cnt;
	quick_sort_b_down(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 1;
	stack_restore(stack_a, stack_b, stack_command, &sort_var);
	next_sort_var.size = sort_var.size - \
	sort_var.next_up_cnt - sort_var.next_down_cnt;
	next_sort_var.upper = sort_var.upper;
	quick_sort_a(stack_a, stack_b, stack_command, next_sort_var);
	sort_var.command = 2;
	stack_restore(stack_a, stack_b, stack_command, &sort_var);
}
