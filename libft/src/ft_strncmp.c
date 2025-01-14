/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:50:28 by acabon            #+#    #+#             */
/*   Updated: 2025/01/07 15:17:04 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (EXIT_SUCCESS);
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main ()
// {
// 	char str1[] = "test1";
// 	char str2[] = "test1";
// 	unsigned int	n = 5;
// 	printf("%d\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%d\n", strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
// 	printf("%d\n", strncmp("test\200", "test\0", 6));
// 	printf("%d\n", ft_strncmp("t", "", 0));
// 	printf("%d\n", strncmp("t", "", 0));
// 	return 0;
// }