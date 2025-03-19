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

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack *headS;

	if (*src == NULL)
		return ;
	headS = *src;
	*src = headS->next;
	ft_stackfront(dst, headS->val);
	free(headS);
}

void	ft_ssab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_swap(a);
	else if (move == 2)
		ft_swap(b);
	else if (move == 3)
	{
		ft_swap(a);
		ft_swap(b);
	}
}

void	ft_pab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_push(b, a);
	else if (move == 2)
		ft_push(a, b);
}

void	ft_r2ab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_rotate(*a);
	else if (move == 2)
		ft_rotate(*b);
	else if (move == 3)
	{
		ft_rotate(*a);
		ft_rotate(*b);
	}
}

void	ft_r3ab(int move, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_revrotate(*a);
	else if (move == 2)
		ft_revrotate(*b);
	else if (move == 4)
	{
		ft_revrotate(*a);
		ft_revrotate(*b);
	}
}

void	ft_moveadmin(int move, int who, t_stack **a, t_stack **b)
{
	if (move == 1)
		ft_ssab(who, a, b);
	else if (move == 2)
		ft_pab(who, a, b);
	else if (move == 3)
		ft_r2ab(who, a, b);
	else if (move == 4)
		ft_r3ab(who, a, b);
}

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
