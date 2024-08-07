/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 15:13:33 by ahadj-ar         ###   ########.fr       */
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
	int		pipefd[2];
	int		i;
	int		pid1;
	int		pid2;
	int		infile;
	int		outfile;
	int		size_env;
	int		save_outfilefd;
}			t_pipex;

// PROTOTYPES

void		ft_error(int i);
void		ft_parsing(char *argv[], char **envp, t_pipex *pipex);
void		ft_pipex(t_pipex *pipex, char *envp[], char **av);
void		ft_cleanup(t_pipex *pipex, char *str);
void		ft_init(t_pipex *pipex);
int			ft_check_access(t_pipex *pipex, int cmd_index);
void		ft_close(t_pipex *pipex);
int			ft_check_all(t_pipex *pipex, char **av);
void		ft_alloc_mycmds(t_pipex *pipex, char **argv);

// EXECUTION PROTOTYPES

void		ft_exec(t_pipex *pipex, char **envp, int cmd_index);
void		ft_absolute_exec(t_pipex *pipex, char **av, char *envp[],
				int cmd_index);
#endif