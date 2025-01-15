/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:50:28 by acabon            #+#    #+#             */
/*   Updated: 2025/01/15 11:20:20 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
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