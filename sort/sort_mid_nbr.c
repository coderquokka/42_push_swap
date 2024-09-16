#include "sort.h"

// Helper function to calculate the number of moves
int calculate_moves(t_stack_var *var, int pos)
{
    int ra = (pos >= 0) ? pos : 0;
    int rra = (pos < 0) ? -pos : 0;
    int rb = find_b_rotation(var);
    int rrb = (rb > 0) ? var->stack_b_size - rb : 0;

    // Calculate the minimum number of moves
    return min_of_four(
        max(ra, rb),           // RR + RA or RB
        max(rra, rrb),         // RRR + RRA or RRB
        ra + rrb,              // RA + RRB
        rra + rb               // RRA + RB
    );
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