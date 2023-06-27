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
	char					command[4];
}	t_command_node;

typedef struct s_command_dlist
{
	t_command_node	*head;
	int				size;
}	t_command_dlist;

typedef struct s_dlist
{
	t_node	*head;
	int		size;
}	t_dlist;

typedef struct s_five
{
	int	first;
	int	second;
	int	third;
	int	four;
	int	five;
}	t_five;

typedef struct s_sort_var
{
	int	upper;
	int	flag;
	int	command;
	int	size;
	int	current_up_cnt;
	int	next_up_cnt;
	int	next_down_cnt;
	int	rrr_cnt;
	int	first_pivot;
	int	second_pivot;
	int	cnt;
}	t_sort_var;

void			swap_stack(t_dlist	*stack_a, t_command_dlist *stack_command, \
int flag);
void			swap_stack_all(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command);
void			push_stack(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void			rotate_stack(t_dlist *stack_a, t_command_dlist *stack_command, \
int flag);
void			rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command);
void			reverse_rotate_stack(t_dlist *stack_a, t_command_dlist \
*stack_command, int flag);
void			reverse_rotate_stack_all(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command);
t_command_dlist	*command_dlist_init(void);
t_command_node	*command_node_init(char *command);
void			add_last_command_node(t_command_dlist *dlist, char *command);
void			dlist_command_print(t_command_dlist *dlist);
int				check_ss(char *str1, char *str2);
int				check_rr(char *str1, char *str2);
int				check_rrr(char *str1, char *str2);
t_command_node	*combine_command(t_command_node *first_node, \
t_command_node *second_node, int flag, t_command_dlist *stack_command);
void			check_combine_command(t_command_dlist *stack_command);
t_dlist			*dlist_init(void);
t_node			*node_init(int value);
void			add_last_node(t_dlist *dlist, int value);
void			add_first_node(t_dlist *dlist, int value);
void			delete_last_node(t_dlist *dlist);
void			delete_first_node(t_dlist *dlist);
void			dlist_print(t_dlist *dlist);
int				dlist_value_check(t_dlist *dlist, int value);
int				is_str_digit(char *str);
void			error(void);
int				add_stack_a(char **argv, int i, t_dlist *stack_a);
void			stack_div(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			stack_div_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			stack_div_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			stack_restore(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			quick_sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_1(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_2(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_3(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_4(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_5(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_6(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_7(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_8(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_9(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_10(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_11(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_12(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_lower_13(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_1(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_2(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_3(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_4(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_5(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_6(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_7(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_8(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_9(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);	
void			quick_sort_four_size_upper_10(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_11(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_12(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_13(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_four_size_upper_14(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
int				quick_sort_size_check(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
int				quick_sort_size_check_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
int				quick_sort_size_check_3(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
int				quick_sort_size_check_4(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
int				quick_sort_size_check_5(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_two_size(t_dlist *stack_a, t_command_dlist \
*stack_command, int flag);
void			sort_three_size_upper(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag);
void			sort_three_size_lower(t_dlist *stack_a, \
t_command_dlist *stack_command, int flag);
void			sort_three_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_three_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_three_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_three_size_upper2(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_three_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_five t);
void			quick_sort_three_size_lower2(t_dlist *stack_a, \
t_dlist *stack_b, t_command_dlist *stack_command, t_five t);
void			sort_four_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void			sort_four_size_upper_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void			sort_four_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void			sort_four_size_lower_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, int flag);
void			sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_five_command_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_five_command_lower_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_five_command_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			sort_five_command_upper_2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_five_command2(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_five_command1(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_five_size_lower(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_five_size_upper(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			ft_swap(int *a, int *b);
void			mid_quick_sort(int *temp_stack, int left, int right);
void			init_pivot(t_dlist *stack_a, int size, t_sort_var *sort_var);
void			sort_stack(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command);
void			quick_sort_a(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			quick_sort_b_push_a(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var sort_var);
void			delete_all_node(t_dlist	**dlist);
void			delete_command_all_node(t_command_dlist	**dlist);
void			stack_rrr(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			sort_var_init(t_sort_var *sort_var, \
t_sort_var *next_sort_var, int flag);
void			stack_div_first(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist *stack_command, t_sort_var *sort_var);
void			quick_sort_a_first(t_dlist *stack_a, t_dlist *stack_b, \
t_command_dlist \
*stack_command, t_sort_var sort_var);
void			three_init(t_five *t, t_dlist *stack_a);
void			four_init(t_five *t, t_dlist *stack_a);
#endif
