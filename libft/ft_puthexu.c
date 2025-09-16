/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:57:43 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/29 13:15:47 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexu(unsigned long n)
{
	char	*hex;
	int		count;
	int		temp;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		temp = ft_puthexu(n / 16);
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
