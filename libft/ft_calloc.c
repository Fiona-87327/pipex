/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:11:58 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/22 09:48:58 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *d, size_t n);

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;
	size_t	total;

	if (n == 0 || size == 0)
		return (malloc(0));
	total = n * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	ft_bzero(p, total);
	return (p);
}
// #include <stdio.h>

// int main(void)
// {
// 	int *arr = (int *)ft_calloc(0, 0);

// 	if (!arr)
// 	{
// 		printf("分配失败\n");
// 		return (1);
// 	}

// 	int *a = ft_calloc(0, 0);
// 	int *b = ft_calloc(10, 0);
// 	int *c = ft_calloc(0, 10);

// 	printf("calloc(0, 0): %p\n", a);
// 	printf("calloc(10, 0): %p\n", b);
// 	printf("calloc(0, 10): %p\n", c);
// 	free(a);
// 	free(b);
// 	free(c);
// 	return (0);
// }
