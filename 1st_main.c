/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1st_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:10:59 by mfornovi          #+#    #+#             */
/*   Updated: 2025/03/11 09:11:04 by mfornovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack
	*ft_stklast(t_stack *lst)
{
	t_stack	*box;

	if (!lst)
		return (NULL);
	box = lst;
	while (box->next)
		box = box->next;
	return (box);
}

t_stack
	*ft_stacknew(int *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> next = NULL;
	new -> val = *content;
	return (new);
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_stklast(*lst);
	if (!*lst)
	{
		*lst = new;
	}
	last -> next = new;
}

int	main(void)
{
	t_stack	*stack;
	t_stack	**stk;
	int		num1;
	int		num2;

	printf("hiii\n");
	num1 = 1;
	num2 = 2;
	stack = ft_stacknew(&num1);
	printf("1 = %d\n", stack->val);
	ft_stkadd_back(stk, stack);
}
