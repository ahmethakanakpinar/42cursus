/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:03:29 by aakpinar          #+#    #+#             */
/*   Updated: 2024/11/09 20:16:05 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !(*lst))
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

// int main()
// {
// 	t_list *new = ft_lstnew(ft_strdup("ahmet"));
// 	ft_lstadd_back(&new,ft_lstnew(ft_strdup("hakan")));
// 	ft_lstadd_back(&new,ft_lstnew(ft_strdup("akpınar")));

// 	t_list *new2 = ft_lstlast(new);
// 	printf("%s", new2->content);
	


// }