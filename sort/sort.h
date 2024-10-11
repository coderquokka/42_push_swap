#ifndef SORT_H
#define SORT_H

#include "../includes/push_swap.h"  // Include any necessary headers
typedef struct s_stack_var t_stack_var;
typedef struct s_node t_node;

//push swap utils
t_node	*ft_second_last_node(t_node *node, t_node *prev_tail);
int		find_split_start(t_node **node);
void	set_commands_default(t_node *node);
void	rotation_single(t_node *stack_a, t_node *stack_b, t_node *b_cur);
void	rotation_double(t_node *stack_a, t_node *stack_b, t_node *b_cur);
t_node	*execute_commands(t_node *stack_a, t_node *stack_b);
void	save_commands(t_node *stack_a, t_node *stack_b, int a_size, int b_size);
int		save_a_pos(t_node *stack_a, int b_idx);
void	pick_two_pivots(t_stack_var *var);

//push swap
void		b_to_a(t_stack_var *var);
void		a_to_b(t_stack_var *var);
void		a_to_ab(t_stack_var *var);
void		push_swap(t_stack_var *var);

//sort small_nbr
void		sort_two(t_stack_var *var);
void		sort_three(t_stack_var *var);
void		sort_less_than(t_stack_var *var);

//sort mid nbr
int			calculate_moves(t_stack_var *var, int pos);
void		execute_moves(t_stack_var *var, int moves, int pos);
int			find_split_start(t_node **node);

#endif