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

static void	set_index(t_stack **a, int size, int *ordered)
{
	int			i;
	t_stack	*tmp;

	tmp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (ordered == tmp->val)
			{
				tmp->val = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static int	*b_sort(int *nums, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = -1;
	while (++i < size -1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
	}
	return (nums);
}

void	ft_index(int size, t_stack	**a, int *nums)
{
	int	*ordered;

	ordered = b_sort(nums, size);
	set_index(a, size, ordered);
	free(ordered);
}

static void	ft_push_swap(t_stack **a, t_stack **b, int *nums)
{
	// ft_printf("initial stack:\n");
	// ft_printstack(*a);
	ft_index(ft_countnums(*a), a, nums);
	if (ft_countnums(*a) == 2)
		ft_swap(a);
	else if (ft_countnums(*a) == 3)
		ft_sort3(a);
	else
		ft_sorter(a, b);
	// ft_printf("final stack:\n");
	// ft_printstack(*a);
	// ft_printstack(*b);
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
		ft_push_swap(&a, &b, nums);
	ft_freestack(a);
	ft_freestack(b);
	ft_freer(args);
	return (free(nums), 0);
}
