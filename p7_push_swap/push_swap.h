/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:57:40 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/14 06:03:14 by aakpinar         ###   ########.fr       */
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

void				stack_init(t_stack **a, char **argv, int argc,
						int is_split_arg);
long				*normalize(long *numbers, int size);
long				find_bigger(long *numbers, int size);
t_stack				*find_last_node(t_stack *top);
int					append_node(t_stack **head, int nbr);
void				free_matrix(char **argv);
void				free_stack(t_stack **stack);
void				error_free(t_stack **a, char **argv, int is_split_arg,
						long *numbers);
int					error_syntax(char *str_nbr);
int					error_repetition(long *stack, int size);

#endif