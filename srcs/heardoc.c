/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heardoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:33:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/22 03:15:54 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int getline_beforekey2(t_data *dta)
{
	int i;
	int start;
	int end;
	char *str;

	start = 0;
	end = 0;
	i = 0;
	while (dta->cmdwh[i])
	{
	    if (dta->cmdwh[i] == '<' && dta->cmdwh[i + 1] == '<')
		{
		    end = i;
			break;
		}
		i++;
	}
	dta->cmd_rdr = (char *)malloc(sizeof(char *) * (end - start + 1));
	ft_strncpy(dta->cmd_rdr , dta->cmdwh, (end - start));
    printf("get line before key %s\n", dta->cmd_rdr);
    //free(dta->cmd_rdr);
	return 0;
}

void getline_afterkey2(t_data *dta, int *i)
{
        char *tmp;
        char *tmp2;
		int pos;
		int len1;
        
		//pos = (*i + *len);
		len1 = (--*i);
		if (len1 != 1){
			len1--;
		}
        //len1--;
		tmp = ft_jointventure_len(dta->cmd, dta->key_dot, len1, ft_strlen(dta->key_dot));
        printf("tmp apres premier join = %s\n",tmp);
        printf("verification ligne apres heardoc %s\n",dta->copyh);
        dta->cmd = ft_jointventure(tmp , dta->copyh);
        printf("dta->cmdwh apres deuxieme join = %s\n",dta->cmd);
}

// key = nom de fichier str ce qui est ecrit apres 
void    put_str_in_new_file(char *str, char *key, t_data *dta)
{
    int        fd;
    char    *tmp;
    char    test[2];
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
    close(fd);
    //dta->cmd_f = ft_strjoin(dta->cmd_rdr, dta->key_dot);
    //dta->cmd_f = ft_strjoin(cmd_f, dta->copyh);
    printf("changement de nom pour le fichier  = %s\n", dta->key_dot);
    getline_afterkey2(dta, &dta->start_r);
    if (str != NULL)
        free(str);
    free(key);
    free(tmp);
}

