/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:42:44 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/22 10:57:58 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	d = 0;
	if (size == 0)
		return (s);
	while (dest[d] && d < size)
		d++;
	if (d == size)
		return (size + s);
	i = 0;
	while (src[i] && (d + i + 1) < size)
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (d + s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char src[7] = "Coucou";
// 	char dest[7] = "";

// 	size_t longueur = ft_strlcat(dest, src, 3);

// 	printf("%s\n", src);
// 	printf("%s\n", dest);
// 	printf("%zu\n", longueur);

// 	return (0);
// }