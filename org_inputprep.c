/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputprep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:25:04 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:25:07 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*printf("dentro del while ft_str_is_num: %c\n", arg[i]);*/
#include "push_swap.h"

#define NO 0
#define YES 1

int	ft_str_is_num(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		if (ft_isdigit(arg[i]) == 0)
			return (NO);
		i++;
	}
	return (YES);
}

size_t	ft_countargs(char **args)
{
	size_t	i;
	size_t	les;

	i = 0;
	les = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) == 0)
			les++;
		i++;
	}
	return (i - les);
}

int	ft_dupedints(t_stack *a)
{
	t_stack	*num;
	t_stack	*check;

	num = a;
	check = num->next;
	while (num != NULL)
	{
		check = num->next;
		while (check != NULL)
		{
			if (num->val == check->val)
				return (YES);
			check = check->next;
		}
		num = num->next;
	}
	return (NO);
}

int	*ft_check_args(char **args)
{
	size_t		size;
	size_t		i;
	int			*nums;

	size = ft_countargs(args);
	nums = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if (ft_str_is_num(args[i]) == NO || ft_strlen(args[i]) > 11
			|| ft_atol(args[i]) > 2147483647 || ft_atol(args[i]) < -2147483648)
		{
			ft_printf("Error: Invalid input.\n");
			ft_freer(args);
			free(nums);
			exit(1);
		}
		nums[i] = ft_atol(args[i]);
		i++;
	}
	return (nums);
}

size_t	ft_true_input_count(char **input)
{
	char	**ns;
	size_t	cuan;
	int		i;

	i = 0;
	cuan = 0;
	ns = NULL;
	while (input[i])
	{
		ns = ft_split(input[i], ' ');
		cuan += ft_countargs(ns);
		ft_freer(ns);
		i++;
	}
	return (cuan);
}
