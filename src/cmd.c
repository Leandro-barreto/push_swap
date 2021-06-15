#include "push_swap.h"

int	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*aux;

	if (*stack_2 == NULL)
		return (1);
	aux = (*stack_2)->next;
	(*stack_2)->next = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = aux;
	return (1);
}

int	rotate(t_stack **stack_1)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return (1);
	aux = *stack_1;
	*stack_1 = (*stack_1)->next;
	aux2 = *stack_1;
	while (aux2->next)
		aux2 = aux2->next;
	aux2->next = aux;
	aux2->next->next = NULL;
	return (1);
}

int	rev_rotate(t_stack **stack_1)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return (-1);
	if (!((*stack_1)->next->next))
	{
		aux = *stack_1;
		*stack_1 = (*stack_1)->next;
		(*stack_1)->next = aux;
		aux->next = NULL;
		return (1);
	}
	aux = *stack_1;
	*stack_1 = (*stack_1)->next;
	aux2 = *stack_1;
	while (aux2->next->next)
		aux2 = aux2->next;
	*stack_1 = aux2->next;
	aux2->next->next = aux;
	aux2->next = NULL;
	return (1);
}

int	swap(t_stack **stack_1)
{
	t_stack	*aux;

	if (*stack_1 == NULL || (*stack_1)->next == NULL)
		return (1);
	aux = (*stack_1)->next;
	(*stack_1)->next = aux->next;
	aux->next = *stack_1;
	*stack_1 = aux;
	return (1);
}

int	parse_cmd(t_stack **stack_a, t_stack **stack_b, char *cmd, int flag)
{
	int	aux;

	aux = 0;
	if (flag)
	{
		ft_putstr(cmd, 1);
		ft_putstr("\n", 1);
	}
	if (!ft_strncmp(cmd, "pa", 3))
		aux = push(stack_a, stack_b);
	if (!ft_strncmp(cmd, "pb", 3))
		aux = push(stack_b, stack_a);
	if (!(ft_strncmp(cmd, "ra", 3) && ft_strncmp(cmd, "rr", 3)))
		aux = rotate(stack_a);
	if (!(ft_strncmp(cmd, "rb", 3) && ft_strncmp(cmd, "rr", 3)))
		aux = rotate(stack_b);
	if (!(ft_strncmp(cmd, "rra", 4) && ft_strncmp(cmd, "rrr", 4)))
		aux = rev_rotate(stack_a);
	if (!(ft_strncmp(cmd, "rrb", 4) && ft_strncmp(cmd, "rrr", 4)))
		aux = rev_rotate(stack_b);
	if (!(ft_strncmp(cmd, "sa", 3) && ft_strncmp(cmd, "ss", 3)))
		aux = swap(stack_a);
	if (!(ft_strncmp(cmd, "sb", 3) && ft_strncmp(cmd, "ss", 3)))
		aux = swap(stack_b);
	return (aux);
}
