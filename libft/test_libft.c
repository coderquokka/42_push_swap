
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	**dst = ft_split(" hi i am jin ! ", ' ');
	if (!dst)
		return (0);

	char **ptr = dst;
	int i = 0;
	while (*ptr)
	{
		printf("[%d]:%s\n", i++, *ptr);
		ptr++;
	}

	// Free the allocated memory
	ptr = dst;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(dst);

	return 0;

}