#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	get_numbers(char *av, t_stack **stack_a)
{
	long int	n;
	char		**param;
	int			i;

	param = ft_split (av, ' ');
	i = 0;
	while (param[i] != '\0')
	{
		if (input_is_correct(param[i]))
		{
			n = ft_atoi(param[i]);
			if (n > INT_MAX || n < INT_MIN)
				error_exit(stack_a, NULL);
			stack_add(stack_a, stack_new(n));
		}
		else
			error_exit(NULL, NULL);
		free(param[i]);
		i++;
	}
	free(param);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ac)
	{
		get_numbers(av[i], &stack_a);
		i++;
	}
	if (is_duplicate(stack_a))
		error_exit(&stack_a, NULL);
	stack_size = get_stack_size(stack_a);
	get_index(stack_a, stack_size + 1);
	pusk_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}