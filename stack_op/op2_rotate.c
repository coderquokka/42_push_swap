#include "../includes/push_swap.h"
#include "stack_op.h"

/*gpt: also wrong
static void rotate(t_node **stack)
{
	t_node *tail;
	t_node *head;

	if (!stack || !*stack || !(*stack)->right)
		return;

	// Move the head pointer to the second node
	head = (*stack)->right;
	
	// Update the stack to point to the new head
	*stack = head;

	// Find the last node of the updated list
	tail = ft_last_node(*stack);

	// Attach the original head node (which is now `tail`) to the end of the list
	tail->right = head;
	head->left = tail;
	head->right = NULL;
}*/


static void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (!stack || !*stack || !(*stack)->right)
		return ;
		/*
	tail = *stack;
	head = ft_last_node(*stack);
	tail->right = NULL;
	tail->left = head;
	head->right = tail;
	*/
}

/*wrong
static void	rotate(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->right)
		return ;
	temp = *stack;
	*stack = (*stack)->right;
	temp->right = NULL;
	*stack = ft_last_node(*stack); //here: fix
	temp->left = *stack;
	(*stack)->right = temp;
	//while((*stack)->left)
	//	*stack = (*stack)->left;
}
*/
	
void	rotate_a(t_stack_var *var)
{
	rotate(&var->stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack_var *var)
{
	rotate(&var->stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack_var *var)
{
	rotate_a(var);
	rotate_b(var);
	//write(1, "rr\n", 3);
}
