/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:01 by llopes-d          #+#    #+#             */
/*   Updated: 2023/11/26 15:33:06 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	index;

	if (!s)
		return (0);
	index = 0;
	while ((s[index] != '\0'))
		index++;
	return (index);
}
