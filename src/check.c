#include "../includes/push_swap.h"

/*
<valid>
./a.out "0 1 3 2"
./a.out "0    1   3  2"

<invalid>
(A) without param
./a.out
-> not disp, give prompt back

(B) non numeric param
./a.out "a b c"

(C) a duplicate numeric param
./a.out "1 3 1"

(D) only numeric but with one greater than MAXINT
./a.out "99999999999999 0 3"

(1)~(3)
-> disp "Error"
*/
int	is_numeric(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
			{
				if (j != 0)
					return (0);
				while (j == 0 || av[i][j] == '-' || av[i][j] == '+')
					j++;
			}
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	have_same_nbr(t_node *tmp)
{
	t_node	*current;

	if (tmp == NULL || tmp->right == NULL)
		return (0);
	while (tmp != NULL)
	{
		current = tmp;
		while (current->right != NULL)
		{
			current = current->right;
			if (tmp->val == current->val)
				return (1);
		}
		tmp = tmp->right;
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	int		prev;
	t_node	*temp;

	if (!stack || !stack->right)
		return (-1);
	temp = stack;
	while (temp->right)
	{
		prev = temp->val;
		temp = temp->right;
		if (prev >= temp->val)
			return (0);
	}
	return (1);
}