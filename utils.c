#include "push_swap.h"

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}