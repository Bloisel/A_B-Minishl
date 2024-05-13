/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:03:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/05 15:24:32 by bloisel          ###   ########.fr       */
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
	int count;
	char *cmdwh;
	const char *arg_env;
	char *cmd_env;
	char *cmd_rdr;
	char *cmd;
	char *wc;
	char *copy;
	char *cmdhp;
	int 	error;
	char **envv;
	char *envh;
}t_data;


void get_envln(t_data *dta, char *str);
char **env_split(char *env, t_data *dta);
int env_copy(char **env, t_data *dta);
int env_copy2(char **env, t_data *dta);
int env_copy3(char **env, t_data *dta);
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
int error_redir();
int s_redir(t_data *dta, char *str);
int copystr_redir(t_data *dta);
int error_redir();
int skip_wh(char *str, int pos);
char *ft_strncpy(char *s1, char *s2, int n);
void s_redir2(t_data *dta, int j, int start, int end, int i);
void s_redir3(t_data *dta, int k);
char *take_input2();
int arg_redir(t_data *dta);
int init_intforredir(t_data *dta);
char	*ft_jointventure(char const *s1, char const *s2);
int is_sep2(char c);
void countwh_sep(t_data *dta);
char *add_whsep(t_data *dta, int res);
int is_sep3(t_data *dta, int pos);
char *ft_joinnewline(char *str);
void pipe_heardoc(t_data *dta, int i);


#endif