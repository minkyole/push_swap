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

void	swap_stack(t_dlist	*stack_a, int flag)
{
	t_node	*temp_node;

	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
	else if (flag == 3)
		;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		stack_a->head = stack_a->head->next;
		return ;
	}
	temp_node = stack_a->head->next;
	temp_node->prev = stack_a->head->prev;
	temp_node->next->prev = stack_a->head;
	stack_a->head->next = temp_node->next;
	stack_a->head->prev = temp_node;
	temp_node->next = stack_a->head;
	stack_a->head = temp_node;
}

void	swap_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_printf("ss\n");
	swap_stack(stack_a, 3);
	swap_stack(stack_b, 3);
}

void	push_stack(t_dlist *stack_a, t_dlist *stack_b, int flag)
{
	if (flag == 1)
		ft_printf("pa\n");
	else if (flag == 2)
		ft_printf("pb\n");
	if (stack_b->size == 0)
		return ;
	add_first_node(stack_a, stack_b->head->value);
	delete_first_node(stack_b);
}

void	rotate_stack(t_dlist *stack_a, int flag)
{
	if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
	else if (flag == 3)
		;
	if (!(stack_a == NULL || stack_a->size <= 1))
	{
		add_last_node(stack_a, stack_a->head->value);
		delete_first_node(stack_a);
	}
}

void	rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_printf("rr\n");
	if (!(stack_a == NULL || stack_a->size <= 1))
		rotate_stack(stack_a, 3);
	if (!(stack_b == NULL || stack_b->size <= 1))
		rotate_stack(stack_b, 3);
}
