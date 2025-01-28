/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:59:50 by acabon            #+#    #+#             */
/*   Updated: 2025/01/28 15:53:29 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	open_here_doc(t_data *data)
{
	char	*buffer;
	char	*limiter;

	data->fd_infile = open("./src/here_doc",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_infile == -1)
		return (perror("Error here_doc"), EXIT_FAILURE);
	limiter = ft_strjoin(data->here_doc_limiter, "\n");
	if (!limiter)
	{
		close(data->fd_infile);
		return (ft_fprintf(2, "Malloc error\n"), EXIT_FAILURE);
	}
	buffer = get_next_line(1);
	while (buffer != NULL && (ft_strcmp(buffer, limiter) != 0))
	{
		write(data->fd_infile, buffer, ft_strlen(buffer));
		ft_bzero(buffer, ft_strlen(buffer));
		free(buffer);
		buffer = get_next_line(1);
	}
	if (buffer != NULL)
		free(buffer);
	free(limiter);
	return (close(data->fd_infile), EXIT_SUCCESS);
}

int	open_files(t_data *data)
{
	if (data->here_doc == 1)
		open_here_doc(data);
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror(data->infile);
		data->fd_infile = open("/dev/null", O_RDONLY);
		data->cmds++;
		data->valid_infile = 1;
	}
	if (data->here_doc == 1)
		data->fd_outfile = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
	data->fd_outfile = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_outfile == -1)
	{
		close(data->fd_infile);
		perror(data->outfile);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
