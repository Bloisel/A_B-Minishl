/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloise <bloise@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:52:26 by bloise            #+#    #+#             */
/*   Updated: 2024/02/09 15:55:14 by bloise           ###   ########.fr       */
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
	dta->error = 0;
}
