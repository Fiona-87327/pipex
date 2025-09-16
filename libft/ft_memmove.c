/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:50:51 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:56:59 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*dest1;
	unsigned const char	*src1;

	if (!dest && !src)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (dest1 < src1)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest1[i] = src1[i];
		}
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[10] = "felipe";
// 	char d[10];
// 	char *r;

// 	r = ft_memmove(d, s, 5);
// 	printf("%s", r);
// 	return (0);
// }
