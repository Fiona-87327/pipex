/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:37:11 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 11:43:04 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

// #include <stdio.h>

// int main() {
//     // 测试空链表
//     t_list *empty = NULL;
//     printf("Empty list: %d\n", ft_lstsize(empty)); // 应输出0
//     // 测试单节点链表
//     t_list single;
//     single.next = NULL;
//     printf("Single node: %d\n", ft_lstsize(&single)); // 应输出1
//     // 测试多节点链表
//     t_list node1, node2, node3;
//     node1.next = &node2;
//     node2.next = &node3;
//     node3.next = NULL;
//     printf("Three nodes: %d\n", ft_lstsize(&node1)); // 应输出3
//     return 0;
// }