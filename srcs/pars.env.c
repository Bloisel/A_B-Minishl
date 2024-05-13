/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:16:50 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/09 01:33:50 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
// PARSER LES CAS AVEC QUOTES PAS FAIT EX : '$HOME' != "$HOME" != '"dd$HOME"' 
// $HOME on reccupere ce quil ya apres le =  (parcour la chaine echo $HONME $HOME jusqua char fin) join les deux bouts modifier join 
// parser de maniere a ce que ft_strncmp de ce quil ya apres un dollars jusqua un delimiteur determiner quel sont les delimiteurs white space ou quotes 
int env_copy(char **env, t_data *dta)
{
			int i;
			int start;
			char *str;

			start = 0;
			i = 0;
			while (dta->cmd[i])
			{
					while(dta->cmd[i] != '$')
						i++;
					if (dta->cmd[i] == '$')
						i++;
					start = i;
					// boucle is sep de quotes egalemet 
					while((is_sep(dta->cmd[i]) == 0) && dta->cmd[i] != '\0' && dta->cmd[i] != '$') 
						i++;
					i--;
					str = (char *)malloc(sizeof(char *) * (i - start) + 1);
					str = ft_strncpy(str , &dta->cmd[start], (i - start + 1));
					get_envln(dta , str);
					free(str);
					i++;
			}
			return 0;
}

int env_copy3(char **env, t_data *dta)
{
			int i;
			int k;
			int start;
			char *str;

			k = 0;
			int j = 0;
			start = 0;
			i = 0;
			while (dta->cmd[i])
			{
				if (dta->cmd[i] == -34 && k < 2 && j == 0)
				{
						k++;
						dta->cmd[i++] *= -1;
						if (k == 2)
						{
							 k = 0;
								break;
						}
				}
				if (dta->cmd[i] == -39 && j < 2 && k == 0)
				{
					j++;
					dta->cmd[i++] *= -1;
					if (j == 2)
					{
						j = 0;
						break;
					}
				}
			i++;
			}
			return 0;
}

int env_copy2(char **env, t_data *dta)
{
			int i;
			int start;
			char *str;

			start = 0;
			i = 0;
			while (dta->cmd[i])
			{
					if (dta->cmd[i] == '$')
							start = i;
						i++;
			}
			dta->envh = (char *)malloc(sizeof(char *) * (i - start));
			dta->envh = ft_strncpy(dta->envh , &dta->cmd[0], (i - start));
			dta->envh = ft_jointventure(dta->envh , " ");
			env_copy(env, dta);
			return 0;
}

char **env_split(char *env, t_data *dta)
{
	dta->envv = ft_split(env, ':');
	return (dta->envv);
}

void get_envln(t_data *dta, char *str)
{
	dta->arg_env = getenv(str);
	dta->arg_env = ft_jointventure(dta->envh, dta->arg_env);
	printf("%s\n",dta->arg_env);
}