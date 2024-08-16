#include "../includes/push_swap.h"

void	init_stack(char **temp, t_node **stack)
{
	t_node	*new_node;
	t_node	*cur;

	if (!stack || !temp)
		return ;
	*stack = NULL;
	while (*temp)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->val = ft_atoi(*temp);
		new_node->right = NULL;
		if (*stack == NULL)
		{
			*stack = new_node;
			cur = *stack;
		}
		else
		{
			cur->right = new_node;
			cur = cur->right;
		}
		temp++;
	}
}

void	get_index_stack(t_stack_var *var)
{
	int		i;
	t_node	*first;
	t_node	*second_current;
	t_node	*second_start;

	first = var->stack_a; //origin, unsorted
	second_start = var->temp_sorted_stack_a; //sorted
	if (!first || !second_current)
		return ;
	while (first != NULL)
	{
		i = 1;
		second_current = second_start;
		while (second_current != NULL)
		{
			if (first->val == second_current->val)
			{
				first->idx = i;
				break ;
			}
			second_current = second_current->right;
			i++;
		}
		first = first->right;
	}
}

/* wrong moves
82613
(1st)
-> 28613 -> 26813 -> 26183 -> 26138
(2nd)
-> 21638 -> 21368
(3rd)
-> 21368

=> wrong algorithmm fix
아예 처음부터 바꾼다면?
82613
(1st)28613 -> 26813 -> 26183 -> 26138
(2nd)26813 -> 26183 -> 26138
(3rd)21638 -> 21368 
(4th)12368

*/
void	get_sorted_stack(t_stack_var *var)
{
	t_node	*start_of_searching;
	t_node	*end_of_searching;
	t_node	*current;

	if (!var || !start_of_searching || var->stack_size <= 1)
		return ;
	cp_node(&var->temp_sorted_stack_a, var->stack_a);
	if (!var->temp_sorted_stack_a)
		return ;
	start_of_searching = var->temp_sorted_stack_a;
	end_of_searching = ft_last_node(start_of_searching);
	
	while (start_of_searching != end_of_searching && start_of_searching->right)
	{
		current = start_of_searching;
		while (current != end_of_searching && current->right)
		{
			if (current->val > current->right->val)
				swap_nodes(current, current->right); // Swapping values
			current = current->right;
		}
		//start_of_searching = start_of_searching->right; //여기가 틀린 것 같은데 고치면 또 아님. 
		end_of_searching = get_new_tail(current, end_of_searching);
	}
	
}

int	measure_size(t_stack_var *var)
{
	int		i;
	t_node	*cur_stack;

	i = 0;
	cur_stack = var->stack_a;
	while (cur_stack)
	{
		i++;
		cur_stack = cur_stack->right;
	}
	return (i);
}
//하는 일 3가지 : var에 stack a 집어 넣기 / size 재기 / sorted&ac 체크 
//sorting이나 indexing은 하지 않음
t_stack_var	*setup_stack_var(t_node *stack_a)
{
	t_stack_var	*stack_var;

	stack_var = (t_stack_var *)malloc(sizeof(t_stack_var));
	if (!stack_var)
		return (NULL);
	stack_var->stack_a = stack_a;
	stack_var->stack_size = measure_size(stack_var);
	if (stack_var->stack_size < 1)
		printf("invalid stack size\n");
	if (is_sorted(stack_var->stack_a) == 1)
		printf("stack a is already sorted\n");
	else if (stack_var->stack_size >= 4)
		printf("stack a is not sorted yet, has more than 4 arg\n");
	else
		printf("stack a is not sorted yet, but has less than 3 arguments\n");
	return (stack_var);
}
