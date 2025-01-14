/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:20:28 by acabon            #+#    #+#             */
/*   Updated: 2025/01/14 17:14:51 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	exec(t_data *data, char *cmd)
{
	int		i;
	char	*tmp_path_slash;
	char	*tmp_path_cmd;
	char	**params;

	i = 0;
	while (data->paths[i] != NULL)
	{
		params = ft_split(cmd, ' ');
		if(!params)
			return (EXIT_FAILURE);

		tmp_path_slash = ft_strjoin(data->paths[i], "/");
		tmp_path_cmd = ft_strjoin(tmp_path_slash, params[0]);
		free(tmp_path_slash);
		if(!access(tmp_path_cmd, X_OK))
		{
			execve(tmp_path_cmd, params, data->envp);
			perror(tmp_path_cmd);
		}
		// mettre une erreur en cas de commade non trouve
		free(tmp_path_cmd);
		i++;
	}
	return (EXIT_FAILURE);
}
