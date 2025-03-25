/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 20:44:05 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"
#include <stdio.h>
#include <unistd.h>

static int	ft_puthexa(unsigned long nb, char format)
{
	char	*base;
	int		chars_written;

	chars_written = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (format = 'p')
		chars_written += write(1, "0x", 2);
	if (nb < 16)
		chars_written += write(1, &base[nb], 1);
	else
	{
		ft_puthexa(nb / 16, is_uppercase, 0);
		ft_puthexa(nb % 16, is_uppercase, 0);
	}
	return (chars_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		n;

	i = -1;
	n = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			n += write(1, &format[i], 1);
		else if (format[++i] == 'c')
			n += write(1, (char) va_arg(ap, int), 1);
		else if (format[i] == 's')
			ft_putstr_fd((char *) va_arg(ap, char *), 1);
		else if (format[i] == 'p')
			n += ft_puthexa((unsigned long) va_arg(ap, long), format[i]);
		else if (format[i] == 'd' || format[i] == 'i')
			ft_putnbr_fd((int) va_arg(ap, int), 1);
		else if (format[i] == 'u')
			ft_putnbr_fd((unsigned int) va_arg(ap, int), 1);
		else if (format[i] == 'x' || format[i] == 'X')
			n += ft_puthexa((unsigned int) va_arg(ap, int), format[i]);
		else if (format[i] == '%')
			n += write(1, "%", 1);
	}
	va_end(ap);
	return (n);
}

int	main(void)
{
	char *s = "test";
	printf("printf:\n");
	printf("%s\n", s);
	printf("ft_printf:\n");
	ft_printf("%s\n", s);
}
