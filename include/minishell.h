/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:03:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 18:24:27 by bloisel          ###   ########.fr       */
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
	int res;
	char *cmdwh;
	char *cmd_envr;
	char *arg_env;
	char *cmd2;
	char *cmd_env;
	char *cmd_rdr;
	char *cmd;
	char *wc;
	char *copy;
	char *cmdhp;
	int 	error;
	char **envv;
	char *envh;
	int check;
}t_data;

// utils 1
void	init_data(t_data *dta);
int set_v(t_data *dta, char *str);
char *ft_strncpy(char *s1, char *s2, int n);

//utils 2
int skip_wh(char *str, int pos);
int	is_sep(char c);
int is_sep2(char c);
int is_sep3(t_data *dta, int pos);
int is_sep4(char c);

//utils 3
char *add_whsep(t_data *dta, int res);
void countwh_sep(t_data *dta);

// utils 4
char	*ft_jointventure(char const *s1, char const *s2);
char	*ft_jointventure_len(char const *s1, char const *s2, int x, int y);

// quote && fonction s_quote
int s_quote(t_data *dta, char *str);
void error_s_quote();

// pars quote , changement etat quotes (negatif / cut)
void replace_quote(t_data *dta);
void  remove_q(t_data *dta);
void reset_quoteenv(t_data *dta);

//pars redir 
int error_redir();
int arg_beforeredir(t_data *dta);
int arg_redir(t_data *dta);
int arg_redirbis(t_data *dta, int k, int start);
int intfors_redir(t_data *dta);
int parsing_redir(t_data *dta, int i, int j, int k, int end);

// pars redir 2
char *take_input2();
void s_redir3(t_data *dta, int k);
void s_redir2(t_data *dta, int j, int start, int end, int i);
void pipe_heardoc(t_data *dta, int i);


//pars env 
void getline_afterkey(t_data *dta, int *i, int *len);
int get_envln(t_data *dta, char *str);
int get_key(t_data *dta);
int getline_beforekey(char **env, t_data *dta);

// pars env2
char **env_split(char *env, t_data *dta);

#endif
