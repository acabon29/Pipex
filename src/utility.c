/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:39:11 by acabon            #+#    #+#             */
/*   Updated: 2025/01/28 15:53:58 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	del_content(void *content)
{
	free(content);
}

char	*find_path(char *envp[])
{
	int	i;
	char *res;

	i = 0;
	while (envp[i] != NULL
		&& ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (ft_fprintf(2, "Path not find\n"), NULL);
	res = ft_strdup(envp[i] + 5);
	if (!res)
		return (ft_fprintf(2, "Malloc error\n"), NULL);
	return (res);
}

void	free_data(t_data *data)
{
	if (data->valid_infile)
		data->cmds--;
	free_tab((void **)data->paths);
	free_tabn((void **)data->cmds,
		(int)(data->argc - (3 + data->here_doc)));
	free(data->tab_pid);
	free_tabn((void **)data->tab_pipe,
		(int)(data->argc - (5 + data->here_doc)));
	free(data);
}
