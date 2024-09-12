#ifndef SORT_H
#define SORT_H

#include "../includes/push_swap.h"  // Include any necessary headers

//push swap utils
int			handle_exception_case(t_stack_var *var, int pos);
int			find_exception_case(t_stack_var *var);
int			find_best_position(t_stack_var *var);

//push swap
void		b_to_a(t_stack_var *var);
void		a_to_b(t_stack_var *var);
void		a_to_ab(t_stack_var *var);
void		push_swap(t_stack_var *var);

//sort less than
void		sort_two(t_stack_var *var);
void		sort_three(t_stack_var *var);
void		sort_less_than(t_stack_var *var);
void		pick_two_pivots(t_stack_var *var);
#endif