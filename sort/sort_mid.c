#include "sort.h"

/*
int find_b_rotation(t_stack_var var)
{

	
}*/
int ft_max(int a, int b)
{
    return (a > b) ? a : b;
}
int ft_min_of_four(int a, int b, int c, int d)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;

    return min;
}
// Helper function to calculate the number of moves
int	calculate_moves(t_stack_var *var, int pos)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	moves[4];

	ra = 0;
	rra = 0;
	if (pos >= 0)
		ra = pos;
	else
		rra = -pos;
	rb = pos;
	rrb = 0;
	if (rb > 0)
		rrb = var->stack_b_size - rb;
	moves[0] = ft_max(ra, rb);
	moves[1] = ft_max(rra, rrb);
	moves[2] = ra + rrb;
	moves[3] = rra + rb;
	return (ft_min_of_four(moves[0], moves[1], moves[2], moves[3]));
}

// Helper function to execute the moves
void execute_moves(t_stack_var *var, int moves, int pos)
{
    while (moves--)
    {
        if (pos > 0 && var->stack_b->val > var->stack_a->val)
            rotate_ab(var);
        else if (pos > 0)
            rotate_a(var);
        else if (pos < 0 && var->stack_b->val < ft_last_node(var->stack_a)->val)
            rev_rotate_ab(var);
        else if (pos < 0)
            rev_rotate_a(var);
        else if (var->stack_b->val > var->stack_a->val)
            rotate_b(var);
        else
            rev_rotate_b(var);
    }
}

void b_to_a(t_stack_var *var)
{
    int pos;
    int moves;

    if (var->stack_b == NULL)
        return;
    while (var->stack_b)
    {
        pos = find_best_position(var);
        moves = calculate_moves(var, pos);
        execute_moves(var, moves, pos);
        push_a(var);
    }
    // Final rotation to put the smallest element at the top
    //final_rotate(var);
}

/*second last
void b_to_a(t_stack_var *var)
{
    int	pos;
    int	moves;

	if (var->stack_b == NULL)
		return ;
	get_temp_sorted_stack(var->stack_b, &var->temp_sorted_stack_b);
	get_index(var->stack_b, var->temp_sorted_stack_b);
	push_a(var);

    while (var->stack_b)
    {
		var->stack_b_size = measure_size(var->stack_b);
        var->stack_a_size = measure_size(var->stack_a);
        pos = find_best_position(var);
		moves = calculate_moves(var, pos);
        execute_moves(var, moves, pos);
        push_a(var);
    }
}*/

/* last ver
void	b_to_a(t_stack_var *var)
{
	int		pos;

	while (var->stack_b)
	{
		var->stack_a_size = measure_size(var->stack_a);
		get_temp_sorted_stack(var->stack_a, &var->temp_sorted_stack_a);
		get_index(var->stack_a, var->temp_sorted_stack_a);
		pos = find_best_position(var);
		printf("\n pos : %d  cur stack A size:%d", pos, var->stack_a_size);
		if (handle_exception_case(var, pos) == 1)
		{
			printf("exception case\n");
			pos = 0;
		}
		while (pos < 0) //pos < 0 : -1, -2, -3, ...
		{
			rev_rotate_a(var);
			pos++;
		}
		while (pos >= 3) //pos < 0 : -1, -2, -3, ...
		{
			rotate_a(var);
			pos--;
		}
	}
}*/
		/*later use
		while (++pos <= 0) //pos < 0 : -1, -2, -3, ...
			rev_rotate_a(var);
		while (--pos >= 2) //pos >= 3 : 3, 4, 5, ...
			rotate_a(var);
			*/


void	a_to_b(t_stack_var *var)
{
	t_node	*next_node;

	if (var->stack_a == NULL)
		return ;
	while (var->stack_a && var->stack_a_size >= 5)
	{
		var->stack_a_size = measure_size(var->stack_a);
		var->stack_b_size = measure_size(var->stack_b);
		next_node = var->stack_a->right;  // Store next node before modifying stack_a
		push_b(var);					  // push_b might modify var->stack_a
		var->stack_a = next_node;		 // Safely move to the next node
	}
}

void	a_to_ab(t_stack_var *var)
{
	t_node	*prev_tail;
	int		flag;

	prev_tail = ft_last_node(var->stack_a);
	flag = 0;
	while (var->stack_a)
	{
		var->stack_a_size = measure_size(var->stack_a);
		var->stack_b_size = measure_size(var->stack_b);
		if (var->stack_a->val > var->second_piv)
			rotate_a(var);
		else if (var->stack_a->val >= var->first_piv)
			push_b(var);
		else
		{
			push_b(var);
			rotate_b(var);
		}
		if (flag)
			break ;
		if (var->stack_a->val == prev_tail->val)
			flag++;
	}
}

void	sort_mid(t_stack_var *var)
{
	t_node	*last_node;
	
	pick_two_pivots(var);
	a_to_ab(var);
	a_to_b(var);
	last_node = ft_last_node(var->stack_b);
	last_node->right = NULL;
	sort_three(var);
	//b_to_a(var);



}