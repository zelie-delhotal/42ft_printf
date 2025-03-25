/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:07:58 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"
#include <stdio.h>
#include <unistd.h>

static void	ft_puthexa(unsigned long nb, int is_uppercase, int is_address)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (!is_uppercase)
		base = "0123456789abcdef";
	if (is_address)
		write(1, "0x", 2);
	if (nb < 16)
		ft_putchar_fd(base[nb], 1);
	else
	{
		ft_puthexa(nb / 16, is_uppercase, 0);
		ft_puthexa(nb % 16, is_uppercase, 0);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else if (format[++i] == 'c')
			ft_putchar_fd((char) va_arg(ap, int), 1);
		else if (format[i] == 's')
			ft_putstr_fd((char *) va_arg(ap, char *), 1);
		else if (format[i] == 'p')
			ft_puthexa((unsigned long) va_arg(ap, long), 0, 1);
		else if (format[i] == 'd' || format[i] == 'i')
			ft_putnbr_fd((int) va_arg(ap, int), 1);
		else if (format[i] == 'u')
			ft_putnbr_fd((unsigned int) va_arg(ap, int), 1);
		else if (format[i] == 'x' || format[i] == 'X')
			ft_puthexa((unsigned int) va_arg(ap, int), format[i] == 'X', 0);
		else if (format[i] == '%')
			write(1, "%", 1);
	}
	va_end(ap);
	return (0);//returns bytes written
}

/*int	main(void)
{
	char *s = "test";
	printf("printf:\n");
	printf("%p\n", s);
	printf("ft_printf:\n");
	ft_printf("%p\n", s);
}*/
