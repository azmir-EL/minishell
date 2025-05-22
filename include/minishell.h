/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eazmir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:28:46 by eazmir            #+#    #+#             */
/*   Updated: 2025/05/22 17:14:25 by eazmir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
#include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
#include <stddef.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
#include <string.h>
# include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_shell
{
	char *value;
	char 	**env;
	struct s_shell *next;
}t_shell;


typedef struct s_cmd
{
    char **args;
    char *infile;
    char *outfile;
    int append;
    int pipe_to_next;
    struct s_cmd *next;
} t_cmd;


void	_(t_shell **shell,char **env,char *new_var);
void	minishell(t_cmd *cmd,char **env);
t_cmd 	*parse_commands(char *args);
void	print_cmd_list(t_cmd *cmd);
void	cd(t_cmd *shell, char **args);
void	ft_exit(char **args);
void	echo(char **args);
char	*ft_env(t_shell *shell,char **args);
int	pwd(t_shell *shell,char **args);
int	unset(t_shell *shell,char **args);
void	printList(t_shell **node);
void	ft_export(t_shell **shell,char **env,char **args);
char	**get_env(t_shell *shell);
void	free_split(char **split_path);
int		open_file(char *file, int mode);
char	*get_next_line(int fd);
void	error(int mode);
void	exec(char *av, char **env);
#endif

