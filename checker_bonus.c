/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:27:48 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 20:27:49 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist *stack_b;
	char	**temp_arr;
	long long temp_value;
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
			if (is_str_digit(temp_arr[j]))
			{
				ft_printf("not digit\n");
				exit(1);
			}
			temp_value = ft_atoi(temp_arr[j]);
			if (temp_value > 2147483647 || temp_value < -2147483648)
			{
				ft_printf("input error\n");
				exit(1);
			}
			if (dlist_value_check(stack_a, temp_value))
			{
				ft_printf("Duplicate Value\n");
				exit(1);
			}
			add_last_node(stack_a, temp_value);
			j++;
		}
		if (j == 0)
		{
			ft_printf("not digit\n");
			exit(1);
		}
		i++;
	}
	command_input(stack_a, stack_b);
}

int	check_command(char *buff, size_t len, t_dlist *stack_a, t_dlist *stack_b)
{
	if (len <= 2)
		return (1);
	else if (buff[0] == 's')
	{
		if (buff[1] == 'a')
			swap_stack(stack_a);
		else if (buff[1] == 'b')
			swap_stack(stack_b);
		else if (buff[1] == 's')
			swap_stack_all(stack_a, stack_b);
		else
			return (1);
	}
	else if (buff[0] == 'p')
	{
		if (buff[1] == 'a')
			push_stack(stack_a, stack_b);
		else if (buff[1] == 'b')
			push_stack(stack_b, stack_a);
		else
			return (1);
	}
	else if (buff[0] == 'r')
	{
		if (buff[1] == 'a')
			rotate_stack(stack_a);
		else if (buff[1] == 'b')
			rotate_stack(stack_b);
		else if (buff[1] == 'r' && len == 3)
			rotate_stack_all(stack_a, stack_b);
		else if (len == 4 && buff[1] == 'r' && buff[2] == 'a')
			reverse_rotate_stack(stack_a);
		else if (len == 4 && buff[1] == 'r' && buff[2] == 'b')
			reverse_rotate_stack(stack_b);
		else if (len == 4 && buff[1] == 'r' && buff[2] == 'r')
			reverse_rotate_stack_all(stack_a, stack_b);
		else
			return (1);
	}
	return (0);
}

void	command_input(t_dlist *stack_a, t_dlist *stack_b)
{
	char	*buff;
	size_t	len;

	while (1)
	{
		//if (stack_b != NULL && stack_b->head != NULL)
		//{
		//	ft_printf("%d %d %d\n", stack_b->head, stack_b->head->next, stack_b->head->next->next);
		//	ft_printf("%d %d %d\n", stack_b->head, stack_b->head->prev, stack_b->head->prev->prev);
		//}
		buff = get_next_line(0);
		if (buff == NULL)
			break;
		len = ft_strlen(buff);
		if (len > 4)
		{
			ft_printf("input Error1\n");
			exit(1);
		}
		if (check_command(buff, len, stack_a, stack_b))
		{
			ft_printf("input Error2\n");
			exit(1);
		}
		free(buff);
	}
	ft_printf("--------stack_a--------\n");
	dlist_print(stack_a);
	ft_printf("--------stack_b--------\n");
	dlist_print(stack_b);
	check_sort(stack_a, stack_b);
	free(buff);
}

void	check_sort(t_dlist *stack_a, t_dlist *stack_b)
{
	int i = 0;
	t_node *temp_node;

	temp_node = stack_a->head;
	if (stack_b->size != 0)
		ft_printf("KO\n");
	else
	{
		while(i + 1 < stack_a->size)
		{
			//ft_printf("%d %d\n", temp_node->value, temp_node->next->value);
			if (temp_node->value > temp_node->next->value)
			{
				ft_printf("i %d value %d\n", i, temp_node->value);
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
