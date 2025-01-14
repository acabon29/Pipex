/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:05:19 by acabon            #+#    #+#             */
/*   Updated: 2024/12/10 17:00:03 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// int	main ()
// {
// 	char *str1 = "test1";
// 	char *str2 = "test2";
// 	char *str3 = "test3";
// 	char *str4 = "test4";
// 	char *str5 = "test1";
// 	char *str6 = "test2";
// 	char *str7 = "test3";
// 	char *str8 = "test4";
// 	int c1 = 's';
// 	int c2 = 0;
// 	int c3 = 0;
// 	int c4 = 'u';
// 	int c5 = 's';
// 	int c6 = 0;
// 	int c7 = 0;
// 	int c8 = 'u';
// 	size_t n1 = 3;
// 	size_t n2 = 3;
// 	size_t n3 = 8;
// 	size_t n4 = 3;
// 	printf("%s\n", (char *)ft_memchr(str1, c1, n1));
// 	printf("%s\n", (char *)ft_memchr(str2, c2, n2));
// 	printf("%s\n", (char *)ft_memchr(str3, c3, n3));
// 	printf("%s\n", (char *)ft_memchr(str4, c4, n4));
// 	printf("%s\n", (char *)memchr(str5, c5, n1));
// 	printf("%s\n", (char *)memchr(str6, c6, n2));
// 	printf("%s\n", (char *)memchr(str7, c7, n3));
// 	printf("%s\n", (char *)memchr(str8, c8, n4));
// 	return 0;
// }