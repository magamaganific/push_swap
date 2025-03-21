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

void	*ft_lastval(t_stack **stk)
{
	t_stack	*head;

	head = *stk;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	ft_headsmaller(t_stack **a, t_stack **b)
{
	t_stack	*ahead;
	t_stack *anext;

	ahead = *a;
	if (ahead->next == NULL)
		return ;
	anext = ahead->next;
	if (*(ahead->val) > *(anext->val))
		ft_rotate(a);
}
void	ft_headbigger(t_stack **a)
{
	t_stack	*ahead;
	t_stack *anext;

	ahead = *a;
	if (ahead->next == NULL)
		return ;
	anext = ahead->next;
	if (*(ahead->val) > *(anext->val))
		ft_rotate(a);
}

void	ft_1stsorter(t_stack **a, t_stack **b)
{
	while (*a)
	{
		ft_headbigger(a);
		ft_headsmaller(a, b);
		ft_bottombigger(a, b);
		ft_bottomsmaller(a, b);
	}
}
