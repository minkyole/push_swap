/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_restore.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:37 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 15:14:40 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	stack_rrr(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var)
{
	sort_var->rrr_cnt = 0;
	while (sort_var->current_up_cnt > sort_var->rrr_cnt && \
	sort_var->next_down_cnt > sort_var->rrr_cnt)
	{
		reverse_rotate_stack_all(stack_a, stack_b, stack_command);
		sort_var->rrr_cnt++;
	}
	while (sort_var->current_up_cnt - sort_var->rrr_cnt > 0)
	{
		reverse_rotate_stack(stack_a, stack_command, sort_var->flag);
		sort_var->rrr_cnt++;
	}
}
