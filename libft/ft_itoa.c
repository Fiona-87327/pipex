/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:38:22 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/21 10:15:11 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*result;

	nbr = n;
	len = number_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		result[0] = '0';
	while (nbr > 0)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%s\n", ft_itoa(0));              // "0"
// 	printf("%s\n", ft_itoa(123));            // "123"
// 	printf("%s\n", ft_itoa(-123));           // "-123"
// 	printf("%s\n", ft_itoa(2147483647));     // "2147483647"
// 	printf("%s\n", ft_itoa(-2147483648));    // "-2147483648"
// }
// len 先减1再使用，result[--len]：从字符串的尾部向前构建内容.