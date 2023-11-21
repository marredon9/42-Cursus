/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marredon <marredon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:03:56 by marredon          #+#    #+#             */
/*   Updated: 2023/05/09 16:34:59 by marredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**array_of_paths;
	char	*cmd_path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	array_of_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (array_of_paths[i])
	{
		part_path = ft_strjoin(array_of_paths[i], "/");
		cmd_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	i = -1;
	while (array_of_paths[++i])
		free(array_of_paths[i]);
	free(array_of_paths);
	return (0);
}

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
		perror("Error");
	if (execve(path, cmd, envp) == -1)
		perror("Error");
	execve(path, cmd, envp);
}
