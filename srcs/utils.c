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

// $HOME on reccupere ce quil ya apres le =  (parcour la chaine echo $HONME $HOME jusqua char fin) join les deux bouts modifier join 
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
	printf("%s\n", dtal->cmd_env);
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
	dta->cmdwh = NULL;
	dta->copy = NULL;
	dta->cmd_rdr = NULL;
	dta->wc = NULL;
	dta->envh = NULL;
	dta->envv = NULL;
	dta->arg_env = NULL;
	dta->cmd_env = NULL;
	dta->count = 0;
	dta->error = 0;
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
	// fonction error g error etc
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