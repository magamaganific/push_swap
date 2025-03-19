/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:35:51 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:35:55 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_countnums(t_stack *head)
{
	t_stack	*current;
	size_t	size;

	size = 0;
	current = head;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	*ft_savevals(t_stack *head, size_t size)
{
	t_stack	*current;
	int		*vals;
	size_t	i;

	i = 0;
	current = head;
	vals = (int *)malloc(sizeof(int) * size + 1);
	while (i < size)
	{
		vals[i] = *(current->val);
		current = current->next;
		i++;
	}
	return (vals);
}

void	ft_saverot(t_stack *head, int *vals, size_t size)
{
	t_stack	*current;
	size_t	i;

	current = head;
	i = 0;
	while (i < size)
	{
		*(current->val) = vals[i];
		current = current->next;
		i++;
	}
}

void	ft_rotate(t_stack *head)
{
	size_t	size;
	size_t	i;
	int		*vals;
	int		tmp;

	i = 0;
	tmp = 0;
	size = ft_countnums(head);
	if (size < 2)
		return ;
	vals = ft_savevals(head, size);
	tmp = vals[0];
	while (i < size - 1)
	{
		vals[i] = vals[i + 1];
		i++;
	}
	vals[size - 1] = tmp;
	ft_saverot(head, vals, size);
	free(vals);
}

void	ft_revrotate(t_stack *head)
{
	int		*vals;
	int		size;
	int		tmp;
	int		i;

	tmp = 0;
	size = ft_countnums(head);
	if (size < 2)
		return ;
	vals = ft_savevals(head, size);
	tmp = vals[size - 1];
	i = size - 1;
	while (i > 0)
	{
		vals[i] = vals[i - 1];
		i--;
	}
	vals[0] = tmp;
	ft_saverot(head, vals, size);
	free(vals);
}
