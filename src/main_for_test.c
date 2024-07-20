#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "../includes/push_swap.h"

//check after writing mv: av->tmp
//assign val to stack
/*"new_node", "cur"; why necessary?
	1. new_node
		to create/init each new node in the stack
		on each iteration, 
		    1) allocates mem
			2) set its val
			3) link it to the stack

	2. cur
		to keep track of the last node in the stack
		during construction of linked list
		travese and maintain end of the stack, how?
			1) init 'cur' to point to head of stack
			2) mv 'cur' to end of stack as new nodes added
	
*/
void	init_stack(char **temp, t_node **stack)
{

	t_node *new_node;
	t_node *cur;

	if (!stack || !temp)
		return ;

	//why? to signify empty list
	*stack = NULL;

	while (*temp)
	{
		//mem alloc
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;

		//set val
		new_node->val = ft_atoi(*temp);
		new_node->next = NULL;
		//printf("%d", ft_atoi(*temp));

		//if empty, set the new node as 1st node
		if (*stack == NULL)
		{
			*stack = new_node; // The stack (head) now points to the new node
			cur = *stack; // Set current to the new node (the first node)
		} else
		{
			// If the stack is not empty, link the new node to the current last node
			cur->next = new_node; // Link the current node to the new node
			cur = cur->next; // Move current to the new node
		}
		temp++;
	}
}

void	free_stack(t_node *stack)
{
	//to store cur node while freeing mem
	t_node *temp;

	//free while traverses each node in list
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->val);
		stack = stack->next;
	}
}

int main(int ac, char **av)
{
	//later: replace test[] with av
	//char *test[] = {"4", "4", "68", "8282", NULL}; //Proper arr initialization

	t_node *cur = NULL;
	t_node *temp;

	init_stack(&av[1], &cur);
	temp = cur;
	print_stack(cur);
	free(temp);
	return (EXIT_SUCCESS);
}