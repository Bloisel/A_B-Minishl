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

// parser de maniere a ce que ft_strncmp de ce quil ya apres un dollars jusqua un delimiteur determiner quel sont les delimiteurs white space ou quotes 
int env_copy(char **env, t_data *dta)
{
	int i;
	int j;
	int len;

	len = 0;
	j = 0;
	i = 0;
	while (dta->wc[i] != '$')
		i++;
	printf("mon i = %d\n", i);
	if (dta->wc[i] == '\0')
		return (-1);
	i++;
	printf("mon j = %d\n", j);
	while (dta->wc[i] && is_sep(dta->wc[i]) != 1)
		i++;
	//dta->wc[i] = '\0';
	/*dta->cmd_env = ft_strdup(dta->wc);
	printf("%s\n", dta->cmd_env);
	len = (j - i);
	len--;
	printf("ma len %d\n", len);
	printf("char de i = [%c]\n", dta->wc[i]);
	/*/
	/*while (ft_strncmp(dta->wc[j], *env , len))
		env++;
	dta->envh = *env + (len + 1);
	/*/	
	return (0);
}

char **env_split(char *env, t_data *dta)
{
	dta->envv = ft_split(env, ':');
	return (dta->envv);
}

const char *get_envln(t_data *dta)
{
	dta->arg_env = getenv("PATH");
	printf("%s\n",dta->arg_env);
	return (dta->arg_env);
}

void	init_data(t_data *dta)
{
	dta->cmd = NULL;
	dta->wc = NULL;
	dta->envh = NULL;
	dta->envv = NULL;
	dta->arg_env = NULL;
	dta->cmd_env = NULL;
	dta->count = 0;
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