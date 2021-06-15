#include "push_swap.h"

int	check_rra(t_stack *stack_a, int ref)
{
	int	count;

	if (!stack_a->next)
		return (0);
	// aux = stack_a->next->value;
	// if ((!c && aux < ref) || (c && aux >= ref))
	// 	return (0);
	count = 0;
	while (stack_a)
	{
		count++;
		if (stack_a->value < ref)
			count = 0;
		stack_a = stack_a->next;
	}
	if (!count)
		return (1);
	return (0);
}

void	push_below_median(t_stack **stack_a, t_stack **stack_b, t_stat *stat)
{
	int	count;
	int	total;

	count = 0;
	total = stat->size;
	while (count < ((stat->size / 2) + (stat->size % 2)) && stack_a)
	{	
		if ((*stack_a)->value < stat->median)
		{	
			parse_cmd(stack_a, stack_b, "pb", 1);
			count++;
		}
		else
		{
			if (check_rra(*stack_a, stat->median))
				parse_cmd(stack_a, stack_b, "rra", 1);
			else
				parse_cmd(stack_a, stack_b, "ra", 1);
		}
	}
}

void	push_above_median(t_stack **stack_a, t_stack **stack_b, t_stat *stat)
{
	int	count;
	int	total;

	count = 0;
	total = stat->size;
	while (count < ((stat->size / 2) + (stat->size % 2)) && stack_a && total--)
	{
		if ((*stack_a)->value >= stat->median)
		{
			parse_cmd(stack_a, stack_b, "pb", 1);
			count++;
		}
		else
		{
			parse_cmd(stack_a, stack_b, "ra", 1);
		}
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_moves	moves;

	moves = get_moves(*stack_b, ft_stcsize(*stack_b));
	if (moves.flag == 1)
		while ((*stack_b)->value != moves.high)
			parse_cmd(stack_a, stack_b, "rb", 1);
	if (moves.flag == 2)
		while ((*stack_b)->value != moves.high)
			parse_cmd(stack_a, stack_b, "rrb", 1);
	if (moves.flag == 3)
		while ((*stack_b)->value != moves.low)
			parse_cmd(stack_a, stack_b, "rb", 1);
	if (moves.flag == 4)
		while ((*stack_b)->value != moves.low)
			parse_cmd(stack_a, stack_b, "rrb", 1);
	parse_cmd(stack_a, stack_b, "pa", 1);
	if (moves.flag > 2)
		parse_cmd(stack_a, stack_b, "ra", 1);
}

void	sort_onehundred(t_stack **stack_a, t_stack **stack_b, t_stat *stat)
{
	push_below_median(stack_a, stack_b, stat);
	while (*stack_b)
		push_back_to_a(stack_a, stack_b);
	push_above_median(stack_a, stack_b, stat);
	while (*stack_b)
		push_back_to_a(stack_a, stack_b);
	while ((*stack_a)->value != stat->smallest)
		parse_cmd(stack_a, stack_b, "ra", 1);
	return ;
}
