/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:39:54 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 15:26:53 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
 
int ft_clear(t_shell *shell,char *args)
{
	t_shell *tmp;

	while(shell)
	{
		if (ft_strncmp( (*shell->env),args,ft_strlen(args)) == 0)
		{
			tmp = shell->next;
			free(tmp);
			tmp = shell;
			return(0);
		}
		shell = shell->next;
	}
	return (1);
}

int unset(t_shell *shell ,char **args)
{
	
	if (ft_clear(shell,args[1]))
	{
		write(1," " ,1);
		return (0);
	}
	return (1);
}
