/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:17:28 by mfornovi          #+#    #+#             */
/*   Updated: 2025/04/01 14:17:34 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_id(t_stack *head, int pos)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->val == pos)
			return (i);
		head = head -> next;
		i++;
	}
	return (i);
}

static void	set_index(t_stack **a, int size, int *ordered)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (ordered[i] == tmp->val)
			{
				tmp->val = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static int	*b_sort(int *nums, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	swapped;

	i = -1;
	while (++i < size -1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (nums[j] > nums[j + 1])
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
	}
	return (nums);
}

void	ft_index(int size, t_stack	**a, int *nums)
{
	int	*ordered;

	ordered = b_sort(nums, size);
	set_index(a, size, ordered);
	free(ordered);
}
