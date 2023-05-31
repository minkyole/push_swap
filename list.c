/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:04:00 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 15:04:02 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
}	t_node;

typedef struct s_dlist
{
	t_node	*head;
	int		size;
}	t_dlist;

t_dlist	*dlist_init(void)
{
	t_dlist *new_list;

	new_list = malloc(sizeof(t_dlist));
	new_list->head = NULL;
	new_list->size = 0;
	return (new_list);
}

t_node *node_init(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = value;
	return (new_node);
}

void	add_last_node(t_dlist *dlist, int value)
{
	t_node *new_node;

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
	t_node *new_node;

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

void	delete_last_node(t_dlist *dlist)
{
	t_node	*temp_node;

	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head->prev;
	dlist->head->prev = dlist->head->prev->prev;
	dlist->head->prev->next = dlist->head;
	free(temp_node);
}

void	delete_first_node(t_dlist *dlist)
{
	t_node *temp_node;

	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head;
	dlist->head->prev->next = dlist->head->next;
	dlist->head->next->prev = dlist->head->prev;
	dlist->head = dlist->head->next;
	free(temp_node);
}

void	dlist_print(t_dlist *dlist)
{
	int i;
	t_node	*temp_node;

	i = 0;
	if (dlist == NULL || dlist->head == NULL)
		return ;
	temp_node = dlist->head;
	while(i < dlist->size)
	{
		ft_printf("%d\n", temp_node->value);
		temp_node = temp_node->next;
		i++;
	}
}

int		dlist_value_check(t_dlist *dlist, int value)
{
	int i;
	t_node *next_temp;
	t_node *prev_temp;

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

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
	int		i;

	i = 1;
	stack_a = dlist_init();
	while (i < argc)
	{
		if (dlist_value_check(stack_a, ft_atoi(argv[i])))
		{
			ft_printf("Duplicate Value\n");
			exit(1);
		}
		add_last_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
}