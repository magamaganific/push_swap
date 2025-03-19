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
	t_stack	*tmp;

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
	t_stack	*newnum;

	newnum = ft_addval(num);
	if (*head == NULL)
		*head = newnum;
	else
		ft_addlast(head, newnum);
}

void	ft_stackfront(t_stack **head, int *num)
{
	t_stack	*newnum;

	newnum = ft_addval(num);
	if (*head == NULL)
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
	int		*tmp;
	t_stack	*num1;
	t_stack	*num2;

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
	return (size);
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
		current = current->next;
		i++;
	}
}

void	ft_rotate(t_stack *head)
{
	size_t		size;
	int			*vals;
	int			tmp;
	int			i;

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
	t_stack	*shead;

	if (*src == NULL)
		return ;
	shead = *src;
	*src = shead->next;
	ft_stackfront(dst, shead->val);
	free(shead);
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

int	ft_stkissorted(t_stack *head)
{
	t_stack	*current;
	t_stack	*prev;

	current = head->next;
	prev = head;
	while (current != NULL)
	{
		if (*(prev->val) > *(current->val))
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
		if (*(head->val) > *(next->val))
			ft_swap(a);
		else
			ft_revrotate(*a);
	}
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	if (ft_countnums(*a) == 2)
		ft_swap(a);
	else if (ft_countnums(*a) == 3)
		ft_sort3(a);
}

int	ft_strisnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_countargs(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	*ft_check_args(char **args)
{
	size_t	size;
	int		*nums;
	int		i;

	size = ft_countargs(args);
	nums = (int *)malloc(sizeof(int) * size + 1);
	i = 0;
	while (i < size)
	{
		if (ft_strisnum(args[i]) == 0)
		{
			ft_printf("Error: Invalid input.\n");
			free(nums);
			exit(1);
		}
		nums[i] = ft_atoi(args[i]);
		i++;
	}
	return (nums);
}

int	ft_dupedints(t_stack *a)
{
	t_stack	*num;
	t_stack	*check;

	num = a;
	check = num->next;
	while (num != NULL)
	{
		check = num->next;
		while (check != NULL)
		{
			if (*(num->val) == *(check->val))
				return (1);
			check = check->next;
		}
		num = num->next;
	}
	return (0);
}

void	ft_stackargs(char **args, t_stack **a)
{
	size_t	size;
	int		*nums;
	int		i;

	nums = ft_check_args(args);
	size = ft_countargs(args);
	i = 0;
	while (i < size)
	{
		ft_stacknum(a, &nums[i]);
		i++;
	}
	if (ft_dupedints(*a) != 0)
	{
		ft_printf("Error: Duplicated input.\n");
		exit (0);
	}
}

char	**ft_args_to_stack(int ac, char **av)
{
	char	**args;

	args = (char **)malloc(sizeof(char *) * ac);
	args[ac-- - 1] = NULL;
	while (ac--)
		args[ac] = ft_strdup(av[ac + 1]);
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(1);
	if (ac == 2)
	{
		if (ft_strlen(av[1]))
			args = ft_split(av[1], ' ');
		else
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	else
		args = ft_args_to_stack(ac, av);
	ft_printf("initial stack:\n");//test
	ft_stackargs(args, &a);
	ft_printstack(a);//test
	if (!ft_stkissorted(a))
		ft_push_swap(&a, &b);
	ft_printf("final stack:\n");//test
	ft_printstack(a);//test
	ft_freestack(a);
	ft_freestack(b);
	return (0);
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