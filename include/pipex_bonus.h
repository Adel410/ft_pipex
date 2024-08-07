/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:02:35 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/07 14:49:52 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/includes/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// STRUCTURE

typedef struct s_pipex
{
	char	**cmds_paths;
	char	***my_cmds;
	int		count_cmds;
	int		infile;
	int		outfile;
	int		size_env;
	int		i;
	int		arc;
	int		here_doc;
	int		save_outfilefd;
}			t_pipex;

// PROTOTYPES
void		ft_error(int i);
void		ft_parsing(char *argv[], char **envp, t_pipex *pipex);
void		ft_pipex(t_pipex *pipex, char *envp[], char **av);
void		ft_cleanup(t_pipex *pipex, char *str);
void		ft_exit_absolute_failed(t_pipex *pipex, int cmd_index, int *pipefd);
void		ft_close_pipe(t_pipex *pipex, int *pipefd);

// CHECK ACCCESS PROTOTYPES
void		ft_fix(t_pipex *pipex, char **envp);
int			ft_check_all(t_pipex *pipex, char **av);
int			ft_check_access(t_pipex *pipex, int cmd_index);
int			ft_check_absolute_access(t_pipex *pipex);
int			ft_check_absolute_access_here_doc(t_pipex *pipex);
int			ft_check_all_here_doc(t_pipex *pipex, char **av);

// INITS PROTOTYPES
void		ft_alloc_mycmds(t_pipex *pipex, char **argv, int argc);
void		ft_init(t_pipex *pipex, char **av);
void		ft_fd(t_pipex *pipex, char **av, int ac);

// EXECUTION PROTOTYPES
void		ft_exec(t_pipex *pipex, char **envp, int cmd_index);
void		ft_execute_cmds(t_pipex *pipex, char **envp);
void		ft_absolute_exec(t_pipex *pipex, char **av, char *envp[],
				int cmd_index);

// HERE_DOC PROTOTYPES
void		ft_heredoc(t_pipex *pipex, char **av);

// GNL
char		*get_next_line(int fd);
char		*ft_free(char *str);

#endif