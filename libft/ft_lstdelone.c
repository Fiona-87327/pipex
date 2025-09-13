/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:37:21 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 17:33:41 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// t_list *ft_lstnew(void *content);

// void my_del(void *content)
// {
//     printf("Freeing: %s\n", (char*)content);
//     free(content);
// }
// int main(void)
// {
//     // 动态分配字符串，并创建节点
//     char *str = malloc(20);
//     if (str)
//         sprintf(str, "Hello Node!");

//     t_list *node = ft_lstnew(str);

//     // 测试删除
//     ft_lstdelone(node, my_del);

//     // 此处不能再访问 node 或 str
//     return 0;
// }