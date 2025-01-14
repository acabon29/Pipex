/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:32:07 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == 0 && (unsigned char)c != 0)
		return (NULL);
	return ((char *)&(s[i]));
}

// int	main ()
// {
// 	char *str1 = "test1";
// 	char c1 = 's';
// 	char c2 = 0;
// 	char c3 = 'u';
// 	printf("%s\n", ft_strchr(str1, c1));
// 	printf("%s\n", ft_strchr(str1, c2));
// 	printf("%s\n", ft_strchr(str1, c3));
// 	printf("%s\n", ft_strchr(str1, 257));
// 	return 0;
// }