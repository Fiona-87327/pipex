/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:24:51 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/22 11:09:56 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	char	*subs;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	while (i < len && start < s_len && s[start + i])
		i++;
	subs = malloc((i + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	j = 0;
	while (j < i)
	{
		subs[j] = s[start + j];
		j++;
	}
	subs[i] = '\0';
	return (subs);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *s1 = ft_substr("42 Network", 3, 4);
// 	printf("s1: %s\n", s1);
// 	char *s2 = ft_substr("Hello", 1, 4);
// 	printf("s2: %s\n", s2); 
// 	char *s3 = ft_substr("abcdef", 2, 3);
// 	printf("s3: %s\n", s3);
// 	free(s1);
// 	free(s2);
// 	free(s3);
// 	return (0);
// }
