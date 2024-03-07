/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:03:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/07 16:20:38 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft.h"

// struct pour cellules en cas de pipe 
typedef	struct			s_tab
{
	char				*cmd;
}						t_dta;

typedef struct s_data
{
	char *cmd;
	char *wc;
	int 	error;
	char **envv;
	char *envh;
}t_data;


void meta_pars(t_data *dta);
void replace_quote(t_data *dta);
void  remove_q(t_data *dta);
int	is_sep(char c);
int search_c(t_data *dta , char c);
int set_v(t_data *dta, char *str);
int error_s_quote();
int s_quote(t_data *dta, char *str);
void getln(char *str);
char	*trytry(char **env, t_data *dta);
char **separate(char *env);
void	init_data(t_data *dta);

#endif 
