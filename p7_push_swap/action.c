/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:52:30 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 05:57:19 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **source, char *string)
{
	t_stack	*new_node;

	if (*source == NULL)
		return ;
	new_node = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	if (*dest == NULL)
	{
		*dest = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dest;
		new_node->next->prev = new_node;
		*dest = new_node;
	}
	user_message(string);
}

void	rotate(t_stack **head, t_stack **temp, char *string)
{
	t_stack	*last_node;
	int		size;

	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	last_node = find_last_node(*head);
	last_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	if (!ft_strncmp(string, "rr", 2))
		rotate(temp, NULL, "false");
	user_message(string);
}

void	reverse_rotate(t_stack **head, t_stack **temp, char *string)
{
	t_stack	*last;
	int		size;

	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	last = find_last_node(*head);
	last->prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	last->next->prev = last;
	if (!ft_strncmp(string, "rrr", 3))
		reverse_rotate(temp, NULL, "false");
	user_message(string);
}

void	swap(t_stack **head, char *string)
{
	int	size;
	int	temp;
	int	state;

	state = 1;
	size = stack_len(*head);
	if (head == NULL || *head == NULL || size == 1)
		return ;
	if (state)
	{
		temp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = temp;
		user_message(string);
	}
}
