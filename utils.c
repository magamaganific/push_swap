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

void	ft_stacknum(t_stack **head, int *num)
{
	t_stack *newnum;

	newnum = ft_addval(num);
	if(*head == NULL)
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
		ft_printf("%d -> ", *(current->val));
		current = current->next;
	}
	ft_printf("NULL\n");
}

void	ft_swap(t_stack *num1, t_stack *num2)
{
	int	*tmp;

	tmp = num1->val;
	num1->val = num2->val;
	num2->val = tmp;
}

int	ft_countnums(t_stack *head)
{
	t_stack	*current;
	int		*size;

	current = head;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return(size);
}

int	**ft_savevals(s_stack *head, int size)
{
	t_stack	*current;
	int		**vals;
	int		i;

	i = 0;
	current = head;
	vals = (int **)malloc(sizeof(int) * size);
	while (i < size)
	{
		vals[i] = *(current->val);
		current = current->next;
		i++;
	}
	return (vals);
}

void	ft_rotate(t_stack *head)
{
	t_stack	*current;
	int		**vals;
	int		*size;
	int		*tmp;
	int		i;

	i = 0;
	tmp = 0;
	current = head;
	size = ft_countnums(head);
	vals = ft_savevals(head, size);
	tmp = vals[0];
	while (i < size - 1)
	{
		vals[i] = vals[i + 1];
		i++;
	}
	vals[size - 1] = tmp;
	i = 0;
	while (i < size)
	{
		*(current->val) = vals[i];
		current	= current->next;
	}
}

void	ft_revrotate(t_stack *head)
{
	t_stack	*current;
	int		**vals;
	int		*size;
	int		*tmp;
	int		i;

	tmp = 0;
	current = head;
	size = ft_countnums(head);
	i = size;
	vals = ft_savevals(head, size);
	tmp = vals[size];
	while (i < size - 1)
	{
		vals[i] = vals[i + 1];
		i++;
	}
	vals[size - 1] = tmp;
	i = 0;
	while (i < size)
	{
		*(current->val) = vals[i];
		current	= current->next;
	}
}
