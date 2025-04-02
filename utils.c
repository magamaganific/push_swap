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

void	ft_addlast(t_stack **head, t_stack *newnum)
{
	t_stack	*current;

	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = newnum;
}

void	ft_stacknum(t_stack **head, int num)
{
	t_stack	*newnum;

	newnum = ft_addval(num);
	if (*head == NULL)
		*head = newnum;
	else
		ft_addlast(head, newnum);
}

void	ft_printstack(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d -> ", (current->val));
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	ft_max_node(t_stack **a)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		res;

	i = 0;
	tmp = *a;
	max = tmp->val;
	res = 0;
	while (tmp)
	{
		if (tmp->val > max)
		{
			max = tmp->val;
			res = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}
