/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:34:59 by bloisel           #+#    #+#             */
/*   Updated: 2024/03/15 14:01:25 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int set_v(t_data *dta, char *str)
{
	dta->cmd = ft_strdup(str);
	if (dta->cmd == NULL)
	{
		printf("Error Memory allocation\n");
		return (-1);
	}
	dta->wc = dta->wc = (char *)malloc((ft_strlen(dta->cmd) + 1)*sizeof(char));
	if (dta->wc == NULL)
	{
		printf("Error memory allocation\n");
		return (-1);	
	}
	ft_bzero(dta->wc, ft_strlen(dta->cmd));
	// fonction error g error etc
	return (0);
}

int	is_sep(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}
