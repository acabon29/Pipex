/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:17:03 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 14:31:21 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"

# include <errno.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**cmds;
	char	**paths;
	char	**envp;
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	int		*tab_pid;
	int		argc;
	pid_t	**tab_pipe;
	int		*tab_fd_pipe;
	int		current_pipe;
	char	here_doc;
	char	*here_doc_limiter;
}	t_data;

/*    Utility    */
void		del_content(void *content);
char		*get_infile(char *argv);
void		free_tab(void **tab);
void		free_tabn(void **tab, int i);
char		*find_path(char *envp[]);
void		free_data(t_data *data);

/*    other    */
int			fork_and_pipe(t_data *data);
int			exec(t_data *data, char *cmd);

int			open_files(t_data *data);
t_data		*init_data(int argc, char *argv[], char *envp[]);

#endif