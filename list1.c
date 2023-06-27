/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:27:34 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/27 20:27:36 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_dlist	*dlist_init(void)
{
	t_dlist	*new_list;

	new_list = malloc(sizeof(t_dlist));
	if (!new_list)
		error();
	new_list->head = NULL;
	new_list->size = 0;
	return (new_list);
}

t_node	*node_init(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error();
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	return (new_node);
}

void	add_last_node(t_dlist *dlist, int value)
{
	t_node	*new_node;

	new_node = node_init(value);
	if (dlist == NULL)
		return ;
	if (dlist->head == NULL)
	{
		dlist->head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = dlist->head->prev;
		new_node->next = new_node->prev->next;
		new_node->prev->next = new_node;
		dlist->head->prev = new_node;
	}
	dlist->size += 1;
}

void	add_first_node(t_dlist *dlist, int value)
{
	t_node	*new_node;

	new_node = node_init(value);
	if (dlist == NULL)
		return ;
	if (dlist->head == NULL)
	{
		dlist->head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = dlist->head->prev;
		dlist->head->prev->next = new_node;
		new_node->next = dlist->head;
		dlist->head->prev = new_node;
		dlist->head = new_node;
	}
	dlist->size += 1;
}
