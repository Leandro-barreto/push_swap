#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# define MAX 2147483647
# define MIN -2147483648

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stat
{
	int	size;
	int	smallest;
	int	quarter;
	int	median;
	int	tquarter;
	int	biggest;
}				t_stat;

typedef struct s_moves
{
	int	low;
	int	high;
	int	uphigh;
	int	downhigh;
	int	uplow;
	int	downlow;
	int	flag;
}				t_moves;

/*
** checker.c
*/
int				check_args(int ac, char *av[], t_stack *s_a, t_stack *h);
int				get_cmd(t_stack **stack_a, t_stack **stack_b);

/*
** cmd.c
*/
int				parse_cmd(t_stack **s_a, t_stack **s_b, char *cmd, int f);
int				swap(t_stack **stack_1);
int				rev_rotate(t_stack **stack_1);
int				push(t_stack **stack_1, t_stack **stack_2);
int				rotate(t_stack **stack_1);

/*
** final_checker
*/
int				isok(t_stack *stack_a, t_stack *stack_b, int flag);
int				ft_stcsize(t_stack *stack);
int				ft_putstr(char *s, int fd);
long			ft_atolong(const char *str);

/*
** sort.c
*/
void			sort_stack(t_stack **stack_a, t_stack **stack_b);

/*
** sortonehundred.c
*/
void			sort_onehundred(t_stack **s_a, t_stack **s_b, t_stat *s);
void			push_back_to_a(t_stack **s_a, t_stack **s_b);

/*
** sortfivehundred.c
*/
void			sort_fivehundred(t_stack **s_a, t_stack **s_b, t_stat *s);

/*
** stats_moves.c
*/
void			find_stats(t_stack **stack_a, t_stat *stat, int size);
t_moves			get_moves(t_stack *stack, int size);

#endif