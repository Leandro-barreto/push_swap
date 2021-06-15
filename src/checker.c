#include "push_swap.h"

int	get_cmd(t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	char	*cmd;

	count = -1;
	cmd = (char *)malloc(5 * sizeof(char));
	while (read(0, cmd, 3) && (++count != -1))
	{
		if (cmd[0] == 0)
			break ;
		if (cmd[0] == '\n')
			cmd = cmd + 1;
		if (cmd[2] == '\n')
			cmd[2] = 0;
		cmd[3] = 0;
		if (!parse_cmd(stack_a, stack_b, cmd, 0))
			count = -2;
	}
	free(cmd);
	return (count);
}

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
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j])
			if (argv[i][j] < '0' || argv[i][j++] > '9')
				return (1);
		val = ft_atoi(argv[i]);
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

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		aux;

	aux = 0;
	stack_b = NULL;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	*stack_a = (t_stack){0};
	if (check_args(argc, argv, stack_a, stack_a))
		return (ft_putstr("Error\n", 1));
	if (aux == 0 && get_cmd(&stack_a, &stack_b) == -1)
		return (ft_putstr("Error\n", 1));
	isok(stack_a, stack_b, 1);
}
