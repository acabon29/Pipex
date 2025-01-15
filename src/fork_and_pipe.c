/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:33 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 14:26:34 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	dup_fd(t_data *data, int i)
{
	if (i == 0)
	{
		if (dup2(data->fd_infile, STDIN_FILENO) == -1)
			return (perror("Dup2 failed"), EXIT_FAILURE);
		close(data->fd_infile);
	}
	else
	{
		if (dup2(data->tab_pipe[i - 1][0], STDIN_FILENO) == -1)
			return (perror("Dup2 failed"), EXIT_FAILURE);
		close(data->tab_pipe[i - 1][0]);
	}
	if (data->cmds[i + 1] == NULL)
	{
		if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
			return (perror("Dup2 failed"), EXIT_FAILURE);
		close(data->fd_outfile);
	}
	else
	{
		if (dup2(data->tab_pipe[i][1], STDOUT_FILENO) == -1)
			return (perror("Dup2 failed"), EXIT_FAILURE);
		close(data->tab_pipe[i][1]);
	}
	return (EXIT_SUCCESS);
}

static void	wait_process(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds[i] != NULL)
	{
		waitpid(data->tab_pid[i], NULL, 0);
		i++;
	}
}

int	create_pipe(t_data *data, int i)
{
	if (data->cmds[i + 1] != NULL)
	{
		if (pipe(data->tab_pipe[i]) == -1)
		{
			perror("Pipe creation failed");
			return (EXIT_FAILURE);
		}
		data->current_pipe++;
	}
	return (EXIT_SUCCESS);
}

int	fork_and_pipe(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmds[i] != NULL)
	{
		if (create_pipe(data, i))
			return (EXIT_FAILURE);
		if (dup_fd(data, i))
			return (EXIT_FAILURE);
		data->tab_pid[i] = fork();
		if (data->tab_pid[i] == -1)
		{
			perror("Fork failed");
			return (EXIT_FAILURE);
		}
		if (data->tab_pid[i] == 0)
		{
			exec(data, data->cmds[i]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	wait_process(data);
	return (EXIT_SUCCESS);
}
