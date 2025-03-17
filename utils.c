/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:44:43 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/17 10:44:52 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_addval(int num)
{
	t_stack	*newval;

	newval = (t_stack *)malloc(sizeof(t_stack));
	if (newval != NULL)
	{
		newval->val = num;
		newval->next = NULL;
	}
	return (newval);
}


void	ft_stacknum(t_stack **head, int *num)
{
	t_stack *newnum;

	newnum = ft_addval(num);
	if(*head == NULL)
		*head = newnum;
	else
		ft_addlast(head, newnum);
}
