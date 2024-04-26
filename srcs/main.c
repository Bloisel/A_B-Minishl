/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:09:56 by bloisel           #+#    #+#             */
/*   Updated: 2024/04/26 14:43:41 by bloisel          ###   ########.fr       */
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
		countwh_sep(&dta);
		s_redir(&dta);
		
		//countwh_sep(&dta);
		//init_intforredir(&dta);
		//free(input);
	}
	return (0);
} 

