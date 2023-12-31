/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:20:27 by llopes-d          #+#    #+#             */
/*   Updated: 2023/12/25 12:10:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*get_copy(void)
{
	t_env	*copy;
	t_env	*current;
	char	*variable;

	current = get_data()->env;
	copy = (void *)0;
	while (current)
	{
		variable = ft_strdup(current->variable);
		add_next_node(&copy, variable);
		current = current->next;
	}
	return (copy);
}

static void	print_export(t_env *env_copy)
{
	t_env	*current;
	char	*temp;

	current = env_copy;
	while (current->next)
	{
		if (ft_strncmp(current->variable, current->next->variable, \
				ft_strchr(current->variable, '=') - current->variable) > 0)
		{
			temp = current->variable;
			current->variable = current->next->variable;
			current->next->variable = temp;
			current = env_copy;
		}
		current = current->next;
	}
	while (env_copy)
	{
		if (ft_strchr(env_copy->variable, '=') \
				&& !(*(ft_strchr(env_copy->variable, '=') + 1)))
			printf("declare -x %s''\n", env_copy->variable);
		else
			printf("declare -x %s\n", env_copy->variable);
		env_copy = env_copy->next;
	}
}

static void	export_add(char **command)
{
	int		index;
	char	*argument;

	index = 1;
	while (command[index])
	{
		argument = command[index++];
		if (*argument >= '0' && *argument <= '9')
			printf("'%c' identifier can't start with numbers\n", *argument);
		else
		{
			argument = ft_strdup(argument);
			add_next_node(&get_data()->env, argument);
		}
	}
}

void	ft_export(char **command)
{
	t_env	*env_copy;

	env_copy = get_copy();
	if (!command[1])
		print_export(env_copy);
	else
		export_add(command);
	free_env(env_copy);
	if (get_data()->number_of_commands > 1)
		ft_exit(NULL);
	else
		return ;
}
