/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_push-swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:34:40 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:50:16 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackfront(t_stack **head, int num)
{
	t_stack	*newnum;

	newnum = ft_addval(num);
	if (*head == NULL)
		*head = newnum;
	else
	{
		newnum->next = *head;
		*head = newnum;
	}
}

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*shead;

	if (*src == NULL)
		return ;
	shead = *src;
	*src = shead->next;
	ft_stackfront(dst, shead->val);
	free(shead);
}

void	ft_swap(t_stack **stck)
{
	int		tmp;
	t_stack	*num1;
	t_stack	*num2;

	num1 = *stck;
	num2 = (*stck)->next;
	tmp = num1->val;
	num1->val = num2->val;
	num2->val = tmp;
}
