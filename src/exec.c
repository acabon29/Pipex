/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:20:28 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 15:10:49 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_path_cmd(t_data *data, int i, char	**params)
{
	char	*tmp_path_slash;
	char	*path_cmd;

	tmp_path_slash = ft_strjoin(data->paths[i], "/");
	if (!tmp_path_slash)
	{
		free_tab((void **)params);
		return (NULL);
	}
	path_cmd = ft_strjoin(tmp_path_slash, params[0]);
	free(tmp_path_slash);
	if (!path_cmd)
	{
		free_tab((void **)params);
		return (NULL);
	}
	return (path_cmd);
}

static void	close_fd(t_data *data)
{
	int	j;

	j = 0;
	while (j < (data->current_pipe))
	{
		close(data->tab_pipe[j][0]);
		close(data->tab_pipe[j][1]);
		j++;
	}
	close(data->fd_outfile);
	close(data->fd_infile);
}

int	exec(t_data *data, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	**params;

	i = 0;
	while (data->paths[i] != NULL)
	{
		params = ft_split(cmd, ' ');
		if (!params)
			return (EXIT_FAILURE);
		path_cmd = get_path_cmd(data, i, params);
		if (!path_cmd)
			return (EXIT_FAILURE);
		if (!access(path_cmd, X_OK))
		{
			close_fd(data);
			execve(path_cmd, params, data->envp);
			perror(path_cmd);
		}
		free_tab((void **)params);
		free(path_cmd);
		i++;
	}
	ft_fprintf(2, "Erreur: commande not found\n");
	return (EXIT_FAILURE);
}
