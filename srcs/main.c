/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/07 03:22:27 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int get_exit_status;

char *take_input()
{
	return readline("~$");
}

int	main(int argc, char **argv, char **env) 
{
	t_data	dta;
	CommandData data;
	char 		*input;	
	struct sigaction	sa;
	struct termios		terminal;

	
	init_data(&dta);
	init_data3(&data);
	init_signal(&dta, &sa , &terminal);
	while (1)
	{
		input = take_input();	
		if (input == NULL)
					break;
			if (ft_strlen(input) > 0)
					add_history(input);
			set_v(&dta , input);
			if (s_quote(&dta, input) != 1)
				return (1);
			dta.cmd2 = ft_strdup(input);
			countwh_sep(&dta);
			intfors_redir(&dta);
			pars_pipe(&dta);
			// handle_sig()
			// // replace_quote(&dta);
			// // remove_q(&dta);
			if(pars_pipe(&dta) == 0)
			{
				parse_commands(&data, input);
   	print_commands(&data);
   	free_commands(&data);
			}
			free(input);
	}
	return (0);
} 

// main appele une fonction parsing qui fait tout et renvoie dans le main un triple tab 
		// pas oublier d'utiliser la meme chaine 
		// free aussi contenue 
		// parsing pipe pipe en fin de chaine 
		// double pipe 
		//free(input);