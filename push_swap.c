/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:29:49 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:29:51 by mfornovi         ###   ########.fr       */
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
	if (ft_countnums(*a) == 2)
		ft_swap(a);
	else if (ft_countnums(*a) == 3)
		ft_sort3(a);
}