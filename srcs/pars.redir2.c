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

// CAS PAS GERE 
//bash-3.2$ echo | < ls wc
//       1       3      25
// bash-3.2$ echo | > ls wc
//
// C PAS GERE ? 
// echo << ls | wc (je reccupere bien wc mais fait rien avec ? ) 

// dans le fichier si plusieurs ligne avant le nom du fichier qui ferme le heardoc ajouter un backslah N '\n'

// en cas heardoc nouveau readline 
char *take_input2()
{
    return readline("> ");
}

// ARTUNG ARTUNG  echo << ls | wc
// ARTUNG ARTUNG echo << ls << la << pp avec des arguments entre 
// fctn appelle dans le cas ou heardoc << : permet de stocker le nom du fichier apres HEARDOC
// attention verifier les cas avec << et | dans la meme ligne 
void s_redir2(t_data *dta, int j, int start, int end, int i)
{
    int k;

    k = 0;
    j = (i + 2);
    while (dta->cmdwh[j] == ' ')
        j++;
    start = j;
    while (dta->cmdwh[j] != '\0' && dta->cmdwh[j] != '|' && dta->cmdwh[j] != ' ')
        j++;
    j--;
    end = j;
    dta->copy = (char *)malloc(sizeof(char *) * (j - start + 1));
    if (dta->copy == NULL)
        EXIT_FAILURE;
    if (end > start)
        ft_strncpy(dta->copy, &dta->cmdwh[start], (j - start + 1));
    printf("first redir copy %s\n", dta->copy);
    k = (j - start + 1);
    s_redir3(dta, k);
}

// boucle infinit sur le readline jusqua nom de fichier rencontre , a voir si ajouter '\n' a la fin de chaque argument rentree dans fichier 
void s_redir3(t_data *dta, int k)
{
    char *input;
    char *tmp;
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
        {
        tmp = ft_strdup(input);
        yes = ft_jointventure(tmp, "\n");
        printf("input = %s\n", input);
        printf("yes = %s\n", yes);
        free(tmp);
        }
        // put_str_in_new_file(input , dta->copy, dta);
            // yes= ft_jointventure(dta->cmd_rdr  , input);
            // dta->cmd_rdr = ft_jointventure(yes , "\n");
            // put_str_in_new_file(dta->cmd_rdr, dta->copy, dta);
            // printf(" yes = %s\n", yes);
            //dta->cmd_rdr = ft_jointventure(yes , "\n");
            // if (dta->res > 0)
            // {
            //     dta->cmd_rdr = ft_jointventure(yes , dta->cmdhp);
            // }
            //free(yes);
    }
    put_str_in_new_file(input, dta->copy , dta);
}
