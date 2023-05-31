/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:06:52 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:06:55 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_rotate_stack(t_dlist *stack_a)
{
	add_first_node(stack_a, stack_a->head->prev->value);
	delete_last_node(stack_a);
	ft_printf("reverse_rotate\n");
}

void	reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
}
