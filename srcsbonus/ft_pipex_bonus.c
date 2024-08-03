/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/08/02 14:07:15 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/08/02 14:07:15 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_flag0(t_pipex *pipex, char **envp)
{
	int pid1;
	int pid2;

	if (pipe(pipex->pipefd) != 0)
	{
		ft_perror("pipe()");
		ft_cleanup(pipex);
	}
	pid1 = fork();
	if (pid1 == 0)
		ft_exec1(pipex, envp);
	pid2 = fork();
	if (pid2 == 0)
		ft_exec2(pipex, envp);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait(&pid1);
	wait(&pid2);
}

void	ft_flag1(t_pipex *pipex, char **envp, char **av)
{
	int pid1;
	int pid2;

	if (pipe(pipex->pipefd) != 0)
	{
		ft_perror("pipe()");
		ft_cleanup(pipex);
	}
	pid1 = fork();
	if (pid1 == 0)
		ft_absolute_exec1(pipex, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		ft_exec2(pipex, envp);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait(&pid1);
	wait(&pid2);
}

void	ft_flag2(t_pipex *pipex, char **envp, char **av)
{
	int pid1;
	int pid2;

	if (pipe(pipex->pipefd) != 0)
	{
		ft_perror("pipe()");
		ft_cleanup(pipex);
	}
	pid1 = fork();
	if (pid1 == 0)
		ft_exec1(pipex, envp);
	pid2 = fork();
	if (pid2 == 0)
		ft_absolute_exec2(pipex, av, envp);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait(&pid1);
	wait(&pid2);
}

void	ft_flag3(t_pipex *pipex, char **envp, char **av)
{
	int pid1;
	int pid2;

	if (pipe(pipex->pipefd) != 0)
	{
		ft_perror("pipe()");
		ft_cleanup(pipex);
	}
	pid1 = fork();
	if (pid1 == 0)
		ft_absolute_exec1(pipex, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		ft_absolute_exec2(pipex, av, envp);
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait(&pid1);
	wait(&pid2);
}

void	ft_pipex(t_pipex *pipex, char **envp, char **av)
{
	int flag;
	int get;
	(void)envp;
	(void)pipex;

	flag = 0;
	get = 1;
	while (av[get])
	{
		if (access(av[get], X_OK) == 0)
			flag++;
		get++;
	}
	printf("%d\n", flag);
	// if (access(av[2], X_OK) == 0)
	// 	flag = 1;
	// if (access(av[3], X_OK) == 0)
	// 	flag = flag + 2;
	// if (flag == 0)
	// 	ft_flag0(pipex, envp);
	// else if (flag == 1)
	// 	ft_flag1(pipex, envp, av);
	// else if (flag == 2)
	// 	ft_flag2(pipex, envp, av);
	// else if (flag == 3)
	// 	ft_flag3(pipex, envp, av);
}
