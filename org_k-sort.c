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

int	*ft_smaller(t_stack **a)
{
	int	*moves;

	if (!*a)
		return (0);
	moves = NULL;
	if (ft_smallest(a) == HEAD)
		return (&PB);
	return (NULL);
	// if (ft_smallest(a) == NEXT && ft_biggest(a) == HEAD)
	// 	return (&RA, &PB);
}

void	ft_1stsorter(t_stack **a, t_stack **b)
{
	int	*moves;
	int	i;

	moves = NULL;
	i = 0;
	while (*a)
	{
		if ((*a)->next == NULL)
			ft_moveadmin(PB, a, b);
		while (moves == NULL)
		{
			moves = ft_smaller(a);
			//moves = ft_bigger(a, b);
		}
		while (moves[i] != 0)
		{
			ft_moveadmin(moves[i], a, b);
			i++;
		}
		free(moves);
		moves = NULL;
		i = 0;
	}
}

