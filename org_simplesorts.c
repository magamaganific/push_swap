/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplesorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:27:37 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:29:14 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bissorted(t_stack *head)
{
	t_stack	*current;
	t_stack	*prev;

	current = head->next;
	prev = head;
	while (current != NULL)
	{
		if (prev->val < current->val)
			return (0);
		prev = current;
		current = current->next;
	}
	return (1);
}

int	ft_stkissorted(t_stack *head)
{
	t_stack	*current;
	t_stack	*prev;

	current = head->next;
	prev = head;
	while (current != NULL)
	{
		if (prev->val > current->val)
			return (0);
		prev = current;
		current = current->next;
	}
	return (1);
}

void	ft_sort3(t_stack **a)
{
	t_stack	*head;
	t_stack	*next;

	head = *a;
	next = head->next;
	while (!ft_stkissorted(*a))
	{
		if (head->val > next->val)
		{
			ft_swap(a);
			ft_printf("sa\n");
		}
		else
		{
			ft_revrotate(*a);
			ft_printf("rra\n");
		}
	}
}

void	ft_sort4(t_stack **a, t_stack **b)
{
	int	max;

	max = ft_max_node(a);
	if (max == 1)
		ft_moveadmin(SA, a, b);
	else if (max == 2)
	{
		ft_moveadmin(RRA, a, b);
		ft_moveadmin(RRA, a, b);
	}
	else if (max == 3)
		ft_moveadmin(RRA, a, b);
	ft_moveadmin(PB, a, b);
	ft_sort3(a);
	ft_moveadmin(PA, a, b);
	ft_moveadmin(RA, a, b);
	return ;
}

void	ft_sort5(t_stack **a, t_stack **b)
{
	int	max;

	max = ft_max_node(a);
	if (max == 1)
		ft_moveadmin(SA, a, b);
	else if (max == 2)
	{
		ft_moveadmin(RA, a, b);
		ft_moveadmin(RA, a, b);
	}
	else if (max == 3)
	{
		ft_moveadmin(RRA, a, b);
		ft_moveadmin(RRA, a, b);
	}
	else if (max == 4)
		ft_moveadmin(RRA, a, b);
	ft_moveadmin(PB, a, b);
	ft_sort4(a);
	ft_moveadmin(PA, a, b);
	ft_moveadmin(RA, a, b);
	return ;
}
