/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:54:52 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/22 15:01:50 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <stdio.h>

// t_list	*ft_lstnew(void *content);
// void print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }
// int main(void)
// {
//     // 创建链表 "hello" -> "world" -> "ft_lstiter"
//     t_list *head = ft_lstnew("hello");
//     head->next = ft_lstnew("world");
//     head->next->next = ft_lstnew("ft_lstiter");

//     // 用ft_lstiter遍历链表并打印内容
//     ft_lstiter(head, print_content);

//     return 0;
// }