#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"


//val : changed?
void	init_stack(int *arr, int ac, char **av)
{
	int		i;

	arr = malloc(ac * sizeof(int));
	if (!arr)
	{
		ft_putstr_fd("Error\n", 1);
		return; 
	}
	i = 0;
	while (i < ac)
	{
		arr[i] = ft_atoi(av[i + 1]);
		i++;
	}
	//return (arr);
}


void	print_int_arr(int *arr, int arr_len)
{
	int		i;

	i = 0;
	while (i <= arr_len)
		printf("%d", arr[i++]);
}

int	main(int ac, char **av)
{
	int		*arr;
	
	//check_param(ac, av);
	if (!arr)
		exit(0);
	init_stack(arr, ac, av);
	print_int_arr(arr, 5);
	//after init, check validity


}


