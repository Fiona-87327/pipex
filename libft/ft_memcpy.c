/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:17:23 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:48:14 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (n == 0 || dest == src)
		return (dest);
	dest1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

//  #include <stdio.h>

// int	main(void)
// {
// 	char src[100] = "Hello,world!";
// 	char dest[100];
// 	printf("%s\n", ft_memcpy(dest, src, 5));
// 	printf("%s\n", ft_memcpy(NULL, NULL, 0));
// 	printf("%s", ft_memcpy(NULL, NULL, 1)); 
// 	return (0);
// }
