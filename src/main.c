/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:17:08 by acabon            #+#    #+#             */
/*   Updated: 2025/01/14 19:12:12 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL
		&& ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (ft_strdup(envp[i] + 5));
}

int	get_all_path(t_data *data, char *envp[])
{
	char	*path;

	path = find_path(envp);
	if (!path)
		return (EXIT_FAILURE);
	
	data->paths = ft_split((const char *)path, ':');
	free(path);
	if (!(data->paths))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char **gen_tab_cmd(int argc, char *argv[])
{
	char **cmds;
	size_t i;

	cmds = malloc((argc - 2) * sizeof(char *));
	if (!cmds)
		return (NULL);
	
	i = 2;
	while (i < (size_t)(argc - 1))
	{
		// cmds[i - 2] = malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
		cmds[i - 2] = ft_strdup(argv[i]);
		if (!cmds[i - 2])
			return (free_tabn((void **)cmds, (int)(i - 2)), NULL);
		i++;
	}
	cmds[i - 2] = NULL;
	return (cmds);
}

int open_files(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1) {
			perror("Error opening file1");
			return (EXIT_FAILURE);
	}
	data->fd_outfile = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd_outfile == -1) {
			perror("Error opening file2");
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_data * init_data(int argc, char *argv[], char *envp[])
{
	t_data *data;
	int i;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->argc = argc;
	data->current_pipe = 0;
	if (get_all_path(data, envp))
		return (free(data), NULL);
	data->envp = envp;
	data->cmds = gen_tab_cmd(argc, argv);
	if (!data->cmds)
	{
		free_tab((void **)data->paths);
		free(data);
		return (NULL);
	}
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->tab_pid = malloc((argc - 3) * sizeof(int));
	if (!data->tab_pid)
	{
		free_tab((void **)data->paths);
		free_tabn((void **)data->cmds, (int)(data->argc - 3));
		free(data);
		return (NULL);
	}
	data->tab_pipe = malloc((argc - 4) * sizeof(pid_t *));
	if (!data->tab_pipe)
	{
		free_tab((void **)data->paths);
		free_tabn((void **)data->cmds, (int)(data->argc - 3));
		free(data->tab_pid);
		free(data);
		return (NULL);
	}
	i = 0;
	while (i < (argc - 4))
	{
		data->tab_pipe[i] = malloc(2 * sizeof(pid_t));
		if (!data->tab_pipe)
		{
			free_tab((void **)data->paths);
			free_tabn((void **)data->cmds, (int)(data->argc - 3));
			free(data->tab_pid);
			free_tabn((void **)data->tab_pipe, i);
			free(data);
			return (NULL);
		}
		i++;
	}
	
	return(data);
}

// valgrind --leak-check=full --trace-children=yes --track-fds=yes
int main(int argc, char *argv[], char *envp[])
{
	t_data *data;

	if (argc < 5)
	{
		perror("Usage: ./pipex file1 cmd1 cmd2 file2");
		return (EXIT_FAILURE);
	}

	data = init_data(argc, argv, envp);
	if (!data)
		return (EXIT_FAILURE);

	if(open_files(data))
	{
		free_data(data);
		return (EXIT_FAILURE);
	}

	mypipe(data);


	// free_tabn((void *)(data->paths), (size_tab((void *)(data->paths)) - 1));

	// close(data->fd_infile);
	// close(data->fd_outfile);
	// close(data->tab_pipe[0][0]);
	// close(data->tab_pipe[0][1]);
	free_data(data);
	return (EXIT_SUCCESS);
}
