/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/14 16:57:27 by bloisel          ###   ########.fr       */
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
	char *input;	
		
	init_data(&dta);

	while (1)
	{
		 input = take_input();	
		
		if (input == NULL)
		{
			break;
		}
		if (ft_strlen(input) > 0)
		{
			add_history(input);
		}
		set_v(&dta , input);
		s_quote(&dta, input);
		//replace_quote(&dta);
		//remove_q(&dta);
		printf("%s\n",dta.cmd);
		//if (env_copy(env , &dta) == 0)
		//	printf("%s\n",dta.cmd);
		free(input);
	} 
	return (0);
} 

