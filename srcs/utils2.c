/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:34:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/25 15:03:14 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	is_sep(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int skip_wh(char *str, int pos)
{
    int j;

    j = 1;
    while (str[pos + j] && is_sep(str[pos + j]) != 0)
    {
        j++;
    }
    return (j);
}

int is_sep2(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int countwh_sep(t_data *dta)
{
	int i;
	int j;
	int res;

	res = 0;
	j = 0;
	i = 0;
	while (dta->cmd[i])
	{
		if (is_sep2(dta->cmd[i]) != 0)
		{
			if (dta->cmd[i] == '>' && dta->cmd[i + 1] == '>')
				i += 2;
			if (dta->cmd[i] == '<' && dta->cmd[i + 1] == '<')
				i += 2;
			j++;
		}
		i++;
	}
	printf("mon %d\n", j);
	res = (i + (j * 2));
	printf("%d\n", res);
	dta->cmdwh = (char *)malloc(sizeof(char *) * res + 1);
	ft_strlcpy(dta->cmdwh, dta->cmd, (res));
	printf("ma commande white space %s\n", dta->cmdwh);
	add_whsep(dta);
}

char *add_whsep(t_data *dta)
{
	int i;
	char c;
	char d;

	i = 0;
	while (dta->cmdwh[i])
	{
		//dta->cmdwh[i] *= -1;
		if (is_sep2(dta->cmdwh[i]) != 0)
		{
			c = dta->cmdwh[i];
			dta->cmdwh[i] = 32;
			dta->cmdwh[i + 1] = c;
			//if (dta->cmdwh[i] == '>' && dta->cmd[i + 1] == '>')
			//{
			//	i += 1;
			//	dta->cmdwh[i] = 32;
			//}
			//if (dta->cmdwh[i] == '<' && dta->cmd[i + 1] == '<')
			//{
			//	i += 1;
			//	dta->cmdwh[i] = 32;
			//}
		}
		i++;
	}
	printf("%s\n", dta->cmdwh);
	return (dta->cmdwh);
}