/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_list;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		current_list = *lst;
		while (current_list != NULL)
		{
			if (current_list->next == NULL)
			{
				current_list->next = new;
				return ;
			}
			current_list = current_list->next;
		}
	}
}

// int main()
// {
// 	t_list *new_list;
// 	t_list *temps_list;

// 	new_list = ft_lstnew("test1");
// 	ft_lstadd_back(&new_list, ft_lstnew("test2"));
// 	ft_lstadd_back(&new_list, ft_lstnew("test3"));
// 	// ft_putlist(new_list);

// 	while(new_list != NULL)
// 	{
// 		temps_list = new_list->next;
// 		free(new_list);
// 		new_list = temps_list;
// 	}
// 	free(new_list);
// 	return (EXIT_SUCCESS);
// }