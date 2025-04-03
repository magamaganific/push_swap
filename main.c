/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:14:26 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:14:32 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' ');
 ./push_swap $ARG | ./checker_linux $ARG*/
#include "push_swap.h"

void	ft_moveadmin(int move, t_stack **a, t_stack **b)
{
	if (move == PA || move == PB)
		ft_pab(move, a, b);
	if (move == SA || move == SB || move == SS)
		ft_ssab(move, a, b);
	if (move == RA || move == RB || move == RR)
		ft_r2ab(move, a, b);
	if (move == RRA || move == RRB || move == RRR)
		ft_r3ab(move, a, b);
}

void	ft_push_swap(t_stack **a, t_stack **b, int *nums)
{
	ft_printf("stack: ");
	ft_printstack(*a);
	ft_index(ft_countnums(*a), a, nums);
	ft_printf("indexed stack: ");
	ft_printstack(*a);
	if (ft_countnums(*a) == 2)
		ft_moveadmin(SA, a, b);
	else if (ft_countnums(*a) == 3)
		ft_sort3(a);
	else if (ft_countnums(*a) == 4)
		ft_sort4(a, b);
	else if (ft_countnums(*a) == 5)
		ft_sort5(a, b);
	else
		k_sort(a, b);
	ft_printf("sorted stack index: ");
	ft_printstack(*a);
	ft_freestack(*b);
}

int	*ft_stackargs(char **args, t_stack **a)
{
	size_t	size;
	size_t	i;
	int		*nums;

	nums = ft_check_args(args);
	size = ft_countargs(args);
	i = 0;
	while (i < size)
	{
		ft_stacknum(a, nums[i]);
		i++;
	}
	if (ft_dupedints(*a) != 0)
	{
		ft_printf("Error: Duplicated input.\n");
		ft_freestack(*a);
		free(nums);
		ft_freer(args);
		exit (0);
	}
	return (nums);
}

char	**ft_args_to_stack(char **input)
{
	char	**args;
	char	**ns;
	int		n;
	int		i;

	i = 0;
	n = 0;
	ns = NULL;
	args = (char **)ft_calloc(sizeof(char *), ft_true_input_count(input) + 1);
	args[ft_true_input_count(input) - 1] = 0;
	while (*input)
	{
		n = 0;
		ns = ft_split(*input, ' ');
		while (ns[n])
		{
			args[i] = ft_strdup(ns[n]);
			n++;
			i++;
		}
		ft_freer(ns);
		input++;
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		*nums;

	a = NULL;
	b = NULL;
	if (ac == 1 || ft_strlen(av[1]) == 0)
		exit(1);
	args = ft_args_to_stack(av + 1);
	nums = ft_stackargs(args, &a);
	if (!ft_stkissorted(a))
		ft_push_swap(&a, &b, nums);
	ft_freestack(a);
	ft_freer(args);
	free(nums);
	return (0);
}
