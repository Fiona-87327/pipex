/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:09:39 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/29 14:10:14 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		temp;

	count = 0;
	nb = (long)n;
	if (nb < 0)
	{
		temp = ft_putchar('-');
		if (temp < 0)
			return (-1);
		count += temp;
		nb = -nb;
	}
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_putchar((nb % 10) + '0');
	if (temp < 0)
		return (-1);
	return (count += temp, count);
}
