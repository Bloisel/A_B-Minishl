/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/05/16 21:04:28 by bloisel          ###   ########.fr       */
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
			printf("%s\n",dta.cmdwh);
			if (arg_beforeredir(&dta) == 0)
				dta.cmd = ft_strdup(dta.cmdwh);
			else
				dta.cmd = ft_strdup(dta.cmd_rdr);
			printf("redir main = %s\n",dta.cmd_rdr);
			//printf("white space = %s\n",dta.cmdwh);
			replace_quote(&dta);
			remove_q(&dta);
			getline_beforekey(env , &dta);
			printf("commande main %s\n", dta.cmd);
			free(input);
	}
	return (0);
} 

		// pas oublier d'utiliser la meme chaine 
		// free aussi contenue 
		// parsing pipe pipe en fin de chaine 
		// double pipe 
		//free(input);