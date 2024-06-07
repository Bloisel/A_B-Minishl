/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:39:33 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/07 02:42:29 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Fonction pour compter les occurrences d'un délimiteur dans une chaîne
int count_delimiter(const char *str, char delimiter) 
{
   int count = 0;
   while (*str) 
			{
    	if (*str == delimiter) 
					{
       count++;
     }
     str++;
   }
   return count;
}

// Fonction pour diviser une chaîne en sous-chaînes basées sur un délimiteur
char **split_string(const char *str, char delimiter) 
{
    int num_tokens = count_delimiter(str, delimiter) + 1;
    char **tokens = malloc((num_tokens + 1) * sizeof(char *));
    const char *start = str;
    int token_index = 0;
    
    while (*str) 
				{
        if (*str == delimiter) 
								{
            int len = str - start;
            if (len > 0) {
                tokens[token_index] = malloc((len + 1) * sizeof(char));
                strncpy(tokens[token_index], start, len);
                tokens[token_index][len] = '\0';
                token_index++;
            }
            start = str + 1;
        }
        str++;
    }
    // Dernier token
    int len = str - start;
    if (len > 0) 
				{
        tokens[token_index] = malloc((len + 1) * sizeof(char));
        strncpy(tokens[token_index], start, len);
        tokens[token_index][len] = '\0';
        token_index++;
    }
    tokens[token_index] = NULL; // Terminateur NULL
    
    return tokens;
}

void free_split_result(char **result) 
{
    int i = 0;
    while (result[i] != NULL) 
				{
        free(result[i]);
        i++;
    }
    free(result);
}

void parse_commands(CommandData *data, const char *input) {
    // Séparer les commandes par '|'
    char **cmd_tokens = split_string(input, '|');
    
    // Compter les commandes
    int num_commands = 0;
    while (cmd_tokens[num_commands] != NULL) 
				{
        num_commands++;
    }
    
    data->commands = malloc(num_commands * sizeof(char **));
    data->num_commands = num_commands;
    
    // Séparer chaque commande en arguments par espace
    int i = 0;
    while (i < num_commands) 
				{
        data->commands[i] = split_string(cmd_tokens[i], ' ');
        i++;
    }
    free_split_result(cmd_tokens);
}

void print_commands(const CommandData *data) 
{
    int i = 0;
    while (i < data->num_commands) 
				{
        printf("Command %d:\n", i + 1);
        int j = 0;
        while (data->commands[i][j] != NULL) 
								{
           printf("  Arg %d: %s\n", j + 1, data->commands[i][j]);
           j++;
        }
        i++;
    }
}

void free_commands(CommandData *data) 
{
    int i = 0;
    while (i < data->num_commands) 
				{
        int j = 0;
        while (data->commands[i][j] != NULL) 
								{
            free(data->commands[i][j]);
            j++;
        }
        free(data->commands[i]);
        i++;
    }
    free(data->commands);
}


