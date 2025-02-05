/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:05:02 by acabon            #+#    #+#             */
/*   Updated: 2025/01/28 16:04:40 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	get_all_path(t_data *data, char *envp[])
{
	char	*path;

	path = find_path(envp);
	if (!path)
		return (EXIT_FAILURE);
	data->paths = ft_split((const char *)path, ':');
	free(path);
	if (!(data->paths))
	{
		ft_fprintf(2, "Malloc error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char	**gen_tab_cmd(int argc, char *argv[], char here_doc)
{
	char	**cmds;
	size_t	i;
	size_t	decal;

	decal = 2 + here_doc;
	cmds = malloc((argc - decal) * sizeof(char *));
	if (!cmds)
	{
		ft_fprintf(2, "Malloc error\n");
		return (NULL);
	}
	i = decal;
	while (i < (size_t)(argc - 1))
	{
		cmds[i - decal] = ft_strdup(argv[i]);
		if (!cmds[i - decal])
		{
			ft_fprintf(2, "Malloc error\n");
			free_tabn((void **)cmds, (int)(i - decal));
			return (NULL);
		}
		i++;
	}
	cmds[i - decal] = NULL;
	return (cmds);
}

static int	init_tab_pipe(t_data *data, int argc, int i)
{
	data->tab_pipe = malloc((argc - (4 + data->here_doc)) * sizeof(pid_t *));
	if (!data->tab_pipe)
	{
		free_tab((void **)data->paths);
		free_tabn((void **)data->cmds,
			(int)(data->argc - (3 + data->here_doc)));
		ft_fprintf(2, "Malloc error\n");
		return (free(data->tab_pid), EXIT_FAILURE);
	}
	i = 0;
	while (i < (argc - (4 + data->here_doc)))
	{
		data->tab_pipe[i] = malloc(2 * sizeof(pid_t));
		if (!data->tab_pipe)
		{
			free_tab((void **)data->paths);
			free_tabn((void **)data->cmds,
				(int)(data->argc - (3 + data->here_doc)));
			free(data->tab_pid);
			ft_fprintf(2, "Malloc error\n");
			return (free_tabn((void **)data->tab_pipe, i), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	init_base_data(t_data *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->current_pipe = 0;
	data->envp = envp;
	data->outfile = argv[argc - 1];
	data->valid_infile = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		data->here_doc_limiter = argv[2];
		data->here_doc = 1;
		data->infile = "./src/here_doc";
	}
	else
	{
		data->infile = argv[1];
		data->here_doc = 0;
	}
	if (get_all_path(data, envp))
		return (EXIT_FAILURE);
	data->cmds = gen_tab_cmd(argc, argv, data->here_doc);
	if (!data->cmds)
	{
		free_tab((void **)data->paths);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_data	*init_data(int argc, char *argv[], char *envp[])
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_fprintf(2, "Malloc error\n"), NULL);
	if (init_base_data(data, argc, argv, envp))
		return (free(data), NULL);
	data->tab_pid = malloc((argc - (3 + data->here_doc)) * sizeof(int));
	if (!data->tab_pid)
	{
		free_tab((void **)data->paths);
		free_tabn((void **)data->cmds,
			(int)(data->argc - (3 + data->here_doc)));
		free(data);
		ft_fprintf(2, "Malloc error\n");
		return (NULL);
	}
	i = 0;
	if (init_tab_pipe(data, argc, i))
		return (free(data), NULL);
	return (data);
}
