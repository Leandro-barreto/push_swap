#include "push_swap.h"

int	same(int val, t_stack *stack_a)
{
	static int	a;

	if (val == 0)
		a++;
	if (a > 1)
		return (1);
	while (stack_a)
	{
		if (val && stack_a->value == val)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	check_args(int argc, char *argv[], t_stack *stack_a, t_stack *head)
{
	int		i;
	int		j;
	long	val;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' && argv[i][1])
			j++;
		while (argv[i][j])
			if (argv[i][j] < '0' || argv[i][j++] > '9')
				return (1);
		val = ft_atolong(argv[i]);
		if (val > MAX || val < MIN || same((int)val, head))
			return (1);
		stack_a->value = (int)val;
		if (++i == argc)
			break ;
		stack_a->next = (t_stack *)malloc(sizeof(t_stack));
		*(stack_a->next) = (t_stack){0};
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stacks(t_stack *stack_a)
{
	if (stack_a != NULL)
	{
		free_stacks(stack_a->next);
		free(stack_a);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_b = NULL;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	*stack_a = (t_stack){0};
	if (argc == 2 && check_one_arg(argv[1], stack_a, stack_a))
	{
		free_stacks(stack_a);
		stack_a = NULL;
		return (ft_putstr("Error\n", 2));
	}
	if (argc > 2 && check_args(argc, argv, stack_a, stack_a))
	{
		free_stacks(stack_a);
		stack_a = NULL;
		return (ft_putstr("Error\n", 2));
	}
	sort_stack(&stack_a, &stack_b);
	free_stacks(stack_a);
	stack_a = NULL;
	return (0);
}
