/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:26:51 by minkyole          #+#    #+#             */
/*   Updated: 2023/07/04 22:43:24 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;
	int			i;

	i = 0;
	if (argc == 1)
		return (1);
	stack_a = dlist_init();
	stack_b = dlist_init();
	while (++i < argc)
	{
		if (add_stack_a(argv, i, stack_a) == 0)
			error();
	}
	command_input(stack_a, stack_b);
	delete_all_node(&stack_a);
	delete_all_node(&stack_b);
	return (0);
}

int	check_command(char *buff, size_t len, t_dlist *stack_a, t_dlist *stack_b)
{
	if (buff[0] == 's')
	{
		if (buff[1] == 'a' && buff[2] == '\n')
			swap_stack(stack_a);
		else if (buff[1] == 'b' && buff[2] == '\n')
			swap_stack(stack_b);
		else if (buff[1] == 's' && buff[2] == '\n')
			swap_stack_all(stack_a, stack_b);
		else
			return (1);
	}
	else if (buff[0] == 'p')
	{
		if (buff[1] == 'a' && buff[2] == '\n')
			push_stack(stack_a, stack_b);
		else if (buff[1] == 'b' && buff[2] == '\n')
			push_stack(stack_b, stack_a);
		else
			return (1);
	}
	else if (buff[0] == 'r')
		return (check_command_r(buff, len, stack_a, stack_b));
	else
		return (1);
	return (0);
}

void	command_input(t_dlist *stack_a, t_dlist *stack_b)
{
	char	*buff;
	size_t	len;

	while (1)
	{
		buff = get_next_line(0);
		if (buff == NULL)
			break ;
		len = ft_strlen(buff);
		if (len > 4 || len <= 2)
			error();
		if (check_command(buff, len, stack_a, stack_b))
			error();
		free(buff);
	}
	check_sort(stack_a, stack_b);
	free(buff);
}

void	check_sort(t_dlist *stack_a, t_dlist *stack_b)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = stack_a->head;
	if (stack_b->size != 0)
		ft_printf("KO\n");
	else
	{
		while (i + 1 < stack_a->size)
		{
			if (temp_node->value > temp_node->next->value)
			{
				ft_printf("KO\n");
				return ;
			}
			temp_node = temp_node->next;
			i++;
		}
		ft_printf("OK\n");
		return ;
	}
}
