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

t_stack	*ft_secondlastval(t_stack **stk)
{
	t_stack	*head;
	t_stack	*next;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = *stk;
	next = head->next;
	while (next->next != NULL)
	{
		head = head->next;
		next = head->next;
	}
	return (head);
}

t_stack	*ft_lastval(t_stack **stk)
{
	t_stack	*head;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = *stk;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int	ft_slastnum(t_stack	**stack)
{
	t_stack	*point;
	int		num;

	if (!*stack || (*stack)->next == NULL)
		return (0);
	point = ft_secondlastval(stack);
	num = *(point->val);
	return (num);
}

int	ft_lastnum(t_stack	**stack)
{
	t_stack	*point;
	int		num;

	if (!*stack || (*stack)->next == NULL)
		return (0);
	point = ft_lastval(stack);
	num = *(point->val);
	return (num);
}
int	ft_thirdnum(t_stack	**stack)
{
	t_stack	*point;
	int		num;

	if (!*stack || (*stack)->next == NULL)
		return (0);
	point = (*stack)->next;
	if (point->next == NULL)
		return (0);
	point = point->next;
	num = *(point->val);
	return (num);
}
int	ft_nextnum(t_stack	**stack)
{
	t_stack	*point;
	int		num;

	if (!*stack || (*stack)->next == NULL)
		return (0);
	point = (*stack)->next;
	num = *(point->val);
	return (num);
}

int	ft_firstnum(t_stack	**stack)
{
	t_stack	*point;
	int		num;

	point = *stack;
	num = *(point->val);
	return (num);
}

int	ft_minval(t_stack **a)
{
	t_stack	*point;
	int		val;

	val = *((*a)->val);
	point = (*a)->next;
	while (point)
	{
		if (val > *(point->val))
			val = *(point->val);
		point = point->next;
	}
	return (val);
}

int	ft_maxval(t_stack **a)
{
	t_stack	*point;
	int		val;

	val = *((*a)->val);
	point = (*a)->next;
	while (point)
	{
		if (val < *(point->val))
			val = *(point->val);
		point = point->next;
	}
	return (val);
}

int	ft_biggestav(t_stack **stk)
{
	int	head;
	int	next;
	int	slast;
	int	last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = ft_firstnum(stk);
	next = ft_nextnum(stk);
	slast = ft_slastnum(stk);
	last = ft_lastnum(stk);
	// ft_printf("bigvals-> head: %d, next: %d, slast: %d, last: %d\n", head, next, slast, last);
	if (head > next && head > slast && head > last)
		return (HEAD);
	if (next > head && next > slast && next > last)
		return (NEXT);
	if (slast > head && slast > next && slast > last)
		return (SLAST);
	if (last > head && last > slast && last > next)
		return (LAST);
	if (slast == next)
		return (NEXT);
	return (0);
}

int	ft_smallestav_val(t_stack **stk)
{
	int	head;
	int	next;
	int	slast;
	int	last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = ft_firstnum(stk);
	next = ft_nextnum(stk);
	slast = ft_slastnum(stk);
	last = ft_lastnum(stk);
	if (head < next && head < slast && head < last)
		return (head);
	if (next < head && next < slast && next < last)
		return (next);
	if (slast < head && slast < next && slast < last)
		return (slast);
	if (last < head && last < slast && last < next)
		return (last);
	if (slast == next)
		return (next);
	return (0);
}


int	ft_biggestav_val(t_stack **stk)
{
	int	head;
	int	next;
	int	slast;
	int	last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = ft_firstnum(stk);
	next = ft_nextnum(stk);
	slast = ft_slastnum(stk);
	last = ft_lastnum(stk);
	if (head > next && head > slast && head > last)
		return (head);
	if (next > head && next > slast && next > last)
		return (next);
	if (slast > head && slast > next && slast > last)
		return (slast);
	if (last > head && last > slast && last > next)
		return (last);
	if (slast == next)
		return (next);
	return (0);
}

int	ft_smallestav(t_stack **stk)
{
	int	head;
	int	next;
	int	slast;
	int	last;

	if (!*stk || (*stk)->next == NULL)
		return (0);
	head = ft_firstnum(stk);
	next = ft_nextnum(stk);
	slast = ft_slastnum(stk);
	last = ft_lastnum(stk);
	// ft_printf("smallvals-> head: %d, next: %d, slast: %d, last: %d\n", head, next, slast, last);
	if (head < next && head < slast && head < last)
		return (HEAD);
	if (next < head && next < slast && next < last)
		return (NEXT);
	if (slast < head && slast < next && slast < last)
		return (SLAST);
	if (last < head && last < slast && last < next)
		return (LAST);
	if (slast == next)
		return (NEXT);
	return (0);
}

// int	ft_b_moves2(t_stack **b, int min, int max)
// {
// 	if (ft_countnums(*b) == 2)
// 	{
// 		if (ft_firstnum(b) < ft_nextnum(b))
// 			return (SB);
// 		return (PA);
// 	}
// 	else if (ft_biggestav(b) == NEXT || ft_firstnum(b) < ft_nextnum(b))
// 		return (SB);
// 	else if (ft_biggestav(b) == LAST || ft_biggestav(b) == SLAST || ft_firstnum(b) == min)
// 		return (RRB);
// 	else if (ft_biggestav(b) == HEAD || ft_firstnum(b) == max || ft_countnums(*b) == 1)
// 		return (PA);
// 	return (0);
// }

// int	ft_a_moves2(t_stack **a, t_stack **b, int min)
// {
// 	if (!*a || !(*a)->next)
// 		return (0);
// 	else if (ft_nextnum(a) == min || ft_firstnum(a) > ft_nextnum(a))
// 		return(SA);
// 	else if (ft_firstnum(a) < ft_firstnum(b))
// 		return(PB);
// 	return (0);
// }

// int	ft_hierarchy2(int a, int b)
// {
// 	if (a == PB && b == RB)
// 		return (b);
// 	else if (a == SA && b == SB)
// 		return (SS);
// 	else if (a == RA && b == RB)
// 		return (RR);
// 	else if (a == RRA && b == RRB)
// 		return (RRR);
// 	else if (a)
// 		return (a);
// 	return (b);
// }


int	ft_a_moves2(t_stack **a, t_stack **b/*,int min*/)
{
	if (!*a || !(*a)->next || !*b)
		return (0);
	if (ft_minval(a) != ft_firstnum(a) != ft_smallestav_val(a)
		&& ((ft_biggestav(a) == NEXT && ft_firstnum(a) < ft_lastnum(a))
			|| (ft_firstnum(a) > ft_nextnum(a) && (ft_countnums(*a) == 2
					|| ft_nextnum(a) > ft_lastnum(a))) || ((ft_nextnum(a)
					&& ft_lastnum(a)) > ft_firstnum(a) && ft_countnums(*a) > 5)
			|| (ft_nextnum(a) < ft_firstnum(a)
				&& ft_firstnum(a) < ft_thirdnum(a) && ft_countnums(*a) > 2)))
		return (SB);
	else if ((ft_firstnum(a) > ft_firstnum(b) > ft_nextnum(a))
		|| ((ft_firstnum(a) > (ft_thirdnum(a) || ft_nextnum(a)) > ft_slastnum(a))
		&& ft_countnums(*a) > 5))
		return (PA);
	else if (((ft_biggestav(a) == LAST && ft_smallestav(b) == HEAD
				&& ft_firstnum(a) < ft_firstnum(b))
			&& (ft_smallestav_val(b) < (ft_biggestav_val(a) && ft_firstnum(a))))
		|| ((ft_firstnum(a) < ft_lastnum(a) && ft_firstnum(a) > ft_slastnum(a))))
		return (RRB);
	else if ((ft_biggestav(a) == NEXT && ft_firstnum(a) > ft_lastnum(a))
		|| (ft_biggestav(a) == HEAD && ft_smallestav_val(b) > ft_firstnum(a)))
		return (RB);
	return (0);
}

int	ft_b_moves2(t_stack **b, t_stack **a, int max)
{
	// ft_printf("\n----------------------------\n	smallest = %c\n", ft_smallestav(b));
	if (!*b)
		return (0);
	if ((ft_firstnum(b) == max && ft_countnums(*b) == 2))
		return (SA);
	else if (((ft_lastnum(b) == max && ft_countnums(*b) == 2)
		|| (ft_smallestav(b) == HEAD || ft_countnums(*b) == 1)))
		return (PB);
	else if (ft_smallestav(b) == NEXT && ft_thirdnum(b) < ft_nextnum(b))
		return (RA);
	else if (ft_smallestav(b) == NEXT || (ft_firstnum(b) > ft_nextnum(b)))
		return (SA);
	else if (ft_smallestav(b) == LAST || ft_smallestav(b) == SLAST
		|| ft_slastnum(b) < (ft_nextnum(a) || ft_firstnum(a)))
		return (RRA);
	return (0);
}

int	ft_hierarchy2(int b, int a)
{
	if (b == PB && a == RB)
		return (a);
	else if (b == SA && a == SB)
		return (SS);
	else if (b == RA && a == RB)
		return (RR);
	else if (b == RRA && a == RRB)
		return (RRR);
	else if (a)
		return (a);
	return (b);
}

int	ft_bestmove2(t_stack **a, t_stack **b, /*int min,*/ int max)
{
	int	final;
	int	move_a;
	int	move_b;

	move_a = 0;
	move_b = 0;
	move_b = ft_b_moves2(a, b, max);
	move_a = ft_a_moves2(b, a/*, min*/);
	// ft_printf("Moves-> a = %d, b = %d\n", move_a, move_b);
	// ft_printf("stacks-> a: ");
	// ft_printstack(*a);
	// ft_printf("	b: ");
	// ft_printstack(*b);
	final = ft_hierarchy2(move_a, move_b);
	return (final);
}

int	ft_b_moves(t_stack **b, t_stack **a/*,int min*/)
{
	if (!*b || !(*b)->next)
		return (0);
	if (ft_minval(b) != ft_firstnum(b) != ft_smallestav_val(b)
		&& ((ft_biggestav(b) == NEXT && ft_firstnum(b) < ft_lastnum(b))
			|| (ft_firstnum(b) > ft_nextnum(b) && (ft_countnums(*b) == 2
					|| ft_nextnum(b) > ft_lastnum(b))) || ((ft_nextnum(b)
					&& ft_lastnum(b)) > ft_firstnum(b) && ft_countnums(*b) > 5)
			|| (ft_nextnum(b) < ft_firstnum(b)
				&& ft_firstnum(b) < ft_thirdnum(b) && ft_countnums(*b) > 2)))
		return (SB);
	else if ((ft_firstnum(b) > ft_firstnum(a) > ft_nextnum(b))
		|| ((ft_firstnum(b) > (ft_thirdnum(b) || ft_nextnum(b)) > ft_slastnum(b))
		&& ft_countnums(*b) > 5))
		return (PA);
	else if (((ft_biggestav(b) == LAST && ft_smallestav(a) == HEAD
				&& ft_firstnum(b) < ft_firstnum(a))
			&& (ft_smallestav_val(a) < (ft_biggestav_val(b) && ft_firstnum(b))))
		|| ((ft_firstnum(b) < ft_lastnum(b) && ft_firstnum(b) > ft_slastnum(b))))
		return (RRB);
	else if ((ft_biggestav(b) == NEXT && ft_firstnum(b) > ft_lastnum(b))
		|| (ft_biggestav(b) == HEAD && ft_smallestav_val(a) > ft_firstnum(b)))
		return (RB);
	return (0);
}

int	ft_a_moves(t_stack **a, t_stack **b, int max)
{
	// ft_printf("\n----------------------------\n	smallest = %c\n", ft_smallestav(a));
	if ((ft_firstnum(a) == max && ft_countnums(*a) == 2))
		return (SA);
	else if (((ft_lastnum(a) == max && ft_countnums(*a) == 2)
		|| (ft_smallestav(a) == HEAD || ft_countnums(*a) == 1)))
		return (PB);
	else if (ft_smallestav(a) == NEXT && ft_thirdnum(a) < ft_nextnum(a))
		return (RA);
	else if (ft_smallestav(a) == NEXT || (ft_firstnum(a) > ft_nextnum(a)))
		return (SA);
	else if (ft_smallestav(a) == LAST || ft_smallestav(a) == SLAST
		|| ft_slastnum(a) < (ft_nextnum(b) || ft_firstnum(b)))
		return (RRA);
	return (0);
}

int	ft_hierarchy(int a, int b)
{
	if (a == PB && b == RB)
		return (b);
	else if (a == SA && b == SB)
		return (SS);
	else if (a == RA && b == RB)
		return (RR);
	else if (a == RRA && b == RRB)
		return (RRR);
	else if (b)
		return (b);
	return (a);
}

int	ft_bestmove(t_stack **a, t_stack **b, int max/*, int min*/)
{
	int	final;
	int	move_a;
	int	move_b;

	move_a = 0;
	move_b = 0;
	move_a = ft_a_moves(a, b, max);
	move_b = ft_b_moves(b, a/*, min*/);
	// ft_printf("Moves-> a = %d, b = %d\n", move_a, move_b);
	// ft_printf("stacks-> a: ");
	// ft_printstack(*a);
	// ft_printf("	b: ");
	// ft_printstack(*b);
	final = ft_hierarchy(move_a, move_b);
	return (final);
}

void	ft_sorter(t_stack **a, t_stack **b)
{
	int	move;
	int	max;
	int	min;

	max = ft_maxval(a);
	min = ft_minval(a);
	min = 0;
	move = 0;
	while (*a)
	{
		move = ft_bestmove(a, b, max/*, min*/);
		if (move != 0)
			ft_moveadmin(move, a, b);
		move = 0;
	}
	while (*b)
	{
		// ft_printf("\n2nd Sort: ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		move = ft_bestmove2(a, b, /*min*/ max);
		if (move != 0)
			ft_moveadmin(move, a, b);
		move = 0;
	}
}
