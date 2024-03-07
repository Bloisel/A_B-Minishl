/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:52:26 by bloise            #+#    #+#             */
/*   Updated: 2024/03/07 16:18:26by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*trytry(char **env, t_data *dta)
{
	while (ft_strncmp("PATH" , *env , 4))
	{
		env++;
	}
	dta->envh = *env + 5;
	return (*env + 5);
}

char **separate(char *env)
{
	char **test;
	test = ft_split(env , ':');
	return (test);
}

void	init_data(t_data *dta)
{
	dta->cmd = NULL;
	dta->wc = NULL;
	dta->envh = NULL;
	dta->error = 0;
}

int search_c(t_data *dta , char c)
{
    int i;

    i = 0;

    while(dta->wc[i])
    {
        if (dta->wc[i] == c)
            return (-1);
        i++; 
    }
    return (1);
}

int	is_sep(char c)
{
	if (c == '\n' || c == ' ')
		return (1);
	return (0);
}