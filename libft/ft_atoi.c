/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:03:43 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/18 13:27:24 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	p;

	n = 0;
	p = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			p++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10;
		n += *nptr - '0';
		nptr++;
	}
	if (p % 2 != 0)
		return (-n);
	return (n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "--123";
// 	char *s1 = "-+123";
// 	char *s2 = "+-123";
// 	char *s3 = "++123";
// 	char *s4 = "-123";
// 	char *s5 = "+123";
// 	char *s6 = "  \t\n123";
// 	char *s7 = "42 ist die Antwort";
// 	printf("%d\n", ft_atoi(s));
// 	printf("%d\n", ft_atoi(s1));
// 	printf("%d\n", ft_atoi(s2));
// 	printf("%d\n", ft_atoi(s3));
// 	printf("%d\n", ft_atoi(s4));
// 	printf("%d\n", ft_atoi(s5));
// 	printf("%d\n", ft_atoi(s6));
// 	printf("%d\n", ft_atoi(s7));
// 	return (0);
// }
