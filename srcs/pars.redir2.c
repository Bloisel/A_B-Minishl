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

// CAS PAS GERE ? 

//bash-3.2$ echo | < ls wc
//       1       3      25
// bash-3.2$ echo | > ls wc
//

// C PAS GERE ?

// echo << ls | wc (je reccupere bien wc mais fait rien avec ? ) 

// en cas heardoc nouveau readline 
char *take_input2()
{
    return readline("> ");
}

// ARTUNG ARTUNG  echo << ls | wc
// ARTUNG ARTUNG echo << ls << la << pp avec des arguments entre 
// fctn appelle dans le cas ou heardoc << : permet de stocker le nom du fichier apres HEARDOC

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

    tmp = NULL;
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
            if (!tmp)
            {
                tmp = ft_strdup("");
            }
            yes = tmp;
            tmp = ft_strjoin(tmp , input);
            free(yes);
            yes = tmp;
            tmp = ft_jointventure(tmp, "\n");
            free(yes);
            printf("%s\n",tmp);
        }
    }
    //put_str_in_new_file(tmp, dta->copy , dta);
    free(dta->copy);
    // free de tmp et dta->copy inside fonction
}
