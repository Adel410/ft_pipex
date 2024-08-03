/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:02:35 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 17:03:02 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

// STRUCTURE

typedef struct s_pipex
{
	char	**cmds_paths;
	char	***my_cmds;
	int		count_cmds;
	int		pipefd[2];
	int		pid1;
	int		pid2;
	int		infile;
	int		outfile;
	int		size_env;
	int		i;
}			t_pipex;

// PROTOTYPES

void		ft_error(int i);
void		ft_parsing(char *argv[], char **envp, t_pipex *pipex);
void		ft_pipex(t_pipex *pipex, char *envp[], char **av);
void		ft_cleanup(t_pipex *pipex);
void		ft_debug(t_pipex *pipex);
void		ft_init(t_pipex *pipex);
void		ft_exec(t_pipex *pipex, char **envp);
void		ft_perror(char *str);

// EXECUTION PROTOTYPES

void		ft_exec1(t_pipex *pipex, char **envp);
void		ft_exec2(t_pipex *pipex, char **envp);
void		ft_absolute_exec1(t_pipex *pipex, char **av, char *envp[]);
void		ft_absolute_exec2(t_pipex *pipex, char **av, char *envp[]);

#endif