/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:03:56 by marredon          #+#    #+#             */
/*   Updated: 2023/05/09 16:34:59 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, S_IRWXU);
	if (infile == -1)
		perror("Error");
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute_cmd(argv[2], env);
}

void	parent(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (outfile == -1)
		perror("Error");
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("Error");
		pid1 = fork();
		if (pid1 == -1)
			perror("Error");
		if (pid1 == 0)
		child(argv, env, fd);
		waitpid(pid1, NULL, 0);
		parent (argv, env, fd);
	}
	else
	{
		ft_putendl_fd("Bad arguments", 2);
	}
	return (0);
}