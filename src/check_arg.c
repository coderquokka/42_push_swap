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
int		is_numeric(t_node *tmp)
{
	return (0);
}

int have_same_nbr(t_node *tmp)
{
	t_node *current;

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


int	is_valid_args(t_node *tmp)
{
	if (have_same_nbr(tmp) || !is_numeric(tmp))
	{
			ft_putstr_fd("Error\n", 1);
			return(0);
	}
	return (1);
	//D. numeric but greater than MAXINT


}