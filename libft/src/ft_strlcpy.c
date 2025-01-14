/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:03:17 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned long	i;
	size_t			size_src;

	size_src = (unsigned long)ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (size_src);
}

// unsigned int strlcpy(char *dest, const char *src, unsigned int size);
//flag -lbsd

// int main()
// {
// 	unsigned int size = 3;
// 	char src[] = "test";
// 	char dest[4];
// 	// char dest2[4];
// 	printf("src = %s\n", src);
// 	unsigned int res = ft_strlcpy(dest, src, size);
// 	// unsigned int res2 = strlcpy(dest2, src, size);
// 	printf("ft_strlcpy = %s %d\n", dest, res);
// 	// printf("strlcpy = %s %d\n", dest2, res2);
// 	return 0;
// }