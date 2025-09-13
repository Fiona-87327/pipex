/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:14:36 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:48:28 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n > 0)
	{
		*s1 = (unsigned char)c;
		s1++;
		n--;
	}
	return (s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s[10] = "hi,jiyan";
// 	printf("%s", ft_memset(s, '*', 2));
// 	return 0;
// }