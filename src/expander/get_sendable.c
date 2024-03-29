/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sendable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:38:26 by isbraz-d          #+#    #+#             */
/*   Updated: 2024/01/29 19:02:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_sendable(char *str)
{
	char	*sendable;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sendable = malloc(sizeof(char) * ft_strlen(str));
	if (!sendable)
		return (NULL);
	while (str[i] != '$')
		i++;
	i++;
	while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		sendable[j++] = str[i++];
	sendable[j] = '\0';
	return (sendable);
}
