/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:54:15 by llopes-d          #+#    #+#             */
/*   Updated: 2024/01/29 18:42:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BLUE "\001\033[1;94m\002-> \001\033[0m\002\001\033[104m\002 "
# define GREEN "\001\033[1;92m\002-> \001\033[0m\002\001\033[30;102m\002 "
# define PINK "\001\033[1;95m\002-> \001\033[0m\002\001\033[105m\002 "
# define YELLOW "\001\033[1;93m\002-> \001\033[0m\002\001\033[30;103m\002 "
# define RED "\001\033[1;91m\002-> \001\033[0m\002\001\033[101m\002 "
# define WHITE "\001\033[1m\002-> \001\033[0m\002\001\033[30;107m\002 "

/* ---------------HEADERS--------------- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <sys/wait.h>
# include <fcntl.h>

# include <sys/stat.h>

# include <signal.h>

# include <dirent.h>

# include "env.h"
# include "executor.h"
# include "parser.h"
# include "builtins.h"
# include "utils.h"
# include "expander.h"
/* ------------------------------------- */

typedef struct s_env{
	char			*variable;
	struct s_env	*next;
}	t_env;

typedef struct s_commands{
	char				**command;
	char				**gt_files;
	char				**greater_than;
	char				**heredocs;
	char				**lt_files;
	char				*less_than;
	struct s_commands	*next;
}	t_commands;

typedef struct s_exec{
	int			next_fd[2];
	int			files[2];
	int			fd[2];
	int			*pids;
}	t_exec;

typedef struct s_data{
	char		*prompt_color;
	int			number_of_commands;
	int			interactive;
	int			exit_status;
	int			quit;
	int			pid;
	t_commands	*commands;
	t_env		*env;
}	t_data;

/**
 * @brief	Static struct accessible from any point of the code.
 * @return	the adress of the static struct.
 */
t_data	*get_data(void);

/**
 * @brief	Capture CTRL C command and give the prompt back
 */
void	signal_handler_main(int sig);

/**
 * @brief	Capture CTRL C command and close standard input
 * ending capture processes
 */
void	signal_handler_heredoc(int sig);

void	print_error(char *value, char *message);

#endif