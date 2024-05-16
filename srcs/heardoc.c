/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:33:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 22:34:15 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// fonction dans le cas ou << se trouve des | chaine de char cmdhp  
int pipe_heardoc(t_data *dta, int i)
{
    int k;
    int j;
    int start;
    int end;
    int l;

    l = 0;
    j = (i + 2);
    k = 0;
    start = 0;
    end = 0;
    while (dta->cmd[j])
    {
        if(dta->cmd[j] == '|')
            l++;
        j++;
    }
    if (l > 0)
    {
        j = (i + 2);
        while (dta->cmdwh[j] != '|')
            j++;
        start = j;
        while (dta->cmdwh[j])
            j++;
        j--;
        end = j;
        dta->cmdhp = (char *)malloc(sizeof(char *) * (j - start) + 1);
        if (dta->cmdhp)
            EXIT_FAILURE;
        if (end > start)
            ft_strncpy(dta->cmdhp , &dta->cmdwh[start], (j - start) + 1);
        printf("heardoc et pipe %s\n", dta->cmdhp);
        return (0);
    }
    return (1);
}


// key = nom de fichier str ce qui est ecrit apres 
void    put_str_in_new_file(char *str, char *key, t_data *dta)
{
    int        fd;
    char    *key_dot;

    key_dot = ft_strjoin(".", key);
	if (open(key_dot, O_WRONLY, 0644) > 0)
        unlink(key_dot);
    fd = open(key_dot, O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Error when opening the file");
        exit(EXIT_FAILURE);
    }
    if (str[0] != '\0' && str[0] != '\n')
        write(fd, str, ft_strlen(str));
    //store_key(dta, key_dot);
    close(fd);
    if (str != NULL)
        free(str);
    free(key);
}