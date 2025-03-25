/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/14 15:16:54 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexa(long nb, char format)
{
	char	*base;
	int		chars_written;

	chars_written = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (format == 'p')
	{
		nb = (unsigned long) nb;
		chars_written += write(1, "0x", 2);
		format = 'x';
	}
	if (nb < 16)
		chars_written += write(1, &base[nb], 1);
	else
	{
		ft_puthexa(nb / 16, format);
		ft_puthexa(nb % 16, format);
	}
	return (chars_written);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putnb(int n, char format)
{
	long	cast;
	int		written;

	if (format == 'u')
		cast = (unsigned int) n;
	else
		cast = (long) n;
	written = 0;
	if (cast < 0)
	{
		cast = -cast;
		written += ft_putchar('-');
	}
	if (n > 9)
		written += ft_putnb(cast / 10, 'i');
	written += ft_putchar(cast % 10 + '0');
	return (written);
}

static int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"));
	i = -1;
	while (s[++i])
		write (1, &s[i], 1);
	return (i);
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
		if (format[i] != '%' || format[++i] == '%')
			n += write(1, &format[i], 1);
		else if (format[i] == 'c')
			n += ft_putchar((char) va_arg(ap, int));
		else if (format[i] == 's')
			n += ft_putstr((char *) va_arg(ap, char *));
		else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
			n += ft_putnb((int) va_arg(ap, int), format[i]);
		else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'p')
			n += ft_puthexa((long) va_arg(ap, long), format[i]);
	}
	va_end(ap);
	return (n);
}

#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char *s = "test";
	char *vide = "";
	char *vide2 = NULL;
	printf("printf:\n");
	printf("%c %c %c %c %c\n", 0, 'z', '\n', 'P', '\'');
	ft_printf("ft_printf:\n");
	ft_printf("%c %c %c %c %c\n", 0, 'z', '\n', 'P', '\'');
	printf("printf:\n");
	printf("%s %s %s %s\n", vide, s, vide2, "12345");
	ft_printf("ft_printf:\n");
	ft_printf("%s %s %s %s\n", vide, s, vide2, "12345");
	printf("printf:\n");
	printf("%p %p %p %p\n", s, &s, &vide2, &vide);
	ft_printf("ft_printf:\n");
	ft_printf("%p %p %p %p\n", s, &s, &vide2, &vide);
	printf("printf:\n");
	printf("%d %d %d %d\n", s, &s, &vide2, &vide);
	ft_printf("ft_printf:\n");
	ft_printf("%p %p %p %p\n", s, &s, &vide2, &vide);
	printf("printf:\n");
	printf("%s %s %% %p %x %X\n", s, s, &s, 123, 123);
	ft_printf("ft_printf:\n");
	ft_printf("%s %s %% %p %x %X\n", s, s, &s, 123, 123);
}
