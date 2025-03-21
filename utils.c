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

t_stack	*ft_addval(int *num)
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
		ft_printf("%d -> ", *(current->val));
		current = current->next;
	}
	ft_printf("NULL\n");
}
/*
int main(void) //test
{
	int nums[] = {20, 30, 40, 50};
	int	num[] = {10};
	int n = sizeof(nums)/sizeof(nums[0]);
	int m = sizeof(num)/sizeof(num[0]);
	int i = 0;
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;

	ft_printf("initial stacks:\n");
	while (i < n)
	{
		ft_stacknum(&a, &nums[i]);
		i++;
	}
	ft_printstack(a);
	i = 0;
	while (i < m)
	{
		ft_stacknum(&b, &num[i]);
		i++;
	}
	ft_printstack(b);
	ft_printf("push a b:\n");
	ft_moveadmin(2, 1, &a, &b);
	ft_printstack(a);
	ft_printstack(b);
	ft_printf("push b a:\n");
	ft_printstack(a);
	ft_printstack(b);
	ft_printf("push b a:\n");
	ft_push(&b, &a);
	ft_printstack(a);
	ft_printstack(b);
	ft_printf("push b a:\n");
	ft_push(&b, &a);
	ft_printstack(a);
	ft_printstack(b);
	ft_printf("revrotate a:\n");
	ft_revrotate(a);
	ft_printstack(a);
	ft_printf("rotate b:\n");
	ft_rotate(b);
	ft_printstack(b);
	ft_printf("swap a:\n");
	ft_swap(&a);
	ft_printstack(a);
	ft_printstack(b);
	ft_freestack(a);
	ft_freestack(b);
}
*/