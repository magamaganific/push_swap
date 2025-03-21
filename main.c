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

#include "push_swap.h"

void	ft_moveadmin(int move, int who, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_ssab(who, a, b);
	else if (move == 2)
		ft_pab(who, a, b);
	else if (move == 3)
		ft_r2ab(who, a, b);
	else if (move == 4)
		ft_r3ab(who, a, b);
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	ft_printf("initial stack:\n");
	ft_printstack(*a);
	if (ft_countnums(*a) == 2)
		ft_swap(a);
	else if (ft_countnums(*a) == 3)
		ft_sort3(a);
	ft_1stsorter(a, b);
	ft_printf("final stack:\n");
	ft_printstack(*a);
	ft_printstack(*b);
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
		ft_stacknum(a, &nums[i]);
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

char	**ft_args_to_stack(int ac, char **av)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * ac);
	args[ac-- - 1] = 0;
	while (ac--)
		args[ac] = ft_strdup(av[ac + 1]);
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
	if (ac == 1)
		exit(1);
	if (ac == 2)
	{
		if (ft_strlen(av[1]))
			args = ft_split(av[1], ' ');
		else
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		args = ft_args_to_stack(ac, av);
	nums = ft_stackargs(args, &a);
	if (!ft_stkissorted(a))
		ft_push_swap(&a, &b);
	ft_freestack(a);
	ft_freer(args);
	free(nums);
	return (0);
}
