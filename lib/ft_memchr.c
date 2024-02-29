/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:27 by bloisel           #+#    #+#             */
/*   Updated: 2022/11/28 08:22:37 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s1;

	i = -1;
	s1 = (char *)s;
	if (c >= 256)
		c -= 256;
	while (++i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)c)
			return (&s1[i]);
	}
	return (NULL);
}
