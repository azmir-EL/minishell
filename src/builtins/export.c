/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:38:08 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 17:53:48 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/minishell.h"


/*
int path_len(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
		i++;
	return (i);
	
}

char  **ft_sort_tab(char **tab,int len)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(tab[i],tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

char **cp_path(t_shell *shell)
{
	int	len;
	int 	i;
	char **ptr;
	
	
	len = path_len(shell->env);
	ptr = malloc((len + 1) * sizeof(char *));
	i = 0;
	while (i < len)
	{
		ptr[i] = ft_strdup(shell->env[i]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void print_path(t_shell *shell)
{
	int	len;
	int	i;
	char **path;
	char **sort_path;
	
	path = cp_path(shell);
	len = path_len(path);
	sort_path = ft_sort_tab(path,len);
	i = 0;
	
	while (sort_path[i])
	{
		
		ft_putstr_fd("declare -x ",1);
		ft_putstr_fd(sort_path[i],1);
		write(1,"\n",1);
		i++;
	}
}
*/
t_shell	 *create_node(char *data)
{
	t_shell *node = malloc(sizeof(t_shell));
	node->value = ft_strdup(data);
	node->next = NULL;
	return (node);
	
}

void add_back(t_shell **head,t_shell *last)
{
	t_shell	*tmp;
	if (*head == NULL)
		*head = last;
	else
	{	tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next  = last;
	}
	
}


void 	_(t_shell **shell,char **env,char *new_var)
{
	int i = 0;
	while (env[i])
	{
		add_back(shell,create_node(env[i]));
		i++;
	}
	if (new_var)
		add_back(shell,create_node(new_var));
}

void printList(t_shell **node)
{
	t_shell *tmp;

	tmp = *node;
	while (tmp)
	{
		printf("%s\n",tmp->value);
		tmp = tmp->next;
	}
	printf("The end\n");
}
void	ft_export(t_shell **shell,char **args,char **env)
{
	if (!args[1])
		printList(shell);
	else
	{
		_(shell,env,"user=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		printf("Done\n");
	}
	(void)args;
}
/*
int main(int ac,char **av,char **env)
{
	t_shell *shell = NULL;
	
	_(&shell,env,"user=azmir");
	printLinkedList(shell);
}
*/
