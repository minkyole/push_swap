/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:59:10 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/18 16:59:14 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_two_size(t_dlist *stack_a, t_command_dlist \
*stack_command, int flag)
{
	if (flag == 1)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, stack_command, 1);
	}
	else if (flag == 2)
	{
		if (stack_a->head->value > stack_a->head->next->value)
			swap_stack(stack_a, stack_command, 2);
	}
	else if (flag == 3)
	{
		if (stack_a->head->value < stack_a->head->next->value)
			swap_stack(stack_a, stack_command, 1);
	}
	else if (flag == 4)
	{
		if (stack_a->head->value < stack_a->head->next->value)
			swap_stack(stack_a, stack_command, 2);
	}
}
