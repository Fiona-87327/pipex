/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:46:04 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 11:54:13 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

// #include <stdio.h>

// int main() {
//     // 测试空链表
//     t_list *empty = NULL;
//     printf("Empty list last: %p\n", (void *)ft_lstlast(empty));
//     t_list single;
//     single.next = NULL;
//     printf("Single node last: %p\n", (void *)ft_lstlast(&single));
//     t_list node1, node2, node3;
//     node1.next = &node2;
//     node2.next = &node3;
//     node3.next = NULL;
//     printf("Three nodes last: %p\n", (void *)ft_lstlast(&node1)); 
//     return 0;
// }