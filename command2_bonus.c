/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:27:26 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 20:27:28 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

void	reverse_rotate_stack(t_dlist *stack_a)
{
	if (stack_a == NULL || stack_a->size <= 1)
		return ;
	add_first_node(stack_a, stack_a->head->prev->value);
	delete_last_node(stack_a);
}

void	reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	if (!(stack_a == NULL || stack_a->size <= 1))
		reverse_rotate_stack(stack_a);
	if (!(stack_b == NULL || stack_b->size <= 1))
		reverse_rotate_stack(stack_b);
}
