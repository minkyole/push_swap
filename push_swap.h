/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:07:51 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 17:07:54 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

t_dlist	*dlist_init(void);
t_node *node_init(int value);
void	add_last_node(t_dlist *dlist, int value);
void	add_first_node(t_dlist *dlist, int value);
void	delete_last_node(t_dlist *dlist);
void	delete_first_node(t_dlist *dlist);
void	dlist_print(t_dlist *dlist);
int		dlist_value_check(t_dlist *dlist, int value);
void	swap_stack(t_dlist	*stack_a, int flag);
void	swap_stack_all(t_dlist *stack_a, t_dlist *stack_b);
void	push_stack(t_dlist *stack_a, t_dlist *stack_b, int flag);
void	rotate_stack(t_dlist *stack_a, int flag);
void	rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b);
void	reverse_rotate_stack(t_dlist *stack_a, int flag);
void	reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b);
int		is_str_digit(char *str);
void	sort_stack(t_dlist *stack_a, t_dlist *stack_b);
void	sort_two_size(t_dlist *stack_a, int flag);
void	sort_three_size_lower(t_dlist *stack_a, int flag);
void	sort_three_size_upper(t_dlist *stack_a, int flag);

int init_mid(t_dlist *stack_a, int size);
void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, int size, int upper);
void quick_sort_b(t_dlist *stack_a, t_dlist *stack_b, int size, int upper);
int check_size(t_dlist *stack_b, int *pivot_arr, int pivot_idx);
void	quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, int flag);
void	quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, int flag);
void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, int flag);
void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, int flag);
void	sort_four_size_lower(t_dlist *stack_a, int flag);
void	sort_four_size_upper(t_dlist *stack_a, int flag);

#endif