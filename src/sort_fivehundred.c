#include "push_swap.h"

void	get_limits(int limts[2], int flag, t_stat *stat)
{
	limts[0] = stat->smallest;
	limts[1] = stat->biggest;
	if (flag == 1)
		limts[1] = stat->quarter;
	if (flag == 2)
	{
		limts[0] = stat->quarter;
		limts[1] = stat->median;
	}
	if (flag == 3)
	{
		limts[0] = stat->median;
		limts[1] = stat->tquarter;
	}
	if (flag == 4)
		limts[0] = stat->tquarter;
}

void	push_quarter(t_stack **stack_a, t_stack **stack_b, t_stat *stat, int f)
{
	int	count;
	int	total;
	int	l[2];

	get_limits(l, f, stat);
	count = 0;
	total = stat->size;
	while (count < (stat->size / 4 + 3) && stack_a && total--)
	{	
		if ((*stack_a)->value > l[0] && (*stack_a)->value <= l[1])
		{
			parse_cmd(stack_a, stack_b, "pb", 1);
			count++;
		}
		else
			parse_cmd(stack_a, stack_b, "ra", 1);
	}
}

void	sort_fivehundred(t_stack **stack_a, t_stack **stack_b, t_stat *stat)
{
	int	flag;

	flag = 1;
	while (flag < 5)
	{
		push_quarter(stack_a, stack_b, stat, flag);
		while (*stack_b)
			push_back_to_a(stack_a, stack_b);
		while ((*stack_a)->value != stat->smallest)
			parse_cmd(stack_a, stack_b, "ra", 1);
		flag++;
	}
	return ;
}
