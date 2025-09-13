/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:36:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 17:28:22 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

// #include <stdio.h>

// t_list *ft_lstnew(void *content);
// int main(void)
// {
//     t_list *head = NULL;
//     // 创建第一个节点
//     t_list *node1 = ft_lstnew("hello");
//     ft_lstadd_back(&head, node1);
//     // 再创建一个节点加到链表尾部
//     t_list *node2 = ft_lstnew("world");
//     ft_lstadd_back(&head, node2);
//     // 打印一下链表内容
//     t_list *curr = head;
//     while (curr)
//     {
//         printf("%s\n", (char*)curr->content);
//         curr = curr->next;
//     }
//     // 记得最后释放内存(此处省略)
//     return 0;
// }