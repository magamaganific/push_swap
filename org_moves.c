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

void	ft_pab(int move, t_stack **a, t_stack **b)
{
	if (move == PA)
	{
		ft_push(b, a);
		ft_printf("pa\n");
	}
	else if (move == PB)
	{
		ft_push(a, b);
		ft_printf("pb\n");
	}
}

void	ft_ssab(int move, t_stack **a, t_stack **b)
{
	if (move == SA)
	{
		ft_swap(a);
		ft_printf("sa\n");
	}
	else if (move == SB)
	{
		ft_swap(b);
		ft_printf("sb\n");
	}
	else if (move == SS)
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}

void	ft_r2ab(int move, t_stack **a, t_stack **b)
{
	if (move == RA)
	{
		ft_rotate(*a);
		ft_printf("ra\n");
	}
	else if (move == RB)
	{
		ft_rotate(*b);
		ft_printf("rb\n");
	}
	else if (move == RR)
	{
		ft_rotate(*a);
		ft_rotate(*b);
		ft_printf("rr\n");
	}
}

void	ft_r3ab(int move, t_stack **a, t_stack **b)
{
	if (move == RRA)
	{
		ft_revrotate(*a);
		ft_printf("rra\n");
	}
	else if (move == RRB)
	{
		ft_revrotate(*b);
		ft_printf("rrb\n");
	}
	else if (move == RRR)
	{
		ft_revrotate(*a);
		ft_revrotate(*b);
		ft_printf("rrr\n");
	}
}
