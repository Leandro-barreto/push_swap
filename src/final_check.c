#include "push_swap.h"

int	ft_putstr(char *s, int fd)
{
	int	n;

	n = 0;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
		n++;
	}
	return (n);
}

long	ft_atolong(const char *str)
{
	long int	count;
	int			sign;

	count = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		if (*str)
			str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		count = count * 10 + (*str - '0');
		str++;
	}
	return ((long)(count * sign));
}

int	ft_stcsize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	isok(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_b)
		return (ft_putstr("KO\n", 1));
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
		{
			if (flag)
				return (ft_putstr("KO\n", 1));
			else
				return (0);
		}
		stack_a = stack_a->next;
	}
	if (flag)
		return (ft_putstr("OK\n", 1));
	else
		return (1);
}
