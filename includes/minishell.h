/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:15 by llopes-d          #+#    #+#             */
/*   Updated: 2023/11/26 18:10:11 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define GLOBAL_WARMING_DONT_EXIST 1
# define DO_FREE 1
# define NO_FREE 0

typedef struct s_env{
	char	*key;
	char	*value;
	struct s_env *next;
}	t_env;

typedef struct s_data{
	char	*input;
	char	*prompt;
	char	*username;
	char	*path;
	t_env	current_env;
}	t_data;


/**
 * @brief	Static struct accessible from any point of the code.
 * @return	the adress of the static struct.
 */
t_data	*get_data(void);



/**
 * @param	s the string in which to search.
 * @param	c the char to search in 's'.
 * @return	the adress of the last occurence of 'c' in 's'.
 * 0 if nothing is found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief	Concatenates two strings.
 * @param	is_free is used to determine whether you 
 * want to free s1 or not. Passing 0 indicate that 
 * it should not be freed.
 * @return	the new concatenated string, which should be
 * freed afer use.
 */
char	*ft_strjoin(char *s1, char *s2, int is_free);

/**
 * @param	s string in which to get size.
 * @return	the size of 's'.
 */
int		ft_strlen(const char *s);



/**
 * @brief	Compares home directory with the current PWD
 * and returns the portion of the actual directory path 
 * that is beyond the home directory.
 */
char	*get_dir(void);

/**
 * @brief	Concatenates the username with the current directory
 * and end the terminal stylization.
 * The prompt is stored in the global data.
 */
void	get_prompt(void);

/**
 * @brief	Gets the username and initiates the terminal stylization.
 * The username is stored in the global data.
 */
void	get_username(void);


/**
 * @brief	Prints exit message, free what is needed and exit program.
 */
void ft_exit(void);

/**
 * @brief	Prints whats was the input.
 */
void ft_echo(char *str);

#endif