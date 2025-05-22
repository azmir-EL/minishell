/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:55:07 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 09:25:16 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char  **get_env(t_shell *shell)
{
	int	i;
	char **env;
	
	i = 0;
	while (shell->env[i])
		i++;
	env = malloc((i + 1) * sizeof(char*));
	i = 0;
	while (shell->env[i])
	{
		env[i] = ft_strdup(shell->env[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

char  *ft_env(t_shell *shell,char **args)
{
	char 	**env;
	char	*msg;
	int 	i;
	msg = ": No such file or directory";
	env = get_env(shell);
	if (!args[0])
		return(NULL);
	if (args[1])
	{
		write(2,"env: ",5);
		write(2,args[1],ft_strlen(args[1]));
		write(2,msg,ft_strlen(msg));
		write(2,"\n",1);
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		write(1,env[i],ft_strlen(env[i]));
		write(1,"\n",1);
		i++;
	}
	return (NULL);
}
