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

#include "push_swap.h"

int	ft_strisnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_countargs(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
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
			if (*(num->val) == *(check->val))
				return (1);
			check = check->next;
		}
		num = num->next;
	}
	return (0);
}

int	*ft_check_args(char **args)
{
	size_t	size;
	int		*nums;
	int		i;

	size = ft_countargs(args);
	nums = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		if (ft_strisnum(args[i]) == 0)
		{
			ft_printf("Error: Invalid input.\n");
			ft_freer(args);
			free(nums);
			exit(1);
		}
		nums[i] = ft_atoi(args[i]);
		i++;
	}
	return (nums);
}
