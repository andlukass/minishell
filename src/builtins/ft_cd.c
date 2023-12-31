/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:14:55 by llopes-d          #+#    #+#             */
/*   Updated: 2023/12/25 12:11:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_path_valid(char **old_pwd, char *path)
{
	if (chdir(path) != 0)
	{
		perror(path);
		free(*old_pwd);
		return (0);
	}
	return (1);
}

static int	have_env(char **old_pwd)
{
	if (!get_env_value("HOME"))
	{
		printf("HOME is not set!\n");
		free(*old_pwd);
		return (0);
	}
	return (1);
}

static void	go_home(char **old_pwd)
{
	if (!have_env(old_pwd))
		ft_exit(NULL);
	if (!is_path_valid(old_pwd, get_env_value("HOME")))
		ft_exit(NULL);
}

void	ft_cd(char **command)
{
	char	directory[4097];
	char	*pwd;
	char	*old_pwd;

	if (command[1] && command[2])
	{
		printf("cd only takes one argument!\n");
		ft_exit(NULL);
	}
	getcwd(directory, sizeof(directory));
	old_pwd = ft_strjoin("OLDPWD=", directory, NO_FREE);
	if (!command[1] || !ft_strcmp(command[1], "~"))
		go_home(&old_pwd);
	else
		if (!is_path_valid(&old_pwd, command[1]))
			ft_exit(NULL);
	getcwd(directory, sizeof(directory));
	pwd = ft_strjoin("PWD=", directory, NO_FREE);
	add_next_node(&get_data()->env, pwd);
	add_next_node(&get_data()->env, old_pwd);
	if (get_data()->number_of_commands > 1)
		ft_exit(NULL);
	else
		return ;
}
