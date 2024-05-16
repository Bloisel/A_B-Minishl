/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:38:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 16:40:00 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// join modifier dans le cas ou la chaine 1 est vide au cas ou si argument vide avant heardoc ex : "      <<  ls "
char	*ft_jointventure(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	if (*s1 != '\0')
    {
        while (s1[++i])
		    dup[i] = s1[i];
        i--;
    }
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	return (dup);
}

char	*ft_jointventure_len(char const *s1, char const *s2, int x, int y)
{
	size_t	i;
	size_t	j;
	char	*dup;

    //printf("PRINT LEN: %d %d\n", x, y);
	dup = malloc(x + y + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	if (*s1 != '\0')
    {
        while (s1[++i] && i <= x - 1)
		    dup[i] = s1[i];
        i--;
    }
	while (s2[++j] && j <= y)
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	return (dup);
}
