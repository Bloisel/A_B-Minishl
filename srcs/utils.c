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


// fonction error g error etc

void	init_data(t_data *dta)
{
	dta->cmd = NULL;
	dta->key_dot = NULL;
	dta->cmdwh = NULL;
	dta->cmd_envr = NULL;
	dta->cmd2 = NULL;
	dta->copy = NULL;
	dta->cmd_rdr = NULL;
	dta->wc = NULL;
	dta->envh = NULL;
	dta->envv = NULL;
	dta->arg_env = NULL;
	dta->cmd_env = NULL;
	dta->copyh = NULL;
	dta->cmd_f = NULL;
	dta->count = 0;
	dta->error = 0;
	dta->check = 0;
	dta->res = 0;
	dta->c = 'a';
	dta->start_r = 0;
}

void init_data3(CommandData *data) 
{
  data->commands = NULL;
  data->num_commands = 0;
}

int set_v(t_data *dta, char *str)
{
	dta->cmd = ft_strdup(str);
	if (dta->cmd == NULL)
	{
		printf("Error Memory allocation\n");
		return (-1);
	}
	dta->wc = (char *)malloc((ft_strlen(dta->cmd) + 1)*sizeof(char));
	if (dta->wc == NULL)
	{
		printf("Error memory allocation\n");
		return (-1);	
	}
	ft_bzero(dta->wc, ft_strlen(dta->cmd));
	return (0);
}

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i = 0;
    int j = 0;

    while (i < n && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}