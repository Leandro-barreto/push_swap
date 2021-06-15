#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		parse_cmd(stack_a, NULL, "sa", 1);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	secnd;
	int	third;

	first = (*stack_a)->value;
	secnd = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (secnd < first && first < third)
		parse_cmd(stack_a, NULL, "sa", 1);
	else if (first > third && third > secnd)
		parse_cmd(stack_a, NULL, "ra", 1);
	else if (first > third && secnd > first)
		parse_cmd(stack_a, NULL, "rra", 1);
	if (isok(*stack_a, NULL, 0))
		return ;
	parse_cmd(stack_a, NULL, "sa", 1);
	sort_three(stack_a);
}

int	find_smallest(t_stack *stack)
{
	int	small;

	small = stack->value;
	while (stack)
	{
		if (stack->value < small)
			small = stack->value;
		stack = stack->next;
	}
	return (small);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int	size)
{
	int	small;

	while (size > 3)
	{
		small = find_smallest(*stack_a);
		while ((*stack_a)->value != small)
			parse_cmd(stack_a, NULL, "ra", 1);
		parse_cmd(stack_a, stack_b, "pb", 1);
		size--;
	}
	sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
		parse_cmd(stack_a, stack_b, "sb", 1);
	while (*stack_b)
		parse_cmd(stack_a, stack_b, "pa", 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stat	stat;

	if (isok(*stack_a, *stack_b, 0))
		return ;
	size = ft_stcsize(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
		return (sort_two(stack_a));
	if (size == 3)
		return (sort_three(stack_a));
	if (size <= 5)
		return (sort_five(stack_a, stack_b, size));
	find_stats(stack_a, &stat, size);
	if (size <= 100)
		return (sort_onehundred(stack_a, stack_b, &stat));
	sort_fivehundred(stack_a, stack_b, &stat);
}
