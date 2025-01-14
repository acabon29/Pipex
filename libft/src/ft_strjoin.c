/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:47 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_concat;
	size_t	i;

	str_concat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_concat == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str_concat[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		str_concat[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str_concat[i] = 0;
	return (str_concat);
}

// int	main()
// {
// 	char *str1 = "test1";
// 	char *str2 = "test2";
// 	char *res;
// 	res = ft_strjoin(str1, str2);
// 	printf("res = %s\n", res);
// 	if (res != NULL)
// 		free(res);
// 	return 0;
// }