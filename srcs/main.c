/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/20 06:43:16 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *take_input()
{
	return readline("~$");
}

int	main(int argc, char **argv, char **env) 
{
	t_data	dta;
	char 		*input;	
		
	init_data(&dta);
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
			countwh_sep(&dta);
			arg_beforeredir(&dta);
			
			// if (arg_beforeredir(&dta) == 1)
			// 	dta.cmd = ft_strdup(dta.cmdwh);
			// else	
			// 	dta.cmd = ft_strdup(dta.cmd_rdr);
			// // replace_quote(&dta);
			// // remove_q(&dta);
			// // rajouter un if si $ var env sinon malloc pour rien // getline_beforekey(env , &dta);
			printf("commande main %s\n", dta.cmd);
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