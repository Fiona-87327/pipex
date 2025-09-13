/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:40:30 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:48:09 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1c;
	const unsigned char	*s2c;
	size_t				i;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char a[10] = "nihao";
// 	char b[10] = "nikao";
// 	printf("%d\n", ft_memcmp(a, b, 2));
// 	printf("%d", ft_memcmp(a, b, 5));
// }