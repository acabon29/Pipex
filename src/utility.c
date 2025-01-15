/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:39:11 by acabon            #+#    #+#             */
/*   Updated: 2025/01/14 19:46:58 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	del_content(void *content)
{
	free(content);
}

void free_data(t_data *data)
{
	// int i;

	free_tab((void **)data->paths);
	// i = 0;
	// while (data->paths[i])
	// {
	// 	free(data->paths[i]);
	// 	i++;
	// }
	// free(data->paths);
	free_tabn((void **)data->cmds, (int)(data->argc - 3));
	free(data->tab_pid);
	// free_tabn((void **)data->tab_pipe, (int)(data->argc - 5));
	free_tabn((void **)data->tab_pipe, (int)(data->argc - 5));
	free(data);
}

int size_tab(void **tab)
{
	size_t i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tabn(void **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}
