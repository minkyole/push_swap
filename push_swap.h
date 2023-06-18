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

typedef struct s_command_node
{
	struct s_command_node	*next;
	struct s_command_node	*prev;
	char			command[4];
}	t_command_node;

typedef struct s_command_dlist
{
	t_command_node	*head;
	int		size;
}	t_command_dlist;

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
void	swap_stack(t_dlist	*stack_a, t_command_dlist *stack_command, int flag);
void	swap_stack_all(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command);
void	push_stack(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	rotate_stack(t_dlist *stack_a, t_command_dlist *stack_command, int flag);
void	rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command);
void	reverse_rotate_stack(t_dlist *stack_a, t_command_dlist *stack_command, int flag);
void	reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command);
int		is_str_digit(char *str);
void	sort_stack(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command);
void	sort_two_size(t_dlist *stack_a, t_command_dlist *stack_command, int flag);
void	sort_three_size_lower(t_dlist *stack_a, t_command_dlist *stack_command, int flag);
void	sort_three_size_upper(t_dlist *stack_a, t_command_dlist *stack_command, int flag);

void init_pivot(t_dlist *stack_a, int size, int *first_pivot, int *second_pivot);
void quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper);
void quick_sort_b_up(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper);
void quick_sort_b_down(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper);
void quick_sort_a_down(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper);
int check_size(t_dlist *stack_b, int *pivot_arr, int pivot_idx);
void	quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	quick_sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b ,t_command_dlist *stack_command, int flag);
void	sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);

t_command_node *command_node_init(char *command);
void	add_last_command_node(t_command_dlist *dlist, char *command);
void	add_first_command_node(t_command_dlist *dlist, char *command);
void	delete_last_command_node(t_command_dlist *dlist);
void	delete_first_command_node(t_command_dlist *dlist);
void	dlist_command_print(t_command_dlist *dlist);
t_command_dlist	*command_dlist_init(void);
void check_combine_command(t_command_dlist *stack_command);
t_command_node *combine_command(t_command_node *first_node, t_command_node *second_node, int flag, t_command_dlist *stack_command);
void	quick_sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b ,t_command_dlist *stack_command, int flag);
void	quick_sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
void	sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int flag);
int	add_stack_a(char **argv, int i, t_dlist *stack_a);
void	error(int flag);
void	quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void	quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void	sort_three_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int command, int flag);
void	sort_three_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int command, int flag);
void	sort_three_size_lower(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag);
void	sort_three_size_upper(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag);
void	init_pivot(t_dlist *stack_a, int size, int *first_pivot, \
int *second_pivot);
void	stack_restore(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int upper,\
int sort_b_up_cnt, int sort_b_down_cnt, int sort_a_up_cnt, int flag, int command);
void	stack_div(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper,\
int *sort_b_up_cnt, int *sort_b_down_cnt, int *sort_a_up_cnt, int flag);
int	quick_sort_size_check(t_dlist *stack_a, t_dlist *stack_b, t_command_dlist *stack_command, int size, int upper, int flag);
#endif
