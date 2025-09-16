/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:59:13 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/29 13:18:16 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(void *ptr)
{
	int				count;
	int				temp;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
	{
		temp = (write(1, PTRNULL, NPTRSIZE));
		if (temp < 0)
			return (-1);
		count += temp;
		return (count);
	}
	temp = (write(1, "0x", 2));
	if (temp < 0)
		return (-1);
	count += temp;
	temp = ft_puthexl(address);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
