/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:32:47 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/29 13:40:51 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n >= 10)
	{
		temp = ft_putunsigned(n / 10);
		if (temp < 0)
			return (-1);
		count += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
