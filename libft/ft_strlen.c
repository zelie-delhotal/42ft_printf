/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:07:17 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/05 15:16:16 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i * sizeof(char));
}

/*#include <stdio.h>
int main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("%d", (int) ft_strlen(av[1]));
	}
}*/
