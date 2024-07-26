#include "../includes/push_swap.h"


void	push_a(t_node **stack1, t_node **stack2)
{
	t_node	*temp;

	if (!*stack2)
		return ;

	temp = (*stack2)->right;
	(*stack2)->right = temp;
	*stack1 = *stack2;
	*stack2 = temp;

	ft_putstr_fd("pa\n", 1);
	/*
	1. if stack2 doesn't exist -> return
	2. STORE <2nd node of stack2> to temp
	3. COPY 1st node
	4. REMOVE <top of stack2>, by moving ptr to the next node
	5. put the rest of original stack
	*/
}

void	push_b(t_node **stack1, t_node **stack2)
{
	t_node	*temp;

	if (!*stack1)
		return ;
	temp = (*stack1)->right;
	(*stack1)->right = temp;
	*stack2 = *stack1;
	*stack1 = temp;
	ft_putstr_fd("pb\n", 1);
	/*
	1. if stack2 doesn't exist -> return
	2. STORE <2nd node of stack2> to temp
	3. COPY 1st node
	4. REMOVE <top of stack2>, by moving ptr to the next node
	5. put the rest of original stack
	*/
}