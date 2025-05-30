/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:57:40 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 05:57:16 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

# define PA "pa\n"
# define PB "pb\n"

# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"

# define RRA "rra\n"
# define RRR "rrr\n"

# define SA "sa\n"
# define SB "sb\n"

# define SYNTAX "Error\n"
# define DUPLICATE "Error\n"
# define OVERFLOW "Error\n"

void		stack_init(t_stack **a, char **argv, int argc,
				int flag_argc_2);
long		*normalize(long *numbers, int size);
long		find_bigger(long *numbers, int size);
void		user_message(char *string);
void		radix_sort(t_stack **a, t_stack **b, int size);
void		operations(t_stack **a, t_stack **b, int bit_index);
int			get_bit(int bit_index, int n);
t_stack		*find_last_node(t_stack *top);
int			append_node(t_stack **head, int nbr);
int			stack_len(t_stack *stack);
int			stack_sorted(t_stack *stack);
void		free_matrix(char **argv);
void		free_stack(t_stack **stack);
void		error_free(t_stack **a, char **argv, int flag_argc_2,
				long *numbers);
int			error_syntax(char *str_nbr);
int			error_repetition(long *stack, int size);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);
void		push(t_stack **dest, t_stack **source, char *string);
void		rotate(t_stack **head, t_stack **temp, char *string);
void		reverse_rotate(t_stack **head, t_stack **temp,
				char *string);
void		swap(t_stack **head, char *string);
int			ft_iswhitespace(char c);
long		ft_atol(char *string);

#endif