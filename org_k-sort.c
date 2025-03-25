/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_k-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:43:12 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/21 11:43:16 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_secondlastval(t_stack **stk)
{
	t_stack	*head;

	head = *stk;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	*ft_lastval(t_stack **stk)
{
	t_stack	*head;

	head = *stk;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	ft_biggest(t_stack **stk)
{
	t_stack	*head;
	t_stack	*next;
	t_stack	*slast;
	t_stack	*last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = *stk;
	next = head->next;
	slast = ft_secondlastval(stk);
	last = ft_lastval(stk);
	if ((*head->val) > (*next->val) && (*head->val) > (*slast->val)
		&& (*head->val) > (*last->val))
		return (HEAD);
	if ((*next->val) > (*head->val) && (*next->val) > (*slast->val)
		&& (*next->val) > (*last->val))
		return (NEXT);
	if ((*slast->val) > (*head->val) && (*slast->val) > (*next->val)
		&& (*slast->val) > (*last->val))
		return (SLAST);
	if ((*last->val) > (*head->val) && (*last->val) > (*slast->val)
		&& (*last->val) > (*next->val))
		return (LAST);
	return (0);
}

int	ft_smallest(t_stack **stk)
{
	t_stack	*head;
	t_stack	*next;
	t_stack	*slast;
	t_stack	*last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = *stk;
	next = head->next;
	slast = ft_secondlastval(stk);
	last = ft_lastval(stk);
	if ((*head->val) < (*next->val) && (*head->val) < (*slast->val)
		&& (*head->val) < (*last->val))
		return (HEAD);
	if ((*next->val) < (*head->val) && (*next->val) < (*slast->val)
		&& (*next->val) < (*last->val))
		return (NEXT);
	if ((*slast->val) < (*head->val) && (*slast->val) < (*next->val)
		&& (*slast->val) < (*last->val))
		return (SLAST);
	if ((*last->val) < (*head->val) && (*last->val) < (*slast->val)
		&& (*last->val) < (*next->val))
		return (LAST);
	return (0);
}

int	ft_nextbigger(t_stack **stk)
{
	t_stack	*head;
	t_stack	*next;

	if (!*stk || !(*stk)->next)
		return(0);
	head = *stk;
	next = head->next;
	if (*(next->val) > *(head->val))
		return (1);
	return (0);
}

int	ft_b_moves(t_stack **b, t_stack **a, int a_move)
{
	if (!*b || !(*b)->next)
		return(0);
	if (a_move == PA)
	{
		if (ft_biggest(b) == HEAD)
			if()
	}
	return(0);
}

int	ft_a_moves(t_stack **a)
{
	if (ft_smallest(a) == HEAD)
		return (PB);
	if (ft_smallest(a) == LAST)
		return (RRA);
	if (ft_smallest(a) == NEXT)
		return (SA);
	if (ft_smallest(a) == SLAST)
		return (RRA);
	if (ft_biggest(a) == HEAD)
		return (SA);
	if (ft_biggest(a) == LAST)
		return (RA);
	if (ft_biggest(a) == NEXT)
		return (RRA);
	if (ft_biggest(a) == SLAST)
		return (RA);
	return(0);
}

int	ft_hierarchy(int a, int b)
{
	if (a == SA && b == SB)
		return (SS);
	if (b == SB)
		return (b);
	if (a == RA && b == RB)
		return (RR);
	if (a == RRA && b == RRB)
		return (RRR);
	if (b)
		return (b);
	return (a);
}

int	ft_bestmove(t_stack **a, t_stack **b)
{
	int	final;
	int	move_a;
	int	move_b;

	move_a = 0;
	move_b = 0;
	move_a = ft_a_moves(a);
	move_b = ft_b_moves(b, a, move_a);
	ft_printf("Moves-> a = %d, b = %d\n", move_a, move_b);
	ft_printf("stacks-> a: ");
	ft_printstack(*a);
	ft_printf("	b: ");
	ft_printstack(*b);
	final = ft_hierarchy(move_a, move_b);
	return(final);
}

void	ft_1stsorter(t_stack **a, t_stack **b)
{
	int	move;

	move = 0;
	while (*a && !ft_stkissorted(*a))
	{
		move = ft_bestmove(a, b);
		if (move != 0)
			ft_moveadmin(move, a, b);
		move = 0;
	}
}
