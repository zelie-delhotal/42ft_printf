/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:03:06 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/07 20:14:46 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cast;
	unsigned char	*s_cast;
	size_t			i;

	d_cast = (unsigned char *)dest;
	s_cast = (unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (n-- > 0)
		{
			d_cast[n] = s_cast[n];
		}
	}
	else if (dest < src)
	{
		while (i < n)
		{
			d_cast[i] = s_cast[i];
			i++;
		}
	}
	return (dest);
}
