#include "../includes/push_swap.h"


int	measure_size(t_node *cur)
{
	int i;
    t_node *slow = cur;
    t_node *fast = cur;

	i = 0;
	if (!cur || !cur->val)
		return (0);
	while (cur)
	{
		i++;
		cur = cur->right;
	}
	return (i);
}