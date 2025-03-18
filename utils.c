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

void	ft_freestack(t_stack *head)
{
	t_stack	*current;
	t_stack *tmp;

	current = head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

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
	t_stack *newnum;

	newnum = ft_addval(num);
	if(*head == NULL)
		*head = newnum;
	else
		ft_addlast(head, newnum);
}
void	ft_stackfront(t_stack **head, int *num)
{
	t_stack *newnum;

	newnum = ft_addval(num);
	if(*head == NULL)
		*head = newnum;
	else
	{
		newnum->next = *head;
		*head = newnum;
	}
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

void	ft_swap(t_stack **stck)
{
	int	*tmp;
	t_stack *num1;
	t_stack *num2;

	num1 = *stck;
	num2 = (*stck)->next;
	tmp = num1->val;
	num1->val = num2->val;
	num2->val = tmp;
}

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
	return(size);
}

int	*ft_savevals(t_stack *head, size_t size)
{
	t_stack	*current;
	int		*vals;
	int		i;

	i = 0;
	current = head;
	vals = (int *)malloc(sizeof(int) * size);
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
	int		i;

	current = head;
	i = 0;
	while (i < size)
	{
		*(current->val) = vals[i];
		current	= current->next;
		i++;
	}
}
void	ft_rotate(t_stack *head)
{
	size_t		size;
	int		*vals;
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	size = ft_countnums(head);
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
	vals = ft_savevals(head, size);
	tmp = vals[size - 1];
	i = size;
	while (i > 0)
	{
		vals[i] = vals[i - 1];
		i--;
	}
	vals[0] = tmp;
	ft_saverot(head, vals, size);
	free(vals);
}

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack *headS;

	headS = *src;
	*src = headS->next;

	ft_stackfront(dst, headS->val);
	free(headS);
}
/*
void	ft_moveadmin(int move, t_stack *a, t_stack *b)
{
	if (move = "sa")
		ft_swap(a);
	else if (move = "sb")
		ft_swap(b);
	else if (move = "ss")
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (move = "pa")
		ft_push(a, b);
	else if (move = "pb")
		ft_push(b, a);
}*/

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
	ft_push(&a, &b);
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
