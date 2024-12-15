#include "push_swap.h"

t_stack *stack_new(int value)
{
	t_stack *new;
	
	new = malloc(sizeof(t_stack));
	if(!new)
		return(NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack *bottom;

	if (!new)
		return ;
	if (!stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = new;
}

t_stack *get_bottom(t_stack *stack)
{
	while (stack && stacko->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack *before_bottom(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int get_stack_size(t_stack *stack)
{
	int size;

	size = 0;
	if(!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}