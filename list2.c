/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:10:53 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:10:54 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	delete_last_node(t_dlist *dlist)
{
	t_node	*temp_node;

	temp_node = dlist->head;
	if (dlist == NULL || dlist->head == NULL)
		return ;
	if (dlist->head->next == dlist->head)
		dlist->head = NULL;
	else if (dlist->head->next == dlist->head->prev)
	{
		temp_node = dlist->head->next;
		dlist->head->next = dlist->head;
		dlist->head->prev = dlist->head;
	}
	else
	{
		temp_node = dlist->head->prev;
		dlist->head->prev = dlist->head->prev->prev;
		dlist->head->prev->next = dlist->head;
	}
	free(temp_node);
	dlist->size -= 1;
	if (dlist->size == 0)
		dlist->head = NULL;
}

void	delete_first_node(t_dlist *dlist)
{
	t_node	*temp_node;

	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head;
	dlist->head->prev->next = dlist->head->next;
	dlist->head->next->prev = dlist->head->prev;
	dlist->head = dlist->head->next;
	free(temp_node);
	dlist->size -= 1;
	if (dlist->size == 0)
		dlist->head = NULL;
}

void	dlist_print(t_dlist *dlist)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head;
	while (i < dlist->size)
	{
		ft_printf("%d\n", temp_node->value);
		temp_node = temp_node->next;
		i++;
	}
}

int	dlist_value_check(t_dlist *dlist, int value)
{
	int		i;
	t_node	*next_temp;
	t_node	*prev_temp;

	i = 0;
	if (dlist == NULL || dlist->head == NULL)
		return (0);
	next_temp = dlist->head;
	prev_temp = dlist->head->prev;
	while (i < (dlist->size / 2) + 1)
	{
		if (next_temp->value == value || prev_temp->value == value)
			return (1);
		next_temp = next_temp->next;
		prev_temp = prev_temp->prev;
		i++;
	}
	return (0);
}
