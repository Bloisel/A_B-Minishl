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

// dans le fichier si plusieurs ligne avant le nom du fichier qui ferme le heardoc ajouter un backslah N '\n'
// un free a ajouter pour la commande rdr a un moment

// en cas heardoc nouveau readline 
char *take_input2()
{
    return readline("> ");
}

// boucle infinit sur le readline jusqua nom de fichier rencontre , a voir si ajouter '\n' a la fin de chaque argument rentree dans fichier 
void s_redir3(t_data *dta, int k)
{
    char *input;
    char *yes;
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
            break;
        }
        else
            yes= ft_jointventure(dta->cmd_rdr , input);
            dta->cmd_rdr = ft_jointventure(yes , "\n");
            free(yes);
    }
}

// fonction pour reccuper argument avant heardoc ex : "echo << ls" devient "echo "
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
        if (is_sep(dta->cmdwh[i]) == 1)
        {
            start = i;
            i++;
        }
        while (is_sep(dta->cmdwh[i]) == 0)
        {
            k++;
            i++;
        }
    }
    dta->cmd_rdr = (char *)malloc(sizeof(char *) * (k - start + 1));
    if (dta->cmdwh == NULL)
        return (-1);
    ft_strncpy(dta->cmd_rdr , dta->cmdwh, (k - start + 1));
    //printf("tour de arg redir chaine realloc %s\n", dta->cmd_rdr);
    return (0);
}

// join modifier dans le cas ou la chaine 1 est vide au cas ou si argument vide avant heardoc ex : "      <<  ls "
char	*ft_jointventure(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

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
	return (dup);
}
