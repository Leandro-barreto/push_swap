#include "push_swap.h"

void	sort_lst(int *lst, int size)
{
	int		aux;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (lst[i] > lst[j])
			{
				aux = lst[i];
				lst[i] = lst[j];
				lst[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	find_stats(t_stack **stack_a, t_stat *stat, int size)
{
	t_stack	*aux;
	int		*lst;
	int		i;

	aux = *stack_a;
	lst = (int *)malloc(sizeof(int) * (size + 1));
	i = 0;
	while (*stack_a)
	{
		lst[i++] = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
	}
	sort_lst(lst, size);
	stat->smallest = lst[0];
	stat->quarter = lst[size / 4];
	stat->median = lst[size / 2];
	stat->tquarter = lst[(size / 4)*3];
	stat->size = size;
	stat->biggest = lst[size - 1];
	free(lst);
	*stack_a = aux;
}

t_moves	lesser_moves(t_moves moves)
{
	if (moves.uphigh <= moves.uplow && moves.uphigh <= moves.downlow
		&& moves.uphigh <= moves.downhigh)
		moves.flag = 1;
	else if (moves.downhigh < moves.uphigh && moves.downhigh <= moves.uplow
		&& moves.downhigh <= moves.downlow)
		moves.flag = 2;
	else if (moves.uplow < moves.uphigh && moves.uplow < moves.downhigh
		&& moves.uplow <= moves.downlow)
		moves.flag = 3;
	else if (moves.downlow < moves.uphigh && moves.downlow < moves.downhigh
		&& moves.downlow < moves.uplow)
		moves.flag = 4;
	return (moves);
}

t_moves	get_moves(t_stack *stack, int size)
{
	int		count;
	t_moves	moves;

	count = 0;
	moves.low = stack->value;
	moves.high = stack->value;
	while (stack)
	{
		count++;
		if (stack->value >= moves.high)
		{
			moves.high = stack->value;
			moves.uphigh = count;
			moves.downhigh = size + 1 - count;
		}
		if (stack->value <= moves.low)
		{
			moves.low = stack->value;
			moves.uplow = count;
			moves.downlow = size + 1 - count;
		}
		stack = stack->next;
	}
	return (lesser_moves(moves));
}
