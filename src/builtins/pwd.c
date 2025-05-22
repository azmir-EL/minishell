/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:58:08 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 15:23:32 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"

char	*set_path1(t_shell *shell , char *parm,int len)
{
	int		j;
	int		size;
	char	*ptr;
	char	*ptr2;

	while (shell)
	{
		j = 0;
		while (shell->env[j])
		{
			if (ft_strncmp(shell->env[j],parm,len) == 0)
			{
				size = ft_strlen(shell->env[j]);
				ptr = malloc((size + 1) * sizeof(char));
				ft_strlcpy(ptr,shell->env[j],size+1);
				ptr2 = ft_substr(ptr,len,size);
				return (ptr2);
			}
			j++;
		}
		shell = shell->next;
	}
	return (NULL);
}

int pwd(t_shell *shell ,char **args)
{
	char *pwd;
	char *msg;

	msg = "pwd: too many arguments";
	pwd = set_path1(shell,"PWD=",4);
	if (args[1])
	{
		write(2,msg,ft_strlen(msg));
		write(2,"\n",1);
		return (1);
	}
	ft_putendl_fd(pwd,1);
	return (0);
}
