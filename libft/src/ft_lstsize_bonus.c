/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
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

int	ft_lstsize(t_list *lst)
{
	t_list	*current_list;
	size_t	i;

	i = 0;
	current_list = lst;
	while (current_list != NULL)
	{
		current_list = current_list->next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	t_list *new_list;
// 	t_list *temps_list;

// 	new_list = ft_lstnew("test1");
// 	ft_lstadd_front(&new_list, ft_lstnew("test2"));
// 	ft_lstadd_front(&new_list, ft_lstnew("test3"));
// 	ft_putlist(new_list);

// 	printf("res = %d\n",  ft_lstsize(new_list));
// 	while(new_list != NULL)
// 	{
// 		temps_list = new_list->next;
// 		free(new_list);
// 		new_list = temps_list;
// 	}
// 	free(new_list);
// 	return (EXIT_SUCCESS);
// }