/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:33:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/17 15:56:20 by bloisel          ###   ########.fr       */
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
        printf("%s\n",tmp);
		dta->cmd = ft_jointventure(tmp , &dta->cmd[pos]);
        printf("apres join %s\n",dta->cmd);
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
    //store_key(dta, key_dot);
    
    int j = ft_strlen(dta->key_dot);
    //getline_afterkey2(dta, &dta->start_r, &j);
    //str_remanier(dta);
    //printf("%s\n", dta->cmd_rdr);
    close(fd);
    //cmd_f = ft_strjoin(dta->cmd_rdr, key_dot);
    // printf("cmd_f = %s\n", cmd_f);
    if (str != NULL)
        free(str);
    free(key);
    free(tmp);
}

