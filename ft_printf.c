/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:25:54 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/11 21:42:39 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"

static int	ft_print_var(char format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd((char) va_arg(args, char), 1);
	/*else if(format == 's')
	else if (format == 'p')
	else if (format == 'd')
	else if (format == 'i')
	else if (format == 'u')
	else if (format == 'x')
	else if (format == 'X')
	else if (format == '%')
	else*/
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			write (1, &format[i], i);
		else
		{
			if (!ft_print_var(format[++i], args))
				return (0);
		}
		i++;
	}
}

int	main(void)
{
	ft_printf("%c", 'a');
}
