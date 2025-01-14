/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
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

// void * replace_first_cara(void *content)
// {
// 	if (content == NULL)
// 		return (content);
// 	((char *)content)[0] = 'u';
// 	return (content);
// }

// void free_content(void *content)
// {
// 	free(content);
// }

// ft_lstdelone(lst, del);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temps_list;
	t_list	*temps_node;
	char	*content_temp;

	new_list = NULL;
	while (lst != NULL)
	{
		content_temp = f(lst->content);
		if (content_temp == NULL)
			return (ft_lstclear(&new_list, del), NULL);
		temps_node = ft_lstnew(content_temp);
		ft_lstadd_back(&new_list, temps_node);
		if (temps_node == NULL)
		{
			del(content_temp);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		temps_list = lst->next;
		lst = temps_list;
	}
	return (new_list);
}

// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list *new_list;
// 	t_list *temp_node;
// 	char *content_temp;

// 	new_list = NULL;
// 	while (lst != NULL)
// 	{
// 		content_temp = f(lst->content);
// 		if (content_temp == NULL)
// 		{
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		temp_node = ft_lstnew(content_temp);
// 		if (temp_node == NULL)
// 		{
// 			free(content_temp);
// 			ft_lstclear(&new_list, del);
// 			return (NULL);
// 		}
// 		ft_lstadd_back(&new_list, temp_node);
// 		lst = lst->next;
// 	}
// 	return (new_list);
// }

// int main()
// {
// 	t_list *new_list;

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

// 	new_list = ft_lstmap(new_list, replace_first_cara, free_content);

// 	// printf("%s\n", (char *)new_list);

// 	ft_putlist(new_list);

// 	ft_lstclear(&new_list, free_content);

// 	ft_putlist(new_list);

// 	return (EXIT_SUCCESS);
// }