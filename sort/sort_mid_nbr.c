#include "sort.h"

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
	rb = find_b_rotation(var);
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
            rotate_both(var);
        else if (pos > 0)
            rotate_a(var);
        else if (pos < 0 && var->stack_b->val < ft_last_node(var->stack_a)->val)
            rev_rotate_both(var);
        else if (pos < 0)
            rev_rotate_a(var);
        else if (var->stack_b->val > var->stack_a->val)
            rotate_b(var);
        else
            rev_rotate_b(var);
    }
}