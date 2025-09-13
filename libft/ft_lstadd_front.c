/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:27:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 11:44:49 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>

// int main(void)
// {
//     int a = 42, b = 21;
//     t_list *node1 = ft_lstnew(&a); // 原来的头
//     t_list *node2 = ft_lstnew(&b); // 要加的新节点
//     ft_lstadd_front(&node1, node2);
//     // node1 现在指向 node2，因为 node2 是新的头
//     t_list *current = node1;
//     while (current)
//     {
//         printf("%d\n", *(int *)(current->content));
//         current = current->next;
//     }
//     free(node2);
//     free(node1); // 注意顺序：new 是 node2，在前面
//     return 0;
// }