/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.env2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:42:12 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/15 19:01:42 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void reset_quoteenv(t_data *dta)
{
		int i;

		i = 0;
		while (dta->cmd[i])
		{
				if (dta->cmd[i] == -34 || dta->cmd[i] == -39)
					dta->cmd[i] *= -1;
				i++;
		}
}

char **env_split(char *env, t_data *dta)
{
	dta->envv = ft_split(env, ':');
	return (dta->envv);
}

