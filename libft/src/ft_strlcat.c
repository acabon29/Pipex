/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:59:38 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	i;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size_dest >= size)
		return (size + size_src);
	i = 0;
	while (src[i] != 0 && (size_dest + i) < (size - 1))
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
//flag -lbsd

// int	main ()
// {
// 	unsigned int size = 6;
// 	char str1[6] = "test1";
// 	char str2[6] = "test1";
// 	char src[11] = "test2";
// 	printf("%zu\n", ft_strlcat(str1, src, size));
// 	printf("%zu\n", strlcat(str2, src, size));
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// 	return 0;
// }