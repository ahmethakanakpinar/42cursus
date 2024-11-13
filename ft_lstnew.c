/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:14:13 by aakpinar          #+#    #+#             */
/*   Updated: 2024/11/09 19:38:47 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// int main()
// {
// 	// t_list *new = ft_lstnew(malloc(sizeof(int)));
// 	// *(int*)(new->content) = 42;
// 	// printf("%d", *(int*) new->content);

// 	int ds = 42;
// 	int *de = &ds;
// 	t_list *new = ft_lstnew(de);
// 	printf("%d", *(int*)new->content);


// }	