/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:55:44 by minkyole          #+#    #+#             */
/*   Updated: 2023/05/31 20:55:44 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>

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
t_node	*node_init(int value);
void	add_last_node(t_dlist *dlist, int value);
void	add_first_node(t_dlist *dlist, int value);
void	delete_last_node(t_dlist *dlist);
void	delete_first_node(t_dlist *dlist);
void	dlist_print(t_dlist *dlist);
int		dlist_value_check(t_dlist *dlist, int value);
void	swap_stack(t_dlist	*dlist);
void	swap_stack_all(t_dlist *stack_a, t_dlist *stack_b);
void	push_stack(t_dlist *stack_a, t_dlist *stack_b);
void	rotate_stack(t_dlist *stack_a);
void	rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b);
void	reverse_rotate_stack(t_dlist *stack_a);
void	reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b);
int		is_str_digit(char *str);
void	command_input(t_dlist *stack_a, t_dlist *stack_b);
int		check_command(char *buff, size_t len, t_dlist *stack_a, \
t_dlist *stack_b);
void	check_sort(t_dlist *stack_a, t_dlist *stack_b);
int		add_stack_a(char **argv, int i, t_dlist *stack_a);
int		check_command_r(char *buff, size_t len, t_dlist *stack_a, \
t_dlist *stack_b);
void	error(void);
void	delete_all_node(t_dlist	**dlist);
#endif
