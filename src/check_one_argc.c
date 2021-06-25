#include "push_swap.h"

int	check_spaces_end(char *text, int i)
{
	while (text[i] == ' ')
		i++;
	if (text[i])
		return (0);
	return (1);
}

int	get_value(char *text, char *aux, int *i, long *val)
{
	int	j;

	j = 0;
	while (text[*i] == ' ')
		(*i)++;
	if (text[*i] == '-' && text[*i + 1] && ++(*i))
		aux[j++] = '-';
	while (text[*i] && text[*i] != ' ')
	{
		if (text[*i] < '0' || text[*i] > '9')
		{
			free(aux);
			aux = NULL;
			return (1);
		}
		else
			aux[j++] = text[*i];
		(*i)++;
	}
	aux[j] = 0;
	*val = ft_atolong(aux);
	return (0);
}

int	check_one_arg(char *text, t_stack *stack_a, t_stack *head)
{
	int		i;
	char	*aux;
	long	val;

	i = 0;
	while (text[i])
	{
		if (i == 0 || text[i] == ' ')
			aux = (char *)malloc(ft_strlen(&text[i]) + 1);
		if (get_value(text, aux, &i, &val) > 0)
			return (1);
		free(aux);
		aux = NULL;
		if (val > MAX || val < MIN || same((int)val, head))
			return (1);
		stack_a->value = (int)val;
		if (!text[i] || check_spaces_end(text, i))
			break ;
		stack_a->next = (t_stack *)malloc(sizeof(t_stack));
		*(stack_a->next) = (t_stack){0};
		stack_a = stack_a->next;
	}
	return (0);
}
