/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:58:58 by llopes-d          #+#    #+#             */
/*   Updated: 2023/12/25 12:11:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **command)
{
	int	i;

	if (ft_strcmp(command[1], "-n"))
		i = 1;
	else
		i = 2;
	while (command[i])
	{
		printf("%s", command[i++]);
		if (command[i])
			printf(" ");
	}
	if (ft_strcmp(command[1], "-n"))
		printf("\n");
	ft_exit(NULL);
}
