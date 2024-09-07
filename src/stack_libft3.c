#include "../includes/push_swap.h"


int	measure_size(t_node *cur)
{
	int i;
    t_node *slow = cur;
    t_node *fast = cur;

	i = 0;
    while (slow != NULL && fast != NULL && fast->right != NULL)
    {
        i++;
        slow = slow->right;
        fast = fast->right->right;
        
        if (slow == fast) // Cycle detected
        {
            // Handle cycle (e.g., return -1 or break)
            return -1;
        }
    }
	if (!cur || !cur->val)
		return (0);
	while (cur)
	{
		i++;
		cur = cur->right;
	}
	return (i);
}