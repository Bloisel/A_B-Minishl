/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:03:40 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/27 23:03:04 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include<fcntl.h>
# include<dirent.h>
# include<termios.h>
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
	char *key_dot;
	char *cmdwh;
	char *cmd_f;
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
	int  start_r;
	char **envv;
	char *envh;
	char *copyh;
	int check;
	char c;
	int st;
	int key_done;
	char **keys;
}t_data;


extern int get_exit_status;

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
int error_redir2();
void arg_beforeredir(t_data *dta);
void arg_redir(t_data *dta);
void arg_redirbis(t_data *dta, int k, int start);
void intfors_redir(t_data *dta);
int parsing_redir(t_data *dta, int i, int j, int k, int end);

// pars redir 2
char *take_input2();
void s_redir3(t_data *dta, int k);
void s_redir2(t_data *dta, int j, int start, int end, int i);
void s_redir4(t_data *dta, int *j, int k);


// heardoc
void    put_str_in_new_file(char *str, char *key, t_data *dta);
int 	pipe_heardoc(t_data *dta, int *i);
int 	getline_beforekey2(t_data *dta);
void 	getline_afterkey2(t_data *dta, int *i);

//pars env 
void getline_afterkey(t_data *dta, int *i, int *len);
int get_envln(t_data *dta, char *str);
int get_key(t_data *dta);
int getline_beforekey(char **env, t_data *dta);

// pars env2
char **env_split(char *env, t_data *dta);

// pars pipe
int pars_pipe(t_data *dta);

// signal 
void	init_signal(t_data *dta, struct sigaction *sa,
			struct termios *terminal);
void	handle_sig(int signum, siginfo_t *info, void *ptr);
void	handle_sig_alt(int signum, siginfo_t *info, void *ptr);

#endif
