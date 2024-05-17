/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:33:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/17 02:35:53 by bloisel          ###   ########.fr       */
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
    char    *tmp;
     
    tmp = ft_strjoin(".", key);
    key_dot = ft_strjoin(tmp , &dta->c);
    printf("key.dot %s\n", key_dot);
    dta->c++;
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
    free(tmp);
}

// void	init_keys(t_data *dta, char *key)
// {
// 	dta->keys = malloc(sizeof(char *) * 2);
// 	dta->keys[0] = key;
// 	dta->keys[1] = NULL;
// }


// void	store_key(t_data *dta, char *key)
// {
// 	char	**tmp;
// 	int		i;

// 	i = -1;
// 	if (dta->keys == NULL)
// 		init_keys(dta, key);
// 	else
// 	{
// 		while (dta->keys[++i])
// 			if (!ft_strncmp(dta->keys[i], key, 1024))
// 				return ;
// 		tmp = malloc(sizeof(char *) * (i + 2));
// 		i = -1;
// 		while (dta->keys[++i])
// 			tmp[i] = dta->keys[i];
// 		tmp[i] = key;
// 		tmp[i + 1] = NULL;
// 		if (dta->keys)
// 			free(dta->keys);
// 		dta->keys = tmp;
// 	}
// }

