/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyawang <jiyawang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:12:05 by jiyawang          #+#    #+#             */
/*   Updated: 2025/07/28 16:09:09 by jiyawang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(__linux__)
#  define PTRNULL "(nil)"
#  define NPTRSIZE 5
# elif defined(__APPLE__)
#  define PTRNULL "0x0"
#  define NPTRSIZE 3
# endif

int	ft_printf(const char *format, ...);
int	ft_putunsigned(unsigned int n);
int	ft_puthexl(unsigned long n);
int	ft_puthexu(unsigned long n);
int	ft_putpointer(void *ptr);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);

#endif
