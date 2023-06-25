/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:09:37 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:09:38 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist			*stack_a;
	t_dlist			*stack_b;
	t_command_dlist	*stack_command;
	int				i;

	i = 1;
	stack_a = dlist_init();
	stack_b = dlist_init();
	stack_command = command_dlist_init();
	while (i < argc)
	{
		if (add_stack_a(argv, i, stack_a) == 0)
			error();
		i++;
	}
	sort_stack(stack_a, stack_b, stack_command);
	check_combine_command(stack_command);
	dlist_command_print(stack_command);
	delete_all_node(&stack_a);
	delete_all_node(&stack_b);
	delete_command_all_node(&stack_command);
	return (0);
}
