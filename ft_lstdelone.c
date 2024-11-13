/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:15:19 by aakpinar          #+#    #+#             */
/*   Updated: 2024/11/09 20:39:01 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		if (del != NULL && lst->content != NULL)
			del(lst->content);
		free(lst);
		lst = NULL;
	}
}
// void del(void *content)
// {
// 	free(content);
// }
// int main()
// {
// 	t_list *new = ft_lstnew(ft_strdup("ahmet"));
// 	ft_lstadd_back(&new,ft_lstnew(ft_strdup("hakan")));
// 	ft_lstadd_back(&new,ft_lstnew(ft_strdup("akpınar")));

// 	ft_lstdelone(new->next,del);
	
// 	// while (new)
// 	// {
// 	// 	printf("%s\n", (char*) new->content);
// 	// 	new = new->next;
// 	// }
// 	printf("%d \n",ft_lstsize(new));

	
	

	


// }


// // A -> B -> C -> D -> NULL