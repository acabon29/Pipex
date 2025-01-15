/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:33 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 11:14:54 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int dup_fd(t_data *data, int i)
{
	if (i == 0)
	{
		// dup2(data->fd_infile, STDIN_FILENO);
		if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->fd_infile);
	}
	else
	{
		// dup2(data->tab_pipe[i - 1][0], STDIN_FILENO);
		if(dup2(data->tab_pipe[i - 1][0], STDIN_FILENO) == -1)
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->tab_pipe[i - 1][0]);
	}
	if (data->cmds[i + 1] == NULL)
	{
		// dup2(data->fd_outfile, STDOUT_FILENO);
		if(dup2(data->fd_outfile, STDOUT_FILENO) == -1) // out_file = fd out_file
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->fd_outfile);
	}
	else
	{
		// dup2(data->tab_pipe[i][1], STDOUT_FILENO);
		if(dup2(data->tab_pipe[i][1], STDOUT_FILENO) == -1)
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->tab_pipe[i][1]);
	}
	return (EXIT_SUCCESS);
}

// faire un while plutot qu'une fonction recursive
int fork_and_pipe(t_data *data)
{
	int i;

	i = 0;
	while (data->cmds[i] != NULL)
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

		if (dup_fd(data, i))
			return (EXIT_FAILURE); // free des trucs

		data->tab_pid[i] = fork();
		if (data->tab_pid[i] == -1) {
			perror("Fork failed");
			free_data(data);
			return (EXIT_FAILURE);
		}

		if (data->tab_pid[i] == 0) {
			exec(data, data->cmds[i]);
			// free_data(data);
			return (EXIT_FAILURE);
		}
		i++;
	}

	i = 0;
	while (data->cmds[i] != NULL)
	{
		waitpid(data->tab_pid[i], NULL, 0);
		i++;
	}
	return (EXIT_SUCCESS);
}
