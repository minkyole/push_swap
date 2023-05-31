/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:05:58 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:06:01 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap_stack(t_dlist	*dlist)
{
	t_node	*temp_node;

	if (dlist->size <= 1)
		return ;
	temp_node = dlist->head->next;
	temp_node->prev = dlist->head->prev;
	dlist->head->next = dlist->head->next->next;
	dlist->head->prev = temp_node;
	temp_node->next = dlist->head;
	dlist->head = temp_node;
	ft_printf("swap\n");
}

void	swap_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("swap\n");
}

void	push_stack(t_dlist *stack_a, t_dlist *stack_b)
{
	if (stack_b->size == 0)
		return ;
	add_first_node(stack_a, stack_b->head->value);
	delete_first_node(stack_b);
	ft_printf("push\n");
}

void	rotate_stack(t_dlist *stack_a)
{
	if (!(stack_a == NULL || stack_a->size <= 1))
	{
		add_last_node(stack_a, stack_a->head->value);
		delete_first_node(stack_a);
		ft_printf("rotate\n");
	}
}

void	rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	if (!(stack_a == NULL || stack_a->size <= 1))
		rotate_stack(stack_a);
	if (!(stack_b == NULL || stack_b->size <= 1))
		rotate_stack(stack_b);
}
