
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
int		is_numeric(int ac, char **av)
{



}

int		have_same_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac - 1)
	{
		while (av[i+j])
		{
			if (ft_strcmp(av[i], av[i + j]) == 1) //check
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


void	check_args(int ac, char **av)
{
	int	i;

	//A.no param
	if (ac == 1)
		exit(0);

	//B. check ac and av
	if (have_same_nbr(ac, av) || !is_numeric(ac, av))
	{
			ft_putstr_fd("Error\n", 1);
			exit(0);
	}





	//D. numeric but greater than MAXINT


}

int		is_valid_int(char *str)
{



}


void	print_err()
{
	write(1, "Error", 5);
}