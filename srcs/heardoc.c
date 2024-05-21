/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:33:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/21 18:27:24 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void getline_afterkey2(t_data *dta, int *i, int *len)
{
        char *tmp;
		int pos;
		int len1;
		
		pos = (*i + *len);
		len1 = *i;
		if (len1 != 1){
			len1--;
		}
        printf("avant join %s\n", dta->cmd);
		tmp = ft_jointventure_len(dta->cmd_rdr, dta->key_dot, len1, ft_strlen(dta->key_dot));
        ft_strjoin(tmp,"    ");
        printf("apres join %s\n",tmp);
		//dta->cmd = ft_jointventure(tmp , &dta->cmd[pos]);
        //printf("apres join %s\n",dta->cmd);
}

// key = nom de fichier str ce qui est ecrit apres 
void    put_str_in_new_file(char *str, char *key, t_data *dta)
{
    int        fd;
    //char    *key_dot;
    char    *tmp;
    char    test[2];
    char *cmd_f;
    int i;
    
    test[0] = dta->c;
    test[1] = 0;
    tmp = ft_strjoin(".", key);
    dta->key_dot = ft_strjoin(tmp , test);
    printf("key.dot %s\n", dta->key_dot);
    dta->c++;
    if (open(dta->key_dot, O_WRONLY, 0644) > 0)
        unlink(dta->key_dot);
    fd = open(dta->key_dot, O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Error when opening the file");
        exit(EXIT_FAILURE);
    }
    if (str[0] != '\0' && str[0] != '\n')
        write(fd, str, ft_strlen(str));
    int j = ft_strlen(dta->key_dot);
    //getline_afterkey2(dta, &dta->start_r, &j);
    close(fd);
    cmd_f = ft_strjoin(dta->cmd_rdr, dta->key_dot);
    dta->cmd_f = ft_strdup(cmd_f);
    printf("dta cmd _ rdr  = %s\n", dta->cmd_f);
    if (str != NULL)
        free(str);
    free(cmd_f);
    free(key);
    free(tmp);
}

