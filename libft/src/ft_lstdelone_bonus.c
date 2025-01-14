/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:20:18 by acabon            #+#    #+#             */
/*   Updated: 2025/01/07 15:17:04 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void ft_putlist(t_list *begin_list)
// {
// 	t_list *current_list;

// 	current_list = begin_list;
// 	while(current_list != NULL)
// 	{
// 		printf("%s\n", (char *)current_list->content);
// 		current_list = current_list->next;
// 	}
// }

// void free_content(void *content)
// {
// 	free(content);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// int main()
// {
// 	t_list *new_list;
// 	t_list *temps_list;

// 	void * content1;
// 	void * content2;
// 	void * content3;
// 	content1 = malloc(10);
// 	content2 = malloc(10);
// 	content3 = malloc(10);
// 	((char *)content1)[0] = 't';
// 	((char *)content1)[1] = '1';
// 	((char *)content1)[2] = 0;
// 	((char *)content2)[0] = 't';
// 	((char *)content2)[1] = '2';
// 	((char *)content2)[2] = 0;
// 	((char *)content3)[0] = 't';
// 	((char *)content3)[1] = '3';
// 	((char *)content3)[2] = 0;

// 	new_list = ft_lstnew(content1);
// 	ft_lstadd_back(&new_list, ft_lstnew(content2));
// 	ft_lstadd_back(&new_list, ft_lstnew(content3));
// 	ft_putlist(new_list);

// 	while(new_list != NULL)
// 	{
// 		temps_list = new_list->next;
// 		ft_lstdelone(new_list, free_content);
// 		// free(new_list);
// 		new_list = temps_list;
// 	}
// 	// ft_lstdelone(new_list, free_content);
// 	return (EXIT_SUCCESS);
// }