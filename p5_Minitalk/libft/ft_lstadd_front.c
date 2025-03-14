/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:01:58 by aakpinar          #+#    #+#             */
/*   Updated: 2024/11/09 19:49:36 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list *new = ft_lstnew(ft_strdup("ahmet"));
// 	ft_lstadd_front(&new,(ft_lstnew(ft_strdup("hakan"))));
// 	printf("%s\n %s\n",new->content,new->next->content);

// }
