/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:54:37 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/22 11:06:37 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	if (s1 == NULL && s2 != NULL && n == 0)
		return (NULL);
	i = 0;
	while ((s1[i]) && (i < n))
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < n)
		{
			j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s1 = "jiyan";
// 	char *s2 = "y";
// 	size_t i = 0;

// 	char *result = ft_strnstr(s1, s2, i);
// 	if (result)
// 		printf("Found: %s\n", result);
// 	else
// 		printf("Not found\n");

// 	return 0;
// }