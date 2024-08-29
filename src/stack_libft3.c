#include "../includes/push_swap.h"


int	measure_size(t_node *cur)
{
	int		i;

	i = 0;
	while (cur)
	{
		i++;
		cur = cur->right;
	}
	return (i);
}