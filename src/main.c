/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:34:41 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 17:54:52 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

char **split_input(char *token)
{
	char **split;
	char **ptr;
	int i;
	split = ft_split(token,' ');
	i = 0;
	while (split[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	i = 0;
	while (split[i])
	{
		ptr[i] = ft_strdup(split[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

int main(int argc,char **argv,char **env)
{
	(void)argc;
	(void)argv;
	

	t_cmd *cmd;
	char *input;
	char **args;
	cmd = malloc(sizeof(t_cmd));

	t_shell *shell = NULL;
	_(&shell, env, NULL );
	while (1)
	{
		input = readline("$> ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		args = split_input(input);
       		if (args[0] && strcmp(args[0], "export") == 0)
		{
			ft_export(&shell,args,env);
		}
		else
		{
			cmd = parse_commands(input);
			print_cmd_list(cmd);
			if (cmd)
				minishell(cmd,env);
		}
		//free(input);
	
	}
}
