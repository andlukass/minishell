/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:19:38 by user              #+#    #+#             */
/*   Updated: 2023/12/11 00:00:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset(char **command)
{
	int	i;

	i = 1;
	while (command[i])
		remove_env_value(command[i++]);
	if (get_data()->number_of_commands > 1)
		ft_exit(NULL);
	else
		return ;
}
