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

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist *stack_b;
	char	**temp_arr;
	int		i;
	int		j;

	i = 1;
	stack_a = dlist_init();
	stack_b = dlist_init();
	while (i < argc)
	{
		j = 0;
		temp_arr = ft_split(argv[i], ' ');
		while (temp_arr[j])
		{
			if (dlist_value_check(stack_a, ft_atoi(temp_arr[j])))
			{
				ft_printf("Duplicate Value\n");
				exit(1);
			}
			add_last_node(stack_a, ft_atoi(temp_arr[j]));
			j++;
		}
		i++;
	}
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
	swap_stack(stack_a);
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
	push_stack(stack_b, stack_a);
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
	rotate_stack(stack_a);
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
	reverse_rotate_stack(stack_a);
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
}
