/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:22:48 by mfornovi          #+#    #+#             */
/*   Updated: 2025/04/01 14:22:51 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	raiz_cuadrada(int nbr)
{
	int	i;

	if (nbr == 0)
		return (0);
	i = 1;
	while (i * i <= nbr)
		i++;
	return (i - 1);
}

static void	ft_firstsort_pb(t_stack **a, t_stack **b, int *a_s, int *b_s)
{
	int	range;

	range = raiz_cuadrada(*a_s) * 133 / 100;
	while (*a_s > 0)
	{
		if ((*a)->val <= *b_s)
		{
			ft_moveadmin(PB, a, b);
			(*a_s)--;
			(*b_s)++;
		}
		else if ((*a)->val <= *b_s + range)
		{
			ft_moveadmin(PB, a, b);
			(*a_s)--;
			(*b_s)++;
			if (!((*a)->val <= *b_s + range))
				ft_moveadmin(RR, a, b);
			else
				ft_moveadmin(RB, a, b);
		}
		else
			ft_moveadmin(RA, a, b);
	}
}

static void	ft_secondsort_pa(t_stack **a, t_stack **b, int *a_s, int *b_s)
{
	while (*b_s > 0)
	{
		while ((*b)->val != *b_s - 1)
		{
			if (ft_pos_id(*b, *b_s - 1) <= *b_s / 2)
				ft_moveadmin(RB, a, b);
			else
				ft_moveadmin(RRB, a, b);
		}
		ft_moveadmin(PA, a, b);
		(*a_s)++;
		(*b_s)--;
	}
}

void	k_sort(t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

	a_size = ft_countnums(*a);
	b_size = ft_countnums(*b);
	ft_firstsort_pb(a, b, &a_size, &b_size);
	ft_secondsort_pa(a, b, &a_size, &b_size);
}
