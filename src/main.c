/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:17:08 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 14:24:27 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// valgrind --leak-check=full --trace-children=yes --track-fds=yes
int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	if (argc < 5 || (argc < 6 && (ft_strcmp(argv[1], "here_doc") == 0)))
	{
		ft_fprintf(2, "Usage: ./pipex file1 cmd1 cmd2 file2 or\
			./pipex here_doc LIMITER cmd1 cmd2 file2\n");
		return (EXIT_FAILURE);
	}
	data = init_data(argc, argv, envp);
	if (!data)
	{
		ft_fprintf(2, "Malloc error\n");
		return (EXIT_FAILURE);
	}
	if (open_files(data))
	{
		free_data(data);
		return (EXIT_FAILURE);
	}
	fork_and_pipe(data);
	free_data(data);
	return (EXIT_SUCCESS);
}

// pb d'ouvertudes des fichiers infile