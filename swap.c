#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*box;

	if (!*stack || (*stack)->next == NULL)
		return ;
	box = *stack;
	*stack = (*stack)->next;
	box->next = (*stack)->next;
	(*stack)->next = box;
}

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr("ss\n");
}