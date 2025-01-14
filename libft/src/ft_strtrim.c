/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:19:39 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str_temp;
	char	*res;

	str_temp = ft_strdup(s1);
	if (str_temp == NULL)
		return (NULL);
	i = ft_strlen(s1) - 1;
	while (str_temp[i] && ft_memchr(set, str_temp[i], ft_strlen(set)) != NULL)
	{
		str_temp[i] = 0;
		i--;
	}
	i = 0;
	while (str_temp[i] && ft_memchr(set, str_temp[i], ft_strlen(set)) != NULL)
		i++;
	res = ft_strdup(&str_temp[i]);
	if (res == NULL)
		return (free(str_temp), NULL);
	free(str_temp);
	return (res);
}

// int main()
// {
// 	char *res;
// 	res = ft_strtrim("testgfdsgfds111gs12d", "t12");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " ");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_strtrim("testgfdsgfds111gs12d", "t12");
// 	printf("%s\n", res);
// 	free(res);
// 	res = ft_strtrim("testgfdsgfds111gs12d", "t12");
// 	printf("%s\n", res);
// 	free(res);

// 	return 0;
// }
