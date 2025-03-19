/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:31:24 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:31:29 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ssab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_swap(a);
	else if (move == 2)
		ft_swap(b);
	else if (move == 3)
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_pab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_push(b, a);
	else if (move == 2)
		ft_push(a, b);
}

void	ft_r2ab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_rotate(*a);
	else if (move == 2)
		ft_rotate(*b);
	else if (move == 3)
	{
		ft_rotate(*a);
		ft_rotate(*b);
	}
}

void	ft_r3ab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_revrotate(*a);
	else if (move == 2)
		ft_revrotate(*b);
	else if (move == 4)
	{
		ft_revrotate(*a);
		ft_revrotate(*b);
	}
}