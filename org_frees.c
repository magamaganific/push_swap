/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:39:41 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/19 13:39:46 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

void	ft_freestack(t_stack *head)
{
	t_stack	*current;
	t_stack	*tmp;

	current = head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}