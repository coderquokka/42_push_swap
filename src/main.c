//learning struct


#include <stdio.h>
#include <stdlib.h> //for EXIT_SUC/FAIL
#include "push_swap.h"

//check after writing mv: av->tmp
void	init_stack(char **temp, t_node *stack)
{
	if (!stack)
		return ;
	while (*temp)
	{
		stack->val = *temp;
		stack = stack->next;
		temp++;
	}
}

int	main(int ac, char **av)
{
	int		**temp;
	t_node	*stack_a;
	int		i;
	
	//A. if(ac < 2)
	if (ac < 2)
		return (EXIT_FAILURE);
	//B. if(ac==2): mv input to temp -> put into stack A && free temp
	//B-1.mv: input->temp
	//B-2.mv: temp->stack A
	//B-3.error_hanlder(NULL, NULL) : don't understand why it's needed
	//B-4.free: tmp
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		if (!temp || !*temp)
		{
			free(temp);
			return (EXIT_FAILURE);
		}
	}
	//C. if(ac > 2): 
	else
	{
		i = 1;
		while (av[i])
		{
			*temp = malloc (ac * sizeof(int));
			if (!*temp)
				return (EXIT_FAILURE);
			temp[i - 1] = av[i];
			i++;
		}
		temp[ac - 1] = '\0';
	}
	if (temp)
	{
		init_stack(temp, stack_a);
		free(temp);
	}
	else if (*temp)
		free(temp);
	//D. if (is_sorted(stack A))

	//E. push_swap

	return (EXIT_SUCCESS);
}

