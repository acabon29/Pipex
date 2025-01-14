/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:03:48 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*tmp;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	tmp = dest;
	while (*src)
	{
		*dest = *src;
		dest ++;
		src ++;
	}
	*dest = '\x00';
	return (tmp);
}

// int main()
// {
// 	char *src = "test";
// 	char *test;
// 	test = ft_strdup(src);
// 	printf("%s\n", src);
// 	free(test);
// 	return 0;
// }
