/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:48:13 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 10:13:03 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "hello";
// 	char *s1 = "";

// 	printf("Len of %s -> %zu\n", s, ft_strlen(s));
// 	printf("Len of %s -> %zu", s1, ft_strlen(s1));

// }
