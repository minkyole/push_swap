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
		quick_sort_a_first(stack_a, stack_b, stack_command, sort_var);
}
