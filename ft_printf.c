/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 14:06:46 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else if (format[++i] == 'c')
			ft_putchar_fd((char) va_arg(ap, int), 1);
		/*else if (format[i] == 's')
		else if (format[i] == 'p')
		else if (format[i] == 'd')
		else if (format[i] == 'i')
		else if (format[i] == 'u')
		else if (format[i] == 'x')
		else if (format[i] == 'X')
		else if (format[i] == '%')*/
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("b%cba", 'x');
}
