/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:05:50 by minkyole          #+#    #+#             */
/*   Updated: 2023/06/14 02:05:51 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_ss(char *str1, char *str2)
{
	if (!ft_strncmp(str1, "sa", 5))
	{
		if (!ft_strncmp(str2, "sb", 5))
		{
			return (1);
		}
	}
	else if (!ft_strncmp(str1, "sb", 5))
	{
		if (!ft_strncmp(str2, "sa", 5))
		{
			return (1);
		}
	}
	return (0);
}

int	check_rr(char *str1, char *str2)
{
	if (!ft_strncmp(str1, "ra", 5))
	{
		if (!ft_strncmp(str2, "rb", 5))
		{
			return (1);
		}
	}
	else if (!ft_strncmp(str1, "rb", 5))
	{
		if (!ft_strncmp(str2, "ra", 5))
		{
			return (1);
		}
	}
	return (0);
}

int	check_rrr(char *str1, char *str2)
{
	if (!ft_strncmp(str1, "rra", 5))
	{
		if (!ft_strncmp(str2, "rrb", 5))
		{
			return (1);
		}
	}
	else if (!ft_strncmp(str1, "rrb", 5))
	{
		if (!ft_strncmp(str2, "rra", 5))
		{
			return (1);
		}
	}
	return (0);
}

t_command_node	*combine_command(t_command_node *first_node, \
t_command_node *second_node, int flag, t_command_dlist *stack_command)
{
	t_command_node	*new_node;

	if (flag == 1)
		new_node = command_node_init("ss");
	else if (flag == 2)
		new_node = command_node_init("rr");
	else
		new_node = command_node_init("rrr");
	first_node->prev->next = new_node;
	new_node->next = second_node->next;
	second_node->next->prev = new_node;
	new_node->prev = first_node->prev;
	free(first_node);
	free(second_node);
	stack_command->size--;
	return (new_node);
}

void	check_combine_command(t_command_dlist *stack_command)
{
	t_command_node	*temp;
	int				i;

	if (stack_command == NULL || stack_command->head == NULL)
		return ;
	temp = stack_command->head;
	i = -1;
	while (++i + 1 < stack_command->size)
	{
		if (check_ss(temp->command, temp->next->command))
			temp = combine_command(temp, temp->next, 1, stack_command);
		else if (check_rr(temp->command, temp->next->command))
			temp = combine_command(temp, temp->next, 2, stack_command);
		else if (check_rrr(temp->command, temp->next->command))
			temp = combine_command(temp, temp->next, 3, stack_command);
		temp = temp->next;
	}
}
