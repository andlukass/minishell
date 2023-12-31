/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:39:20 by user              #+#    #+#             */
/*   Updated: 2024/01/05 16:46:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define RED "<>"

static void	check_quotes(char c, int *double_q, int *single_q)
{
	if (c == '\"' && *double_q == 0 && *single_q == 0)
		*double_q = 1;
	else if (c == '\"' && *double_q == 1 && *single_q == 0)
		*double_q = 0;
	if (c == '\'' && *single_q == 0 && *double_q == 0)
		*single_q = 1;
	else if (c == '\'' && *single_q == 1 && *double_q == 0)
		*single_q = 0;
}

static int	check_redirections(char *input, char *new_input, int open_quotes)
{
	int	i;

	i = -1;
	if (open_quotes)
		return (0);
	while (RED[++i])
	{
		if (input[0] != RED[i] && input[1] == RED[i] && input[0] != ' ')
		{
			new_input[0] = input[0];
			new_input[1] = '\2';
			return (1);
		}
		if (input[0] == RED[i] && input[1] != RED[i] && input[1] != ' ')
		{
			new_input[0] = input[0];
			new_input[1] = '\2';
			return (1);
		}
	}
	return (0);
}

static void	init_vars(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

char	*lexer(char *input)
{
	char	*new_input;
	int		i;
	int		j;
	int		double_q;
	int		single_q;

	init_vars(&i, &j, &double_q, &single_q);
	new_input = malloc(sizeof(char) * (ft_strlen(input) * 2) + 1);
	while (input[i])
	{
		if (check_redirections(&input[i], &new_input[j], double_q + single_q))
			j++;
		else if (input[i] == ' ' && (double_q == 0 && single_q == 0))
			new_input[j] = '\2';
		else if (input[i] == '|' && (double_q == 0 && single_q == 0))
			new_input[j] = '\3';
		else
			new_input[j] = input[i];
		check_quotes(input[i++], &double_q, &single_q);
		j++;
	}
	new_input[j] = '\0';
	if (seek_errors(new_input, single_q + double_q))
		return (free(new_input), NULL);
	return (new_input);
}
