/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:29:33 by acabon            #+#    #+#             */
/*   Updated: 2025/01/14 19:12:41 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int dup_fd(t_data *data, int i)
{
	if (i == 0)
	{
		if (dup2(data->fd_infile, STDIN_FILENO) == -1)
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->fd_infile);
	}
	else
	{
		if(dup2(data->tab_pipe[i - 1][0], STDIN_FILENO) == -1)
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->tab_pipe[i - 1][0]);
	}
	if (data->cmds[i + 1] == NULL)
	{
		if(dup2(data->fd_outfile, STDOUT_FILENO) == -1) // out_file = fd out_file
		{
			perror("Dup2 failed");
			return (EXIT_FAILURE);
		}
		close(data->fd_outfile);
	}
	else
	{
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
int mypipe(t_data *data)
{
	int i;

	i = 0;
	while (data->cmds[i] != NULL)
	{
		// mettre les pip dans uin tableau de pid

		// ft_printf("i = %d\n", i);
		if (data->cmds[i + 1] != NULL)
		{
			// ft_printf("voila %d %p\n", i, data->tab_pipe[i]);
			if (pipe(data->tab_pipe[i]) == -1)
			{
				perror("Pipe creation failed");
				return (EXIT_FAILURE);
			}
			data->current_pipe++;
		}

		// verrification aue les dup n'echouent pas
		if (dup_fd(data, i))
			return (EXIT_FAILURE); // free des trucs
		
		

		data->tab_pid[i] = fork();

		
		if (data->tab_pid[i] == -1) {
			// tout free
			perror("Fork failed");
			return 1;
		}

		if (data->tab_pid[i] == 0) {
			exec(data, data->cmds[i]);
			// perror("Error1 :");
			return (EXIT_FAILURE);
			// tout free
		}
		i++;
	}

	i = 0;
	while (data->cmds[i] != NULL)
	{
		// ft_printf("wait pid = %d\n", data->cmds[i]);
		waitpid(data->tab_pid[i], NULL, 0);
		i++;
	}
	
	
	
	// wait(NULL);
	return (EXIT_SUCCESS);
}
