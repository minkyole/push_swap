/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:28:30 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 20:28:31 by minkyole         ###   ########.fr       */
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
