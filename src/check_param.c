
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


void	check_param(int ac, char **av)
{
	int	i;

	//A.no param
	if (ac == 1)
		exit(0);

	//B.not numeric : atoi_err
	i = 0;
	while (i <= ac)
	{
		if (is_valid_int(av[i]) == 0) //invalid
		{
			ft_putstr_fd("Error\n", 1);
			exit(0);
		}
		av[i];
	}

	//C. dumplicate numeric
	i = 0;
	while (i <= ac)
	{
		


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