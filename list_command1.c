/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:43:12 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/14 01:43:13 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_command_dlist	*command_dlist_init(void)
{
	t_command_dlist	*new_list;

	new_list = malloc(sizeof(t_command_dlist));
	if (!new_list)
		error();
	new_list->head = NULL;
	new_list->size = 0;
	return (new_list);
}

t_command_node	*command_node_init(char *command)
{
	t_command_node	*new_node;

	new_node = malloc(sizeof(t_command_node));
	if (!new_node)
		error();
	new_node->next = NULL;
	new_node->prev = NULL;
	ft_strlcpy(new_node->command, command, 5);
	return (new_node);
}

void	add_last_command_node(t_command_dlist *dlist, char *command)
{
	t_command_node	*new_node;

	new_node = command_node_init(command);
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

void	dlist_command_print(t_command_dlist *dlist)
{
	int				i;
	t_command_node	*temp_node;

	i = 0;
	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head;
	while (i < dlist->size)
	{
		ft_printf("%s\n", temp_node->command);
		temp_node = temp_node->next;
		i++;
	}
}

void	delete_command_all_node(t_command_dlist	**dlist)
{
	t_command_node	*free_temp;
	t_command_node	*next_temp;
	int				i;

	i = 0;
	if (dlist == NULL)
		return ;
	next_temp = (*dlist)->head;
	while (i < (*dlist)->size)
	{
		free_temp = next_temp;
		next_temp = next_temp->next;
		free(free_temp);
		i++;
	}
	free(*dlist);
}
