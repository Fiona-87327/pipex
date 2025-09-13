/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:14:13 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:47:28 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *d, size_t n)
{
	ft_memset(d, 0, n);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char d[5] = "jjj";  // Änderbar, sicher für bzero
// 	size_t n = 1;

// 	ft_bzero(d, n);

// 	// Ausgabe der ASCII-Werte zur Kontrolle
// 	for (int i = 0; i < 3; i++)
// 		printf("d[%d] = %d\n", i, d[i]);

// 	return 0;
// }