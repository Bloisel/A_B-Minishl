/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:23:07 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/13 16:35:47 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	count(const char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
		{
			j = 0;
		}
		str++;
	}
	return (i);
}

char	*duplicator(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof (char));
	if (!word || !str)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{	
	size_t	i;
	size_t	j;
	int		trigger;
	char	**result;

	i = -1;
	j = 0;
	trigger = -1;
	result = malloc((count(str, c) + 1) * sizeof(char *));
	if (!str || !result)
		return (0);
	while (++i <= ft_strlen(str))
	{
		if (str[i] != c && trigger < 0)
				trigger = i;
		else if ((str[i] == c || i == ft_strlen(str)) && trigger >= 0)
		{
			result[j] = duplicator(str, trigger, i);
			j++;
			trigger = -1;
		}
	}
	result[j] = NULL;
	return (result);
}
