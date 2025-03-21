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

void	ft_1stsorter(t_stack **a, t_stack **b)
{
	t_stack	*ahead;
	t_stack	*bhead;
	t_stack	*anext;
	t_stack	*bnext;

	ahead = *a;
	bhead = *b;
	anext = ahead->next;
	bnext = bhead->next;
	while (ahead != NUlL)
	{
		if (ahead->val < anext->val)
			ft_push()
	}
}
