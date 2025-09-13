/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:38:49 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 09:50:16 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*s_new;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	s_new = malloc(sizeof(char) * (i + 1));
	if (!s_new)
		return (NULL);
	j = 0;
	while (i > j)
	{
		s_new[j] = f(j, s[j]);
		j++;
	}
	s_new[i] = '\0';
	return (s_new);
}

// #include <stdio.h>

// char test_func(unsigned int i, char c)
// {
//     if (i % 2 == 0 && c >= 'a' && c <= 'z')
//         return c - 32;
//     return c;
// }

// int main(void)
// {
//     const char *str = "libtmapi";
//     char *res = ft_strmapi(str, test_func);
//     if (res)
//     {
//         printf("Result: %s\n", res);
//         free(res);
//     }
//     return 0;
// }
