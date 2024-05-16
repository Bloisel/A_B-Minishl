/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:16:50 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 15:58:40 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


// deuxieme fonction trouver la clef entre dollars et separateur ou fin 
int get_key(t_data *dta)
{
			int i;
			int start;
			int end;
			int len;
			char *key;

			len = 0;
			end = 0;
			start = 0;
			i = 0;
			while (dta->cmd[i])
			{
					while(dta->cmd[i] != '$' && dta->cmd[i])
						i++;
					if (dta->cmd[i] == '$' && dta->cmd[i])
						start = i++ + 1;
					while((is_sep(dta->cmd[i]) == 0) && dta->cmd[i] != '\0' && is_sep4(dta->cmd[i]) == 0 && dta->cmd[i] != '$')
						i++;	
					if (start > 0)
					{
						key = (char *)malloc(sizeof(char *) * (i - start) + 1);
						key = ft_strncpy(key , &dta->cmd[start], (i - start));
						len = ft_strlen(key);
						if (get_envln(dta , key) == 0){
							getline_afterkey(dta, &start , &len);
						}
						free(key);
						start = 0;
						dta->count = 0;
					}
					i++;
			}
			return 0;
}

// premier fonction appelle trouver tout ce qui se trouve avant le dollars 
int getline_beforekey(char **env, t_data *dta)
{
			int i;
			int start;
			int end;
			char *str;

			start = 0;
			end = 0;
			i = 0;
			while (dta->cmd[i])
			{
					if (dta->cmd[i] == '$')
					{
							end = i;
							break;
					}
					i++;
			}
			dta->envh = (char *)malloc(sizeof(char *) * (end - start + 1));
			dta->envh = ft_strncpy(dta->envh , &dta->cmd[0], (end - start));
			get_key(dta);
			return 0;
}

// reccupere ce qui ce trouve apres la variable environmment character ou autre var d'env ou juste quote etc //  
void getline_afterkey(t_data *dta, int *i, int *len)
{
		int pos;
		int len1;
		
		pos = (*i + *len);
		len1 = *i;
		if (len1 != 1){
			len1--;
		}
		dta->arg_env = ft_jointventure_len(dta->cmd, dta->cmd_envr, len1, ft_strlen(dta->cmd_envr));
		dta->cmd = ft_jointventure(dta->arg_env , &dta->cmd[pos]);
}

// transformer la clef en la ligne de var environnement correspondante 
int get_envln(t_data *dta, char *str)
{
	char *str1;
	dta->cmd_envr = ft_strdup(str);
	dta->cmd_envr = getenv(str);
	if (dta->cmd_envr == NULL)
	{
		printf("ce qui se trouve apres $ n'est pas dans l'env \n");
		return (1);
	}
	return (0);
}
