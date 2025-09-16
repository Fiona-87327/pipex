/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:41:31 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/29 13:22:32 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexl(unsigned long n)
{
	char	*hex;
	int		count;
	int		temp;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		temp = ft_puthexl(n / 16);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_putchar(hex[n % 16]);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
