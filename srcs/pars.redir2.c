/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.redir2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:15:43 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/30 13:05:39by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *take_input2()
{
    return readline("> ");
}

// un free a ajouter pour la commande rdr a un moment 
int s_redir3(t_data *dta, int k)
{
    char *input;
    int i;

    i = 0;
    while (1)
    {
        input = take_input2();
        if (input == NULL)
		    break;
		if (ft_strlen(input) > 0)
			add_history(input);
        if (ft_strncmp(input , dta->copy , k) == 0)
        {
            printf("cmd_rdr du heardoc cmd finale = %s\n", dta->cmd_rdr);
            //return (dta->cmd_rdr);
            return (0);
            break;
        }
        else
            dta->cmd_rdr = ft_jointventure(dta->cmd_rdr , input);
    }
    printf("cmd_rdr du heardoc cmd finale = %s\n", dta->cmd_rdr);
    return (0);    
}



// PB MALLOC AU NIVEAU DES WH 
int arg_redir(t_data *dta)
{
    int i;
    int start;
    int k;

    i = 0;
    start = 0;
    k = 0;
    while (dta->cmdwh[i] != '<' && dta->cmdwh[i] != '>')
    {
        while (is_sep(dta->cmdwh[i]) == 1)
            i++;
        if (dta->cmdwh[i] == '>' || dta->cmdwh[i] == '<')
            break;
        if (is_sep(dta->cmdwh[i]) == 0)
            start = i;
        while (is_sep(dta->cmdwh[i]) == 0)
        {
            k++;
            i++;
        }
    }
    dta->cmd_rdr = (char *)malloc(sizeof(char *) * (k - start + 1));
    if (dta->cmd_rdr == NULL)
        return (-1);
    ft_strncpy(dta->cmd_rdr , dta->cmdwh, (k - start + 1));
    printf("commande avant redir %s\n", dta->cmd_rdr);
    printf("break sans malloc\n");
    return (0);
}

// a modifier 
char	*ft_jointventure(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	//if (!s1 || !s2)
	//	return (NULL);
	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	if (*s1 != '\0')
    {
        while (s1[++i])
		    dup[i] = s1[i];
        i--;
    }
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
    printf("dup de join venture %s\n", dup);
	return (dup);
}