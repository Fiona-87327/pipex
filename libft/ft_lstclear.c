/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:47:52 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 17:41:46 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

// #include <stdio.h>

// t_list	*ft_lstnew(void *content);
// char	*ft_strdup(const char *s);
// void my_del(void *ptr) { free(ptr); }
// int main(void)
// {
//     t_list *lst = ft_lstnew(ft_strdup("one"));
//     lst->next = ft_lstnew(ft_strdup("two"));
//     lst->next->next = ft_lstnew(ft_strdup("three"));

//     ft_lstclear(&lst, my_del);

//     return 0;
// }