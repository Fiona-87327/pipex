/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:23:32 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 11:55:01 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

size_t	w_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

size_t	w_count(const char *s, char c)
{
	size_t	count;
	size_t	w_in;

	count = 0;
	w_in = 0;
	while (*s)
	{
		if (*s != c && w_in == 0)
		{
			w_in = 1;
			count++;
		}
		else if (*s == c)
			w_in = 0;
		s++;
	}
	return (count);
}

int	add_w(char **dest, const char **s, char c)
{
	size_t	len;

	len = w_len(*s, c);
	*dest = malloc(sizeof(char) * (len + 1));
	if (!*dest)
		return (0);
	ft_memcpy(*dest, *s, len);
	(*dest)[len] = '\0';
	*s += len;
	return (1);
}

void	*all_free(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	i = w_count(s, c);
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!add_w(&result[i], &s, c))
				return (all_free(result, i));
			i++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	char **res = ft_split("Wang-ji-yan", '-');

// 	int	i = 0;
// 	while (res && res[i])
// 	{
// 		printf("Word %d: \"%s\"\n", i, res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }